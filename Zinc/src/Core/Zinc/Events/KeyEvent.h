#pragma once
#include "Event.h"

/// <summary>
/// Base class for any events involving the keyboard
/// </summary>
class ZINC_API KeyEvent : public Event {
public:
	inline int GetKeyCode() const;
	std::string ToString() const override;

	EVENT_CATEGORY(Keyboard)

protected:
	int m_KeyCode;
	KeyEvent(int keyCode);
};

class ZINC_API KeyPressedEvent : public KeyEvent {
public:
	KeyPressedEvent(int keyCode);
	EventType GetType() const override;

	EVENT_NAME(KeyPressedEvent)
};

class ZINC_API KeyReleasedEvent : public KeyEvent {
public:
	KeyReleasedEvent(int keyCode);
	EventType GetType() const override;

	EVENT_NAME(KeyReleasedEvent)
};