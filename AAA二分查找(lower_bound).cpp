#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<class Type>
int binarySearch(vector<Type> a, Type k){
	int l = 0;
	int r = a.size() - 1;
	while (l <= r){
		int mid = l + (r - l) / 2;
		if (a[mid] == k){
			while (a[mid] == k && mid >= 0) --mid;
			return mid + 1;
		}
		else if (a[mid] > k)
			r = mid - 1;
		else
			l = mid + 1;
	}
}

int main(){
	//测试
	vector<int> a = { 1,1,2,2,3,3,3,3,3,3,4,5,6,7,8,9,9,9,9,9,9,9,9,10,11,12,13,14,15 };
	cout << "原数组： " << endl;
	for (auto i : a){
		cout << i << " ";
	}
	cout << endl;
	int k;
	while (cin >> k){
		int index = binarySearch(a, k);
		cout << a[index - 1] << " " << a[index] << " " << a[index + 1] << endl;
	}
	return 0;
}
