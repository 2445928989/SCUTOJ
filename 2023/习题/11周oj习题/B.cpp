/*题目描述
某班学生学号按入学考试成绩由高到低从1到n(n为人数)编号。现期末考试成绩已统计好，老师欲分析每位同学的进、退步情况，请你编程解决该问题。
输入
一个int和一个char，
第1行：一个int n，表示学生人数（n<99）
第2行：n个int，表示按学号升序排列的n 个学生的期末考试成绩
输出
n个int，按学号顺序表示的每位同学的进、退步名次（为负表示退步、为正表示进步、为0表示既没有进步也没有退步）
样例输入 Copy
3 
99 98 92
4
91 92 92 94
6
90 95 96 93 92 94
样例输出 Copy
0 0 0
-3 0 1 3
-5 0 2 0 0 3*/

#include<iostream>
using namespace std;
int a[100][3];
int n;
int main() {
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> a[i][0];
			a[i][1] = i + 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (a[j][0] < a[j + 1][0]) {
					swap(a[j][0], a[j + 1][0]);
					swap(a[j][1], a[j + 1][1]);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (a[i][0] == a[i - 1][0]) a[i][2] = a[i - 1][2];
			else a[i][2] = i + 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (a[j][1] > a[j + 1][1]) {
					swap(a[j][0], a[j + 1][0]);
					swap(a[j][1], a[j + 1][1]);
					swap(a[j][2], a[j + 1][2]);
				}
			}
		}
		for (int i = 0; i < n; i++)cout << a[i][1] - a[i][2] << " ";
		cout << endl;
	}
}
