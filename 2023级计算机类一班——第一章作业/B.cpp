/*题目描述
输入三个整数，求出其中最小数（要求使用条件表达式）
输入
三个整数：x，y，z
输出
其中最小的一个整数
样例输入 Copy
2 5 3
样例输出 Copy
2*/

#include<iostream>
using namespace std;
int main()
{   
    int x, y, z, min;
    while (cin >> x >> y >> z)
    {
        min = x <= y ? x : y;
        min = min <= z ? min : z;
        cout << min << endl;
    }
}
