#pragma once

#include "Meow/Core.h"
#include "Meow/Renderer/Layer.h"
#include "Meow/Events/ApplicationEvent.h"
#include "Meow/Events/KeyEvent.h"
#include "Meow/Events/MouseEvent.h"

namespace Meow
{
	class MEOW_API ImGuiLayer : public Layer
	{
	private:
		float m_Time = 0;
	public:
		ImGuiLayer();
		virtual ~ImGuiLayer();

		virtual void onAttach() override;
		virtual void onUpdate() override;
		virtual void onDettach() override;
		virtual void onEvent(Event& e) override;

		virtual void begin() override;
		virtual void onRender(float delta) override;
		virtual void end() override;
	private:
		bool windowResizeCallback(WindowResizeEvent& e);
		bool mouseButtonPressedCallback(MouseButtonPressedEvent& e);
		bool mouseButtonReleasedCallback(MouseButtonReleasedEvent& e);
		bool mouseMovedCallback(MouseMovedEvent& e);
		bool mouseScrollCallback(MouseScrolledEvent& e);
		bool keyPressedCallback(KeyPressedEvent& e);
		bool keyReleasedCallback(KeyReleasedEvent& e);
		bool keyTypedCallback(KeyTypedEvent& e);
	};
}