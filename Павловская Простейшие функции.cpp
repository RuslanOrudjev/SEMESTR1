#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>

using namespace std;

struct TRAIN
{
	string name, time;
	int number;
};

void qs(struct TRAIN *arr, int first, int last)
{
	int x = arr[(first + last) / 2].number,
		i = first, j = last;
	do {
		while (arr[i].number < x) i++;
		while (arr[j].number > x) j--;
		if (i <= j) {
			if (arr[i].number > arr[j].number)
			{
				int t = arr[i].number;
				string str = arr[i].name;
				string st = arr[i].time;
				arr[i].number = arr[j].number;
				arr[i].name = arr[j].name;
				arr[i].time = arr[j].time;
				arr[j].number = t;
				arr[j].name = str;
				arr[j].time = st;
			}
			i++;
			j--;
		}
	} while (i <= j);
	if (first < j) qs(arr, first, j);
	if (last > i) qs(arr, i, last);
}

void print(struct TRAIN *arr, int n)
{
	cout << "Пункт назначения\tНомер\tВремя\n";
	for (int i(0); i < n; i++)
		cout << arr[i].name << '\t' << arr[i].number << '\t' << arr[i].time << '\n';
	cout << endl;
}

int main(int argc, char *argv[])
{
	setlocale(0, "");
	int N;
	cin>>N;
	TRAIN* train = new TRAIN [N];
	for (int i(0); i < N; i++)
	{
		cout << "Пункт назначения: ";
		getline(cin, train[i].name);
		cout << "Номер: ";
		cin >> train[i].number;
		cin.get();
		cout << "Время: ";
		getline(cin, train[i].time);
		system("cls");
	}
	print(train, N);
	qs(train, 0, N - 1); //Быстрая сортировка
	int n;
	cout << "Íîìåð ïîåçäà: ";
	cin >> n; 
	bool f = 1;
	for (int k = 0; k < N; k++)
		if (train[k].number == n)
		{
			cout << train[k].name << '\t' << train[k].number << '\t' << train[k].time << '\n';
			f = 0;
			break;
		}
	if (f) cout << "Нет такого номера поезда";
	cout << endl;
	print(train, N);
	_getch();
	return 0;
}
