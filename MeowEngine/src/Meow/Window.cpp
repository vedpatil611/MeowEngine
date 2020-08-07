#include "Window.h"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>

namespace Meow {
	Window::Window(const char* title, int width, int height)
		:m_Title(title), m_Width(width), m_Height(height)
	{
		if (!glfwInit())
			throw std::runtime_error("Failed to init glfw");

		m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
		if (!m_Window)
		{
			glfwTerminate();
			throw std::runtime_error("Failed to init glfw");
		}
		
		glfwSetWindowSizeCallback(m_Window, &Meow::Window::windowResizeCallback);
		glfwMakeContextCurrent(m_Window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			throw std::runtime_error("Failed to init glad");
		
		//glad triangle test
		unsigned int vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, false, sizeof(float) * 2, 0);
		glEnableVertexAttribArray(0);

		std::string data;
		std::ifstream file("shaders/vert.glsl");
		std::stringstream ss;
		while (getline(file, data))
		{
			ss << data << "\n";
		}
		file.close();
		std::string copy = ss.str();
		const char* vert_src = copy.c_str();
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vert_src, nullptr);
		glCompileShader(vertexShader);

		file.open("shaders/frag.glsl");
		ss.str("");
		while (getline(file, data))
		{
			ss << data << "\n";
		}
		file.close();
		copy = ss.str();
		const char* frag_src = copy.c_str();
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &frag_src, nullptr);
		glCompileShader(fragmentShader);

		unsigned int shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);
		glValidateProgram(shaderProgram);
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		glUseProgram(shaderProgram);
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::update() 
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwGetWindowSize(m_Window, &m_Width, &m_Height);
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window);
	}
	void Window::windowResizeCallback(GLFWwindow* window, int width, int height)
	{
		glfwSetWindowSize(window, width, height);
		glad_glViewport(0, 0, width, height);
	}
}