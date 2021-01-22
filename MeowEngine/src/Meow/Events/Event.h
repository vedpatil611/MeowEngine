#pragma once

#include <Meow/Core.h>

namespace Meow
{
	enum class EventType
	{
		None = 0,
		WindowClosed = BIT(1), 
		WindowResize = BIT(2),
		WindowFocus = BIT(3),
		WindowMoved = BIT(4),
		WindowFocusLost = BIT(5),
		KeyPressed = BIT(6),
		KeyReleased = BIT(7),
		MouseButtonClicked = BIT(8),
		MouseButtonReleased = BIT(9),
		MouseMoved = BIT(10),
		MouseScrolled = BIT(11),
		AppTick = BIT(12),
		AppUpdate = BIT(13),
		AppRender = BIT(14)
	};

	enum EventCategory: unsigned int
	{
		None = 0,
		EventCategoryApplication = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4),
		EventCategoryInput = BIT(5)
	};

	class MEOW_API Event
	{
	protected:
		bool m_Handled = false;
	public:
		virtual EventType getEventType() const = 0;
		virtual unsigned int getEventCategoryFlags() const = 0;

		bool isInCategory(EventCategory category)
		{
			return getEventCategoryFlags() & category;
		}
	};

	class MEOW_API EventDispatcher
	{
		template <typename T>
		using EventFn = bool(*)(T&);
	private:
		Event& m_Event;
	public:
		EventDispatcher(Event& event)
			:m_Event(event) {}

		template<typename T>
		bool dispatch(EventFn<T> func)
		{
			if (m_Event.getEventType() == T::getStaticType())
			{
				m_Event.m_Handled = func((T)m_Event);
				return true;
			}
			return false;
		}
	};
}