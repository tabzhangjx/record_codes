#include <iostream>

bool check(int t) {
	if (t == 0) {
		return true;
	}
	else if (t == 1) {
		return false;
	}
	else {
		std::cout << "input wrong;" << std::endl;
		exit(0);
	}
}
void flip(int *p, int n, int m) {
	for (int a = 0; a < m; a++) {
		for (int b = 0; b < m; b++) {
			*p = 1 - *p;
			p++;
		}
		p = p + (n - m);
	}
}
int main()
{
	int N, M;
	std::cin >> N >> M;
	int sum = N*N;
	int *cards = new int[sum + 1];
	int *card = cards;
	for (int i = 0; i < sum; i++) {
		std::cin >> *card;
		card++;
	}
	*card = 1;
	card = cards;
	
	int steps = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
		
			if (check(*card)) {
				if (j + M > N) {
					return -1;
				}
				else {
					flip(card,N, M);
					steps++;
				}
			}
			else {}
			card++;
		}
	}
	std::cout << steps;
	delete[]cards;
    return 0;
}

