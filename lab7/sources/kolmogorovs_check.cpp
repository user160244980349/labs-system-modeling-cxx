#include "../headers/kolmogorovs_check.h"
#include <vector>

using std::vector;

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

toFunction(array) {
    var tempArray = [];
    var sum = 0.0;
    for (var index = 0; index < array.length; index++) {
        var delta = array[index] + sum;
        tempArray.push(delta);
        sum = delta;
    }
    return tempArray;
}

countConformityKolmogorov(array, theory, n) {
    var temp = 0;
    var max = 0;
    for (var index = 0; index < array.length; index++) {
        if (array[index] >= theory[index]) { // F* is higher
            temp = Math.abs(array[index] - theory[index]);
        } else {
            if (index > 0) {
                temp = Math.abs(array[index - 1] - theory[index]);
            }
        }
        if (temp > max) {
            max = temp;
        }
    }
    return max * Math.sqrt(n);
}

double kolmogorovs_check(vector<double> emp, vector<double> the, int n, int groups, double min, double max) {
   
    this.result_1.sort();
    this.result_2.sort();

    this.data.groups            = this.chunkArray(this.result_1, groups_count, min_result, max_result);
    this.data.histogram         = this.approximateArray(this.data.groups, this.result_1);

    this.data.groups_2          = this.chunkArray(this.result_2, groups_count, min_result, max_result);
    this.data.histogram_2       = this.approximateArray(this.data.groups_2, this.result_2);

    this.data.function      = this.toFunction(this.data.histogram);
    this.data.function_2    = this.toFunction(this.data.histogram_2);
    this.data.kolmogorov_conformity = this.countConformityKolmogorov(this.data.function, this.data.function_2, n);

    return 0;
}