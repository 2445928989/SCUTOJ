/*题目描述
已知勒让德多项式如下图，
 (图没了不好意思..百度吧，第一个就是)
编一程序，从键盘上输入 x和n的值，使用递归函数求pn(x)的值。
输入
x、n
输出
pn(x)的值
样例输入 Copy
222 0
222 1
52 5
-99 3
样例输出 Copy
1
222
117.45
-182.333*/

#include<iostream>
using namespace std;
int main()
{
	double x;
	int n;
	while (cin >> x >> n) {
		double p[3] = { 1,x,0 };
		for (int i = 2; i <= n; i++) {
			p[i % 3] = (p[(i - 1) % 3] * (2 * i - 1) - p[(i + 1) % 3] * (i - 1)) / i;
		}
		cout << p[n % 3]<<endl;
	}
	system("pause");
}
