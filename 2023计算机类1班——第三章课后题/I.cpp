/*题目描述
给定求组合数公式为
(没了，我相信你一定知道它！）
编一程序，输入m和 n的值，求Cmn  的值。注意优化算法（公式在代码中的计算表达），降低溢出可能。要求主函数调用以下函数求组合数：
int Fabricate ( int m, int n ) ;       //返回Cmn的值
Fabricate 函数内又须调用 Multi函数：
int Multi ( int m, int n ) ;             //返回 mxm-1×…× n
程序由4个文件组成。头文件存放函数原型作为调用接口；其他3个 cpp 文件分别是 main,Fabricate和 Multi函数的定义。（oj平台无法提交四个文件，因此写一段代码就行，但是需要定义好题目所说的函数）
输入
两个数m,n
输出
Fabricate函数的返回值，也就是组合计算的结果
样例输入 Copy
15 12
15 3
12 6
5 4
样例输出 Copy
455
455
924
5*/
  
#include <iostream>
using namespace std;
int Multi(int m, int n) {
	int a = 1;
	for (int i = n; i <= m; i++) {
		a *= i;
	}
	return a;
}
int Fabricate(int m, int n) {
	if (n > (m / 2)) return Multi(m, n + 1) / Multi(m-n, 1);
	else return Multi(m, m - n+1) / Multi(n, 1);
}
int main(){
	int m, n;
	while (cin >> m >> n) {
		cout << Fabricate(m, n) << endl;
	}
	system("pause");
}
