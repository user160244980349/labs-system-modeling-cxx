#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>


#include "headers/variant_3.h"
// #include "headers/variant_4.h"
#include "headers/system_modeling.h"

using std::vector;
using std::string;

using std::min_element;
using std::max_element;

using std::cout;
using std::endl;

using std::mt19937;
using std::uniform_real_distribution;

int main() {

	extern int l;
	extern int n;
	extern double p_theoretical;

	vector<double> in;
	vector<double> out;
	
	int t 			= 100;
	int served 		= 0;
	int declined 	= 0;

	system_modeling(served, declined, l, n, t, in, out);

	double p = p_emperical(served, declined);
	double delta = abs(p - p_theoretical);
	double sigma = sqrt(p * (1 - p) / (served + declined));
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
	vector<double> emp;
	extern string check_message;

    mt19937 generator(time(0));
    uniform_real_distribution<> random(0, 1);

	int n_selection = in.size() > out.size() ? out.size() : in.size();
	// int n_selection = 50;

	for (int i = 0; i < n_selection; i++) {
		the.push_back(-(static_cast <double>(1) / l * log(1 - random(generator))));
		emp.push_back(in[i]);
	}
	cout << " " << check_message << endl << " Интенсивность: " << check(emp, the, 20);

	the.clear();
	emp.clear();
	for (int i = 0; i < n_selection; i++) {
		the.push_back(-(static_cast <double>(1) / n * log(1 - random(generator))));
		emp.push_back(out[i]);
	}
	cout << endl << " Производительность: " << check(emp, the, 20) << endl << endl;

}
