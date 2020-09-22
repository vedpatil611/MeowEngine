#pragma once

#include "MeowPCH.h"
#include <Meow/Core.h>
#include <Meow/Maths/Maths.h>

namespace Meow
{
	class MEOW_API Shader // OpenGL shader
	{
	private:
		unsigned int m_ShaderID;
		const char* m_VertPath;
		const char* m_FragPath;
		std::unordered_map<const char*, int> *m_UniformLocationCache;
	public:
		Shader(const char* vertPath, const char* fragPath);
		~Shader();

		unsigned int getShaderID() const { return m_ShaderID; }

		void enable() const;
		void disable() const;

		void setUniform1i(const char* uniformName, const int& value);
		void setUniform1f(const char* uniformName, const float& value);
		void setUniform2f(const char* uniformName, const Maths::vec2& vec);
		void setUniform3f(const char* uniformName, const Maths::vec3& vec);
		void setUniform4f(const char* uniformName, const Maths::vec4& vec);
		void setUniformMat4f(const char* uniformName, const Maths::mat4& mat);
	private:
		int getUniformLocation(const char* uniformName);

		unsigned int compileShader(unsigned int type, const std::string& source);
		unsigned int createShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
	};
}