/*题目描述
编程模拟“剪刀、石头、布”游戏。游戏规则为:剪刀剪布，石头砸剪刀，布包石头。游戏者从键盘输入s(表示剪刀)或r(表示石头)或p(表示布)，要求两个游戏者交替输入，计算机给出输、赢的信息
输入
甲方乙方猜拳的信息
输出
输赢的信息，三种情况甲方胜、乙方胜、平局
样例输入 Copy
s r
s s
样例输出 Copy
乙方胜
平局*/

#include<iostream>
using namespace std;
int main()
{
    char a, b;
        while (cin >> a >> b) {
        if (a == 's' && b == 'p') cout << "甲方胜" << endl;
        else if (a == 'r' && b == 's')cout << "甲方胜" << endl;
        else if (a == 'p' && b == 'r')cout << "甲方胜" << endl;
        else if (b == 'p' && a == 'r')cout << "乙方胜" << endl;
        else if (b == 's' && a == 'p')cout << "乙方胜" << endl;
        else if (b == 'r' && a == 's')cout << "乙方胜" << endl;
        else cout << "平局" << endl;
    }
    return 0;
}
