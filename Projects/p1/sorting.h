/*************************************************************************
    > File Name: sorting.h
    > Author: Charles Chang
    > Mail: charleschang213@sjtu.edu.cn 
    > Created Time: 2018-09-21 01:12:09
 ************************************************************************/
#ifndef SORTING_H
#define SORTING_H
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<ctime>
#define SWAP(a,b) {if (a!=b){a = a^b;b =  a^b;a = a^b;} }
void bubble_sort(int *arr,int n);
void insertion_sort(int *arr,int n);
void selection_sort(int *arr,int n);
void merge_sort(int *arr,int n);
void quick_sort(int *arr,int n);
void quick_sort_inplace(int *arr,int n);
#endif


