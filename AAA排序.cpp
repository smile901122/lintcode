#include <iostream>
#include <vector>

using namespace std;
/****排序算法****/

//冒泡排序
template <class Type>
void bubbleSort(vector<Type> a){
	int start = 0;
	int end = a.size() - 1;
	for (int i = start; i < end - start; ++i){
		for (int j = start; j < end - start; ++j){
			if (a[j] > a[j + 1]){
				swap(a[j], a[j + 1]);
			}
		}
	}

	cout << "冒泡： " << endl;
	for (Type i : a){
		cout << i << " ";
	}
	cout << endl;
}

//选择排序
template <class Type>
void selectSort(vector<Type> a){
	int start = 0;
	int end = a.size() - 1;
	for (int i = start; i < end - start; ++i){
		int min_index = i;
		for (int j = i + 1; j < end - start + 1; ++j){
			if (a[j] < a[min_index]){
				min_index = j;
			}
		}
		swap(a[i], a[min_index]);
	}

	cout << "选择： " << endl;
	for (Type i : a){
		cout << i << " ";
	}
	cout << endl;
}

//插入排序
template <class Type>
void insertSort(vector<Type> a){
	int start = 0;
	int end = a.size() - 1;
	int i;
	int j;
	Type temp;
	for (i = start + 1; i <= end - start; ++i){
		temp = a[i];
		for (j = i; j > start; --j){
			if (a[j - 1] > temp)		a[j] = a[j - 1];
			else break;
		}
		a[j] = temp;
	}

	cout << "插入： " << endl;
	for (Type i : a){
		cout << i << " ";
	}
	cout << endl;
}

//希尔排序
template <class Type>
void shellSort(vector<Type> a){
	int start = 0;
	int end = a.size() - 1;
	int increment;
	int i;
	int j;
	Type temp;
	for (increment = (end - start + 1) / 2; increment > start; increment /= 2){
		for (i = increment; i <= end; ++i){
			temp = a[i];
			for (j = i; j >= increment; j -= increment){
				if (a[j - increment] > temp)		a[j] = a[j - increment];
				else break;
			}
			a[j] = temp;
		}
	}

	cout << "希尔： " << endl;
	for (Type i : a){
		cout << i << " ";
	}
	cout << endl;
}

//快排
template<class Type>
int Partition(vector<Type> &a, int start, int end){
	Type temp = a[start];
	int l = start;
	int r = end;
	while (l < r){
		while (l < r && a[r] > temp)	--r;
		a[l] = a[r];
		while (l < r && a[l] < temp)	++l;
		a[r] = a[l];
	}
	a[l] = temp;
	return l;
}
template<class Type>
void QSort(vector<Type> &a, int start, int end){
	if (start < end){
		int index = Partition(a, start, end); //分割成两部分  
		QSort(a, start, index - 1);
		QSort(a, index + 1, end);
	}
}
template<class Type>
void quickSort(vector<Type> a){
	int start = 0;
	int end = a.size() - 1;
	QSort(a, start, end);

	cout << "快排： " << endl;
	for (Type i : a){
		cout << i << " ";
	}
	cout << endl;
}

int main(){
	//测试
	vector<int> a = { 2, 3, 6, 9, 10, 7, 1, 8, 5, 11, 4 };
	cout << "原数组： " << endl;
	for (auto i : a){
		cout << i << " ";
	}
	cout << endl;
	//冒泡
	//bubbleSort(a);
	//选择
	//selectSort(a);
	//插入
	//insertSort(a);
	//希尔
	//shellSort(a);
	//快排
	quickSort(a);

	return 0;
}
