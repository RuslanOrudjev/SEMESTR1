#include "pch.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	
	int x, y;
	cin>>x>>y;
	
	int** first = new int* [x];
	for(int i=0; i<x; i++){
		first[i] = new int [y];
	}
	
	srand(time(NULL));
	cout << "Начальная матрица: \n" << endl;
	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			first[i][j] = 1 + rand() % 9;
			cout << first[i][j] << "   ";
		}
		cout << "\n\n";
	}

	float second[x][y];
	for (int i = 0; i < x; ++i)
	{
		int cnt = 0, sum = 0;
		for (int j = 0; j < y; ++j)
		{
			if ((i + 1) < x)
			{
				sum += first[i + 1][j]; ++cnt;
			}
			if ((j + 1) < y)
			{
				sum += first[i][j + 1]; ++cnt;
			}
			if ((i - 1) >= 0)
			{
				sum += first[i - 1][j]; ++cnt;
			}
			if ((j - 1) >= 0)
			{
				sum += first[i][j - 1]; ++cnt;
			}

			second[i][j] = sum / cnt;
			cnt = 0;
			sum = 0;
		}
	}

	cout << "\nСглаженная матрица: " << endl;
	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			cout.precision(2);
			cout << second[i][j] << "   ";
		}
		cout << "\n\n";
	}

	system("pause");
}
