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
		delete[] m_VertPath;
		delete[] m_FragPath;
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
			std::cout << COLOUR_RED;
			std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader" << std::endl;
			std::cout << message << COLOUR_RST << std::endl;
			glDeleteShader(id);
			delete[] message;
			return 0;
		}
		#endif
		
		delete[] src;

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