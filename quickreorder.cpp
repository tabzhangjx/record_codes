// 快排.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

#define element theType2	//宏定义元素项名称以便于更改数据类型
#define DefaultSize 100		//宏定义数组大小

//一种数据类型
typedef struct datatype2 {
	int num;
}theType2;

//另一种数据类型
typedef struct datatype1 {
	int order;
	char data;
}theType1;

//定义快速排序的数组类，用于存储待快排的数组首地址并对其进行操作；
class recordlist {
private:
	element * R;
	int MaxSize;
	int CurrentSize;
public:
	recordlist(int Maxsz = DefaultSize) {
		R = new element[Maxsz];
		MaxSize = Maxsz;
		CurrentSize = 0;
	}
	recordlist(element *r, int Maxsz = DefaultSize);
	~recordlist() { delete[]R; }
	void QSort(int left, int right);
	void QuickSort(element *t);
	int Partition(element R[], int low, int high);
	void show(element *t);
};

//初始化
recordlist::recordlist(element *r, int Maxsz) {
	this->R = new element[Maxsz];
	this->MaxSize = Maxsz;
	this->CurrentSize = 0;
	element *a = R;
	element *b = r;
	for (int i = 0; i < Maxsz; i++) {
		a->num = b->num;
		a++;
		b++;
		this->CurrentSize++;
	}
	int tem = 0;
}

//快排递归调用函数
void recordlist::QSort(int left, int right) {
	if (left < right) {
		int pivotpos = Partition(R,left, right);
		QSort(left, pivotpos - 1);
		QSort(pivotpos + 1, right);
	}
}

//快排主程序。调用递归函数
void recordlist::QuickSort(element *t) {
	QSort(0, CurrentSize - 1);
	show(t);
}

//进行元素移动换位；
int recordlist::Partition(element R[], int low, int high) {
	element pivot = R[low];
	while (low < high) {
		while (low<high&&R[high].num>pivot.num) {
			--high;
		}
		R[low] = R[high];
		while (low < high&&R[low].num <= pivot.num) {
			++low;
		}
		R[high] = R[low];
	}
	R[low] = pivot;
	return low;
}

//输出快排结果
inline void recordlist::show(element *t) {
	element *a = R;
	
	for (int i = 0; R[i].num > 0; i++) {
		t->num = R[i].num;
		t++;
		std::cout << R[i].num << ' ';
	}
	int ab = 0;
}

int main()
{
	element theaim[] = { 4,5,5,2,52,45,245,5,6,3,45,2,6,56,67,7,37,2,6,56,746,7,372,46,47,788,4,62,6,6,57,437,47,47,4 };
	//计算数组大小
	int num = sizeof(theaim) / sizeof(element);
	//开始进行快排；
	recordlist aboutint(theaim, num);
	aboutint.QuickSort(theaim);
    return 0;
}