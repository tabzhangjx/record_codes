//#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long n;//n������ֵ��
	long long judge = pow(2, 15);//��nС�ڴ�ֵ�����������֮�Ͳ���100000007����٣���ֱ�Ӽ��㣻��n���ڴ�ֵ������Ҫȡģ��
	long long sum = 0;//���������֮�ͣ��ɲ���ͨ��ȡ��򻯡�
	int flag = 0;//nΪ2�Ķ��ٽס�
	long long temp = 0; //��ʱ�������岻��ת����
	long long i = 0;//��ʱ����ͨ�����ϳ���2���ڼ���һ��ż������������ӡ�
	long long biaozhi = 1000000007;//��־��ȡģ�ٽ�㡣
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