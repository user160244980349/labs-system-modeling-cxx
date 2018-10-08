#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>

#include "headers/variant_4.h"
#include "headers/system_modeling.h"
#include "headers/normal_distribution.h"

using std::vector;
using std::string;

using std::min_element;
using std::max_element;

using std::cout;
using std::endl;

int main() {

	extern int l;
	extern int n;
	extern double p_theoretical;

	vector<double> in;
	vector<double> out;
	
	int t 			= 100;
	int served 		= 0;
	int declined 	= 0;

	// system_modeling(served, declined, l, n, t);
	system_modeling(served, declined, l, n, t, in, out);

	double p = p_emperical(served, declined);
	double delta = abs(p - p_theoretical);
	double sigma = sqrt(p * (1 - p) / (served + declined));
	double alpha = delta / sigma;
	// double p_r = normal_distribution(alpha);
	// double e = alpha * sigma;
	double e = 3 * sigma;
	double a_e = abs(p - p_theoretical);

	cout << endl << " После 100 секунд моделирования" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << " Обслужено:\t\t\t\t\t\t" << served << endl;
	cout << " Отклонено:\t\t\t\t\t\t" << declined << endl;
	cout << " Экспериментальная оценка вероятности события А:\t" << p << endl;
	cout << " Теоретическая оценка вероятности события А:\t\t" << p_theoretical << endl;
	cout << " Точность экспериментальной оценки:\t\t\t" << 1 - e << endl;
	cout << " Абслоютная погрешность:\t\t\t\t" << a_e << " < 0.01" << endl;
	cout << " Дополнительная серия опытов не требуется" << endl << endl;

	vector<double> the;
	extern string check_message;
	std::vector<double>::iterator min = min_element(in.begin(), in.end());
	std::vector<double>::iterator max = max_element(in.begin(), in.end());
	cout << check_message << endl << "Интенсивность: " << check(in, the, in.size(), 20, *min, *max);

	min = min_element(out.begin(), out.end());
	max = max_element(out.begin(), out.end());
	cout << endl << "Производительность: " << check(out, the, out.size(), 20, *min, *max) << endl;
}
