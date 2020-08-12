#include "MeowApplication.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Meow/Maths/Maths.h>
#include <Meow/Render/Renderer.h>
#include <Meow/Render/Shader.h>
#include <Meow/Render/IndexBuffer.h>
#include <Meow/Render/VertexArray.h>
#include <Meow/Render/VertexBuffer.h>
#include <Meow/Utils/File.h>
#include <Meow/Window.h>
#include <Meow/Log.h>

#ifdef MEOW_PLATFORM_WINDOWS
#include <Windows.h>
#endif 


Meow::Application* Meow::CreateApplication()
{
	#ifdef MEOW_PLATFORM_WINDOWS
		#ifndef DEBUG
			ShowWindow(GetConsoleWindow(), SW_HIDE);
		#else
			ShowWindow(GetConsoleWindow(), SW_SHOW);
		#endif 
	#endif 

	return new MeowApplication();
}

MeowApplication::MeowApplication()
{
}

MeowApplication::~MeowApplication()
{
}

void MeowApplication::Run()
{
	Meow::Window window("Meow", 800, 600);
	Meow::Maths::vec2 a;
	Meow::Maths::vec2 b(3.0f, 2.0f);

	Meow::Renderer* renderer = new Meow::Renderer(window);
	Meow::Shader* shader = new Meow::Shader("shaders/vert.glsl", "shaders/frag.glsl");
	shader->enable();
	//renderer->testDraw(*shader);
	float vertices[] =
	{
		 8.0f, 3.0f, 0.0f,
		 4.0f, 6.0f, 0.0f,
		12.0f, 6.0f, 0.0f
	};

	unsigned short indices[] = { 0, 1, 2 };
	Meow::VertexArray vao;
	Meow::VertexBuffer* vbo = new Meow::VertexBuffer(vertices, 3 * 3, 3);
	Meow::IndexBuffer ibo(indices, 3);
	vao.addBuffer(vbo, 0);
	
	Meow::Maths::mat4 m = Meow::Maths::mat4::orthographic(0, 16, 0, 9, -1, 1);
	shader->setUniformMat4f("pr_mat", m);

	while (!window.closed())
	{
		vao.bind();
		ibo.bind();
		renderer->testRender(ibo.getCount());
		ibo.unbind();
		vao.unbind();
		window.update();
	}

	//delete vbo;
	delete renderer;
	delete shader;
}