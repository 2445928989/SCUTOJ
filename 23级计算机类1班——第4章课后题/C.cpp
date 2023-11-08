/*题目描述
将一组数据从大到小排列后输出，要求显示每个元素及它们在原数组中的下标。
输入
一个长度为n的数组（int型）
输出
每个元素（一个空格间隔）在原数组中的下标
样例输入 Copy
8
1 2 3 4 5 67 8 20
9
9 8 7 6 5 4 3 2 1
样例输出 Copy
67 5
20 7
8 6
5 4
4 3
3 2
2 1
1 0
9 0
8 1
7 2
6 3
5 4
4 5
3 6
2 7
1 8
提示*/

#include <iostream>
#include<algorithm>
#include<map>
#include<string>
#include<math.h>
#include<iomanip>
using namespace std;
int n;
int a;
int main()
{
    while (cin>>n) {
        map<int, int>m1;
        for (int i = 0; i <n; i++) {
            cin >> a;
            m1.insert(pair<int, int>(a, i));
        }
        for (map<int, int>::iterator it = --m1.end(); it != --m1.begin(); it--) {
            cout << it->first << " " << it->second << endl;
        }
    }
}
//喜欢我map吗？(
