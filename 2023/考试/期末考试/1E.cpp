/*题目描述
两个单词如果包含相同的字母，次序不同，则称为字母易位词。判断两个单词是否是字母易位词，是输出Yes，不是输出No。
输入
两个不同的单词,都是小写字母。
输出
是否是字母易位词，是输出Yes，不是输出No
样例输入 Copy
silent
listen
split
lisp
样例输出 Copy
Yes
No
提示
使用 while(cin >> str1 >> str2){}进行输入*/

#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	string str1, str2;
	while (cin >> str1 >> str2) {
		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());
		if (str1 == str2)cout << "Yes\n";
		else cout << "No\n";	
	}
}
