/*题目描述
N个同学参加跳远，每个同学有两次机会，已知参加跳远的学生学号和成绩，寻找并输出冠军，亚军，季军。
输入
先输入同学数N
接着输入2*N组数据，每组数组分别是同学的学号和成绩，用空格隔开，输入的数据已经确保不会有并列成绩
输出
每组输出3行数据，从上到下依次是冠，亚，季军，每行数据包括同学的姓名和成绩，用空格隔开


学号为8位 ，同学数N已经确保3<N<20
必须使用的关键字
struct 
样例输入 Copy
6
20230001 2.51
20230002 2.60
20230003 2.10
20230004 2.49
20230005 2.42
20230006 2.57
20230001 2.39
20230002 2.62
20230003 2.41
20230004 2.39
20230005 2.45
20230006 2.53
样例输出 Copy
20230002 2.62
20230006 2.57
20230001 2.51
提示
2^31-1 =  2147483647

已经告知数组长度的上限，如果不会申请动态数组，不妨每次直接申请上限长度的数组来存储数据，多余的位置可以闲置不用

一个人不能独占多个名次，即使一个人两次的成绩都是最好，也不能包揽冠亚军*/

#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct person {
	string number;
	double score;
	bool operator < (const person other)const {
		return score < other.score;
	}
}p1;
vector<person>v1;
int n;
int main() {
	while (cin >> n) {
		for (int i = 0; i < 2 * n; i++) {
			cin >> p1.number >> p1.score;
			bool flag = 0;
			for (int j = 0; j < v1.size(); j++) {
				if (v1[j].number == p1.number) {
					if (v1[j].score < p1.score) {
						v1[j].score = p1.score;
					}
					flag = 1;
				}
			}
			if (flag == 0) {
				v1.push_back(p1);
			}
		}
		sort(v1.begin(), v1.end());
		for (int i = v1.size()-1; i > v1.size() - 4; i--) {
			cout << v1[i].number << " " << v1[i].score << endl;
		}
		v1.clear();
	}
}
