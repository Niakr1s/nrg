#include "state.h"

#include <thread>

EventQueue& State::eventQueue() { return event_queue_; }

State::State(Manager& manager) : manager_(manager), window_(manager.window()) {}
