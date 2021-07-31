#pragma once

#include "MeowPCH.h"
#include <Meow/Core.h>
#include <Meow/Maths/Maths.h>

namespace Meow
{
	class MEOW_API Shader // OpenGL shader
	{
	public:
		static Shader* create(const char* vertPath, const char* fragPath);
		virtual ~Shader() {}

		virtual unsigned int getShaderID() const = 0;

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual void setUniform1i(const char* uniformName, int value) = 0;
		virtual void setUniform1iv(const char* uniformName, int count, int* value) = 0;
		virtual void setUniform1f(const char* uniformName, float value) = 0;
		virtual void setUniform1fv(const char* uniformName, int count, float* value) = 0;
		virtual void setUniform2f(const char* uniformName, const Maths::vec2& vec) = 0;
		virtual void setUniform3f(const char* uniformName, const Maths::vec3& vec) = 0;
		virtual void setUniform4f(const char* uniformName, const Maths::vec4& vec) = 0;
		virtual void setUniformMat4f(const char* uniformName, const Maths::mat4& mat) = 0;
	};
}