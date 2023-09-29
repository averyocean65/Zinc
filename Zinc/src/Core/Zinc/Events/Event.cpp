#include "Event.h"

#pragma region Event
Event::Event()
	: m_Handled(false) { }

EventType Event::GetType() const { return EventType::Unknown; }
void Event::Dispatch() { m_Handled = true; }

std::string Event::ToString() const {
	return GetEventName();
}
#pragma endregion