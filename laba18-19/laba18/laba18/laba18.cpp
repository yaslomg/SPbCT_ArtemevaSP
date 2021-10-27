// laba18.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdalign>
#include <ctime>
#include <random>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");

	string file_in, word_in, word_fn;
	ofstream file;
	file.open("test.txt", ios::out | ios::app);

	if (!file)
	{
		cout << "Ошибка! Невозможно открыть для записи данных!";
		cin.sync(); cin.get(); return 1;
	}

	file << "cat" << endl << "love" << endl << "mom" << endl << "dad" << endl;

	file.close();
	ifstream file2;
	file2.open("test.txt", ios::in);
	if (!file2)
	{
		cout << "Ошибка! Невозможно открыть для записи данных!";
		cin.sync(); cin.get(); return 2;
	}

	cout << "Введите слово: ";
	cin >> word_fn;

	while (file2 >> word_in)
		if (word_in == word_fn)
		{
			cout << "Слово '" << word_fn << "' найдено\n";
			system("PAUSE");
			file2.close();
			return 0;
		}
	if (word_in != word_fn)
	{
		cout << "Слово '" << word_fn << "' не найдено\n";
		system("PAUSE");
		file2.close();
		return 0;
	}
}