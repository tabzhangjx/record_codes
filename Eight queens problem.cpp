// Eight queens problem.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

//全局定义棋盘
char chessboard[8][8] = { '\0' };

bool flag = false;

//定义check函数，用于通过检查行列斜线判断落子位置是否安全；
bool check(int i,int j) {//行，列
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

//落子主程序
bool setqueens(int n = 0) {//n为已落子数量
	for (int theline = 0; theline < 8; theline++) {//从第一列开始遍历
		if (check(n, theline)) {//如果（n,theline)安全
			chessboard[n][theline] = '#';
			n++;//落子
			if (n == 8) {
				flag = 1;
				return true;//满八个退出
			}
			if (setqueens(n)) {
				return true;//如果之后可以成功落子返回真
			}
			else {
				n--;
				chessboard[n][theline] = '*';//否则说明该位置不合理，搜索下一个；
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
	//初始化棋盘
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			chessboard[i][j] = '*';
		}
	}

	//开始落子；
	setqueens(0);

	//展示棋盘；
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::cout << chessboard[i][j] << ' ';
		}
		std::cout << '\n' << '\n';
	}
    return 0;
}

