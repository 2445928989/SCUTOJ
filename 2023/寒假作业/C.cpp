/*题目描述
设计一个程序实现两个任意长的整数（包括正数和负数）、任意精度实数的乘除运算，其中以“-”号开头的为负数。

输入
第一行为一个数字n，表示待计算的组数

接下来为3n行内容，每组内容有3行，第一行表示做乘法还是除法，第二三行为两个数字，每次取一组内容来计算。

输出
共有n行，每行要换行,小数末尾不保留0,若小数点后都为0则不要小数点。

小数结果末尾最多保留10位小数，四舍五入，除数绝对值小于10(-6)则报ERROR

样例输入 Copy
3
*
12,345,678,901,234,567,890,123,456,789,012,345,678,901,234,567,890
12,345,678,901,234,567,890,123,456,789,012,345,678,901,234,567,890
/
1,234.567890123456789012
0.0000000000123
/
66,666,666,666,666,666,666,666,666,666,666.6666666666
-2
样例输出 Copy
152,415,787,532,388,367,504,953,515,625,666,819,450,083,828,733,757,049,236,500,533,455,762,536,198,787,501,905,199,875,019,052,100
ERROR
-33,333,333,333,333,333,333,333,333,333,333.3333333333
提示*/

/*乘法：记录小数点，逐位相乘（比如：114x514，先用514里的4分别乘4，1，1，保存，检查是否有需要进位，
再用1分别乘4，1，1，左移一位字符保存，检查是否有需要进位，最后用5分别乘4，1，1，左移两位字符保存检查是否有需要进位）
最后小数点的位置就是两个数的小数点后数位相加，记得保留10位小数。

除法：用减法模拟除法，当发现被除数的相应位数比除数大，相应位数减去被除数，结果的相应位置+1
（比如，3145/123,判断314大于123,于是314-123,答案里的十位+1，再用314-123=191和123对比，发现191>123,于是191-123，得68,答案里的十位数再+1
接着看下面的位数，判断0685>123，于是0685-123……直到得到答案的第十一位小数，最后四舍五入保留即可。（整除也不要紧，除去末尾0就可以了。））*/

#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
//#define mian main //不要直接抄。
using namespace std;
int n;
char c;
string str1, str2;
void mult() {
    string A, B;
    int pos1 = str1.length(), pos2 = str2.length();
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] >= '0' && str1[i] <= '9')A.push_back(str1[i]);
        else if (str1[i] == '.')pos1 = A.length();
    }
    while (A.length() > pos1 && A.back() == '0') {
        A.pop_back();
    }
    for (int i = 0; i < str2.length(); i++) {
        if (str2[i] >= '0' && str2[i] <= '9')B.push_back(str2[i]);
        else if (str2[i] == '.')pos2 = B.length();
    }
    while (B.length() > pos2 && B.back() == '0') {
        B.pop_back();
    }
    int pos = max((int)(A.length() + B.length() - pos1 - pos2), 0);
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    string C;
    C.resize(str1.size() + str2.size());
    for (int i = 0; i < B.length(); i++) {
        for (int j = 0; j < A.length(); j++) {
            C[i + j] += (A[j] - '0') * (B[i] - '0');
            C[i + j + 1] += C[i + j] / 10;
            C[i + j] %= 10;
        }
    }
    for (int i = 0; i < C.length(); i++) {
        C[i] += '0';
    }
    C.insert(pos, ".");
    while (C.back() == '0' && C.length() != pos + 2) C.pop_back();

    for (int i = 1; i * 4 < C.length() - pos; i++) {
        C.insert(i * 4 + pos, ",");
    }
    reverse(C.begin(), C.end());
    int l = C.length();
    if (pos > 10) {
        for (int i = l - 1; i > l - pos + 9; i--) {
            if (C[i] >= '5' && i == l - pos + 10)C[i - 1]++;
            C.pop_back();
        }
    }
    for (int i = C.length() - 1; i >= 0; i--) {
        if (C[i] == '.')continue;
        if (i == 0) {
            if (C[i] > '9') {
                C.insert(0, "1");
                C[1] -= 10;
            }
        }
        else if (C[i - 1] != '.' && C[i - 1] != ',') {
            if (C[i] > '9') {
                C[i - 1]++;
                C[i] -= 10;
            }
        }
        else if (C[i - 1] == '.' || C[i - 1] == ',') {
            if (C[i] > '9') {
                C[i - 2]++;
                C[i] -= 10;
            }
        }
    }
    while (C.back() == '0' || C.back() == '.') {
        if (C.back() == '.') {
            C.pop_back();
            break;
        }
        else {
            C.pop_back();
        }
    }
    if ((str1[0] == '-' && str2[0] != '-') || (str1[0] != '-' && str2[0] == '-')) {
        cout << '-';
    }
    for (int i = 0; i < C.length(); i++) {
        cout << C[i];
    }
    cout << endl;
}
void div() {
    string A, B, C = "0";
    int pos1 = -1, pos2 = -1, pos3 = 99999;
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] >= '0' && str1[i] <= '9')A.push_back(str1[i]);
        else if (str1[i] == '.')pos1 = A.length();
    }
    while (A.length() > pos1 && A.back() == '0') {
        A.pop_back();
    }
    for (int i = 0; i < str2.length(); i++) {
        if (str2[i] >= '0' && str2[i] <= '9')B.push_back(str2[i]);
        else if (str2[i] == '.')pos2 = B.length();
    }
    while (B.length() > pos2 && B.back() == '0') {
        B.pop_back();
    }
    for (int i = 0; i < 7; i++) {
        if (B[i] != '0')break;
        if (i == 6 && B[i] == '0') {
            cout << "ERROR" << endl;
            return;
        }
    }
    if (pos1 == -1)pos1 = A.length();
    if (pos2 == -1)pos2 = B.length();
    int pos = A.length() - B.length() - pos1 + pos2;
    if (pos < 0) {
        for (int i = 0; i < abs(pos); i++) {
            A.push_back('0');
        }
    }
    else {
        for (int i = 0; i < pos; i++) {
            B.push_back('0');
        }
    }
    int k = 0;
    while ((int)(C.length() - pos3) < 10) {
        if (A.length() < B.length()) {
            A.push_back('0');
            pos3 = min(pos3, (int)C.length());
        }
        bool flag = 1;
        for (int i = 0; i < B.length(); i++) {
            if (A[i] > B[i]) {
                break;
            }
            if (A[i] < B[i]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            C[k]++;
            for (int i = B.length() - 1; i >= 0; i--) {
                if (A[i] >= B[i])A[i] -= B[i] - '0';
                else {
                    A[i - 1]--;
                    A[i] += 10;
                    A[i] -= B[i] - '0';
                }
            }
        }
        else {
            C.push_back('0');
            B.insert(0, "0");
            k++;
        }
    }
    if (C.back() >= '5') {
        C[C.length() - 2]++;
    }
    C.pop_back();
    C.insert(pos3 - 1, ".");
    while ((C.back() == '0' || C.back() == '.') && C.length() >= pos3) {
        C.pop_back();
    }
    reverse(C.begin(), C.end());
    while (C.back() == '0' && C.length() != 1 && C[C.length() - 2] != '.') {
        C.pop_back();
    }
    reverse(C.begin(), C.end());
    int point = C.find('.');
    if (point != -1) {
        for (int i = 1; point - 3 * i > 0; i++) {
            C.insert(point - 3 * i, ",");
        }
    }
    if ((str1[0] == '-' && str2[0] != '-') || (str1[0] != '-' && str2[0] == '-'))cout << '-';
    for (int i = 0; i < C.length(); i++) {
        cout << C[i];
    }
    cout << endl;
}
int mian() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> c >> str1 >> str2;
            if (c == '*')mult();
            if (c == '/')div();
        }
    }
    return 0;
}
//不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄不要直接抄
//高精度不难，麻烦的是这破题要做太多细节处理和特判了。
