#pragma once

#ifdef MEOW_PLATFORM_WINDOWS
#pragma warning(push)
#pragma warning(disable : 4251)
#pragma warning(pop)
#endif

#include <Meow/Core.h>
#include <Meow/Maths/Maths.h>
#include <Meow/Renderer/Texture.h>
#include <vector>

DISABLE_WARNINGS()

namespace Meow 
{
	struct VertexData {
		Maths::vec3 vertex;
		Maths::vec4 colour;
		Maths::vec2 UV;
		float tid;
	};

	struct Transformations2D
	{
		Maths::vec3 translation = { 0.0f, 0.0f, 0.0f };
		Maths::vec2 scale = { 1.0f, 1.0f};
		float rotation = 0.0f;
	};

	class MEOW_API Renderable2D
	{
	public:
		Maths::vec3 m_Position;
		Maths::vec2 m_Size;
		Maths::vec4 m_Colour;
	protected:
		std::vector<Maths::vec2> m_UVS;
		Texture* m_Texture = nullptr;
	public:
		Renderable2D(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4 colour);
		virtual ~Renderable2D();

		virtual inline class VertexArray* getVAO() const = 0;
		virtual inline class IndexBuffer* getIBO() const = 0;
		virtual inline class Shader* getShader() const = 0;

		inline const Maths::vec3& getPositions() const { return m_Position; }
		inline const Maths::vec2& getSize() const { return m_Size; }
		inline const Maths::vec4& getColor() const { return m_Colour; };
		inline const std::vector<Maths::vec2>& getUVs() const { return m_UVS; }
		inline const unsigned int getTID() const { return !m_Texture ? 0 : m_Texture->getTextureId(); }
	};
}