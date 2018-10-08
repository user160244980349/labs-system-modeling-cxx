#include "kolmogorovs_check.h"

#include <vector>

int l = 15;
int n = 20;
double p_theoretical = static_cast<double>(n) / (l + n);

double p_emperical(int served, int declined) {
    return static_cast<double>(served) / (served + declined);
}

double check(std::vector<double> emp, std::vector<double> the, int n, int groups, double min, double max) {
    return kolmogorovs_check(emp, the, n, groups, min, max);
}

std::string check_message = "Критерий Колмогорова";