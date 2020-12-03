#pragma once

#include "Event.h"

namespace Meow
{
	class MEOW_API KeyEvent : public Event
	{
	protected:
		int m_KeyCode;
		KeyEvent(int keycode)
			:m_KeyCode(keycode) {}

	public:
		virtual unsigned int getEventCategoryFlags() const override;
	};

	class MEOW_API KeyPressedEvent : public KeyEvent
	{
	private:
		unsigned int m_RepeatCount;
	public:
		KeyPressedEvent(int keycode, unsigned int repeatCount)
			:KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline unsigned int getRepeatCount() const { return m_RepeatCount; }

		EventType getEventType() const override;
	};
}