// 行程编码.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;


int main()
{
	string test;
	cin >> test;
	int len = sizeof(test) / sizeof(test[0]);
	if (len == 1) {
		cout << test;
	}
	if (len == 2 && test[0] == test[1]) {
		cout << 2 << test[0];
	}
	if (len == 2) {
		cout << test;
	}
	char temp;
	int midlen = len / 2;
	string str1[101];
	for (int i = 0; i < midlen; i++) {
		str1[i] = test[midlen - i - 1];
	}

	string aa(str1);


	for (int i = 0; i < midlen; i++) {
		test[i] = str1[i];
	}
	int sum = 1;
	int i = 0;
	for (i = 0; test[i + 1] != '\0'; i++) {
		if (test[i] == test[i + 1]) {
			sum++;
		}
		else if (test[i] != test[i + 1]) {
			if (sum == 1) {
				cout << test[i - 1];
			}
			else if (sum > 1) {
				cout << sum << test[i - 1];
				sum = 1;
			}
		}
	}
	if (sum == 1) {
		cout << test[i - 1];
	}
	else if (sum > 1) {
		cout << sum << test[i - 1];
		sum = 1;
	}
    return 0;
}

