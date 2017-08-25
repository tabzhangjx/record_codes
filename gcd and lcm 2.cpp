// gcd and lcm 2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <limits>

int main()
{
	using namespace std;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int m = 0;
	int p = 0;
	int q = 0;

	cin >> p;
	cin >> q;

	a = p;
	b = q;
	
	while (d == 0||d%p != 0 || d%q != 0) {
		d = d + q;
	}
	
	while (c==0||p%c != 0 || q%c != 0) {
		if (a <= b)
			a = a;
		else
			m = a, a = b, b = m;
		//c = sqrt((a - b)*(a - b));
		c = b - a;
		b = c;
		//m = numeric_limits<int>::max()
	}
	
	//cout << c << '\n' << d;
	cout << d << '\n' << c;
	return 0;
}

