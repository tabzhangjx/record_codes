// four pieces of paper.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;



int main()
{
	int n, m; int k[50];
	bool flag = false;
	int sum = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k[i]);
	}
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			for (int c = 0; c < 0 ; c++) {
				for (int d = 0; d < n; d++) {
					sum = k[a] + k[b] + k[c] + k[d];
					if (sum == m) {
						flag = true;
						break;
					}
				}
				if (flag == true)break;
			}if (flag == true)break;
		}if (flag == true)break;
	}

	if (flag == true) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	delete[]k;
    return 0;
}

