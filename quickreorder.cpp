// ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>

#define element theType2	//�궨��Ԫ���������Ա��ڸ�����������
#define DefaultSize 100		//�궨�������С

//һ����������
typedef struct datatype2 {
	int num;
}theType2;

//��һ����������
typedef struct datatype1 {
	int order;
	char data;
}theType1;

//�����������������࣬���ڴ洢�����ŵ������׵�ַ��������в�����
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

//��ʼ��
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

//���ŵݹ���ú���
void recordlist::QSort(int left, int right) {
	if (left < right) {
		int pivotpos = Partition(R,left, right);
		QSort(left, pivotpos - 1);
		QSort(pivotpos + 1, right);
	}
}

//���������򡣵��õݹ麯��
void recordlist::QuickSort(element *t) {
	QSort(0, CurrentSize - 1);
	show(t);
}

//����Ԫ���ƶ���λ��
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

//������Ž��
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
	//���������С
	int num = sizeof(theaim) / sizeof(element);
	//��ʼ���п��ţ�
	recordlist aboutint(theaim, num);
	aboutint.QuickSort(theaim);
    return 0;
}