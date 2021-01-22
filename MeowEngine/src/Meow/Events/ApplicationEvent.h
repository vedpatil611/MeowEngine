#pragma once

#include <Meow/Core.h>
#include "Event.h"

namespace Meow
{
	class MEOW_API WindowResizeEvent :public Event
	{
	private:
		unsigned int m_Width, m_Height;
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			:m_Width(width), m_Height(height) {}

		inline unsigned int getWidth() const { return m_Width; }
		inline unsigned int getHeight() const { return m_Height; }

		unsigned int getEventCategoryFlags() const override;
		static EventType getStaticType();
		EventType getEventType() const override;
	};

	class MEOW_API WindowCloseEvent :public Event
	{
	public:
		WindowCloseEvent() {}

		unsigned int getEventCategoryFlags() const override;
		static EventType getStaticType();
		EventType getEventType() const override;
	};

	class MEOW_API AppTickEvent :public Event
	{
	public:
		AppTickEvent() {}

		unsigned int getEventCategoryFlags() const override;
		static EventType getStaticType();
		EventType getEventType() const override;
	};

	class MEOW_API AppUpdateEvent :public Event
	{
	public:
		AppUpdateEvent() {}

		unsigned int getEventCategoryFlags() const override;
		static EventType getStaticType();
		EventType getEventType() const override;
	};

	class MEOW_API AppRenderEvent :public Event
	{
	public:
		AppRenderEvent() {}

		unsigned int getEventCategoryFlags() const override;
		static EventType getStaticType();
		EventType getEventType() const override;
	};
}