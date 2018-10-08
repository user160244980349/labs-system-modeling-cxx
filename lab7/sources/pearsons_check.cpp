#include "../headers/pearsons_check.h"
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

chunkArray() {
    var counter     = begin_value;
    var tempArray   = [];
    var range       = (target_value - begin_value) / groups_count;
    while (counter < target_value) {
        tempArray.push(array.filter((value) => (value >= counter) && (value < counter + range)));
        counter += range;
    }
    return tempArray;
}

approximateArray() {
    var tempArray = [];
    for (var index = 0; index < array.length; index++) {

        // histogram
        var delta = array[index].length / result_array.length;
        tempArray.push(delta);

        // average
        var tempLength = array[index].length;
        if (array[index][tempLength - 1] != undefined && array[index][0] != undefined) {
            this.data.average.push((array[index][tempLength - 1] + array[index][0]) / 2);
        } else {
            this.data.average.push(0);
        }

        this.data.data_t.push(index);
    }
    return tempArray;
}

vector<double> toFunction(vector<double> array) {
    vector<double> tempArray;
    double sum = 0;
    for (int index = 0; index < array.size(); index++) {
        double delta = array[index] + sum;
        tempArray.push_back(delta);
        sum = delta;
    }
    return tempArray;
}

countExpectedValue(array) {
    var sum = 0;
    for (var index = 0; index < array.length; index++) {
        sum += array[index] * this.data.average[index];
    }
    return sum;
}

countDispersion(array, expected_value) {
    var sum = 0;
    for (var index = 0; index < array.length; index++) {
        sum += array[index] * pow(this.data.average[index] - expected_value, 2);
    }
    return sum;
}

countConformityPearson(array, theory, n) {
    var sum = 0;
    for (var index = 0; index < array.length; index++) {
        sum += pow(array[index] - theory[index], 2) / theory[index];
    }
    return n * sum;
}

double pearsons_check(vector<double> emp, vector<double> the, int n, int groups, double min, double max) {
    
    sort(emp.begin(), emp.end());
    sort(the.begin(), the.end());

    this.data.groups            = this.chunkArray(this.result_1, groups_count, min_result, max_result);
    this.data.histogram         = this.approximateArray(this.data.groups, this.result_1);
    this.data.expected_value    = this.countExpectedValue(this.data.histogram);
    this.data.dispersion        = this.countDispersion(this.data.histogram, this.data.expected_value);

    this.data.data_t    = [];
    this.data.average   = [];

    this.data.groups_2          = this.chunkArray(this.result_2, groups_count, min_result, max_result);
    this.data.histogram_2       = this.approximateArray(this.data.groups_2, this.result_2);
    this.data.expected_value_2  = this.countExpectedValue(this.data.histogram_2);
    this.data.dispersion_2      = this.countDispersion(this.data.histogram_2, this.data.expected_value_2);

    if (this.mode == 1) {
        this.data.pearson_conformity = this.countConformityPearson(this.data.histogram, this.data.histogram_2, n);
        console.log('Критерий согласия Пирсона: '.concat(this.data.pearson_conformity));

    } else if (this.mode == 2) {
        this.data.function      = this.toFunction(this.data.histogram);
        this.data.function_2    = this.toFunction(this.data.histogram_2);
        this.data.kolmogorov_conformity = this.countConformityKolmogorov(this.data.function, this.data.function_2, n);

        console.log('Критерий согласия Колмогорова:'.concat(this.data.kolmogorov_conformity));
    } else if (this.mode == 3) {
        this.data.function      = this.toFunction(this.data.histogram);
        this.data.function_2    = this.toFunction(this.data.histogram_2);
        this.data.kolmogorov_smirnov_conformity = this.countConformityKolmogorovSmirnov(this.data.function, this.data.function_2, n);

        console.log('Критерий согласия Колмогорова-Смирнова:'.concat(this.data.kolmogorov_smirnov_conformity));
    }

    console.log('(1) Мат. ожидание: '.concat(this.data.expected_value)  .concat(', дисперсия: ').concat(this.data.dispersion));
    console.log('(2) Мат. ожидание: '.concat(this.data.expected_value_2).concat(', дисперсия: ').concat(this.data.dispersion_2));

    return 0;
}

    