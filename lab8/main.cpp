#include <iostream>
#include <math.h>

#include "headers/variant_3.h"
// #include "headers/variant_4.h"
#include "headers/system_modeling.h"
#include "headers/normal_distribution.h"

using std::cout;
using std::endl;

int main() {

	extern int l;
	extern int n;
	extern double p_theoretical;
	int t 			= 100;
	int served 		= 0;
	int declined 	= 0;

	system_modeling(&served, &declined, l, n, t);

	double p = p_a(served, declined);
	double delta = abs(p - p_theoretical);
	double sigma = sqrt(p * (1 - p) / (served + declined));
	double alpha = delta / sigma;
	// double p_r = 2 * normal_distribution(alpha);
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

	while (a_e > 0.01) {

		cout << " Абслоютная погрешность:\t\t\t\t" << a_e << " > 0.01" << endl;
		cout << " Требуется дополнительная серия опытов" << endl;

		system_modeling(&served, &declined, l, n, t);

		p = static_cast<double>(declined) / (served + declined);
		p_theoretical = pow(static_cast<double>(l) / n, 4) / (1 +
			static_cast<double>(l) / n +
			pow(static_cast<double>(l) / n, 2) +
			pow(static_cast<double>(l) / n, 3) +
			pow(static_cast<double>(l) / n, 4));
		delta = abs(p - p_theoretical);
		sigma = sqrt(p * (1 - p) / (served + declined));
		alpha = delta / sigma;
		// p_r = 2 * normal_distribution(alpha);
		// e = alpha * sigma;
		e = 3 * sigma;
		a_e = abs(p - p_theoretical);

		cout << endl << " После еще 100 секунд моделирования" << endl;
		cout << "------------------------------------------------------------------------------" << endl;
		cout << " Обслужено:\t" << served << endl;
		cout << " Отклонено:\t" << declined << endl;
		cout << " Экспериментальная оценка вероятности события А:\t" << p << endl;
		cout << " Теоретическая оценка вероятности события А:\t\t" << p_theoretical << endl;
		cout << " Точность экспериментальной оценки:\t\t\t" << 1 - e << endl;

	}

	cout << " Абслоютная погрешность:\t\t\t\t" << a_e << " < 0.01" << endl;
	cout << " Дополнительная серия опытов не требуется" << endl << endl;

}
