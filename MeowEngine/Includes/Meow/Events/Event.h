#pragma once

#include <Meow/Core.h>
#include <functional>

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
		KeyTyped = BIT(8),
		MouseButtonClicked = BIT(9),
		MouseButtonReleased = BIT(10),
		MouseMoved = BIT(11),
		MouseScrolled = BIT(12),
		AppTick = BIT(13),
		AppUpdate = BIT(14),
		AppRender = BIT(15)
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
		friend class EventDispatcher;
	public:
		bool handled = false;
		
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
		using EventFn = std::function<bool(T&)>;
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
				m_Event.handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	};
}