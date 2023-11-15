/*题目描述
把某班学生的姓名和学号分别存放到两个数组中，从键盘输入某位学生的学号，查找该学生是否在该班中，若找到该学生，则显示出相应的姓名。
注意：两个数组是：// 学生姓名数组
char name[5][20] = { "li ming", "zhang qing", "liu xiao ping", "wang yin", "lu pei" };
// 学生编号数组
long num[5] = { 20030001, 20030002, 20030005, 20030007, 20030010 };

输入
一个学生的学号
输出
如果找到，则输出该学生的姓名
如果未找到，则输出：未找到该学生的信息。

样例输入 Copy
2003005
20030005
样例输出 Copy
未找到该学生的信息。
liu xiao ping*/

#include <iostream>
#include<algorithm>
#include<map>
#include<string>
#include<math.h>
#include<iomanip>
using namespace std;
char name[5][20] = { "li ming", "zhang qing", "liu xiao ping", "wang yin", "lu pei" };
long num[5] = { 20030001, 20030002, 20030005, 20030007, 20030010 };
int n;
int main()
{
    while (cin >> n) {
        bool flag = 0;
        for (int i = 0; i < 5; i++) {
            if (num[i] == n) {
                cout << name[i] << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)cout << "未找到该学生的信息。" << endl;
    }
}
