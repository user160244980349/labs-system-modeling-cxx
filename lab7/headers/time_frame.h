#ifndef MODSYS_TIMEFRAME_H
#define MODSYS_TIMEFRAME_H

#include "time_frame_type.h"

class time_frame {
public:
	time_frame_type type;
	double time_point;

	time_frame(time_frame_type type, double time_point) {
		this->type = type;
		this->time_point = time_point;
	}

	bool operator< (const time_frame& other) const {
		return time_point > other.time_point;
	}
};

#endif // MODSYS_TIMEFRAME_H
