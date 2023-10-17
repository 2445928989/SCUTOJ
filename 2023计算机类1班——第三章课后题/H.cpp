/*题目描述
使用重载函数编程序分别把两个数和三个数从大到小排列。
输入
五个数字（前面两个数字为一组，后面三个数字为一组）
输出
从大到小排列后的数字（组内数字之间以一个空格间隔，组与组之间换行符间隔）
样例输入 Copy
56 79 0.5 30.8 5.9
2.3 5 10 23 60
样例输出 Copy
79 56
30.8 5.9 0.5
5 2.3
60 23 10*/

#include <iostream>
using namespace std;
void paixu(double a, double b) {
	if (a > b)cout << a << " " << b << endl;
	else cout << b << " " << a << endl;
}
void paixu(double arr[]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2 - i; j++) {
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}
	cout << arr[2] << " " << arr[1] << " " << arr[0] << endl;
}
int main(){
	double a, b, arr[3];
	while (cin >> a >> b >> arr[0] >> arr[1] >> arr[2]) {
		paixu(a, b);
		paixu(arr);
	}
	system("pause");
}
