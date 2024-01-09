/*题目描述
设计一个程序实现两个任意长的数（包括正数和负数）、任意精度实数的加减运算，其中以“-”号开头的为负数。

输入
第一行为一个数字n，表示待计算的组数

接下来为3n行内容，每组内容有3行，第一行表示做加法还是减法，第二三行为两个数字，每次取一组内容来计算。

输出
共有n行，每行要换行,小数末尾不保留0,若小数点后都为0则不要小数点。

样例输入 Copy
4
+
1,111,111,111,111,111,111,111,111,111,111,111,111
222,222,222,222,222,222,222,222,222,222,222,222
+
-12,345,678,901,234,567,890,123,456,789,012,345,678,901,234,567,890
98,765,432,198,765,432,198,765,432,198,765,432,198,765,432,198,765
+
3.14159265358979384626
6.66666666666666666666666
-
-41,829,471,284,124,414.49104801248981284
-64,580,569,452,374,277.12783183148912947
样例输出 Copy
1,333,333,333,333,333,333,333,333,333,333,333,333
86,419,753,297,530,864,308,641,975,409,753,086,519,864,197,630,875
9.80825932025646051292666
22,751,098,168,249,862.63678381899931663
提示
*/

/*与上一题不同的是，需要在输入时记录小数点位数，分别逐位相加/相减正数与小数部分，最后输出即可。*/

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
    int pos1 = str1.length(), pos2 = str2.length();
    bool flag = 0;
    string A, B, A1, B1;
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] >= '0' && str1[i] <= '9')A.push_back(str1[i]);
        if (str1[i] == '.') {
            pos1 = i;
            break;
        }
    }
    for (int i = 0; i < str2.length(); i++) {
        if (str2[i] >= '0' && str2[i] <= '9')B.push_back(str2[i]);
        if (str2[i] == '.') {
            pos2 = i;
            break;
        }
    }
    for (int i = pos1; i < str1.length(); i++) {
        if (str1[i] >= '0' && str1[i] <= '9')A1.push_back(str1[i]);
    }
    for (int i = pos2; i < str2.length(); i++) {
        if (str2[i] >= '0' && str2[i] <= '9')B1.push_back(str2[i]);
    }
    while (A1.length() != B1.length()) {
        if (A1.length() < B1.length()) {
            A1.push_back('0');
        }
        else {
            B1.push_back('0');
        }
    }
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    reverse(A1.begin(), A1.end());
    reverse(B1.begin(), B1.end());
    //cout << A1 << " " << B1 << endl;
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
        for (int i = 0; i < A1.length(); i++) {
            A1[i] += B1[i] - '0';
            if (A1[i] > '9') {
                if (i != A1.length() - 1) {
                    A1[i + 1]++;
                    A1[i] -= 10;
                }
                else {
                    A1[i] -= 10;
                    A[0]++;
                }
            }
        }
        A1.push_back('.');
        reverse(A1.begin(), A1.end());
        while (!A1.empty() && (A1.back() == '0' || A1.back() == '.'))A1.pop_back();
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
        if (str1[0] == '-')cout << '-';
        cout << A << A1 << endl;
    }
    else {
        bool big = 0;
        if (str1[0] == '-') {
            swap(A, B);
            swap(A1, B1);
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
        if (big) {
            swap(A, B);
            swap(A1, B1);
        }
        while (B.length() < A.length()) {
            B.push_back('0');
        }
        for (int i = 0; i < A1.length(); i++) {
            if (A1[i] >= B1[i])A1[i] -= B1[i] - '0';
            else {
                if (i != A1.length() - 1) {
                    A1[i] += 10;
                    A1[i + 1]--;
                    A1[i] -= B1[i] - '0';
                }
                else {
                    A1[i] += 10;
                    A[0]--;
                    A1[i] -= B1[i] - '0';
                }
            }
        }
        A1.push_back('.');
        reverse(A1.begin(), A1.end());
        while (!A1.empty() && (A1.back() == '0' || A1.back() == '.'))A1.pop_back();
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
        cout << A << A1 << endl;
    }
}
void sredu() {
    int pos1 = str1.length(), pos2 = str2.length();
    bool flag = 0;
    string A, B, A1, B1;
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] >= '0' && str1[i] <= '9')A.push_back(str1[i]);
        if (str1[i] == '.') {
            pos1 = i;
            break;
        }
    }
    for (int i = 0; i < str2.length(); i++) {
        if (str2[i] >= '0' && str2[i] <= '9')B.push_back(str2[i]);
        if (str2[i] == '.') {
            pos2 = i;
            break;
        }
    }
    for (int i = pos1; i < str1.length(); i++) {
        if (str1[i] >= '0' && str1[i] <= '9')A1.push_back(str1[i]);
    }
    for (int i = pos2; i < str2.length(); i++) {
        if (str2[i] >= '0' && str2[i] <= '9')B1.push_back(str2[i]);
    }
    while (A1.length() != B1.length()) {
        if (A1.length() < B1.length()) {
            A1.push_back('0');
        }
        else {
            B1.push_back('0');
        }
    }
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    reverse(A1.begin(), A1.end());
    reverse(B1.begin(), B1.end());
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
        for (int i = 0; i < A1.length(); i++) {
            A1[i] += B1[i] - '0';
            if (A1[i] > '9') {
                if (i != A1.length() - 1) {
                    A1[i + 1]++;
                    A1[i] -= 10;
                }
                else {
                    A1[i] -= 10;
                    A[0]++;
                }
            }
        }
        A1.push_back('.');
        reverse(A1.begin(), A1.end());
        while (!A1.empty() && (A1.back() == '0' || A1.back() == '.'))A1.pop_back();
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
        if (str1[0] == '-')cout << '-';
        cout << A << A1 << endl;
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
        if (big) {
            swap(A, B);
            swap(A1, B1);
        }
        while (B.length() < A.length()) {
            B.push_back('0');
        }
        for (int i = 0; i < A1.length(); i++) {
            if (A1[i] >= B1[i])A1[i] -= B1[i] - '0';
            else {
                if (i != A1.length() - 1) {
                    A1[i] += 10;
                    A1[i + 1]--;
                    A1[i] -= B1[i] - '0';
                }
                else {
                    A1[i] += 10;
                    A[0]--;
                    A1[i] -= B1[i] - '0';
                }
            }
        }
        A1.push_back('.');
        reverse(A1.begin(), A1.end());
        while (!A1.empty() && (A1.back() == '0' || A1.back() == '.'))A1.pop_back();
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
        cout << A << A1 << endl;
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
//不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄
