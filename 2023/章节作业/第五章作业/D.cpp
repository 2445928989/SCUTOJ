/*题目描述
设计函数，不使用辅助数组，实现两个 int 型或 double 型数组中数据的快速交换。
输入
一个整数，代表四个数组的长度，两个整型数组，两个double型数组
输出
交换后的四个数组（每一个数组结束需要换行）
样例输入 Copy
5
1 2 3 4 5
6 9 8 7 10
1.1 2.2 3.3 4.4 5.5
6.6 7.7 8.8 9.9 10.1
3
5 6 9
12 23 56
2.6 5.9 9.5
6.6 55.5 66.6
样例输出 Copy
6 9 8 7 10
1 2 3 4 5
6.6 7.7 8.8 9.9 10.1
1.1 2.2 3.3 4.4 5.5
12 23 56
5 6 9
6.6 55.5 66.6
2.6 5.9 9.5*/

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
    int l;
    int *i1p, *i2p;
    double *d1p, *d2p;
    while (cin >> l)
    {
        i1p = new int[l];
        i2p = new int[l];
        d1p = new double[l];
        d2p = new double[l];
        for (int i = 0; i < l; i++) {
            cin >> i1p[i];
        }
        for (int i = 0; i < l; i++) {
            cin >> i2p[i];
        }
        for (int i = 0; i < l; i++) {
            cin >> d1p[i];
        }
        for (int i = 0; i < l; i++) {
            cin >> d2p[i];
        }
        for (int j = 0; j < l; j++) {
            SW(i1p[j], i2p[j]);
        }
        for (int j = 0; j < l; j++) {
            SW(d1p[j], d2p[j]);
        }
        for (int j = 0; j < l; j++) {
            cout << i1p[j]<<" ";
        }
        cout << endl;
        for (int j = 0; j < l; j++) {
            cout << i2p[j]<<" ";
        }
        cout << endl;
        for (int j = 0; j < l; j++) {
            cout << d1p[j]<<" ";
        }
        cout << endl;
        for (int j = 0; j < l; j++) {
            cout << d2p[j]<<" ";
        }
        cout << endl;
        delete[]i1p;
        delete[]i2p;
        delete[]d1p;
        delete[]d2p;
        i1p = NULL;
        i2p = NULL;
        d1p = NULL;
        d2p = NULL;
    }
}
