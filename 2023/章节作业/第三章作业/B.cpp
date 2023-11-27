/*题目描述
输入 m 、n和 p 的值 , 求
s=  (1+2+⋯+m+1^3+2^3+⋯+n^3)/(1^5+2^5+⋯+p^5 )
的值。注意判断运算中的溢出 。
输入
整数m,n,p的值
输出
s的值，当发生溢出的时候输出“溢出”两个字符。
样例输入 Copy
1 1 1
555 12 10
5555 5555 5555
样例输出 Copy
2
0.726249
溢出*/

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int m, n, p;
	while (cin >> m >> n >> p) {
		double s = 0, a = 0, b = 0, c = 0;
		for (int i = 1; i <= m; i++) a += i;
		for (int i = 1; i <= n; i++) b += pow(i, 3);
		for (int i = 1; i <= p; i++) c += pow(i, 5);
		s = (a + b) / c;
		if (a > 2147483647 || a < -2147483648 || b>2147483647 || b < -2147483648 || c>2147483647 || c < -2147483648)cout << "溢出" << endl;
		else cout<<s << endl;
	}
}
