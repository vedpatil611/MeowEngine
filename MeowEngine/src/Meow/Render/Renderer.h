#pragma once

#include <glad/glad.h>
#include <Meow/Core.h>
#include <Meow/Log.h>
#include <Meow/Window.h>
#include <Meow/Render/Shader.h>
#include <Meow/Maths/Maths.h>

#ifdef DEBUG
	#define ASSERT(x) if(!(x)) __debugbreak();
	#define GLCALL(func) GlClearError();			\
		func;										\
		ASSERT(GlLogCall(#func, __FILE__, __LINE__))
#else
	#define ASSERT(x)
	#define GLCALL(func) func; 
#endif 

void GlClearError();
bool GlLogCall(const char* functionName, const char* file, const int& line);

namespace Meow
{
	class MEOW_API Renderer
	{
	public:
		Renderer(const Window& window);

		void testDraw(Shader& shader)
		{
			float vertex[] =
			{
				 8.0f,  3.0f,
				 4.0f,  6.0f,
				12.0f,  6.0f
			};

			unsigned int vbo;
			glGenBuffers(1, &vbo);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
			glVertexAttribPointer(0, 2, GL_FLOAT, false, 0, nullptr);
			glEnableVertexAttribArray(0);

			Meow::Maths::mat4 m = Meow::Maths::mat4::orthographic(0, 16, 0, 9, -1, 1);

			shader.setUniformMat4f("pr_mat", m);
		}

		void testRender()
		{
			glDrawArrays(GL_TRIANGLES, 0, 3);
		}
	};
}