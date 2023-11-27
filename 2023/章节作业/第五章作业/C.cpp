/*题目描述
设计重载函数，使用按位异或 (^) 运算，实现快速交换两个整型变量和浮点型变量的值
输入
两个整数以及两个浮点数（均空格间隔）
输出
交换后的结果（各个数之间以空格间隔）
样例输入 Copy
2 3 5.3 6.2
5 6 33.9 99.5
样例输出 Copy
3 2 6.2 5.3
6 5 99.5 33.9*/

#include<iostream>
using namespace std;
void SW(int& a,int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}
void SW(double& a, double& b) {
    int* p = (int*)(&a);
    int* q = (int*)(&b);
    *p ^= *q;
    *q ^= *p;
    *p ^= *q;
    p++; q++;
    *p ^= *q;
    *q ^= *p;
    *p ^= *q;
}
int main()
{
    int i1, i2;
    double d1, d2;
    while (cin >> i1>>i2>>d1>>d2)
    {
        SW(i1, i2);
        SW(d1, d2);
        cout << i1 << " " << i2 <<" "<< d1 << " " << d2 << endl;
    }
}
