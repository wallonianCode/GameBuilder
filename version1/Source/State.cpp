#include "../Headers/State.hpp"


State::State() {}


bool State::has_to_be_removed() {
	return _hasToBeRemoved;
}


State* State::get_next_state() {
  return _nextState;
}
