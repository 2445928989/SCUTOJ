/*题目描述
已知Sn=1 + 1/2 + 1/3 + ... + 1/n。显然对于任意一个整数K，当n足够大的时候，Sn大于K。现给出一个整数K（1 <= K <= 15），要求计算出一个最小的n，使得Sn > K。
输入
多组输入。每组一行，每行输入一个整数K（1 <= K <= 15）。
输出
每组输出一个整数n。
样例输入 Copy
2
7
样例输出 Copy
4
616*/

#include<iostream>
using namespace std;
int main()
{
    int k;
    while (cin >> k) {
        double s = 0;
        int n = 0;
        while (s <= k)
        {   
            n += 1;
            s += double(1) / n;
        }
        cout << n << endl;
    }
    return 0;
}
