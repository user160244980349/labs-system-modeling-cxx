#ifndef MODSYS_SYSTEMSTATE_H
#define MODSYS_SYSTEMSTATE_H

enum system_state {
	IDLING,
	PROCESSING,
	NULL_TERM,
};

system_state& inc(system_state& cs);

system_state& dec(system_state& cs);

bool is_max(system_state cs);

bool is_min(system_state cs);

#endif // MODSYS_SYSTEMSTATE_H
