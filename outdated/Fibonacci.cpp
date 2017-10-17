// Fibonacci.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;
	int n = 0;
	int i = 3;
	int f[100000];
	f[1] = 1, f[2] = 1;
	cin >> n;
	while (i <= n) {
		f[i] = f[i - 1] + f[i - 2];
		i++;
	}
	cout << f[n];

    return 0;
}

