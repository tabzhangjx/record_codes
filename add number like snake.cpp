// 蛇形填数 2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;
	int a[102][102]; int i = 0; int j = 0; int p = 0; int q = 0; int t = 0;
	int n = 0;
	cin >> n;

	if (n % 2 == 0) {
		i = j = (n / 2);
		while (2 * q <= (n - 2)) {
			while (((n / 2) - p) < j && ((n / 2) + p) >= j) {
				a[i][j] = n*n - t;
				j--; t++;
			}
			while (((n / 2) - p) <= i && ((n / 2) + p + 1) > i) {
				a[i][j] = n*n - t;
				i++; t++;
			}
			while (((n / 2) - p) <= j && ((n / 2) + p + 1) > j) {
				a[i][j] = n*n - t;
				j++; t++;
			}
			while (((n / 2) - p) <= i && ((n / 2) + p + 1) >= i) {
				a[i][j] = n*n - t;
				i--; t++;
			}
			p++; q++;
		}
	}
	else {
		i = j = (n + 1) / 2;
		a[i][j] = n*n;
		t++; i--;
		while (2 * q < (n - 1)) {
			while ((((n + 1) / 2) - p - 1) < j && (((n + 1) / 2) + p) >= j) {
				a[i][j] = n*n - t;
				j--; t++;
			}
			while ((((n + 1) / 2) - p - 1) <= i && (((n + 1) / 2) + p + 1) > i) {
				a[i][j] = n*n - t;
				i++; t++;
			}
			while ((((n + 1) / 2) - p - 1) <= j && (((n + 1) / 2) + p + 1) > j) {
				a[i][j] = n*n - t;
				j++; t++;
			}
			while ((((n+1) / 2) - p-1) <= i && (((n+1) / 2) + p + 1) >= i) {
				a[i][j] = n*n - t;
				i--; t++;
			}
			p++; q++;
		}
	}

	i = 1; j = 1;
	while (i <= n) {
		cout << a[i][1];
		j = 2;
		while (j <= n) {
			cout << ' ' << a[i][j];
			j++;
		}
		j = 1; i++;
		cout << endl;
	}
	
    return 0;
}



