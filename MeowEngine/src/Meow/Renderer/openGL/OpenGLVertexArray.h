#pragma once

#include <Meow/Core.h>
#include <Meow/Renderer/Buffer.h>
#include <Meow/Renderer/VertexArray.h>
#include <vector>

namespace Meow
{
	class MEOW_API OpenGLVertexArray : public VertexArray
	{
	private:
		unsigned int m_ArrayId;
		std::vector<Buffer*> m_Buffers;
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray();

		void addBuffer(Buffer* buffer, unsigned int index) override;

		void bind() const override;
		void unbind() const override;
	};
}