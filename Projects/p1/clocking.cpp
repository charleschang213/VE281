/*************************************************************************
    > File Name: clocking.cpp
    > Author: Charles Chang
    > Mail: charleschang213@sjtu.edu.cn 
    > Created Time: 2018-09-21 03:03:58
 ************************************************************************/

#include "sorting.h"
#include <string>
using namespace std;

string int_to_string(int x){
	ostringstream sout;
	sout<<x;
	return sout.str();
}

void clocking_main(){
	void (*func[6]) (int *arr,int n) = {
		bubble_sort,
		insertion_sort,
		selection_sort,
		merge_sort,
		quick_sort,
		quick_sort_inplace
	};
	double table[6][100];
	for (int i=0;i<6;i++)
		for (int j=0;j<100;j++)
			table[i][j] = 0;
	string number[101];
	for (int i=0;i<101;i++) number[i]= int_to_string(i);
	for (int i=0;i<6;i++) {
		cout << "Checking Mode " << i << endl;
		for (int j=1;j<=100;j++){
			cout << "Checking number " << j << endl;
			for (int k=0;k<100;k++){
				string name = "p1/"+number[j]+"/"+number[i]+"/"+number[k]+"/test.in";
				ifstream fin;
				fin.open(name.c_str());
				int *arr,n,mode;
				fin >> mode >> n;
				arr = new int[n];
				for (int x = 0;x<n;x++) fin >> arr[x];
				int now = clock();
				func[mode](arr,n);
				int duration = clock()-now;
				table[mode][j-1]+=(double)duration/(double)CLOCKS_PER_SEC*1000.0;
				fin.close();
				delete []arr;
			}
		}
	}
	ofstream fout;
	fout.open("result.out");
	for (int i=0;i<6;i++){
		for (int j=0;j<100;j++) fout << table[i][j]/100.0 << " ";
		fout << endl;
	}
	fout.close();
}

