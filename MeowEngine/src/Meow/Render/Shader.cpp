#include "Shader.h"

#include <iostream>
#include <glad/glad.h>
#include <Meow/Utils/File.h>
#include <Meow/Render/Renderer.h>

namespace Meow
{
	Shader::Shader(const char* vertPath, const char* fragPath)
		:m_VertPath(vertPath), m_FragPath(fragPath)
	{
		unsigned int program = glCreateProgram();

		m_ShaderID = createShaderProgram(Utils::readFile(vertPath), Utils::readFile(fragPath));
	}

	Shader::~Shader()
	{
		GLCALL(glDeleteProgram(m_ShaderID));
	}

	void Shader::enable() const
	{
		GLCALL(glUseProgram(m_ShaderID));
	}

	void Shader::disable() const
	{
		GLCALL(glUseProgram(0));
	}

	int Shader::getUniformLocation(const char* uniformName) const
	{
		GLCALL(int location = glGetUniformLocation(m_ShaderID, uniformName));
		if (location == -1)
			LOG_WARN << "Warning: uniform '" << uniformName << "' not found" << END_LOG;
		return location;
	}

	void Shader::setUniform1i(const char* uniformName, const int& value)
	{
		GLCALL(glUniform1i(getUniformLocation(uniformName), value));
	}

	void Shader::setUniform1f(const char* uniformName, const float& value)
	{
		GLCALL(glUniform1f(getUniformLocation(uniformName), value));
	}

	void Shader::setUniform2f(const char* uniformName, const Maths::vec2& vec)
	{
		GLCALL(glUniform2f(getUniformLocation(uniformName), vec.x, vec.y));
	}

	void Shader::setUniform3f(const char* uniformName, const Maths::vec3& vec)
	{
		GLCALL(glUniform3f(getUniformLocation(uniformName), vec.x, vec.y, vec.z));
	}

	void Shader::setUniform4f(const char* uniformName, const Maths::vec4& vec)
	{
		GLCALL(glUniform4f(getUniformLocation(uniformName), vec.x, vec.y, vec.z, vec.w));
	}

	void Shader::setUniformMat4f(const char* uniformName, const Maths::mat4& mat)
	{
		GLCALL(glUniformMatrix4fv(getUniformLocation(uniformName), 1, false, mat.elements));
	}

	unsigned int Shader::compileShader(unsigned int type, const std::string& source)
	{
		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		#ifdef DEBUG
		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if (!result)
		{
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = new char[length];
			glGetShaderInfoLog(id, length, &length, message);
			LOG_ERROR << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader" << message << END_LOG;
			glDeleteShader(id);
			delete[] message;
			return 0;
		}
		#endif
		
		return id;
	}

	unsigned int Shader::createShaderProgram(const std::string& vertexShader, const std::string& fragmentShader)
	{
		unsigned int program = glCreateProgram();
		unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
		unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vs);
		glDeleteShader(fs);

		return program;
	}
}