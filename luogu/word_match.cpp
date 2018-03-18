#include <iostream>

#define N 1001000

using namespace std;
inline int match(char *a, char *b, int m) {
	int i;
	char b1, b2;
	for (i = 0; isalpha(a[i]); i++) {
		if (b[m + i] == '\0') return 0;
		//if (isalpha(b[m + i - 1])) return -1;
		b1 = (b[m + i] + 'A' - 'a');
		b2 = (b[m + i] - 'A' + 'a');
		if (a[i] == b[m + i] || a[i] == b1 || a[i] == b2) {

		}
		else
			return -1;
	}
	if (isalpha(b[m + i]))
		return -1;
	return 1;
}

int main() {
	char a[13], str[N];
	int sum = 0, mark = -1;
	cin.getline(a, 13);
	cin.getline(str, N);
	int m;
	for (int i = 0; 1; i++) {
		if (i != 0){
			if(isalpha(str[i - 1]))
				continue;
		}
		m = match(a, str, i);
		if (m == 0) break;
		if (m == 1) {
			sum++;
			if (mark == -1)
				mark = i;
		}
	}
	if (sum == 0)
		cout << "-1";
	else
		cout << sum << ' ' << mark;
	return 0;
}