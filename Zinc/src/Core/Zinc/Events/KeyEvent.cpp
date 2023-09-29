#include "KeyEvent.h"

#pragma region KeyEvent
KeyEvent::KeyEvent(int keyCode)
	: m_KeyCode(keyCode), Event()
{ }

int KeyEvent::GetKeyCode() const { return m_KeyCode; }
std::string KeyEvent::ToString() const
{
	const size_t MAX_BUFFER_SIZE = 128;

	char buf[MAX_BUFFER_SIZE];
	snprintf(buf, MAX_BUFFER_SIZE, "%s 0x%X", GetEventName().c_str(), m_KeyCode);

	return std::string(buf);
}
#pragma endregion

#pragma region KeyPressedEvent
KeyPressedEvent::KeyPressedEvent(int keyCode)
	: KeyEvent(keyCode)
{ }

EventType KeyPressedEvent::GetType() const { return EventType::KeyPressed; }
#pragma endregion

#pragma region KeyReleasedEvent
KeyReleasedEvent::KeyReleasedEvent(int keyCode)
	: KeyEvent(keyCode)
{ }

EventType KeyReleasedEvent::GetType() const { return EventType::KeyReleased; }
#pragma endregion