/*在中国象棋中，炮是按照一定规则进行移动的。对于一个给定的位置，炮每次移动之后可以到达的位置如下图所示

炮在棋盘上移动遵循以下三个原则
1. 正常情况下，只能沿着上下左右四个方向直线移动，遇到己方或者对方棋子就停止
2. 当吃对方棋子时，己方和对方的棋子中间必须是沿着上下左右只间隔1个棋子 （间隔的棋子可以是己方或者对方的）
3. 不能吃自家棋子
输入
输入炮棋子位置x,y
再输入10*9的棋盘数组，用空格隔开，其中0表示空白，1表示本方棋子，2表示对方棋子
输出
当前情况下，炮棋子能移动到的位置用3标记，输出棋盘，注意输出时不需要以空格分隔
样例输入 Copy
3 4
0 0 2 2 2 0 0 0 0
0 0 0 0 2 2 0 0 0
0 0 0 0 2 0 0 0 0
0 0 0 0 1 0 0 1 0
0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
1 0 0 1 0 1 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0
样例输出 Copy
002220000
000032000
000020000
333313310
000030000
001030000
000030000
100131000
000030000
000010000*/

#include<iostream>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<stdio.h>
#include<math.h>
#include<string>
using namespace std;
int x, y;
int plat[10][9];
int main() {
    while (cin >> x >> y) {
        int flag = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> plat[i][j];
            }
        }
        for (int i = x + 1; i < 10; i++) {
            if (flag == 0) {
                if (plat[i][y] == 0)plat[i][y] = 3;
                else if (plat[i][y] == 1 || plat[i][y] == 2)flag = 1;
            }
            else if (flag == 1) {
                if (plat[i][y] == 1)break;
                if (plat[i][y] == 2) {
                    plat[i][y] = 3;
                    break;
                }

            }
        }
        flag = 0;
        for (int i = x - 1; i >= 0; i--) {
            if (flag == 0) {
                if (plat[i][y] == 0)plat[i][y] = 3;
                else if (plat[i][y] == 1 || plat[i][y] == 2)flag = 1;
            }
            else if (flag == 1) {
                if (plat[i][y] == 1)break;
                if (plat[i][y] == 2) {
                    plat[i][y] = 3;
                    break;
                }

            }
        }
        flag = 0;
        for (int i = y - 1; i >= 0; i--) {
            if (flag == 0) {
                if (plat[x][i] == 0)plat[x][i] = 3;
                else if (plat[x][i] == 1 || plat[x][i] == 2)flag = 1;
            }
            else if (flag == 1) {
                if (plat[x][i] == 1)break;
                if (plat[x][i] == 2) {
                    plat[x][i] = 3;
                    break;
                }

            }
        }
        flag = 0;
        for (int i = y + 1; i < 9; i++) {
            if (flag == 0) {
                if (plat[x][i] == 0)plat[x][i] = 3;
                else if (plat[x][i] == 1 || plat[x][i] == 2)flag = 1;
            }
            else if (flag == 1) {
                if (plat[x][i] == 1)break;
                if (plat[x][i] == 2) {
                    plat[x][i] = 3;
                    break;
                }

            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                cout << plat[i][j];
            }
            cout << endl;
        }
    }
}
