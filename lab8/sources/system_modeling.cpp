#include "../headers/system_modeling.h"
#include "../headers/system_state.h"
#include "../headers/time_frame.h"
#include "../headers/time_frame_type.h"
#include <random>
#include <ctime>
#include <chrono>
#include <queue>
#include <vector>
#include <list>
#include <iostream>
#include <functional>
#include <math.h>

using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::microseconds;
using std::chrono::duration_cast;
using std::chrono::steady_clock;

using std::function;
using std::vector;
using std::list;
using std::priority_queue;

using std::mt19937;
using std::uniform_real_distribution;

using std::cout;
using std::endl;

// #define DEBUG

void system_modeling(int* served, int* declined, int lambda, int nu, int t) {

    mt19937 generator(time(0));
    uniform_real_distribution<> random(0, 1);

    priority_queue<time_frame, vector<time_frame>> ordered_time_frames;

    system_state system_status = IDLING;

    double new_request = -(static_cast<double>(1) / lambda * log(1 - random(generator)));
    double channel_time = new_request;

    ordered_time_frames.emplace(INNER, new_request);

    cout << endl << " Моделирование" << endl;
    cout << "------------------------------------------------------------------------------" << endl;

#ifdef DEBUG
    cout << "\t\tstatus: " << system_status << "\ttime: " << 0 << endl;
#endif // DEBUG

    auto start = steady_clock::now();
    while (duration_cast<seconds>(steady_clock::now() - start) < seconds(t)) {

        auto current_time_point = ordered_time_frames.top();
        ordered_time_frames.pop();

        if (current_time_point.type == INNER) {

            double time_till_request = -(static_cast<double>(1) / lambda * log(1 - random(generator)));
            new_request += time_till_request;
            ordered_time_frames.emplace(INNER, new_request);

            if (!is_max(system_status)) {
                (*served)++;

                if (is_min(system_status))
                    channel_time = current_time_point.time_point;

                inc(system_status);

                double serving_time = -(static_cast<double>(1) / nu * log(1 - random(generator)));

                channel_time += serving_time;
                ordered_time_frames.emplace(OUTER, channel_time);

#ifdef DEBUG
                cout << " ACCEPTED,\tstatus: " << system_status << "\ttime: " << current_time_point.time_point << endl;
#endif // DEBUG

            } else {
                (*declined)++;

#ifdef DEBUG
                cout << " DECLINED,\tstatus: " << system_status << "\ttime: " << current_time_point.time_point << endl;
#endif // DEBUG

            }
        }

        if (current_time_point.type == OUTER) {
            dec(system_status);

#ifdef DEBUG
            cout << " SERVED,\tstatus: " << system_status << "\ttime: " << current_time_point.time_point << endl;
#endif // DEBUG

        }

    }

}
