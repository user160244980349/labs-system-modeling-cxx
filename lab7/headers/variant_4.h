
int l = 2;
int n = 3;
double p_theoretical = static_cast<double>(l) / (l + n);

double p_emperical(int served, int declined) {
    return static_cast<double>(declined) / (served + declined);
}
