#include<iostream>

using namespace std;

inline int read() {
	static int a;
	cin >> a;
	static int i, j, k;
	if (a>20170521)
		return 1;
	return 2;
}

int printtt(int a) {
	if (a == 1) {
		cout << "safe" << endl;
	}
	else {
		cout << "unsafe" << endl;
	}
	return 0;
}

int main() {
	int n;
	cin >> n;
	for (int m = 0; m < n; m++) {
		printtt(read());
	}
	return 0;
}