  /*题目描述
歌唱家在家唱歌”“水外天光山外树”“上海自来水来自海上”这三句话，从左往右读和从右往左读，结果完全相同，或者都有意思，这样的现象，文学上称为“回文”。数学与文学有相似之处，文学中有“回文”，数学上有“回文数”。比如 77，它无论从左往右，还是从右往左读，都是同一个数。再如 252、7887、34143，它们都是回文数。自然数中，回文数的个数并不多，两位数中只有 9 个，它们是 11、22、33、44、55、66、77、88、99。三位数中的也才 90 个。你知道吗？很多自然数虽然不是回文数，但只要施上一个“魔法”——把它与它的倒序数相加，就能让它“变成”回文数。比如
36+63 = 99


64+46 = 110
110+011 = 121


195+591 = 786
786+687 = 1473
1473+3741 = 5214
5214+4125 = 9339


现在给出一个位于0-1000的整数，请问通过16以及16次以内的以上操作，能让它变为回文数吗，如果可以，输出第一次得到的回文数，否则输出-1
输入
一个整数，位于0-1000
输出
回文数结果
样例输入 Copy
11
36
64
177
195
392
998
样例输出 Copy
11
99
121
8836886388
9339
2992
-1*/

#include<iostream>
#include<iomanip>
#include<string>
#include<map>
#include<algorithm>
#include<bitset>
#include<math.h>
using namespace std;
bool huiwen(string str) {
	string temp = str;
	reverse(temp.begin(), temp.end());
	return (str == temp);
}
void splus(string& str) {
	string temp = str;
	str += '0';
	reverse(temp.begin(), temp.end());
	temp += '0';
	for (int i = 0; i < str.length(); i++) {
		str[i] += temp[i] - 2 * '0';
		str[i + 1] += str[i] / 10;
		str[i] %= 10;
		str[i] += '0';
	}
	if (str[str.length() - 1] == '0')str.pop_back();
}
int main() {
	string M="0";
	while (cin >> M) {
		bool flag = 0;
		reverse(M.begin(), M.end());
		if (huiwen(M)) {
			cout << M << endl;
			flag = 1;
			continue;
		}
		for (int i = 1; i <= 16; i++) {
			splus(M);
			if (huiwen(M)) {
				cout << M << endl;
				flag = 1;
				break;
			}
		}
		if(flag==0)cout << "-1\n";
		string M="0";
	}
}
