#include<iostream>
using namespace std;
int main() {
	int T = 0;
	cin >> T;
	char luvletter[10] = { "luvletter" };
	char check[100001] = { '\0' };
	char temp;
	int NUM = 0;
	int flag = 0;
	for (int i = 0; i < T; i++) {
		cin >> temp;
		cin.getline(check+1, 100001);
		check[0] = temp;
		for (int j = 0; check[j] != '\0'; j++) {
			if (check[j] == luvletter[flag] && flag == 8) {
				NUM = NUM + 1;
				flag = 0;
			}
			else if (check[j] == luvletter[flag] && flag != 8) {
				flag++;
			}
		}
		cout << NUM << endl;
		NUM = 0;
	}
	return 0;
}