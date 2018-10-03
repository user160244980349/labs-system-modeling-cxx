
int l = 2;
int n = 3;
double p_theoretical = pow(static_cast<double>(l) / n, 4) / (1 +
    static_cast<double>(l) / n +
    pow(static_cast<double>(l) / n, 2) +
    pow(static_cast<double>(l) / n, 3) +
    pow(static_cast<double>(l) / n, 4));

double p_emperical(int served, int declined) {
    return static_cast<double>(declined) / (served + declined);
}
