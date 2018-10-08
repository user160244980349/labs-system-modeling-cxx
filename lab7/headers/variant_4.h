#include "pearsons_check.h"

#include <vector>

int l = 2;
int n = 3;
double p_theoretical = static_cast<double>(l) / (l + n);

double p_emperical(int served, int declined) {
    return static_cast<double>(declined) / (served + declined);
}

double check(std::vector<double> emp, std::vector<double> the, int n, int groups, double min, double max) {
    return pearsons_check(emp, the, n, groups, min, max);
}

std::string check_message = "Критерий Пирсона";