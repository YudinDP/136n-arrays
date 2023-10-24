#include <iostream> //����-�����
#include <time.h>//��� ������ �����
#include <stdlib.h>// ���������� ������� srand,rand
#include <fstream>  //����-����� � ����
#include <cmath>  //����������
#include <string>  //��� ������������� �����
#include <typeinfo> //���������� � ������ ������ ��� �������� ����� ������� try-catch
#include <vector>
#include <stdexcept>  //���������� exception
using namespace std;

namespace arrays {

	void print_array(std::vector<double>& a) {
		for (unsigned i = 0; i < a.size(); i++) {
			cout << "[" << a[i] << "],  ";
		}
	}


	//���� ������� ������� a(�� ������� ����� ��� try-catch)
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
	//���� ����� ����� ��� ������ �������(�� ������� ����� ��� try-catch)
	std::string ReadFileName() {
		std::string FileName;
		char rep[]{ '*', '/', ':', '?', '"', '<', '>', '|' };
		cin >> FileName;
		for (int i = 0; i < 8; i++) {
			if (FileName.find(rep[i]) != FileName.npos) {
				throw std::invalid_argument("������������ ��� �����");
			}
			FileName = FileName + ".txt";
			return FileName;
		}
	}


	///��������� ������ a �������� n ���������� �������
	void mass_fill(std::vector<double>& a) {


		for (unsigned i = 0; i < a.size(); i++) {
			a[i] = (1.0 * rand() / RAND_MAX * 200 - 100); //((rand() % 100) + rand()%100/100.0);
			//author Yudin D. 
		};
	}


	///����� ��������� ������� a
	double mass_sum(std::vector<double>& a) {
		double Msum = 0.0;
		for (unsigned i = 0; i < a.size(); i++) {
			Msum = Msum + a[i];
		}
		return Msum;
	}


	///������� ������ a � ��������� ����
	void file_output(std::vector<double>& a, const std::string& Fname) {
		std::ofstream out; //����������� ������ ������ � ����
		out.open(Fname);  //�������� �����
		if (out.is_open()) {   //�������� �������� �����
			for (unsigned i = 0; i < a.size(); i++) {
				out << a[i] << endl;  //��� �����
			}
		}
		out.close();  //��������� ���� �����
	}


	///������� ���-�� �����/��������� ������� � �����
	int File_str_count(const std::string& Fname) {
		int count = 0;
		std::string s;
		std::ifstream f(Fname, ios::in);
		if (f.is_open()) {
			while (!f.eof()) {
				count++;//���� ���� �� ���������� ������ ������ � ����������� �������
				getline(f, s);
			}
		}
		return count;
	}


	///��������� ������ a �������� n �� ���������� �����, � ������� �� ��� ����� �������
	void file_input(std::vector<double> a, const std::string& Fname) {
		std::ifstream in(Fname);
		if (in.is_open()) {
			for (unsigned i = 0; i < (File_str_count(Fname) - 1); i++) {
				in >> a[i];
			}
		}
		in.close();
	}

	//������ � ���� � �������� ������
	void file_output_binary(std::vector<double>& a, const std::string& Fname) {
		std::ofstream out(Fname, ios::binary | ios::out);//��������� ������ � �������� ������ ��� ������
		if (out.is_open()) {   //�������� �������� �����
			for (unsigned i = 0; i < a.size(); i++) {
				out << a[i] << endl;  //��� �����
			}
		}
		out.close();  //��������� ���� �����
	}

	//����� �� ����� � ������ � �������� ������
	void file_input_binary(std::vector<double> a, const std::string& Fname) {
		std::ifstream in(Fname, ios::binary | ios::in);//��������� ������ � �������� ������ ��� ������
		if (in.is_open()) {//�������� ��������
			for (unsigned i = 0; i < (File_str_count(Fname) - 1); i++) {
				in >> a[i];//���������� � ������
			}
		}
		in.close();//���������
	}
}