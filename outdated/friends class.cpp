// friends class.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;
class Sample {
private:
	friend class Process;
	char name[5];
	int arr[5];
public:
	Sample();
};
Sample::Sample() {
	name[0] = '\0';
	int i = 0;
	while (i < 5) {
		cin >> arr[i];
		i++;
	}
}
class Process {
public:
	void reorder(Sample&a);
};
inline void Process::reorder(Sample&a) {
	int i = 0, n = 0; int tem = 0;
	while (n <= 20) {
		while (i < 4) {
			if (a.arr[i] > a.arr[i + 1]) {
				tem = a.arr[i];
				a.arr[i] = a.arr[i + 1];
				a.arr[i + 1] = tem;
				i++;
			}
			else {
				i++;
			}
		}
		i = 0; n++;
	}
	i = 0;
	while (i < 4) {
		cout << a.arr[i];
		cout << ' ';
		i++;
	}
	cout << a.arr[i];
}
int main()
{
	Sample s1;
	Process p1;
	p1.reorder(s1);
    return 0;
}

