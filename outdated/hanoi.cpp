// hanoi.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
using namespace std;
long long hanoi(int, long long);
int main()
{
	int n = 0; long long step = 0;
	cin >> n;
	step = hanoi(n, 0);
	cout << step;
	return 0;
}
long long hanoi(int a, long long s) {
	if (a == 1) {
		s = 1;
	}
	else if (a == 2) {
		s = 3;
	}
	else if (a > 2) {
		s = hanoi(a - 1, 0) * 2 + 1;
		if (s >= 1000000) {
			s = s - 1000000 * (s / 1000000);
		}
	}
	return s;
}
