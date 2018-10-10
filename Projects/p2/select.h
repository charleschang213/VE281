/*************************************************************************
    > File Name: select.h
    > Author: Charles Chang
    > Mail: charleschang213@sjtu.edu.cn 
    > Created Time: 2018-10-11 03:40:31
 ************************************************************************/

#ifndef SELECT_H
#define SELECT_H
#include <cstdlib>
#define SWAP(a,b) {if (a!=b) {a = a^b;b = a^b;a = a^b;}}
int rselect(int *arr,int size,int k);
int dselect(int *arr,int size,int k);
void quick_sort_inplace(int *arr,int n);
int sortselect(int *arr,int size,int k);
#endif
