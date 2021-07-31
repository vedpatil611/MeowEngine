#include "MeowPCH.h"
#include <Meow/Events/KeyEvent.h>

namespace Meow
{
    unsigned int KeyEvent::getEventCategoryFlags() const
    {
        return (EventCategory::EventCategoryInput | EventCategory::EventCategoryKeyboard);
    }

    EventType KeyPressedEvent::getStaticType()
    {
        return EventType::KeyPressed;
    }

    EventType KeyPressedEvent::getEventType() const
    {
        return EventType::KeyPressed;
    }

    EventType KeyReleasedEvent::getStaticType()
    {
        return EventType::KeyReleased;
    }

    EventType KeyReleasedEvent::getEventType() const
    {
        return EventType::KeyReleased;
    }

    EventType KeyTypedEvent::getStaticType()
    {
        return EventType::KeyTyped;
    }

    EventType KeyTypedEvent::getEventType() const
    {
        return EventType::KeyTyped;
    }
}