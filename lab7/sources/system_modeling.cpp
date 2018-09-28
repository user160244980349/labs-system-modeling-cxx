#include "../headers/system_modeling.h"
#include "../headers/system_state.h"
#include "../headers/time_frame.h"
#include "../headers/time_frame_type.h"
#include <random>
#include <ctime>
#include <chrono>
#include <queue>
#include <vector>
#include <iostream>
#include <math.h>

using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::microseconds;
using std::chrono::duration_cast;
using std::chrono::steady_clock;

using std::vector;
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

    ordered_time_frames.emplace(INNER, -(static_cast <double>(1) / lambda * log(1 - random(generator))));

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

            double time_till_request = -(static_cast <double>(1) / lambda * log(1 - random(generator)));

            ordered_time_frames.emplace(INNER, current_time_point.time_point + time_till_request);

            if (!is_max(system_status)) {
                (*served)++;

                double serving_time = -(static_cast <double>(1) / nu * log(1 - random(generator)));
                ordered_time_frames.emplace(OUTER, current_time_point.time_point + serving_time);

                inc(system_status);
#ifdef DEBUG
                cout << " ACCEPTED,\tstatus: " << system_status << "\ttime: " << current_time_point.time_point << endl;
#endif // DEBUG

            } else {
#ifdef DEBUG
                cout << " DECLINED,\tstatus: " << system_status << "\ttime: " << current_time_point.time_point << endl;
#endif // DEBUG
                (*declined)++;

            }
        }

        if (current_time_point.type == OUTER && !is_min(system_status)) {
            dec(system_status);
#ifdef DEBUG
            cout << " SERVED,\tstatus: " << system_status << "\ttime: " << current_time_point.time_point << endl;
#endif // DEBUG
        }

    }

}
