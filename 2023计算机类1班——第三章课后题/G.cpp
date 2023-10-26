/*已知用梯形法求积分的公式为
其中 h = ( b-a ) / n，n为积分区间的等分数，编程求如下积分的值。要求把求积分公式编写成一个函数，并使用函数指针作为形式参数。调用该函数时，给定不同的被积函数作为实际参数求不同的积分。
（注意这里的n为10000，程序需要求出下面的三个积分的值）
(图又没了！抱歉！)
输入
无
输出
三个积分的值（显示在一行，以一个空格间隔）
*/

#include<iostream>
#include<math.h>
#define n 10000
using namespace std;
double T1(double a, double b, double fa, double fb) {
	double h = (b - a) / n,T;
	T = h * (fa + fb) / 2;
	for (int i = 1; i < n; i++) {
		T += h * 4.0/(1+(a+i*h)* (a + i * h));
	}
	return T;
}
double T2(double a, double b, double fa, double fb) {
	double h = (b - a) / n, T;
	T = h * (fa + fb) / 2;
	for (int i = 1; i < n; i++) {
		T += h * sqrt(1+pow((a + i * h),2));
	}
	return T;
}
double T3(double a, double b, double fa, double fb) {
	double h = (b - a) / n, T;
	T = h * (fa + fb) / 2;
	for (int i = 1; i < n; i++) {
		T += h * sin(a+i*h);
	}
	return T;
}
int main(){
	cout << T1(0, 1, 4, 2)<<" ";
	cout << T2(1, 2, sqrt(2), sqrt(5))<<" ";
	cout << T3(0, 1.570796, 0, 1);
	system("pause");
}
