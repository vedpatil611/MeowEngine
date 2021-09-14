#pragma once

#include <Meow/Core.h>
#include <Meow/Maths/Maths.h>
#include "Renderable2D.h"

namespace Meow
{
	class MEOW_API Sprite: public Renderable2D
	{
	public:
		Transformations2D m_TransformData;
	protected:
		Rc<Shader> m_Shader = nullptr;
	public:
		Sprite(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4& colour, Rc<Shader> shader);
		Sprite(const Maths::vec3& position, const Maths::vec2& size, Rc<Texture> tex, Rc<Shader> shader);
		virtual ~Sprite();

		static Rc<Sprite> create(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4& colour, Rc<Shader> shader);
		static Rc<Sprite> create(const Maths::vec3& position, const Maths::vec2& size, Rc<Texture> tex, Rc<Shader> shader);

		inline Rc<Shader> getShader() const override { return m_Shader; }
		inline Rc<Texture> getTexture() const { return m_Texture; }
		Transformations2D& getTransform() { return m_TransformData; }

		void addTranslation(Maths::vec3 translation);
		void addScaling(Maths::vec2 scale);
		void addRotation(float rotate);

		void setTranslation(Maths::vec3 translation);
		void setScaling(Maths::vec2 scale);
		void setRotation(float rotate);

		virtual void updateUniforms(float delta) const;
	};
}
