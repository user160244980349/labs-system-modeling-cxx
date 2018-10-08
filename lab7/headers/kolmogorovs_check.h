#ifndef MODSYS_KOLMOGOROVSCHECK_H
#define MODSYS_KOLMOGOROVSCHECK_H

#include <vector>

double kolmogorovs_check(std::vector<double> emp, std::vector<double> the, int n, int groups, double min, double max);

#endif // MODSYS_KOLMOGOROVSCHECK_H