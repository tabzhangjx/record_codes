#include "stdafx.h"
#include <iostream>
using namespace std;
int fib(int k, int t1, int t2) {
	int m = 0;
	if (k > 0) {
		if (k == 1 || k == 2) {
			m = m + 1;
		}
		else if (k > 2) {
			m = fib(k - 1, t2, t1 + t2);
		}
	}
	return m;
}
int main() {
	int n = 0;
	cin >> n;
	n = fib(n, 1, 1);
	cout << n;
	return 0;
}