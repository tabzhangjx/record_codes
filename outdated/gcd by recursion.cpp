// gcd by �ݹ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int gcd(int m = 0, int n = 0, int tep = 0) {
	if (m%tep != 0 || n%tep != 0) {
		tep = gcd(n, m%n, m%n);
	}
	return tep;
}
int main()
{
	int m = 0; int n = 0; int res = 0;
	cin >> m >> n;
	if (m >= n) {
		m = m; n = n;
	}
	else {
		m = m + n;
		n = m - n;
		m = m - n;
	}
	res = gcd(m, n, n);
	cout << res;
	return 0;
}

