#pragma once

#include <Meow/Core.h>

typedef void (*eventCallback)();

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
		MouseScrolled = BIT(11)
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
	public:
		virtual EventType getEventType() const = 0;
		virtual unsigned int getEventCategoryFlags() const = 0;

		bool isInCategory(EventCategory category)
		{
			return getEventCategoryFlags() & category;
		}
	};
}