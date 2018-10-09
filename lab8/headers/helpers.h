#ifndef MODSYS_HELPERS_H
#define MODSYS_HELPERS_H

#include <vector>

std::vector<std::vector<double>> chunk_array(std::vector<double> array, int groups, double min, double max);
std::vector<double> approximate_array(std::vector<std::vector<double>> array);
std::vector<double> to_function(std::vector<double> array);

#endif // MODSYS_HELPERS_H