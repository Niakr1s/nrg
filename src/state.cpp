#include "state.h"

#include <thread>

misc::EventQueue& State::eventQueue() { return event_queue_; }

Manager& State::manager() { return manager_; }

State::State(Manager& manager) : manager_(manager), window_(manager.window()) {}
