#pragma once
//author Yudin D.
namespace arrays {

	///������� ������ �� �����
	void print_array(std::vector<double>& a);


	///������� ���-�� �����/��������� ������ a � �����
	int File_str_count(const std::string& Fname);

	///������ ����� ������ a, ��� �� ����� ��� try catch
	int ReadArrLength();

	///������ ��� ����� ��� input/ouput ������ � ����, ��� try-catch ��� ��
	std::string ReadFileName();

	///��������� ������ a �������� n ���������� �������
	void mass_fill(std::vector<double>& a);

	///���������� ����� ��������� ������ a �������� n
	double mass_sum(std::vector<double>& a);

	///������� ������ a  �������� n � ��������� ���� Fname
	void file_output(std::vector<double>& a, const std::string& Fname);

	///��������� ������ a �������� n �� ���������� ����� Fname, � ������� �� ��� ����� �������
	void file_input(std::vector<double> a, const std::string& Fname);

	//������ � ���� � �������� ������ 
	void file_output_binary(std::vector<double>& a, const std::string& Fname);

	//����� �� ����� � ������ � �������� ������
	void file_input_binary(std::vector<double> a, const std::string& Fname);

}