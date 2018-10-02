// ConsoleApplication39.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ifstream in_file("in.txt");
ofstream out_file("out.txt");
ifstream in1_file("in1.txt");

void file() {

	int k = 0;
	int max = 0;
	char str1[500];

	while (!in1_file.eof())
	{
		k = 0;
		in1_file.getline(str1, 500);

		for (int i = 0; str1[i] != '\0'; i++)
		{
			k++;
		}
		if (max < k) max = k;
	}

	cout << max << endl;
}

//Дан текстовый файл. Удалить из него последнюю строку. Результат записать в другой файл.
void del_l() {

	const int len = 30, strings = 3;
	char str[len][strings];

	for (int i = 0; i < strings - 1; i++)
	{
		in_file.getline(str[i], len - 1);
		out_file << str[i] << endl;
	}
}

//Дан текстовый файл. Подсчитать количество слов, начинающихся с символа, который задаёт пользователь.
void fi() {
	
	char name[100];
	char * p, *context;
	int k = 0;
	char choice;

	cout << "Введите нвчальную букву: ";
	cin >> choice;

	while (!in_file.eof())
	{
		in_file.getline(name, 100);
		p = strtok_s(name, " ", &context);
		while (p)
		{
			out_file << p << endl;
			if (p[0] == choice) k++;
			p = strtok_s(context, " ", &context);
		}
	}
	cout << "Количество слов начинающихся с буквы " << choice << " равно " << k << endl;
}


void main()
{
	setlocale(LC_ALL, "Rus");

	del_l();
	file();
	fi();
	
	system("pause");
}
