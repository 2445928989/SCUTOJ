/*题目描述
有n 个玩家围成一圈，并按1到n编号。现从第1个玩家开始从1开始依次递增报数，报得的序号为素数的玩家出圈，直至所有玩家出圈。现需要确定出圈的顺序，请编程解决该问题。
输入
1个int，表示n个玩家
输出
n个int，表示出圈顺序
样例输入 Copy
3
5
7
样例输出 Copy
2 3 1 
2 3 5 4 1 
2 3 5 7 1 6 4*/

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int n;
bool sushu(int x) {
    if (x == 1)return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)return 0;
    }
    return 1;
}
int main() {
    while (cin >> n) {
        bool b[10000] = { 0 };
        int out = 0,turn=1;
        for (int i = 1;; i++) {
            if (out == n) {
                break;
            }
            if (turn == n + 1)turn = 1;
            if (b[turn] == 1) {
                i--;
                turn++;
                continue;
            }
            if (sushu(i)) {
                cout << turn << " ";
                b[turn] = 1;
                out++;
            }
            turn++;
            //cout << "数字:" << i << " 编号:" << turn << endl;
        }
        cout << endl;
    }
    system("pause");
}
