/*题目描述
用矩阵存储图像，矩阵中的每个元素为图像元素，简称像素，给定两个像素p,q的坐标分别为：(x,y)、(s,t)；p和q之间的D4距离（也叫城市街区距离）定义为:D4(p,q)=|x-s|+|y-t|.
根据这个距离度量，与点(x,y)的D4距离小于或等于某一值d的像素组成以(x, y)为中心的菱形, 如图所示。

给定像素位置点(x,y)及d，求与点(x,y)的D4距离小于或等于d的所有其他像素值之和，注意像素坐标是否越界,各个位置具体的像素值为 (a+b) mod 2，其中(a,b)表示像素的坐标，从0开始, 图像的尺寸为 224 * 224 。

输入
像素位置点(x,y)和d，用空格分开
输出
与点(x,y)的D4距离小于或等于d的其他像素值之和
样例输入 Copy
2 3 2
0 0 7
220 1 6
样例输出 Copy
8
20
28
提示
输入 使用while(cin >> x >> y >> d){}*/

#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int x, y, d;
	while (cin >> x >> y >> d) {
		int sum = 0;
		for (int i = max(x - d, 0); i <= min(x + d, 223); i++) {
			for (int j = max(y - d, 0); j <= min(y + d, 223); j++) {
				if (i == x && j == y)continue;
				if (abs(i - x) + abs(j - y) <= d)sum += (i + j) % 2;
			}
		}
		cout << sum << endl;
	}


}
