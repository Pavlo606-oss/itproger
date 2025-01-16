using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
class FilesWork {
	string name;
public:
	FilesWork(string name);
	void write_file(string info);
	void read_file();
	void operator += (string dop_info) {
		ofstream file(name, ofstream::app);
		file << dop_info;
		file.close();
	 }
};
FilesWork::FilesWork(string name) {
	this->name = name;
}
void FilesWork::write_file(string info) {
	ofstream file(name);
	file << info;
	file.close();
}
void FilesWork::read_file() {
	ifstream file(name);
	string info;
	while (getline(file, info)) {
		cout << "���������� �����:" << info << endl;
	}
	file.close();
}
int main() {
	SetConsoleCP(1251);//��� ������ ������, ������� �� ������� ����� �� ������� �����
	SetConsoleOutputCP(1251);//��� ������ ������, ������� �� ������� ����� �������� �����
	setlocale(LC_ALL, "rus");//��� ������ �������� �����
	string file_text;
	string dop_info;
	string name;
	cout << "������� �������� �����:" << endl;
	getline(cin, name);
	FilesWork file(name);
	short vibor;
	do {
		cout << "�������� �������� � ������:"
			<<endl<< "0. ���������� ������ � ������"
			<<endl<< "1. ������ � ����"
			<<endl<< "2. ������ �����"
			<<endl<< "3. ���������� ���������� � ����"<<endl;
		cin >> vibor;
		cin.ignore();
		if (vibor == 1) {
			cout << "������� �����, ������� ����� ������� � ����:"<<endl;
			getline(cin, file_text);
			file.write_file(file_text);
		}
		else if (vibor == 2) {
			file.read_file();
		}
		else if (vibor == 3) {
			cout << "������� �������������� ����������, ������� ����� �������� � ����:"<<endl;
			getline(cin, dop_info);
			file += dop_info;
		}
	} while (vibor != 0);
	cout << "�������, ��� ��������������� ����� ���������� :)";

}