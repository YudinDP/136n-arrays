#pragma once
//author Yudin D.
namespace arrays {

	void print_array(std::vector<double> a, unsigned n);
		

	///������� ���-�� �����/��������� ������� a � �����
	int File_str_count(const std::string& Fname);

	///������ ����� ������� a, ��� �� ����� ��� try catch
	int ReadArrLength();

	///������ ��� ����� ��� input/ouput ������� � ����, ��� try-catch ��� ��
	std::string ReadFileName();

	///��������� ������ a �������� n ���������� �������
	void mass_fill(std::vector<double>& a, unsigned n);

	///���������� ����� ��������� ������� a �������� n
	double mass_sum(std::vector<double> a, unsigned n);

	///������� ������ a  �������� n � ��������� ���� Fname
	void file_output(std::vector<double> a, unsigned n, const std::string& Fname);

	///��������� ������ a �������� n �� ���������� ����� Fname, � ������� �� ��� ����� �������
	void file_input(std::vector<double> a, unsigned n, const std::string& Fname);
}