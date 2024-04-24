/*题目描述
建立某单位职工通讯录的二进制数据文件，文件中的每个记录均包括:职工编号、姓名、电话号码邮政编码和住址。
输入
职工编号、姓名、电话号码邮政编码和住址
输出
通讯录的二进制文件内容

样例输入 Copy
2
1
hui
125849894
265894
huagong
2
hong
165489569
006520
wushan
样例输出 Copy
请输入职工人数：请输入第1个职工的编号：请输入第1个职工的姓名：请输入第1个职工的电话号码：请输入第1个职工的邮政编码：请输入第1个职工的通信地址：第1个职工的信息（二进制格式）：
编号：00110001
姓名：01101000 01110101 01101001
电话号码：00110001 00110010 00110101 00111000 00110100 00111001 00111000 00111001 00110100
邮政编码：00110010 00110110 00110101 00111000 00111001 00110100
通信地址：01101000 01110101 01100001 01100111 01101111 01101110 01100111

请输入第2个职工的编号：请输入第2个职工的姓名：请输入第2个职工的电话号码：请输入第2个职工的邮政编码：请输入第2个职工的通信地址：第2个职工的信息（二进制格式）：
编号：00110010
姓名：01101000 01101111 01101110 01100111
电话号码：00110001 00110110 00110101 00110100 00111000 00111001 00110101 00110110 00111001
邮政编码：00110000 00110000 00110110 00110101 00110010 00110000
通信地址：01110111 01110101 01110011 01101000 01100001 01101110
提示
注意字符编码为utf-8，以及char和unsigned char字符的区别*/
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
class MAN
{
public:
    char num[32];
    int lnum;
    int lname;
    int ltel;
    int lmail;
    int lplace;
    char name[32];
    char tel[32];
    char mail[32];
    char place[32];
    MAN()
    {
        memset(this, 0, sizeof(MAN));
    }
};
void onbit(char a)
{
    bool t[8];
    for (int i = 7; i >= 0; i--)
    {
        t[i] = a % 2;
        a /= 2;
    }
    for (int i = 0; i < 8; i++)
    {
        cout << t[i];
    }
}
void output(MAN t)
{
    cout << "编号：";
    for (int i = 0; i < t.lnum; i++)
    {
        onbit(t.num[i]);
        cout << ' ';
    }
    cout << endl
         << "姓名：";
    for (int i = 0; i < t.lname; i++)
    {
        onbit(t.name[i]);
        cout << ' ';
    }
    cout << endl
         << "电话号码：";
    for (int i = 0; i < t.ltel; i++)
    {
        onbit(t.tel[i]);
        cout << ' ';
    }
    cout << endl
         << "邮政编码：";
    for (int i = 0; i < t.lmail; i++)
    {
        onbit(t.mail[i]);
        cout << ' ';
    }
    cout << endl
         << "通信地址：";
    for (int i = 0; i < t.lplace; i++)
    {
        onbit(t.place[i]);
        cout << ' ';
    }
    cout << endl
         << endl;
}
int main()
{
    MAN m;
    int n;
    cout << "请输入职工人数：";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "请输入第" << i << "个职工的编号：";
        cin >> m.num;
        m.lnum = strlen(m.num);
        cout << "请输入第" << i << "个职工的姓名：";
        cin >> m.name;
        m.lname = strlen(m.name);
        cout << "请输入第" << i << "个职工的电话号码：";
        cin >> m.tel;
        m.ltel = strlen(m.tel);
        cout << "请输入第" << i << "个职工的邮政编码：";
        cin >> m.mail;
        m.lmail = strlen(m.mail);
        cout << "请输入第" << i << "个职工的通信地址：";
        cin >> m.place;
        m.lplace = strlen(m.place);
        cout << "第" << i << "个职工的信息（二进制格式）：\n";
        output(m);
    }
    system("pause");
}