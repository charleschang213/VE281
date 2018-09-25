/*************************************************************************
    > File Name: sorting.cpp
    > Author: Charles Chang
    > Mail: charleschang213@sjtu.edu.cn 
    > Created Time: 2018-09-21 01:12:13
 ************************************************************************/

#include "sorting.h"
using namespace std;

void bubble_sort(int *arr,int n){
	for (int i=n;i>0;i--)
		for (int j=0;j<i-1;j++)
			if (arr[j]>arr[j+1]) SWAP(arr[j],arr[j+1]);
}

void insertion_sort(int *arr,int n){
	for (int i=1;i<n;i++)
		for (int j=i;(j>0)&&(arr[j]<arr[j-1]);j--) SWAP(arr[j],arr[j-1]);
}

void selection_sort(int *arr, int n){
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (arr[i]>arr[j]) SWAP(arr[j],arr[i]);
}

void merge_sort(int *arr,int n){
	if (n==1) return;
	int left = n/2;
	int right = n-left;
	merge_sort(arr,left);
	merge_sort(arr+left,right);
	int *tmp = new int[n];
	int lflag=0,rflag=left,flag=0;
	while ((lflag!=left)||(rflag!=n)){
		if (lflag==left){
			tmp[flag] = arr[rflag];
			flag++;rflag++;
		}
		else if (rflag==n){
			tmp[flag] = arr[lflag];
			flag++;lflag++;
		}
		else if (arr[rflag]<arr[lflag]){
			tmp[flag] = arr[rflag];
			flag++;rflag++;
		}
		else {
			tmp[flag] = arr[lflag];
			flag++;lflag++;
		}
	}
	for (int i=0;i<n;i++) arr[i] = tmp[i];
	delete [] tmp;
}

void quick_sort(int *arr,int n){
	if ((n==0)||(n==1)) return;
	if (n==2){
		if (arr[0]>arr[1]) SWAP(arr[0],arr[1]);
		return;
	}
	int pivot = rand()%n;
	int *arrl = new int[n];
	int *arrr = new int[n];
	int lflag=0,rflag=0;
	for (int i=0;i<n;i++){
		if (arr[i]<arr[pivot]) {
			arrl[lflag] = arr[i];
			lflag++;
		}
		else if ((arr[i]>=arr[pivot])&&(i!=pivot)) {
			arrr[rflag] = arr[i];
			rflag++;
		}
	}
	quick_sort(arrl,lflag);
	quick_sort(arrr,rflag);
	int tmp = arr[pivot];
	for (int i=0;i<lflag;i++) arr[i] = arrl[i];
	arr[lflag] = tmp;
	for (int i=lflag+1;i<n;i++) arr[i] = arrr[i-lflag-1];
	delete [] arrl;
	delete [] arrr;
}

void quick_sort_inplace(int *arr, int n){
	if ((n==0)||(n==1)) return;
	if (n==2){
		if (arr[0]>arr[1]) SWAP(arr[0],arr[1]);
		return;
	}
	int pivot = rand()%n;
	SWAP(arr[pivot],arr[0]);
	int lflag=1,rflag=n-1;
	while (lflag<rflag){
		while ((arr[lflag]<arr[0])&&(lflag<n-1)) lflag++;
		while ((arr[rflag]>=arr[0])&&(rflag>0)) rflag--;
		if (lflag<rflag) SWAP(arr[lflag],arr[rflag]);
	}
	SWAP(arr[0],arr[rflag]);
	quick_sort_inplace(arr,rflag);
	quick_sort_inplace(arr+rflag+1,n-rflag-1);
}
