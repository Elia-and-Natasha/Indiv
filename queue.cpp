#include <iostream>
using namespace std;
#include "priority_queue.h"
#include <string>
#include <fstream>
#include <cassert>
#include <iomanip>

int main()
{
	setlocale(LC_ALL, "Russian");

	//Используя очередь строк решить задачу :
	//Дан файл строк.Выдать строки в порядке убывания их длин. Используя один проход по файлу.

	string line;
	int pr;
	const char* filename = "task2.txt";
	string error; // код ошибки
	assert(filename); //пустая строка недопустима
	ifstream f(filename);
	if (!f.is_open()) {
		error = "Couldn't open file";
		throw error;
	}
	priority_queue<string> strings;
	while (getline(f, line)) {
		pr = line.length();
		strings.push_back(line, pr);
	}
	strings.print();
	f.close();

	

}

