#pragma once

#include <Meow/Core.h>
#include <string>

namespace Meow
{
	MEOW_API class Shader
	{
	private:
		unsigned int m_ShaderID;
		const char* m_VertPath;
		const char* m_FragPath;
	public:
		Shader(const char* vertPath, const char* fragPath);
		~Shader();

		void enable() const;
		void disable() const;
	private:
		unsigned int load();
		unsigned int compileShader(unsigned int type, const std::string& source);
		unsigned int createShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
	};
}