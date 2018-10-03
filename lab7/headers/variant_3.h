
int l = 15;
int n = 20;
double p_theoretical = static_cast<double>(n) / (l + n);

double p_emperical(int served, int declined) {
    return static_cast<double>(served) / (served + declined);
}
