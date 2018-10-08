#include "../headers/pearsons_check.h"
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

vector<vector<double>> chunkArray(vector<double> array) {
    int counter = begin_value;
    vector<vector<double>> tempArray;
    double range = (target_value - begin_value) / groups_count;
    while (counter < target_value) {
        tempArray.push_back();
        counter += range;
    }
    return tempArray;
}

vector<double> approximateArray(vector<vector<double>> array) {
    vector<double> tempArray;
    for (int index = 0; index < array.size(); index++) {

        // histogram
        double delta = array[index].size() / result_array.size();
        tempArray.push_back(delta);

        // average
        int tempLength = array[index].length;
        if (array[index][tempLength - 1] != undefined && array[index][0] != undefined) {
            average.push((array[index][tempLength - 1] + array[index][0]) / 2);
        } else {
            average.push(0);
        }

        data_t.push(index);
    }
    return tempArray;
}

double countConformityPearson(vector<double> array, vector<double> theory, int n) {
    double sum = 0;
    for (int index = 0; index < array.size(); index++) {
        sum += pow(array[index] - theory[index], 2) / theory[index];
    }
    return n * sum;
}

double pearsons_check(vector<double> emp, vector<double> the, int n, int groups, double min, double max) {
    
    sort(emp.begin(), emp.end());
    sort(the.begin(), the.end());

    vector<vector<double>> groups = chunkArray(the, groups, min, max);
    vector<double> histogram = approximateArray(groups, the);

    vector<vector<double>> groups_2 = chunkArray(emp, groups, min, max);
    vector<double> histogram_2 = approximateArray(groups_2, emp);

    return countConformityPearson(histogram, histogram_2, n);
}

    