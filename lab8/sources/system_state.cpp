#include "../headers/system_state.h"

system_state & inc(system_state & cs) {
	switch (cs) {
	case IDLING:
		return cs = PROCESSING;
	case PROCESSING:
		return cs = QUEUED1;
	case QUEUED1:
		return cs = QUEUED2;
	case QUEUED2:
		return cs = QUEUED3;
	}
	return cs = NULL_TERM;
}

system_state & dec(system_state & cs) {
	switch (cs) {
	case QUEUED3:
		return cs = QUEUED2;
	case QUEUED2:
		return cs = QUEUED1;
	case QUEUED1:
		return cs = PROCESSING;
	case PROCESSING:
		return cs = IDLING;
	}
	return cs = NULL_TERM;
}

bool is_max(system_state cs) {
	if (cs == QUEUED3)
		return true;
	return false;
}

bool is_min(system_state cs) {
	if (cs == IDLING)
		return true;
	return false;
}
