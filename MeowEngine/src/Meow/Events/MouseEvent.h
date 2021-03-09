#pragma once

#include "Event.h"
#include <Meow/Core.h>

namespace Meow
{
	class MEOW_API MouseButtonEvent : public Event
	{
	protected:
		int m_Button;
		MouseButtonEvent(int button): m_Button(button) {}
	public:
		virtual unsigned int getEventCategoryFlags() const override;

		inline int getMouseButton() const { return m_Button; }
	};

	class MEOW_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) :
			MouseButtonEvent(button) {}

		static EventType getStaticType();
		EventType getEventType() const override;
	};

	class MEOW_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) :
			MouseButtonEvent(button) {}

		static EventType getStaticType();
		EventType getEventType() const override;
	};

	class MEOW_API MouseMovedEvent :public Event
	{
	private:
		double m_MouseX, m_MouseY;
	public:
		MouseMovedEvent(double x, double y) :
			m_MouseX(x), m_MouseY(y) {}

		inline float getX() const { return static_cast<float>(m_MouseX); }
		inline float getY() const { return static_cast<float>(m_MouseY); }

		unsigned int getEventCategoryFlags() const override;

		static EventType getStaticType();
		EventType getEventType() const override;
	};

	class MEOW_API MouseScrolledEvent :public Event
	{
	private:
		double m_MouseX, m_MouseY;
	public:
		MouseScrolledEvent(double x, double y) :
			m_MouseX(x), m_MouseY(y) {}

		inline float getX() const { return static_cast<float>(m_MouseX); }
		inline float getY() const { return static_cast<float>(m_MouseY); }

		unsigned int getEventCategoryFlags() const override;

		static EventType getStaticType();
		EventType getEventType() const override;
	};
}