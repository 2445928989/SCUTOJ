/*题目描述
给定一个仅包含字符 '('，')'，'{'，'}'，'[' 和 ']' 的字符串 s，判断输入字符串是否有效。
如果输入字符串有效，则：
开放括号必须由相同类型的括号关闭。
必须按正确顺序关闭开放括号。
每个关闭括号都有相应的相同类型的开放括号。
 
例1：
输入：s =“（{}）”
输出：true
 
例2：
输入：s =“（）[] {}”
输出：true
 
例3：
输入：s =“（]”
输出：false
样例输入 Copy

样例输出 Copy

来源/分类
 */

#include<iostream>
#include<stack>
#include<string>
using namespace std;
string str;
char c;
int num;
int main() {
	while (cin >> str) {
		bool flag = 0;
		int i = 0;
		if (str.length() % 2 == 1) {
			cout << "FALSE\n";
			continue;
		}
		int l = str.length();
		while (true) {
			bool find = 0;
			for (int i = 0; i < l; i++) {
				if (str[i] == ')') {
					num = i;
					c = '(';
					break;
				}
				if (str[i] == '}') {
					num = i;
					c = '{';
					break;
				}
				if (str[i] == ']') {
					num = i;
					c = '[';
					break;
				}
				if (i == l - 1) {
					flag = 1;
				}
			}
			int num1 = num;
			for (; num >= -1; num--) {
				if (num == -1) {
					break;
				}
				else {
					if (str[num] == c) {
						str[num] = '0';
						str[num1] = '0';
						find = 1;
					}
				}
			}
			if (find == 0) {
				break;
			}
			if (flag == 1) {
				break;
			}
		}
		cout << flag << endl;
	}
}
