#include "MeowPCH.h"
#include "MouseEvent.h"

#include "Event.h"

namespace Meow
{
    unsigned int MouseButtonEvent::getEventCategoryFlags() const
    {
        return (EventCategory::EventCategoryInput | EventCategory::EventCategoryMouse);
    }
    
    EventType MouseButtonPressedEvent::getStaticType()
    {
        return EventType::MouseButtonClicked;
    }
    
    EventType MouseButtonPressedEvent::getEventType() const
    {
        return EventType::MouseButtonClicked;
    }

    EventType MouseButtonReleasedEvent::getStaticType()
    {
        return EventType::MouseButtonReleased;
    }

    EventType MouseButtonReleasedEvent::getEventType() const
    {
        return EventType::MouseButtonReleased;
    }
    
    unsigned int MouseMovedEvent::getEventCategoryFlags() const
    {
        return EventCategory::EventCategoryMouse | EventCategory::EventCategoryInput;
    }

    EventType MouseMovedEvent::getStaticType()
    {
        return EventType::MouseMoved;
    }

    EventType MouseMovedEvent::getEventType() const
    {
        return EventType::MouseMoved;
    }
}