#ifndef MODSYS_PEARSONSCHECK_H
#define MODSYS_PEARSONSCHECK_H

#include <vector>

double count_conformity_pearson(std::vector<double> array, std::vector<double> theory);
double pearsons_check(std::vector<double> emp, std::vector<double> the, int groups);

#endif // MODSYS_PEARSONSCHECK_H