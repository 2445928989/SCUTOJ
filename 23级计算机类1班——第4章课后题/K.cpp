/*题目描述
一个整型数组的每个元素占 4 字节。编写一个压缩函数 pack，把一个无符号小整数 (0-255)数组进行压缩存储，只存放低 8 位;再编写一个解压函数 upack，把压缩数组展开，以整数形式存放。主函数手动输入数据以初始化数组，（注意使用动态数组），测试 pack 和 unpack 函数
输入
一个数组的长度及数组元素
输出
压缩前和压缩后的数组
样例输入 Copy
5
1 2 3 4 5
15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
样例输出 Copy
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15*/

#include<vector>
#include<iostream>
using namespace std;
int n,a;
vector<int>v1;
void pack() {
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
        *it = *it & 255;
        cout << *it << " ";
    }
    cout << endl;
}
int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a;
            v1.push_back(a);
        }
        for (vector<int>::iterator it = v1.begin(); it != v1.end();it++) {
            cout << *it << " ";
        }
        cout << endl;
        pack();
        v1.clear();
    }
}
//我无法理解这道题的题干。unpack函数有什么用？？？不应该是先输出压缩后的再输出解压后的吗？？
