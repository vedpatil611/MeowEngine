#include "MeowPCH.h"

#include "KeyEvent.h"

namespace Meow
{
    unsigned int KeyEvent::getEventCategoryFlags() const
    {
        return (EventCategory::EventCategoryInput | EventCategory::EventCategoryKeyboard);
    }
    EventType KeyPressedEvent::getEventType() const
    {
        return EventType::KeyPressed;
    }
    EventType KeyReleasedEvent::getEventType() const
    {
        return EventType::KeyReleased;
    }
}