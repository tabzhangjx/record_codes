// ŷ��ɸ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>


int main()
{
	using namespace std;
	
	int a[10000000];
	int i = 0; int j = 1; int n = 0;
	cin >> n;
	while (i <= 9999999) {
		if (i <= n - 1) {
			a[i] = 1;
			i++;
		}
		else {
			a[i] = 0;
			i++;
		}
	}
	i = 0;

    return 0;
}

