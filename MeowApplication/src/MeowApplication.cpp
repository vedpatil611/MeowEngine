#include "MeowApplication.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Meow/Maths/Maths.h>
#include <Meow/Render/Renderer.h>
#include <Meow/Render/Shader.h>
#include <Meow/Render/IndexBuffer.h>
#include <Meow/Render/VertexArray.h>
#include <Meow/Render/Buffer.h>
#include <Meow/Utils/File.h>
#include <Meow.h>
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
	Meow::Window window("Meow", 800, 800);

	Meow::Renderer* renderer = new Meow::Renderer(window);
	Meow::Shader* shader = new Meow::Shader("shaders/vert.glsl", "shaders/frag.glsl");
	float vertices[] =
	{
		200.0f, 200.0f, 0.0f,
		200.0f, 600.0f, 0.0f,
		600.0f, 600.0f, 0.0f,
		600.0f, 200.0f, 0.0f
	};
	float colours[] =
	{
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 1.0f
	};

	unsigned short indices[] = { 0, 1, 2, 2, 3, 0 };
	Meow::VertexArray vao;
	Meow::Buffer* vbo = new Meow::Buffer(vertices, 4 * 3, 3);
	Meow::Buffer* colourBuffer = new Meow::Buffer(colours, 4 * 4, 4);
	Meow::IndexBuffer ibo(indices, 6);
	vao.addBuffer(vbo, 0);
	vao.addBuffer(colourBuffer, 1);

	shader->enable();
	Meow::Maths::mat4 proj = Meow::Maths::mat4::orthographic(0, 800, 0, 800, -1, 1);
	shader->setUniformMat4f("u_pr_mat", proj);
	shader->setUniform4f("u_Color", Meow::Maths::vec4(0.0f, 0.5f, 0.5f, 1.0f));

	while (!window.closed())
	{
		window.update();
		vao.bind();
		ibo.bind();
		shader->enable();
		shader->setUniform2f("u_LightPos", Meow::Maths::vec2(window.getMouseX(), window.getMouseY()));
		renderer->testRender(ibo.getCount());
		ibo.unbind();
		vao.unbind();
	}

	delete shader;
	delete renderer;
}