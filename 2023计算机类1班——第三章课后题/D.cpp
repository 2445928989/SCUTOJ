/*题目描述
输入 a, b 和 c 的值，编写一个程序求这三个数中的最大值和最小值。要求：把求最大值和最小值的操作编写成一个函数，并使用指针或引用作为形式参数把结果返回 main 函数 。
输入
三个数
输出
最大的数和最小的数（如下，注意中间是一个空格）
Max（此处一个空格） = （此处一个空格）3 （此处一个空格）min（此处一个空格） =（此处一个空格） 1

样例输入 Copy
1 2 3
0.25955 -45665 0
样例输出 Copy
max = 3 min = 1
max = 0.25955 min = -45665*/

#include<iostream>
using namespace std;
double big(double a, double  b, double  c) {
	if (a > b) {
		if (a > c) return a;
		else return c;
	}
	else {
		if (b > c)return b;
		else return c;
	}
}
double small(double a, double b, double c) {
	if (a < b) {
		if (a < c) return a;
		else return c;
	}
	else {
		if (b < c)return b;
		else return c;
	}
}
int main()
{	
	double a, b, c,max,min;
	while (cin>>a>>b>>c) {
		max = big(a, b, c);
		min = small(a, b, c);
		cout << "max = " << max << " min = " << min << endl;
	}
	system("pause");
}
