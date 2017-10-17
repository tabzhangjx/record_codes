// 素数表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;
	int i = 2;
	int j = 2;
	int k = 0;
	int m = 0;
	int n = 0;
	cin >> n;
	while (i <= n) {
		if (k != 8)
			if (j < i)
				if (i % j == 0)
					i++, j = 2;
				else
					j++;
			else
				cout << setw(11) << i, i++, j = 2, k++, m++;
		else
			k = 0 ,cout << endl;

	}
	cout << endl << "m = " << m << endl;
    return 0;
}

