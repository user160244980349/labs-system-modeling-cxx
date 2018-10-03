
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
