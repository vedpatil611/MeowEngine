#pragma once

#include "MeowPCH.h"
#include <Meow/Core.h>
#include <Meow/Maths/Maths.h>
#include <Meow/Renderer/Shader.h>

namespace Meow
{
	class MEOW_API OpenGLShader : public Shader
	{
	private:
		unsigned int m_ShaderID;
		const char* m_VertPath;
		const char* m_FragPath;
		std::unordered_map<const char*, int>* m_UniformLocationCache;
	public:
		OpenGLShader(const char* vertPath, const char* fragPath);
		~OpenGLShader();

		unsigned int getShaderID() const override { return m_ShaderID; }

		void bind() const override;
		void unbind() const override;

		void setUniform1i(const char* uniformName, int value) override;
		void setUniform1iv(const char* uniformName, int count, int* value) override;
		void setUniform1f(const char* uniformName, float value) override;
		void setUniform1fv(const char* uniformName, int count, float* value) override;
		void setUniform2f(const char* uniformName, const Maths::vec2& vec) override;
		void setUniform3f(const char* uniformName, const Maths::vec3& vec) override;
		void setUniform4f(const char* uniformName, const Maths::vec4& vec) override;
		void setUniformMat4f(const char* uniformName, const Maths::mat4& mat) override;
	private:
		int getUniformLocation(const char* uniformName);

		unsigned int compileShader(unsigned int type, const std::string& source);
		unsigned int createShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
	};
}
