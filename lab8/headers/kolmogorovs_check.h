#ifndef MODSYS_KOLMOGOROVSCHECK_H
#define MODSYS_KOLMOGOROVSCHECK_H

#include <vector>

double count_conformity_kolmogorov(std::vector<double> array, std::vector<double> theory);
double kolmogorovs_check(std::vector<double> emp, std::vector<double> the, int groups);

#endif // MODSYS_KOLMOGOROVSCHECK_H