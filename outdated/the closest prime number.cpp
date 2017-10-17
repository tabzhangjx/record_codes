// the closest prime number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

int main()
{
	using namespace std;
	int n = 0; int i = 0; int j = 2; int k = 0; int m = 0; int l = 0; int y = 0;
	cin >> n;
	i = n;

	if (i == 1)
		cout << "2 1";

	if (i == 2)
		cout << "2 0";

	while (i < 1000000 && i > 2) {
		while (j < i) {
			if (i%j != 0)
				j++;
			else
			   {k++;
			    y = pow(-1, k);
				i = i + y*k;
				j = 2;
				break;}
			}
		if (i == j )
			break;
		}

	if (i == 1000000) {
		j = 2;
		while (i <= 1000000) {
			while (j < i) {
				if (i%j != 0)
					j++;
				else
				{
					m = 1;
					i = i - m;
					j = 2;
					break;
				}
			}
			if (i == j)
				break;
		}
	}

	if (i <= n)
		l = n - i;
	else
		l = i - n;

	if (i != 2 && i != 1 && i > 0)
		cout << i << ' ' << l;

	if (i <= 0){
		l = 2 - n;
		cout << "2 " << l;
	}


    return 0;
}

