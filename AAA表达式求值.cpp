#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <deque>

using namespace std;
//字符串转int
int string2int(string s){
	stringstream ss;
	ss << s;
	int res;
	ss >> res;
	return res;
}
//char转字符串
string to_string(char ch){
	stringstream ss;
	ss << ch;
	string s = ss.str();
	return s;
}

void addNum(deque<string> &que, int num) {
	if (!que.empty()) {
		string top = que.back();
		if (top == "*" || top == "/"){
			que.pop_back();
			int cur = string2int(que.back());
			que.pop_back();
			if (top == "*")
				cur = cur * num;
			else
				cur = cur / num;
			que.push_back(to_string(cur));
		}
		else
			que.push_back(to_string(num));
	}
	else
		que.push_back(to_string(num));
}

int getNum(deque<string> &que) {
	int res = 0;
	bool add = true;
	string cur = "";
	int num = 0;
	while (!que.empty()) {
		cur = que.front();
		que.pop_front();
		if (cur == "+") {
			add = true;
		}
		else if (cur == "-") {
			add = false;
		}
		else {
			num = string2int(cur);
			res += add ? num : (-num);
		}
	}
	return res;
}

int value(string str, int &i) {
	deque<string> que;
	int n = str.size();
	int pre = 0;
	while (i < n && str[i] != ')') {
		if (str[i] >= '0' && str[i] <= '9') {
			pre = pre * 10 + (str[i] - '0');
		}
		else if (str[i] != '(') {
			addNum(que, pre);
			que.push_back(to_string(str[i]));
			pre = 0;
		}
		else {
			++i;
			int res = value(str, i);
			pre = res;
		}
		++i;
	}
	addNum(que, pre);
	return getNum(que);
}

int getValue(string str) {
	int i = 0;
	return value(str, i);
}

int main()
{
	string exp = "1+(3-2*4)+(4-5)/3";
	int result = getValue(exp);
	cout << result << endl;
	
	return 0;
}


