#pragma once

#include <GL/glew.h>
#include <string>

#define GLIMAC_SHADER_SRC(str) #str

namespace glimac {

class ShaderTexture {
public:
	ShaderTexture(GLenum type): m_nGLId(glCreateShader(type)) {
	}

	~ShaderTexture() {
		glDeleteShader(m_nGLId);
	}

	ShaderTexture(ShaderTexture&& rvalue): m_nGLId(rvalue.m_nGLId) {
		rvalue.m_nGLId = 0;
	}

	ShaderTexture& operator =(ShaderTexture&& rvalue) {
		m_nGLId = rvalue.m_nGLId;
		rvalue.m_nGLId = 0;
		return *this;
	}

	GLuint getGLId() const {
		return m_nGLId;
	}

	void setSource(const char* src) {
		glShaderSource(m_nGLId, 1, &src, 0);
	}

	bool compile();

	const std::string getInfoLog() const;

private:
	ShaderTexture(const ShaderTexture&);
	ShaderTexture& operator =(const ShaderTexture&);

	GLuint m_nGLId;
};

// Load a shader (but does not compile it)
ShaderTexture loadShaderTexture(GLenum type, const char* filename);

}
