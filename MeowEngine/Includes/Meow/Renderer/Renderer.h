#pragma once

#include <Meow/Core.h>

namespace Meow
{
	enum class RendererAPI
	{
		None = 0,
		OpenGL = 1,
		Vulkan = 2
	};

	class MEOW_API Renderer 
	{
	private:
		inline static RendererAPI s_RendererAPI = RendererAPI::OpenGL;
		inline static class GraphicsContext* m_Context;
	public:
		static void setRendererAPI(RendererAPI api) { s_RendererAPI = api; };
		inline static RendererAPI getRendererAPI() { return s_RendererAPI; };
	};
}