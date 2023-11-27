/*题目描述
用带头结点的有序单向链表可以存放集合，如图所示。头结点不存放集合元素，仅为操作方便而设置。使用这种数据结构，设计集合的输入、输出和各种基本运算的函数。
输入
首先输入两个集合的长度，然后输入集合的元素
输出
输出集合的并集、交集、差集（第一个集合相对于第二个集合而言），每一行表示一个运算结果，集合之间用空格表示
样例输入 Copy
5 4
1 2 2 3 3
1 2 5 9
8 9
1 2 5 6 9 8 3 5
2 5 89 56 48 5 9 2 0
样例输出 Copy
1 2 3 5 9
1 2
3
0 1 2 3 5 6 8 9 48 56 89
2 5 9
1 3 6 8*/

#include <iostream>
using namespace std;
int n, m;
int a;
void put(unsigned a, unsigned A[10]) {
    int i = 0;
    while (a >= 32) {
        a -= 32;
        i++;
    }
    unsigned bit = 1 << a;
    A[i] |= bit;
}
void show(unsigned A[10]) {
    for (int i = 0; i < 10; i++) {
        unsigned bit = 1;
        for (int j = 0; j < 32; j++) {
            if (A[i] & bit) {
                cout << (32 * i + j) << " ";
            }
            bit <<= 1;
        }
    }
    cout << endl;
}
unsigned A[10], B[10], C[10], D[10], E[10];
int main()
{
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            cin >> a;
            put((unsigned)a, A);
        }
        for (int i = 0; i < m; i++) {
            cin >> a;
            put((unsigned)a, B);
        }
        for (int i = 0; i < 10; i++) {
            C[i] = A[i] & B[i];
        }
        for (int i = 0; i < 10; i++) {
            D[i] = A[i] | B[i];
        }
        for (int i = 0; i < 10; i++) {
            E[i] = A[i] - C[i];
        }
        show(D);
        show(C);
        show(E);
        for (int i = 0; i < 5; i++) {
            A[i] = 0;
            B[i] = 0;
        }
    }
    system("pause");
}//想不出来怎么用链表把无序数据变为有序。可能要比大小然后插入？时间复杂度爆了。。
