#pragma once

#include "Renderer2D.h"
#include <Meow/Renderable/Renderable2D.h>
#include <vector>

#define RENDERER_MAX_SPRITES	10000
#define RENDERER_VERTEX_SIZE	sizeof(VertexData)
#define RENDERER_SPRITE_SIZE	RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE	RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE	RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX	0
#define SHADER_COLOUR_INDEX	1
#define SHADER_UV_INDEX		2
#define SHADER_TID_INDEX	3

#define VERTEX_DATA_OFFSET(offset) (const void*) ((offset) * sizeof(float))

namespace Meow {
	class MEOW_API BatchRenderer2D : public Renderer2D
	{
	private:
		unsigned int m_VAO;
		class IndexBuffer* m_IBO;
		int m_IndexCount;
		unsigned int m_VBO;
		unsigned int submitCount = 0;
		std::vector<int> m_TexturesSlots;
		VertexData* m_Buffer;
	public:
		BatchRenderer2D();
		~BatchRenderer2D();

		void begin();
		void end();	
		void submit(const Renderable2D* renderable) override;
		void flush(float delta) override;
		void clear();
	private:
		void init();
	};
}
