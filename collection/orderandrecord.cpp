#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

// C++11
std::pair<char, int> records[26];
bool cmp (const std::pair<char, int> &a, const std::pair<char, int> &b) {
	return a.second >= b.second;
}

int main () {
	char ch;
	for (int i = 0; i < 26; i++) {
		records[i] = std::make_pair('A' + i, 0);
	}
	while ((ch = getchar()) != EOF && ch != '!') {
		if ('A' <= ch && ch <= 'Z') {
			records[ch - 'A'].second++;
		}
	}
	std::sort(records, records + 26, cmp);
	for (auto r : records) {
		if (r.second > 0) {
			std::cout << r.first << " " << r.second << std::endl;
		}
	}
	return 0;
}
