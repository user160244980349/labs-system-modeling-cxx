#ifndef MODSYS_SYSTEMMODELING_H
#define MODSYS_SYSTEMMODELING_H

#include <vector>

void system_modeling(int& served, int& declined, int lambda, int nu, int t, std::vector<double>& comes, std::vector<double>& leaves);
void system_modeling(int* served, int* declined, int lambda, int nu, int time);

#endif // MODSYS_SYSTEMMODELING_H
