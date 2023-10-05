#pragma once
//author Yudin D.
namespace arrays {

	void print_array(double* a, unsigned n);
		

	///������� ���-�� �����/��������� ������� a � �����
	int File_str_count(const std::string& Fname);

	///������ ����� ������� a, ��� �� ����� ��� try catch
	int ReadArrLength();

	///��������� ������ a �������� n ���������� �������
	void mass_fill(double* a, unsigned n);

	///���������� ����� ��������� ������� a �������� n
	double mass_sum(double* a, unsigned n);

	///������� ������ a  �������� n � ��������� ���� Fname
	void file_output(double* a, unsigned n, const std::string& Fname);

	///��������� ������ a �������� n �� ���������� ����� Fname, � ������� �� ��� ����� �������
	void file_input(double* a, unsigned n, const std::string& Fname);
}