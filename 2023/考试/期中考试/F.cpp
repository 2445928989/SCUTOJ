/*题目描述
输入一个正整数 n，输出一个沙漏形，这个沙漏形有 2n+1 行，第一行有 2n+1 个字母，其中前 n+1 个字符是从 A 开始依次递增的，而后 n 个字符是由第 n+1 个字符开始依次递减的。之后的 n行每行会少头尾两个字母。再之后的 n 行则正好是前 n 行反过来输出的结果。注意末尾不要有多余的输出。
输入
输入一个正整数 n（0<n<26）
输出
按照样例输出（注意图形是正中对齐的）
样例输入 Copy
2
样例输出 Copy
ABCBA  
  BCB  
   C 
  BCB 
 ABCBA*/

#include<iostream>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        char x = 'A';
        for (int i = 0; i < n; i++) {
            for (int x = 0; x < i; x++) {
                cout << " ";
            }
            for (int j = 0; j < 2 * n + 1 - 2 * i; j++) {
                if (j <= (2 * n + 1 - 2 * i) / 2)cout << (char)((int)x + j + i);
                if (j > (2 * n + 1 - 2 * i) / 2)cout << (char)((int)x - j + i + 2 * n + 1 - 2 * i - 1);
            }
            cout << endl;
        }
        for (int i = n; i >= 0; i--) {
            for (int x = 0; x < i; x++) {
                cout << " ";
            }
            for (int j = 0; j < 2 * n + 1 - 2 * i; j++) {
                if (j <= (2 * n + 1 - 2 * i) / 2)cout << (char)((int)x + j + i);
                if (j > (2 * n + 1 - 2 * i) / 2)cout << (char)((int)x - j + i + 2 * n + 1 - 2 * i - 1);
            }
            cout << endl;
        }
    }
    system("pause");
}