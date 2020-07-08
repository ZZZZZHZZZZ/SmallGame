#include <iostream>
#include <vector>
#include <stdio.h>
#include <conio.h>
using namespace std;
void paintCheckboard(const vector<vector<int>>& checkerboard);//绘制棋盘
void Luozi(vector<vector<int>>& checkerboard, const int& userID);//落子
int main() {
	vector<vector<int>> checkerboard (15, vector<int>(15, 0));//用于存储棋盘，初始化为15*15的0，设置1为白棋，2为黑棋,3为落子位置
	paintCheckboard(checkerboard);
	//for (int i = 0; i < checkerboard.size()-5; ++i) {
	//	checkerboard[i][i] = 1;
	//	checkerboard[i + 1][i] = 2;
	//}
	//checkerboard[7][7] = 3;
	while (true) {
		Luozi(checkerboard, 1);
		Luozi(checkerboard, 2);
	}
}
void Luozi(vector<vector<int>>& checkerboard, const int &userID) {
	int currentX = 14, currentY = 14;
	bool flag = false;
	while (true) {
		while (checkerboard[currentX][currentY] != 0 && currentX > 0) {
			--currentX;
		}
		if (checkerboard[currentX][currentY] == 0) {
			break;
		}
		--currentY;
		while (checkerboard[currentX][currentY] != 0 && currentX < 14) {
			++currentX;
			if (checkerboard[currentX][currentY] == 0) {
				flag = true;
			}
		}
		if (checkerboard[currentX][currentY] == 0) {
			break;
		}
		--currentY;
	}

	checkerboard[currentX][currentY] = 3;
	system("cls");
	paintCheckboard(checkerboard);
	while (true) {
		char X = _getch();
		if (X == 'w' || X == 'W') {
			if (currentX == 0) {
				continue;
			}
			bool flag = false;
			int temp = currentX;
			while (temp > 0) {
				--temp;
				if (checkerboard[temp][currentY] == 0) {
					flag = true;
					break;
				}
			}
			if (flag == false) {
				continue;
			}
				checkerboard[currentX][currentY] = 0;
				currentX = temp;
			    checkerboard[currentX][currentY] = 3;		
		}
		else if (X == 's' || X == 'S') {
			if (currentX == 14) {
				continue;
			}
			bool flag = false;
			int temp = currentX;
			while (temp < 14) {
				++temp;
				if (checkerboard[temp][currentY] == 0) {
					flag = true;
					break;
				}
			}
			if (flag == false) {
				continue;
			}
			checkerboard[currentX][currentY] = 0;
			currentX = temp;
			checkerboard[currentX][currentY] = 3;

		}
		else if (X == 'a'|| X=='A') {
			if (currentY == 0) {
				continue;
			}
			bool flag = false;
			int temp = currentY;
			while (temp>0) {
				--temp;
				if (checkerboard[currentX][temp] == 0) {
					flag = true;
					break;
				}
			}
			if (flag == false) {
				continue;
			}
			checkerboard[currentX][currentY] = 0;
			currentY = temp;
			checkerboard[currentX][currentY] = 3;
		}
		else if (X == 'd' || X == 'D') {
			if (currentY == 14) {
				continue;
			}
			bool flag = false;
			int temp = currentY;
			while (temp < 14) {
				++temp;
				if (checkerboard[currentX][temp] == 0) {
					flag = true;
					break;
				}
			}
			if (flag == false) {
				continue;
			}
			checkerboard[currentX][currentY] = 0;
			currentY = temp;
			checkerboard[currentX][currentY] = 3;
		}
		else if (X == ' ') {
			checkerboard[currentX][currentY] = userID;
			system("cls");
			paintCheckboard(checkerboard);
			break;
		}
		system("cls");
		paintCheckboard(checkerboard);
	}
}
void paintCheckboard(const vector<vector<int>> & checkerboard)  {
	for (auto line : checkerboard) {
		for (auto piece : line) {
			if (piece == 0) {
				cout << "·";
			}
			else if (piece == 1) {
				cout << "○";
			}
			else if (piece == 2) {
				cout << "●";
			}
			else if (piece == 3) {
				cout << "╋ ";
			}
		}
		cout << endl;
	}
}
