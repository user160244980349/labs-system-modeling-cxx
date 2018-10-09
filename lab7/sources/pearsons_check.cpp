#include "../headers/pearsons_check.h"
#include "../headers/helpers.h"
#include <vector>
#include <math.h>
#include <algorithm>

using std::vector;
using std::sort;
using std::min_element;
using std::max_element;

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

    return count_conformity_pearson(histogram_emp, histogram_the);
}

    