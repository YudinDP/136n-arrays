#pragma once
//author Yudin D.
namespace arrays {

	void print_array(std::vector<double> a, unsigned n);
		

	///считает кол-во строк/элементов массива a в файле
	int File_str_count(const std::string& Fname);

	///вводит длину массива a, так же нужна для try catch
	int ReadArrLength();

	///вводит имя файла для input/ouput массива в него, для try-catch так же
	std::string ReadFileName();

	///заполняет массив a размером n случайными числами
	void mass_fill(std::vector<double>& a, unsigned n);

	///возвращает сумму элементов массива a размером n
	double mass_sum(std::vector<double> a, unsigned n);

	///выводит массив a  размером n в текстовый файл Fname
	void file_output(std::vector<double> a, unsigned n, const std::string& Fname);

	///заполняет массив a размером n из текстового файла Fname, в который он был ранее записан
	void file_input(std::vector<double> a, unsigned n, const std::string& Fname);
}