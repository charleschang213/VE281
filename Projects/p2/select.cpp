/*************************************************************************
    > File Name: select.cpp
    > Author: Charles Chang
    > Mail: charleschang213@sjtu.edu.cn 
    > Created Time: 2018-10-11 03:45:18
 ************************************************************************/

#include "select.h"

int rselect(int *arr,int size,int k){
	if (size==1) return arr[0];
	if (size==2){
		if (arr[1]<arr[0]) SWAP(arr[1],arr[0]);
		return arr[k];
	}
	int pivot = rand()%size;
	SWAP(arr[pivot],arr[0]);
	int lflag=1,rflag=size-1;
	while (lflag<rflag){
		while ((arr[lflag]<arr[0])&&(lflag<size-1)) lflag++;
		while ((arr[rflag]>=arr[0])&&(rflag>0)) rflag--;
		if (lflag<rflag) SWAP(arr[lflag],arr[rflag]);
	}
	SWAP(arr[0],arr[rflag]);
	if (rflag==k) return arr[rflag];
	if (rflag>k) return rselect(arr,rflag,k);
	return rselect(arr+rflag+1,size-rflag-1,k-rflag-1);
}

int dselect(int *arr,int size,int k){
	if (size<=5) {
		for (int i=0;i<size;i++)
			for (int j=i+1;j<size;j++)
				if (arr[i]>arr[j]) SWAP(arr[i],arr[j]);
		return arr[k];
	}
	int groups = size/5;
	if (size%5==0) groups--;
	int *C = new int[groups];
	for (int i=0;i<groups;i++){
			int nowgroup = i*5;
			for (int j=0;j<3;j++)
				for (int k=j+1;k<5;k++)
					if (arr[nowgroup+j]>arr[nowgroup+k]) SWAP(arr[nowgroup+j],arr[nowgroup+k])
			C[i] = arr[nowgroup+2];
	}
	int pnum = dselect(C,groups,groups/2);
	delete []C;
	int pivot;
	for (pivot=2;arr[pivot]!=pnum;pivot++);
	SWAP(arr[pivot],arr[0]);
	int lflag=1,rflag=size-1;
	while (lflag<rflag){
		while ((arr[lflag]<arr[0])&&(lflag<size-1)) lflag++;
		while ((arr[rflag]>=arr[0])&&(rflag>0)) rflag--;
		if (lflag<rflag) SWAP(arr[lflag],arr[rflag]);
	}
	SWAP(arr[0],arr[rflag]);
	if (rflag==k) return arr[rflag];
	if (rflag>k) return dselect(arr,rflag,k);
	return dselect(arr+rflag+1,size-rflag-1,k-rflag-1);
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
int cmp(const void *a,const void *b){
	int ta = *((int*)a);
	int tb = *((int*)b);
	return ta-tb;
}
int sortselect(int *arr,int size,int k){
	qsort(arr,size,sizeof(int),cmp);
	//quick_sort_inplace(arr,size);
	return arr[k];
}
