//#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long n;//n是输入值。
	long long judge = pow(2, 15);//若n小于此值，最大奇因子之和不比100000007大多少，可直接计算；若n大于此值，则需要取模。
	long long sum = 0;//最大奇因子之和，可不断通过取余简化。
	int flag = 0;//n为2的多少阶。
	long long temp = 0; //临时量，含义不断转化。
	long long i = 0;//临时量，通过不断除以2用于计算一个偶数的最大奇因子。
	long long biaozhi = 1000000007;//标志。取模临界点。
	cin >> n; temp = n;
	while (temp >= 2) {
		temp = temp / 2;
		flag++;
	}
	if (n < judge) {
		temp = pow(2, flag);
		while (flag > 0) {
			sum = sum + pow(4, flag - 1);
			flag--;
		}
		while (temp <= n) {
			i = temp;
			while (i % 2 == 0) {
				i = i / 2;
			}
			sum = sum + i;
			temp++;
		}
	}
	else {
		while (flag > 0) {
			if (flag > 15) {
				temp = pow(4, flag - 1);
				temp = temp&biaozhi;
				sum = sum + temp;
				if (sum > biaozhi) {
					sum = sum%biaozhi;
				}
			}
			else {
				temp = pow(2, flag);
				while (flag > 0) {
					sum = sum + pow(4, flag - 1);
					flag--;
				}
				while (temp <= n) {
					i = temp;
					while (i % 2 == 0) {
						i = i / 2;
					}
					sum = sum + i;
					temp++;
				}
			}
			flag--;
		}
	}
	sum = sum%biaozhi;
	cout << sum;
	return 0;
}