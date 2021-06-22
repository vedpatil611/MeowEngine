#include "MeowPCH.h"
#include "Meow/Core.h"
#include "OpenGLShader.h"

#include <glad/glad.h>
#include <Meow/Utils/Log.h>
#include <Meow/Utils/File.h>

namespace Meow
{
	OpenGLShader::OpenGLShader(const char* vertPath, const char* fragPath)
		:m_VertPath(vertPath), m_FragPath(fragPath)
	{
		unsigned int program = glCreateProgram();
		m_ShaderID = createShaderProgram(Utils::readFile(vertPath), Utils::readFile(fragPath));
	}

	OpenGLShader::~OpenGLShader()
	{
		GLCALL(glDeleteProgram(m_ShaderID));
	}

	void OpenGLShader::bind() const
	{
		GLCALL(glUseProgram(m_ShaderID));
	}

	void OpenGLShader::unbind() const
	{
		GLCALL(glUseProgram(0));
	}

	int OpenGLShader::getUniformLocation(const char* uniformName)
	{
		if (m_UniformLocationCache.find(uniformName) != m_UniformLocationCache.end())
			return m_UniformLocationCache[uniformName];

		GLCALL(int location = glGetUniformLocation(m_ShaderID, uniformName));
		if (location == -1)
			LOG_WARN << "Warning: uniform '" << uniformName << "' not found" << END_LOG;
		else
			m_UniformLocationCache[uniformName] = location;

		return location;
	}

	void OpenGLShader::setUniform1i(const char* uniformName, int value)
	{
		GLCALL(glUniform1i(getUniformLocation(uniformName), value));
	}

	void OpenGLShader::setUniform1iv(const char* uniformName, int count, int* value)
	{
		GLCALL(glUniform1iv(getUniformLocation(uniformName), count, value));
	}

	void OpenGLShader::setUniform1f(const char* uniformName, float value)
	{
		GLCALL(glUniform1f(getUniformLocation(uniformName), value));
	}

	void OpenGLShader::setUniform1fv(const char* uniformName, int count, float* value)
	{
		GLCALL(glUniform1fv(getUniformLocation(uniformName), count, value));
	}

	void OpenGLShader::setUniform2f(const char* uniformName, const Maths::vec2& vec)
	{
		GLCALL(glUniform2f(getUniformLocation(uniformName), vec.x, vec.y));
	}

	void OpenGLShader::setUniform3f(const char* uniformName, const Maths::vec3& vec)
	{
		GLCALL(glUniform3f(getUniformLocation(uniformName), vec.x, vec.y, vec.z));
	}

	void OpenGLShader::setUniform4f(const char* uniformName, const Maths::vec4& vec)
	{
		GLCALL(glUniform4f(getUniformLocation(uniformName), vec.x, vec.y, vec.z, vec.w));
	}

	void OpenGLShader::setUniformMat4f(const char* uniformName, const Maths::mat4& mat)
	{
		GLCALL(glUniformMatrix4fv(getUniformLocation(uniformName), 1, false, mat.elements));
	}

	unsigned int OpenGLShader::compileShader(unsigned int type, const std::string& source)
	{
		GLCALL(unsigned int id = glCreateShader(type));
		const char* src = source.c_str();
		GLCALL(glShaderSource(id, 1, &src, nullptr));
		GLCALL(glCompileShader(id));

#ifdef DEBUG
		int result;
		GLCALL(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
		if (!result)
		{
			int length;
			GLCALL(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
			char* message = new char[length];
			GLCALL(glGetShaderInfoLog(id, length, &length, message));
			LOG_ERROR << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader: " << message << END_LOG;
			GLCALL(glDeleteShader(id));
			delete[] message;
			return 0;
		}
#endif

		return id;
	}

	unsigned int OpenGLShader::createShaderProgram(const std::string& vertexShader, const std::string& fragmentShader)
	{
		GLCALL(unsigned int program = glCreateProgram());
		unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
		unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

		GLCALL(glAttachShader(program, vs));
		GLCALL(glAttachShader(program, fs));
		GLCALL(glLinkProgram(program));
		GLCALL(glValidateProgram(program));

		GLCALL(glDeleteShader(vs));
		GLCALL(glDeleteShader(fs));

		return program;
	}
}