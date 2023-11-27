/*题目描述
给你一个正整数x，请你将它按照位分割成两个非负整数 x1和 x2，满足：x1和x2的和最小，上述得到的整数没有前导 0。10 ≤ x  ≤  1 000 000 000，超出范围的输出 -1。
输入
正整数 x
4325 
输出
最小分割和
68
解释： 43+25 = 68
样例输入 Copy
4325
10234
1000000001
样例输出 Copy
68
136
-1
提示
循环输入 while(cin >> x) {}
x,x1,x2 没有前导0。例如： 00123=123。*/

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int x, num1, num2, min = 999999999;
	int y, z;
	while (cin >> x)
	{
		int n = 0; int s = 0;
		if (x < 10 || x>1000000000)
		{
			cout << "-1" << endl;
		}
		else if (x >= 10 && x <= 1000000000)
		{
			y = x;
			while (y > 0)
			{
				y /= 10;
				n++;
			}
			for (int i = 1; i < n; i++) {
				int p = pow(10, i);
				num1 = x / p;
				num2 = x % p;
				if (num1 + num2 < min)min = num1 + num2;
			}
			cout << min << endl;
			min = 99999999999;
		}
	}
}
