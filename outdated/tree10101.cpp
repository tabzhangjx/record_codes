#include <iostream>
using namespace std;

int flag = 0;

void search(int n, unsigned long long final = 1, int deep = 1) {
	if (deep > 19) {
		return;
	}
	if (final%n == 0) {
		flag = 1;
		cout << final << endl;
		return;
	}
	else {
		search(n, final * 10, ++deep);
		if (flag == 1) {
			return;
		}
		search(n, final * 10 + 1, ++deep);
	}
	return;
}

int main() {
	int target[20000] = { '\0' };
	for (int i = 0; i < 20000; i++) {
		target[i] = rand() % 190 + 3;
		if (target[i] == 0) {
			break;
		}
	}
	for (int i = 0; target[i] != 0; i++) {
		search(target[i]);
		flag = 0;
	}
	return 0;
}

