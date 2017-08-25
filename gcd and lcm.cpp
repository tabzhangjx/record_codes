// gcd and lcm.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;
	int a=0;
	int b=0;
	int c = 0;
	int m=1;
	int n=1;

	cin >> a;
	cin >> b;

	if (a <= b)
		c = 0;
	else
		c = a, a = b, b = c;

	m = a;
	n = b;

	while (a%m != 0 || b%m != 0) {
		m--;
	}

	while (n%a != 0 || n%b != 0) {
		n++;
	}

	cout << m << " " << n;

    return 0;
}

