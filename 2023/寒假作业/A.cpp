/*题目描述
设计一个程序实现两个任意长的整数（包括正数和负数）、任意精度实数的加减运算，其中以“-”号开头的为负数。
输入
第一行为一个数字n，表示待计算的组数
接下来为3n行内容，每组内容有3行，第一行表示做加法还是减法，第二三行为两个数字，每次取一组内容来计算。
输出
共有n行，每行要换行。
样例输入 Copy
2
+
1,111,111,111,111,111,111,111,111,111,111,111,111
222,222,222,222,222,222,222,222,222,222,222,222
+
-12,345,678,901,234,567,890,123,456,789,012,345,678,901,234,567,890
98,765,432,198,765,432,198,765,432,198,765,432,198,765,432,198,765
样例输出 Copy
1,333,333,333,333,333,333,333,333,333,333,333,333
86,419,753,297,530,864,308,641,975,409,753,086,519,864,197,630,875*/

/*加法：将输入转换成字符串，反转后逐位相加，进位+1，最后按格式输出即可。
减法：同上，但需要判断正负，反转后逐位相减，某位小于减数的对应位时借1当10*/

#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
//#define mian main //不要直接抄。
using namespace std;
int n;
char c;
string str1, str2;
void splus() {
    bool flag = 0;
    string A, B;
    for (int i = 0; i < str1.length(); i++)if (str1[i] >= '0' && str1[i] <= '9')A.push_back(str1[i]);
    for (int i = 0; i < str2.length(); i++)if (str2[i] >= '0' && str2[i] <= '9')B.push_back(str2[i]);
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    if ((str1[0] == '-' && str2[0] == '-') || (str1[0] != '-' && str2[0] != '-')) {
        flag = 1;
    }
    if (flag) {
        while (A.length() != B.length()) {
            if (A.length() < B.length()) {
                A.push_back('0');
            }
            else {
                B.push_back('0');
            }
        }
        A.push_back('0');
        B.push_back('0');
        for (int i = 0; i < A.length() - 1; i++) {
            A[i] += B[i] - '0';
            if (A[i] > '9') {
                A[i + 1]++;
                A[i] -= 10;
            }
        }
        if (A[A.length() - 1] == '0')A.pop_back();
        for (int i = 1; 4 * i - 1 < A.length(); i++) {
            A.insert(4 * i - 1, ",");
        }
        reverse(A.begin(), A.end());
        if (str1[0] == '-')cout << '-' << A << endl;
        else cout << A << endl;
    }
    else {
        bool big = 0;
        if (str1[0] == '-') {
            swap(A, B);
        }
        if (B.length() > A.length()) {
            big = 1;
        }
        else if (B.length() == A.length()) {
            for (int i = A.length() - 1; i >= 0; i--) {
                if (A[i] > B[i])break;
                else if (A[i] < B[i]) {
                    big = 1;
                    break;
                }
            }
        }
        if (big)swap(A, B);
        while (B.length() < A.length()) {
            B.push_back('0');
        }
        for (int i = 0; i < A.length(); i++) {
            if (A[i] >= B[i])A[i] -= B[i] - '0';
            else {
                A[i] += 10;
                A[i + 1]--;
                A[i] -= B[i] - '0';
            }
        }
        for (int i = A.length() - 1; i > 0; i--) {
            if (A[i] == '0')A.pop_back();
            else break;
        }
        for (int i = 1; 4 * i - 1 < A.length(); i++) {
            A.insert(4 * i - 1, ",");
        }
        reverse(A.begin(), A.end());
        if (big)cout << '-';
        cout << A << endl;
    }
}
void sredu() {
    bool flag = 0;
    string A, B;
    for (int i = 0; i < str1.length(); i++)if (str1[i] >= '0' && str1[i] <= '9')A.push_back(str1[i]);
    for (int i = 0; i < str2.length(); i++)if (str2[i] >= '0' && str2[i] <= '9')B.push_back(str2[i]);
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    if ((str1[0] != '-' && str2[0] == '-') || (str1[0] == '-' && str2[0] != '-')) {
        flag = 1;
    }
    if (flag) {
        while (A.length() != B.length()) {
            if (A.length() < B.length()) {
                A.push_back('0');
            }
            else {
                B.push_back('0');
            }
        }
        A.push_back('0');
        B.push_back('0');
        for (int i = 0; i < A.length() - 1; i++) {
            A[i] += B[i] - '0';
            if (A[i] > '9') {
                A[i + 1]++;
                A[i] -= 10;
            }
        }
        if (A[A.length() - 1] == '0')A.pop_back();
        for (int i = 1; 4 * i - 1 < A.length(); i++) {
            A.insert(4 * i - 1, ",");
        }
        reverse(A.begin(), A.end());
        if (str1[0] == '-')cout << '-' << A << endl;
        else cout << A << endl;
    }
    else {
        bool big = 0;
        if (B.length() > A.length()) {
            big = 1;
        }
        else if (B.length() == A.length()) {
            for (int i = A.length() - 1; i >= 0; i--) {
                if (A[i] > B[i])break;
                else if (A[i] < B[i]) {
                    big = 1;
                    break;
                }
            }
        }
        if (big)swap(A, B);
        while (B.length() < A.length()) {
            B.push_back('0');
        }
        for (int i = 0; i < A.length(); i++) {
            if (A[i] >= B[i])A[i] -= B[i] - '0';
            else {
                A[i] += 10;
                A[i + 1]--;
                A[i] -= B[i] - '0';
            }
        }
        for (int i = A.length() - 1; i > 0; i--) {
            if (A[i] == '0')A.pop_back();
            else break;
        }
        for (int i = 1; 4 * i - 1 < A.length(); i++) {
            A.insert(4 * i - 1, ",");
        }
        reverse(A.begin(), A.end());
        if ((str1[0] != '-' && big) || (str1[0] == '-' && !big))cout << '-';
        cout << A << endl;
    }
}
int mian() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> c >> str1 >> str2;
            if (c == '+')splus();
            if (c == '-')sredu();
        }
    }
    return 0;
}
//不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄
