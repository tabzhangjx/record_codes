// IQ(2).cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n = 0; int k = 0; cin >> n >> k; int i = 0; int j = 0; int p = 0; int q = 0; int c = 1; int r = 1; int s = 1;
	char model[10]; int brush[3][3];
	while (i < n*n) {
		cin >> model[i];
		i++;
	}i = 0;
	while (i < n) {
		while (j < n) {
			if (model[(i + 1)*(j + 1) - 1] == '.') {
				brush[i][j] = 1;
			}
			else {
				brush[i][j] = -1;
			}j++;
		}j = 0; i++;
	}j = 0; i = 0;
	int all[243][243];
	while (i < n) {
		while (j < n) {
			if (brush[i][j] == -1) {
				p = i; q = j;
				for (c = 1; c <= k; c = 4) {
					while (p < pow(n, k)) {
						while (q < pow(n, k)) {
							all[p][q] = -1;
							q = q + n;
						}
						q = j; p = p + n;
					}
				}
			}
			j++;
		}
		j = 0; i++;
	}
	j = 0; i = 0;
	while (i < n) {
		while (j < n) {
			if (brush[i][j] == -1) {
				p = (i + 1)*n*r - n - 1; q = (j + 1)*n*s - n - 1;
				for (c = 2; c <= k; c = 4) {
					while (p < pow(n, k) && r <= pow(n, k - 2)) {
						while (((i + 1)*n*r - n - 1 <= p < (i + 1)*n*r - 1)) {
							while (q < pow(n, k) && s <= pow(n, k - 2)) {
								while (((j + 1)*n*s - n - 1 <= q < (j + 1)*n*s - 1) && q < pow(n, k)) {
									all[p][q] = -1;
									q++;
								}s++; q = (j + 1)*n*s - n - 1;
							}p++;
						}r++; p = (i + 1)*n*r - n - 1;
					}
				}
			}
			j++;
		}
		j = 0; i++;
	}
	j = 0; i = 0;
	while (i < n) {
		while (j < n) {
			if (brush[i][j] == -1) {
				p = i + 1 - 1; q = j + 1 - 1;
				for (c = 3; c <= k; c = 4) {
					while (p < pow(n, k)) {
						while (((i + 1)*n*n - n*n - 1 <= p < (i + 1)*n*n - 1)) {
							while (q < pow(n, k)) {
								while (((j + 1)*n*n - n*n - 1 <= q < (j + 1)*n*n - 1)) {
									all[p][q] = -1;
									q++;
								} break;
							}p++;
						}break;
					}
				}
			}
			j++;
		}
		j = 0; i++;
	}
	j = 0; i = 0;
	while (i <= pow(n, k) - 1) {
		while (j <= pow(n, k) - 1) {
			if (all[i][j] == -1) {
				cout << '*';
			}
			else
				cout << '.';
			j++;
		}j = 0; i++; cout << endl;
	}
    return 0;
}

