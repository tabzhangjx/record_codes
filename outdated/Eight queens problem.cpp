// Eight queens problem.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>

//ȫ�ֶ�������
char chessboard[8][8] = { '\0' };

bool flag = false;

//����check����������ͨ���������б���ж�����λ���Ƿ�ȫ��
bool check(int i,int j) {//�У���
	for (int a = i,b = j; a >= 0 && b >= 0; a--, b--) {
		if (chessboard[a][b] == '#') {
			return false;
		}
	}
	for (int a = i,b = j; a >= 0 && b >= 0; a--, b++) {
		if (chessboard[a][b] == '#') {
			return false;
		}
	}
	for (int a = i,b = j; a >= 0; a--) {
		if (chessboard[a][b] == '#') {
			return false;
		}
	}
	for (int a = i,b = j; b >= 0; b--) {
		if (chessboard[a][b] == '#') {
			return false;
		}
	}
	return true;
}

//����������
bool setqueens(int n = 0) {//nΪ����������
	for (int theline = 0; theline < 8; theline++) {//�ӵ�һ�п�ʼ����
		if (check(n, theline)) {//�����n,theline)��ȫ
			chessboard[n][theline] = '#';
			n++;//����
			if (n == 8) {
				flag = 1;
				return true;//���˸��˳�
			}
			if (setqueens(n)) {
				return true;//���֮����Գɹ����ӷ�����
			}
			else {
				n--;
				chessboard[n][theline] = '*';//����˵����λ�ò�����������һ����
			}
		}
	}
	if (flag == 1) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	//��ʼ������
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			chessboard[i][j] = '*';
		}
	}

	//��ʼ���ӣ�
	setqueens(0);

	//չʾ���̣�
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::cout << chessboard[i][j] << ' ';
		}
		std::cout << '\n' << '\n';
	}
    return 0;
}

