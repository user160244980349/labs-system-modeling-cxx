#ifndef MODSYS_TIMEFRAME_H
#define MODSYS_TIMEFRAME_H

#include "time_frame_type.h"

typedef struct time_frame {
	time_frame_type type;
	double time_point;
} time_frame;

struct time_frame_comparator {
	bool operator()(const time_frame& lhs, const time_frame& rhs) {
		return lhs.time_point > rhs.time_point;
	}
};

#endif // MODSYS_TIMEFRAME_H
