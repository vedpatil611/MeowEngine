#include "MeowPCH.h"
#include "ApplicationEvent.h"

namespace Meow
{
    unsigned int Meow::WindowResizeEvent::getEventCategoryFlags() const
    {
        return EventCategory::EventCategoryApplication;
    }

    EventType WindowResizeEvent::getStaticType()
    {
        return EventType::WindowResize;
    }

    EventType WindowResizeEvent::getEventType() const
    {
        return EventType::WindowResize;
    }

    unsigned int WindowCloseEvent::getEventCategoryFlags() const
    {
        return EventCategory::EventCategoryApplication;
    }

    EventType WindowCloseEvent::getStaticType()
    {
        return EventType::WindowClosed;
    }

    EventType WindowCloseEvent::getEventType() const
    {
        return EventType::WindowClosed;
    }

    unsigned int AppUpdateEvent::getEventCategoryFlags() const
    {
        return EventCategory::EventCategoryApplication;
    }

    EventType AppUpdateEvent::getStaticType()
    {
        return EventType::AppUpdate;
    }

    EventType AppUpdateEvent::getEventType() const
    {
        return EventType::AppUpdate;
    }

    unsigned int AppTickEvent::getEventCategoryFlags() const
    {
        return EventCategory::EventCategoryApplication;
    }

    EventType AppTickEvent::getStaticType()
    {
        return EventType::AppTick;
    }

    EventType AppTickEvent::getEventType() const
    {
        return EventType::AppTick;
    }

    unsigned int AppRenderEvent::getEventCategoryFlags() const
    {
        return EventCategory::EventCategoryApplication;
    }

    EventType AppRenderEvent::getStaticType()
    {
        return EventType::AppRender;
    }

    EventType AppRenderEvent::getEventType() const
    {
        return EventType::AppRender;
    }
}