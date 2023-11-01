//задача 136н https://ivtipm.github.io/Programming/Glava06/index06.htm#z136
#include <iostream> //ввод-вывод
#include <fstream>  //ввод-вывод в файл
#include <cmath>  //для мат.функций
#include <string>  //для использования строк
#include <cassert> //для assert-а
#include <iomanip>  //для ограничения знаков precision после запятой
#include <stdexcept>  //для обработки исключений
#include <stdlib.h>  //для использования abort(в связи непониманием неработы try catch)
#include <vector>
#include "136n_func.h";  //модуль
using namespace std;  //стандартное пространоство имен, cout, cin

//свое пространство имен с функцией вывода массива a размером n


//основная функция программы
int main(int argc, char* argv[]) {
	srand(time(NULL));


///блок полный assert
	{	unsigned n = 6;
	std::vector<double> b(n);//{345,35,34,53,53,453,3};
		arrays::mass_fill(b);   //супер-проверка работоспособности заполнения массива
		assert(b[n - 1] > -101 && b[n - 1] < 101);
		//arrays::print_array(b, n);
		assert(arrays::mass_sum(b) > -100.0 * n);//проверка функции суммы массива
		
		//проверка обычных файлов
		double a0 = b[0], an = b[n - 1];
		arrays::file_output(b, "test.txt");
		arrays::file_input(b, "test.txt");
		assert((b[0] - a0 < 0.01) && (b[n - 1] - an < 0.01));

		//проверка файлов в бинарном режиме
		a0 = b[0]; an = b[n - 1];
		arrays::file_output_binary(b, "test_binary.txt");
		arrays::file_input_binary(b, "test_binary.txt");
		assert((b[0] - a0 < 0.01) && (b[n - 1] - an < 0.01));
	}

	//author Yudin D.
	cout.precision(2);
	setlocale(LC_ALL, "Russian");  //русская локализация
	unsigned n;//кол-во элементов массива
	std::string Fname;
	//cmd args
if (argc == 3) {
		n = stoi(argv[1]);//через cmd arg вводим кол-во элементов вектора и имя файла
		Fname = argv[2];
}
else {
	///блок try-catch
	cout << "Number of array elements" << endl;
	try {
		n = arrays::ReadArrLength();//может сгенерировать исключение
	}
	catch (const std::length_error err) {   //ловим исключение
		cout << err.what() << endl; //выводим сообщение о ошибке
	}

	cout << "Input filename:" << endl;
	try {
		Fname = arrays::ReadFileName();//может сгенерировать исключение
	}
	catch (const std::invalid_argument inval) {//ловим исключение
		cout << inval.what() << endl;
		//abort();///////////////аборт для завершения программы
	}
}

		std::vector<double> a(n);
		double sum = 0.0;
	arrays::mass_fill(a);  //заполнение массива


///блок с файлами
	//arrays::file_output(a, Fname);  //вывод в файл
	//arrays::file_input(a, Fname);  //заполнение массива из файла
	arrays::file_output_binary(a, Fname); //вывод в файл в бинарном режиме
	arrays::file_input_binary(a, Fname); //заполнение массива из файла в бинарном режиме

	//сумма по формуле
	for (int i = 0; i < n; i++) {
		sum = (sum + (pow(sqrt(fabs(a[i])) - a[i], 2)));
	};
///блок вывода ответов
	//вывод элементов массива и элементов суммы по формуле
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]" << setfill(' ') << setw(8) << fixed << a[i] << setfill(' ') << setw(12) << fixed << (pow(sqrt(fabs(a[i])) - a[i], 2)) << endl;
	};

	cout << "Elements of array";
	arrays::print_array(a);//функция своего пространства имен
	cout << endl;
	cout << endl << "Sum according to formula = " << sum; //вывод по формуле
	cout << endl;
	cout << endl << "Sum of array elements = " << arrays::mass_sum(a) << endl << endl; //вывод суммы массива
	
	//пример работы с template-функцией
	std::vector<int> test;
	for (int i = 0; i < 5; i++) {
		test.push_back(1);
		test[i] = i;
	}
	arrays::print_array(test);
}