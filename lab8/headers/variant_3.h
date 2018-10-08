

#include <string>
#include "kolmogorovs_check.h"

int l = 15;
int n = 20;
double p_theoretical = 1 - pow(static_cast<double>(l) / n, 4) / (1 +
    static_cast<double>(l) / n +
    pow(static_cast<double>(l) / n, 2) +
    pow(static_cast<double>(l) / n, 3) +
    pow(static_cast<double>(l) / n, 4));

double p_emperical(int served, int declined) {
    return static_cast<double>(served) / (served + declined);
}

double check(std::vector<double> emp, std::vector<double> the, int n, int groups, double min, double max) {
    return kolmogorovs_check(emp, the, n, groups, min, max);
}

std::string check_message = "Критерий Колмогорова";