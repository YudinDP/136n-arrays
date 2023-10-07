//задача 136н https://ivtipm.github.io/Programming/Glava06/index06.htm#z136
#include <iostream> //ввод-вывод
#include <fstream>  //ввод-вывод в файл
#include <cmath>  //для мат.функций
#include <string>  //для использования строк
#include <cassert> //для assert-а
#include <iomanip>  //для ограничения знаков precision после запятой
#include <stdexcept>  //для обработки исключений
#include <stdlib.h>  //для использования abort(в связи непониманием неработы try catch)
#include "136n_func.h"  //модуль
using namespace std;  //стандартное пространоство имен, cout, cin

//свое пространство имен с функцией вывода массива a размером n


//основная функция программы
int main() {
	srand(time(NULL));


	///полный assert
	{	unsigned n = 7;
		double* b = new double[n] {345,35,34,53,53,453,3};
		arrays::mass_fill(b, 7);   //супер-проверка работоспособности заполнения массива
		assert(b[n - 1] > -101 && b[n - 1] < 101);
		assert(arrays::mass_sum(b, n) > -100.0 * n);//проверка функции суммы массива
		double a0 = b[0], an = b[n - 1];
		arrays::file_output(b, n, "test.txt");
		arrays::file_input(b, n, "test.txt");
		assert((b[0] - a0 < 0.01) && (b[n - 1] - an < 0.01));
	}

	//author Yudin D.
	cout.precision(2);
	setlocale(LC_ALL, "Russian");  //русская локализация
	unsigned n;//кол-во элементов массива
	std::string Fname;

	cout << "кол-во элементов массива?" << endl;
	try {
		n = arrays::ReadArrLength();//может сгенерировать исключение
	}
	catch (const std::length_error err) {   //ловим исключение
		cout << err.what() << endl; //выводим сообщение о ошибке
	}

	cout << "Введите имя файла:" << endl;
	try {
		Fname = arrays::ReadFileName();//может сгенерировать исключение
	}
		catch (const std::invalid_argument inval) {//ловим исключение
			cout << inval.what() << endl;
			abort();///////////////аборт для завершения программы
		}
	



	double* a = new double[n], sum = 0.0, element;



	arrays::mass_fill(a, n);  //заполнение массива
	arrays::file_output(a, n, Fname);  //вывод в файл
	arrays::file_input(a, n, Fname);  //заполнение массива из файла


	//сумма по формуле
	for (int i = 0; i < n; i++) {
		sum = (sum + (pow(sqrt(fabs(a[i])) - a[i], 2)));
	};

	//вывод элементов массива и элементов суммы по формуле
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]" << setfill(' ') << setw(8) << fixed << a[i] << setfill(' ') << setw(12) << fixed << (pow(sqrt(fabs(a[i])) - a[i], 2)) << endl;
	};

	cout << "Элементы массива";
	arrays::print_array(a, n);//функция своего пространства имен

	cout << endl << "Сумма по формуле = " << sum; //вывод по формуле
	cout << endl << "Сумма элементов массива = " << arrays::mass_sum(a, n) << endl << endl; //вывод суммы массива

}