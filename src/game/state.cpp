#include "state.h"

#include <thread>

State::State(Manager& manager) : manager_(manager), window_(manager.window()) {}
