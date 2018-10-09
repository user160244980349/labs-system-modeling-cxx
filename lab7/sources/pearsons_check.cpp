#include "../headers/pearsons_check.h"
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>

using std::vector;
using std::sort;
using std::cout;
using std::endl;

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

double count_conformity_pearson(vector<double> array, vector<double> theory) {
    double sum = 0;
    int index = 0;
    for (;index < array.size() && index < theory.size(); index++) {
        if (theory[index] == 0) { 
            continue; 
        }
        sum += pow(array[index] - theory[index], 2) / theory[index];
    }

    return index * sum;
}

double pearsons_check(vector<double> emp, vector<double> the, int groups) {

	double min_emp = *(min_element(emp.begin(), emp.end()));
	double max_emp = *(max_element(emp.begin(), emp.end()));
	double min_the = *(min_element(the.begin(), the.end()));
	double max_the = *(max_element(the.begin(), the.end()));

    sort(emp.begin(), emp.end());
    sort(the.begin(), the.end());

    vector<double> histogram_emp = approximate_array(chunk_array(emp, groups, min_emp, max_emp));
    vector<double> histogram_the = approximate_array(chunk_array(the, groups, min_the, max_the));

    return count_conformity_pearson(histogram_the, histogram_emp);
}

    