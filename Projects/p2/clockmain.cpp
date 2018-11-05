/*************************************************************************
    > File Name: clockmain.cpp
    > Author: Charles Chang
    > Mail: charleschang213@sjtu.edu.cn 
    > Created Time: 2018-10-19 17:105:48
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<ctime>
#include "select.h"
using namespace std;

int main(){
	ofstream fout("result.txt");
	srand(time(NULL));
	double result[3][100];
	for (int i=0;i<3;i++)
		for (int j=0;j<5;j++)
			result[i][j]=0;
	int size = 100;
	for (int i=0;i<100;i++){
		cout << size << endl;
		int *buff = new int[size];
		for (int j=0;j<size;j++) buff[j] = mrand48();
		for (int j=0;j<3;j++){
			int *buf = new int[size];
			clock_t now = clock();
			for (int k=0;k<size;k+=size/25){
				for (int m=0;m<size;m++) buf[m] = buff[m];
				switch(j){
					case 0: rselect(buf,size,k);break;
					case 1: dselect(buf,size,k);break;
					default: sortselect(buf,size,k);break;
				}
			}
			result[j][i] = clock()-now;
			delete []buf;
		}
		for (int j=0;j<3;j++) result[j][i] = result[j][i]/(double)25;
		delete []buff;
		size+=100;
	}
	for (int i=0;i<3;i++){
		for (int j=0;j<100;j++) fout << result[i][j] << " ";
		fout << endl;
	}
	fout.close();
}

