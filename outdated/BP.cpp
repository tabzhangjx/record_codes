#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define LAYER		3
#define NUM			10
#define A			30.0
#define B			10.0
#define ITERS		1000
#define ETA_W		0.0035
#define ETA_B		0.001
#define ERROR		0.002
#define ACCO		0.005

#define Type double
#define Vector std::vector

struct Data {
	vector<Type> x;
	vector<Type> y;
};

class BP {
private:
	int in_num;
	int ou_num;
	int hd_num;

	Vector<Data> data;

	Type w[LAYER][NUM][NUM];
	Type b[LAYER][NUM];

	Type x[LAYER][NUM];
	Type d[LAYER][NUM];

private:
	void InitNetWork();
	void GetNums();
	void ForwardTransfer();
	void ReverseTransfer(int);
	void CalcDelte(int);
	void UpdateNetWork();
	Type GetError(int);
	Type GetAccu();
	Type Sigmoid(const Type);

public:
	void GetData(const Vector<Data>);
	void Train();
	Vector<Type> ForeCast(const Vector<Type>);

};

void BP::GetData(const Vector<Data> _data) {
	data = _data;
}

void BP::Train() {
	cout << "Train start!";
	GetNums();
	InitNetWork();
	int num = data.size;
	for (int iter = 0; iter <= ITERS; iter++) {
		for (int cnt = 0; cnt < num; cnt++) {
			for (int i = 0; i < in_num; i++) {
				x[0][i] = data.at(cnt).x[i];
			}
			while (1) {
				ForwardTransfer();
				if (GetError(cnt) < ERROR) {
					break;
				}
				ReverseTransfer(cnt);
			}
		}
	}
	
}