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
		cout << "Содержимое файла:" << info << endl;
	}
	file.close();
}
int main() {
	SetConsoleCP(1251);//для вывода строки, которую мы сначала ввели на русском языке
	SetConsoleOutputCP(1251);//для вывода строки, которую мы сначала ввели русского языка
	setlocale(LC_ALL, "rus");//для вывода русского языка
	string file_text;
	string dop_info;
	string name;
	cout << "Введите название файла:" << endl;
	getline(cin, name);
	FilesWork file(name);
	short vibor;
	do {
		cout << "Выберите действие с файлом:"
			<<endl<< "0. Завершение работы с файлом"
			<<endl<< "1. Запись в файл"
			<<endl<< "2. Чтение файла"
			<<endl<< "3. Добавление информации в файл"<<endl;
		cin >> vibor;
		cin.ignore();
		if (vibor == 1) {
			cout << "Введите текст, который будет записан в файл:"<<endl;
			getline(cin, file_text);
			file.write_file(file_text);
		}
		else if (vibor == 2) {
			file.read_file();
		}
		else if (vibor == 3) {
			cout << "Введите дополнительную информацию, которая будет записана в файл:"<<endl;
			getline(cin, dop_info);
			file += dop_info;
		}
	} while (vibor != 0);
	cout << "Спасибо, что воспользовались нашей программой :)";

}