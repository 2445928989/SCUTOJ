/*��Ŀ����
����ĳ��λְ��ͨѶ¼�Ķ����������ļ����ļ��е�ÿ����¼������:ְ����š��������绰�������������סַ��
����
ְ����š��������绰�������������סַ
���
ͨѶ¼�Ķ������ļ�����

�������� Copy
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
������� Copy
������ְ���������������1��ְ���ı�ţ��������1��ְ�����������������1��ְ���ĵ绰���룺�������1��ְ�����������룺�������1��ְ����ͨ�ŵ�ַ����1��ְ������Ϣ�������Ƹ�ʽ����
��ţ�00110001
������01101000 01110101 01101001
�绰���룺00110001 00110010 00110101 00111000 00110100 00111001 00111000 00111001 00110100
�������룺00110010 00110110 00110101 00111000 00111001 00110100
ͨ�ŵ�ַ��01101000 01110101 01100001 01100111 01101111 01101110 01100111

�������2��ְ���ı�ţ��������2��ְ�����������������2��ְ���ĵ绰���룺�������2��ְ�����������룺�������2��ְ����ͨ�ŵ�ַ����2��ְ������Ϣ�������Ƹ�ʽ����
��ţ�00110010
������01101000 01101111 01101110 01100111
�绰���룺00110001 00110110 00110101 00110100 00111000 00111001 00110101 00110110 00111001
�������룺00110000 00110000 00110110 00110101 00110010 00110000
ͨ�ŵ�ַ��01110111 01110101 01110011 01101000 01100001 01101110
��ʾ
ע���ַ�����Ϊutf-8���Լ�char��unsigned char�ַ�������*/
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
    cout << "��ţ�";
    for (int i = 0; i < t.lnum; i++)
    {
        onbit(t.num[i]);
        cout << ' ';
    }
    cout << endl
         << "������";
    for (int i = 0; i < t.lname; i++)
    {
        onbit(t.name[i]);
        cout << ' ';
    }
    cout << endl
         << "�绰���룺";
    for (int i = 0; i < t.ltel; i++)
    {
        onbit(t.tel[i]);
        cout << ' ';
    }
    cout << endl
         << "�������룺";
    for (int i = 0; i < t.lmail; i++)
    {
        onbit(t.mail[i]);
        cout << ' ';
    }
    cout << endl
         << "ͨ�ŵ�ַ��";
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
    cout << "������ְ��������";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "�������" << i << "��ְ���ı�ţ�";
        cin >> m.num;
        m.lnum = strlen(m.num);
        cout << "�������" << i << "��ְ����������";
        cin >> m.name;
        m.lname = strlen(m.name);
        cout << "�������" << i << "��ְ���ĵ绰���룺";
        cin >> m.tel;
        m.ltel = strlen(m.tel);
        cout << "�������" << i << "��ְ�����������룺";
        cin >> m.mail;
        m.lmail = strlen(m.mail);
        cout << "�������" << i << "��ְ����ͨ�ŵ�ַ��";
        cin >> m.place;
        m.lplace = strlen(m.place);
        cout << "��" << i << "��ְ������Ϣ�������Ƹ�ʽ����\n";
        output(m);
    }
    system("pause");
}