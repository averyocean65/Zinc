#pragma once

#include "../Core.h"
#include <unordered_map>
#include <string>
#include <vector>
#include <functional>
#include <sstream>

/// Generates 3 functions to get the event category, the flags of the current category and if the current category is in another category
#define EVENT_CATEGORY(c) virtual inline EventCategory GetCategory() { return EventCategory::##c; } \
							virtual inline int GetCategoryFlags() { return (int)EventCategory::##c; } \
							virtual inline bool IsInCategory(const EventCategory& other) { return GetCategoryFlags() & (int)other; }

/// Generates a function to get the Event Name based on the provided input
#define EVENT_NAME(e) virtual inline std::string GetEventName() const { return static_cast<std::string>(#e); }

enum class EventType {
	Unknown,
	
	// WINDOW
	WindowOpen, WindowClose, WindowResize,

	// KEYBOARD
	KeyPressed, KeyReleased,

	// MOUSE
	MousePress, MouseRelease, MouseScroll, MouseMove,
};

enum class EventCategory {
	Unknown				= BIT(0),
	Window				= BIT(1),
	Keyboard			= BIT(2),
	Mouse				= BIT(3),
};

/// <summary>
/// The base event class for ZINC Events
/// </summary>
class ZINC_API Event {
public:
	// Constructor(s)
	Event();

	// Define Event Name
	EVENT_NAME(Event)

	// Basic functions
	inline virtual EventType GetType() const;
	inline virtual std::string ToString() const;

protected:
	// Dispatching
	virtual void Dispatch();
	bool m_Handled = false;

	// Friends
	friend class EventDispatcher;
};

class EventDispatcher {
public:
	// Add a function to a specific event type
	void Subscribe(EventType type, std::function<void(Event&)> callback) {
		m_Listeners[type].push_back(callback);
	}

	// Invoke functions for a certain event using it's event type
	void Dispatch(Event& e) {
		// Check if Event (e) is already handled
		if (e.m_Handled)
			return;

		// Call Events inner dispatch code
		e.Dispatch();

		// Get Type and corresponding vector in the unordered map
		EventType type = e.GetType();
		auto listeners = m_Listeners.find(type);

		// Loop through all functions defined in the vector and run them
		if (listeners != m_Listeners.end()) {
			for (auto& callback : listeners->second) {
				callback(e);
			}
		}
	}

private:
	std::unordered_map<EventType, std::vector<std::function<void(Event&)>>> m_Listeners;
};
