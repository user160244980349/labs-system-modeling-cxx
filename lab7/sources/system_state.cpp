#include "../headers/system_state.h"

system_state & inc(system_state & cs) {
	switch (cs) {
	case IDLING:
		return cs = PROCESSING;
	}
	return cs = NULL_TERM;
}

system_state & dec(system_state & cs) {
	switch (cs) {
	case PROCESSING:
		return cs = IDLING;
	}
	return cs = NULL_TERM;
}

bool is_max(system_state cs) {
	if (cs == PROCESSING)
		return true;
	return false;
}

bool is_min(system_state cs) {
	if (cs == IDLING)
		return true;
	return false;
}
