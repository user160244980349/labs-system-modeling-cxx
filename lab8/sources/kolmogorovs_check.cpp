#include "../headers/kolmogorovs_check.h"
#include "../headers/helpers.h"
#include <vector>
#include <math.h>
#include <algorithm>

using std::vector;
using std::sort;
using std::min_element;
using std::max_element;

double count_conformity_kolmogorov(vector<double> array, vector<double> theory) {

    double temp = 0;
    double max = 0;

    for (int index = 0; index < array.size(); index++) {
        if (array[index] >= theory[index]) {
            temp = abs(array[index] - theory[index]);
        } else {
            if (index > 0) {
                temp = abs(array[index - 1] - theory[index]);
            }
        }
        if (temp > max) {
            max = temp;
        }
    }
    return max * sqrt(array.size() > theory.size() ? theory.size() : array.size());
}

double kolmogorovs_check(vector<double> emp, vector<double> the, int groups) {
   
	double min_emp = *(min_element(emp.begin(), emp.end()));
	double max_emp = *(max_element(emp.begin(), emp.end()));
	double min_the = *(min_element(the.begin(), the.end()));
	double max_the = *(max_element(the.begin(), the.end()));

    sort(emp.begin(), emp.end());
    sort(the.begin(), the.end());

    vector<double> histogram_emp = approximate_array(chunk_array(emp, groups, min_emp, max_emp));
    vector<double> histogram_the = approximate_array(chunk_array(the, groups, min_emp, max_emp));

    return count_conformity_kolmogorov(to_function(histogram_emp), to_function(histogram_the));
}