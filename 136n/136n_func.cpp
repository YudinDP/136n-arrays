#include <iostream> //ввод-вывод
#include <time.h>//для рандом чисел
#include <stdlib.h>// определяет функции srand,rand
#include <fstream>  //ввод-вывод в файл
#include <cmath>  //математика
#include <string>  //для использования строк
#include <typeinfo> //библиотека с типами данных для проверки длины массива try-catch
#include <vector>
#include <stdexcept>  //исключения exception
using namespace std;

namespace arrays {

	void print_array(std::vector<double>& a) {
		for (unsigned i = 0; i < a.size(); i++) {
			cout << "[" << a[i] << "],  ";
		}
	}


	//ввод размера массива a(по большей части для try-catch)
	int ReadArrLength() {
		int len;
		cin >> len;
		if ((len <= 0)) {
			throw std::length_error("(len <= 0) || (len >= 32769)");
		}
		else {
			return len;
		}
	}
	//ввод имени файла для вывода массива(по большей части для try-catch)
	std::string ReadFileName() {
		std::string FileName;
		char rep[]{ '*', '/', ':', '?', '"', '<', '>', '|' };
		cin >> FileName;
		for (int i = 0; i < 8; i++) {
			if (FileName.find(rep[i]) != FileName.npos) {
				throw std::invalid_argument("Некорректное имя файла");
			}
			FileName = FileName + ".txt";
			return FileName;
		}
	}


	///заполняет массив a размером n рандомными числами
	void mass_fill(std::vector<double>& a) {


		for (unsigned i = 0; i < a.size(); i++) {
			a[i] = (1.0 * rand() / RAND_MAX * 200 - 100); //((rand() % 100) + rand()%100/100.0);
			//author Yudin D. 
		};
	}


	///сумма элементов массива a
	double mass_sum(std::vector<double>& a) {
		double Msum = 0.0;
		for (unsigned i = 0; i < a.size(); i++) {
			Msum = Msum + a[i];
		}
		return Msum;
	}


	///выводит массив a в текстовый файл
	void file_output(std::vector<double>& a, const std::string& Fname) {
		std::ofstream out; //определение потока вывода в файл
		out.open(Fname);  //открытие файла
		if (out.is_open()) {   //проверка открытия файла
			for (unsigned i = 0; i < a.size(); i++) {
				out << a[i] << endl;  //сам вывод
			}
		}
		out.close();  //закрываем файл ввода
	}


	///считает кол-во строк/элементов массива в файле
	int File_str_count(const std::string& Fname) {
		int count = 0;
		std::string s;
		std::ifstream f(Fname, ios::in);
		if (f.is_open()) {
			while (!f.eof()) {
				count++;//пока файл не закончился читаем строки и увеличиваем счетчик
				getline(f, s);
			}
		}
		return count;
	}


	///заполняет вектор a размером n из текстового файла, в который он был ранее записан
	void file_input(std::vector<double> a, const std::string& Fname) {
		std::ifstream in(Fname);
		if (in.is_open()) {
			for (unsigned i = 0; i < (File_str_count(Fname) - 1); i++) {
				in >> a[i];
			}
		}
		in.close();
	}

	//запись в файл в двоичном режиме
	void file_output_binary(std::vector<double>& a, const std::string& Fname) {
		std::ofstream out(Fname, ios::binary | ios::out);//открываем файлик в двоичном режиме для записи
		if (out.is_open()) {   //проверка открытия файла
			for (unsigned i = 0; i < a.size(); i++) {
				out << a[i] << endl;  //сам вывод
			}
		}
		out.close();  //закрываем файл ввода
	}

	//вывод из файла в вектор в двоичном режиме
	void file_input_binary(std::vector<double> a, const std::string& Fname) {
		std::ifstream in(Fname, ios::binary | ios::in);//открываем файлик в двоичном режиме для вывода
		if (in.is_open()) {//проверка открытия
			for (unsigned i = 0; i < (File_str_count(Fname) - 1); i++) {
				in >> a[i];//заполнение в вектор
			}
		}
		in.close();//закрываем
	}
}