#include <vector>
#include <math.h>

using std::vector;

vector<vector<double>> chunk_array(vector<double> array, int groups, double min, double max) {
    double step = (max - min) / groups;
    vector<vector<double>> temp_array;

    int j = 0;
    for (int i = 0; i < groups; i++) {
        temp_array.push_back(vector<double>());
        for (; array[j] <= min + i * step && j < array.size(); j++) {
            temp_array.back().push_back(array[j]);
        }
    }

    return temp_array;
}

vector<double> approximate_array(vector<vector<double>> array) {
    vector<double> temp_array;

    for (auto &group : array) {
        if (!group.empty()) {
            temp_array.push_back((group.front() + group.back()) / 2);
        } else {
            temp_array.push_back(0);
        }
    }

    return temp_array;
}

vector<double> to_function(vector<double> array) {
    vector<double> temp_array;
    double sum = 0;
    for (int index = 0; index < array.size(); index++) {
        double delta = array[index] + sum;
        temp_array.push_back(delta);
        sum = delta;
    }
    return temp_array;
}