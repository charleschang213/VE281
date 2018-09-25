/*************************************************************************
    > File Name: main.cpp
    > Author: Charles Chang
    > Mail: charleschang213@sjtu.edu.cn 
    > Created Time: 2018-09-21 01:12:04
 ************************************************************************/
#include "sorting.h"
#include "clocking.h"
//#define CLOCKED
using namespace std;

int main(){
	srand(time(NULL));
#ifdef CLOCKED
	clocking_main();
#else
	void (*func[6]) (int *arr,int n) = {
		bubble_sort,
		insertion_sort,
		selection_sort,
		merge_sort,
		quick_sort,
		quick_sort_inplace
	};
	int mode,n,*arr;
	cin >> mode >> n;
	if (n==0) return 0;
	arr = new int [n];
	for (int i=0;i<n;i++) cin >> arr[i];
	func[mode](arr,n);
	for (int i=0;i<n;i++) cout << arr[i] << endl;
#endif
	return 0;
}

