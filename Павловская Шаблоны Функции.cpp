#include "pch.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct scan_info{
	char model[25];
	int price;
	double x_size;
	double y_size;
	int optr;
	int grey;
};

void scan_infoCreator(int* tSize){
	cout<<"size= ";
	cin>>(*tSize);
	cin.get();
}

void fileWritter(int ssize, scan_info* aarray){
	ofstream file("save.bin", ios::binary | ios_base::trunc);
	file.write((char*)&ssize,sizeof(ssize));
	for(int i=0; i<ssize; i++)
		if(aarray[i].price >= 200) file.write((char*)&aarray[i],sizeof(aarray[i]));
	file.close();
	delete [] aarray;
}

void sortFile(){
	int ssize;
	ifstream file("save.bin", ios::binary);
	file.read((char*)&ssize,sizeof(int));
	scan_info* aArray = new scan_info[ssize];
	for(int i=0;i<ssize;i++){
		file.read((char*)&aArray[i],sizeof(aArray[i]));
	}
	file.close();
	
	scan_info var;
	for(int i=0;i<ssize-1;i++)
		for(int j=0; j<ssize-i-1; j++)
			if(aArray[j].model[0]>aArray[j+1].model[0]){
				var=aArray[j];
				aArray[j]=aArray[j+1];
				aArray[j+1]=var;
			}
	fileWritter(ssize, aArray);
	delete [] aArray;
}

void coutFile(int type){
	int ssize;
	ifstream file("save.bin", ios::binary);
	file.read((char*)&ssize,sizeof(int));
	scan_info* aArray = new scan_info[ssize];
	for(int i=0;i<ssize;i++){
		file.read((char*)&aArray[i],sizeof(aArray[i]));
	}
	file.close();
	
	switch(type){
		case 1:
			for(int i=0; i<ssize; i++){
				cout<<"name="<<aArray[i].model<<endl;
				cout<<"prize="<<aArray[i].price<<endl;
				cout<<"x_size="<<aArray[i].x_size<<endl;
				cout<<"y_size="<<aArray[i].y_size<<endl;
				cout<<"optr="<<aArray[i].optr<<endl;
				cout<<"gray="<<aArray[i].grey<<endl;
			}
			break;
		case 2:
			int number;
			cout<<"Number: ";
			cin>>number;
			cout<<"name="<<aArray[number].model<<endl;
			cout<<"prize="<<aArray[number].price<<endl;
			cout<<"x_size="<<aArray[number].x_size<<endl;
			cout<<"y_size="<<aArray[number].y_size<<endl;
			cout<<"optr="<<aArray[number].optr<<endl;
			cout<<"gray="<<aArray[number].grey<<endl;
			break;
	}
	delete [] aArray;
}

int main(){
	char sort;
	int size;
	int type;
	scan_infoCreator(&size);
	scan_info* array = new scan_info[size];
	
	int trueSize = 0;	
	for(int i=0; i<size; i++){
		cout<<"name="; 		cin.getline(array[i].model,25);
		cout<<"prize="; 	cin>>array[i].price;
		cout<<"x_size="; 	cin>>array[i].x_size;
		cout<<"y_size="; 	cin>>array[i].y_size;
		cout<<"optr="; 		cin>>array[i].optr;
		cout<<"gray="; 		cin>>array[i].grey;
		cin.get();
		if(array[i].price >= 200) trueSize++;
	}
	
	for (int i=0; i<size-1; i++)
		for (int j=i; j<size-i-1; j++)
			if(array[j].price<array[j+1].price){
				scan_info var;
				var=array[j];
				array[j]=array[j+1];
				array[j+1]=var;
			}
	
	fileWritter(trueSize,array);
	cout<<"1"<<endl;
	sortFile();
	cout<<"Enter cout type (1: all 2: number): ";
	cin>>type;
	coutFile(type);
	delete [] array;
	return 0;
}
