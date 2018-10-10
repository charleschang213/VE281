/*************************************************************************
    > File Name: main.cpp
    > Author: Charles Chang
    > Mail: charleschang213@sjtu.edu.cn 
    > Created Time: 2018-10-11 03:56:59
 ************************************************************************/

#include<iostream>
#include "select.h"
using namespace std;

int main(){
	srand(time(NULL));
	int mode,size,k;
	int (*funcs[2])(int *arr,int size,int k) = {rselect,dselect};
	cin >> mode >> size >> k;
	int *arr = new int[size];
	for (int i=0;i<size;i++) cin >> arr[i];
	cout << "The order-" << k << " item is " << funcs[mode](arr,size,k) << endl;
	return 0;
}
