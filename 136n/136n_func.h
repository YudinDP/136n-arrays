#pragma once
//author Yudin D.
namespace arrays {

	///выводит вектор на экран
	void print_array(std::vector<double> a);
		

	///считает кол-во строк/элементов вектор a в файле
	int File_str_count(const std::string& Fname);

	///вводит длину вектор a, так же нужна для try catch
	int ReadArrLength();

	///вводит имя файла для input/ouput вектор в него, для try-catch так же
	std::string ReadFileName();

	///заполняет вектор a размером n случайными числами
	void mass_fill(std::vector<double>& a);

	///возвращает сумму элементов вектор a размером n
	double mass_sum(std::vector<double> a);

	///выводит вектор a  размером n в текстовый файл Fname
	void file_output(std::vector<double> a, const std::string& Fname);

	///заполняет вектор a размером n из текстового файла Fname, в который он был ранее записан
	void file_input(std::vector<double> a, const std::string& Fname);
	
	//запись в файл в двоичном режиме 
	void file_output_binary(std::vector<double> a, const std::string& Fname);

	//вывод из файла в вектор в двоичном режиме
	void file_input_binary(std::vector<double> a, const std::string& Fname);

}