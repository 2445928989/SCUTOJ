/*题目描述
恺撒密码是最简单的加密技术之一，其规则如下：指定一个整数-26<n<26，则明文中的大写英文字母将被加密为在其在字母表中向右平移n位对应的大写字母，其他字符不参与加解密，这种平移是循环的，例如Z向右平移1位得到A，n小于0则代表循环左移，若要解密密文，只需对密文进行反方向操作。示例：n=3，ZOO_QUAD将被加密为CRR_TXDG。
输入
多组输入，每行包括一个字符作为操作指令，一个整数n和一个字符串，当操作指令为’e’时，使用整数n进行加密操作，为’d’时则进行解密操作。
输出
按行输出对应输入的加解密结果
样例输入 Copy
e 3 ZOO_QUAD
d 3 CRR_TXDG
e 5 THE_QUICK_BROWN_FOX_JUMPS_OVER_THE_LAZY_DOG
样例输出 Copy
CRR_TXDG
ZOO_QUAD
YMJ_VZNHP_GWTBS_KTC_OZRUX_TAJW_YMJ_QFED_ITL*/

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
char a;
int n;
string str;
int main()
{
    while (cin >> a >> n >> str) {
        if (a == 'd')n = -n;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] += n;
                if (str[i] < 'A')str[i] += 26;
                if (str[i] > 'Z')str[i] -= 26;
            }
            cout << str[i];
        }
        cout << endl;
    }
}
