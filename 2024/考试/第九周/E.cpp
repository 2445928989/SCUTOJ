/*��Ŀ����
��д��������һ��Ļ����ϣ����һ��ѧ����student������ѧ�š�������ƽʱ��ҵ�ɼ������п��Գɼ�����ĩ���Գɼ������������������*�������ѧ������ɼ���Ȩ��ĳɼ������������������<<�������ѧ���ĳɼ�����
����main������Ҫ���Լ������ͺ�����ʵ�ֹ��ܣ�

int main() {
    int id;
    string name;
    double hw, midterm, final;
    char continue_input = 'y'; // �����Ƿ��������ı�־

    while (continue_input == 'y') {
        cout << "������ѧ��ѧ��: ";
        cin >> id;
        cout << "������ѧ������: ";
        cin >> name;
        cout << "������ƽʱ��ҵ�ɼ�: ";
        cin >> hw;
        cout << "���������п��Գɼ�: ";
        cin >> midterm;
        cout << "��������ĩ���Գɼ�: ";
        cin >> final;

        Student student(id, name, hw, midterm, final);

        // �������صĳ˷���������м�Ȩ�ɼ��ļ���
        student.operator*();

        cout << "ѧ����Ϣ���ɼ�����" << endl;
        cout << student << endl;

        cout << "�Ƿ��������ѧ����Ϣ��(y/n): ";
        cin >> continue_input;
    }

    return 0;
}
����
���ѧ�����������ɼ���
���
�ο����£�

����ʹ�õĹؼ���
class operator*
��ֹʹ�õĹؼ���
sca/nf pr/intf
�������� Copy
1
xiaohuahua
80
90
85
y
2
nike
95
96
98
n
������� Copy
������ѧ��ѧ��: ������ѧ������: ������ƽʱ��ҵ�ɼ�: ���������п��Գɼ�: ��������ĩ���Գɼ�: ѧ����Ϣ���ɼ�����
ѧ������: xiaohuahua
ѧ��ѧ��: 1
ƽʱ��ҵ�ɼ���Ȩ: 16
���п��Գɼ���Ȩ: 27
��ĩ���Գɼ���Ȩ: 42.5
�ܳɼ�: 85.5

�Ƿ��������ѧ����Ϣ��(y/n): ������ѧ��ѧ��: ������ѧ������: ������ƽʱ��ҵ�ɼ�: ���������п��Գɼ�: ��������ĩ���Գɼ�: ѧ����Ϣ���ɼ�����
ѧ������: nike
ѧ��ѧ��: 2
ƽʱ��ҵ�ɼ���Ȩ: 19
���п��Գɼ���Ȩ: 28.8
��ĩ���Գɼ���Ȩ: 49
�ܳɼ�: 96.8

�Ƿ��������ѧ����Ϣ��(y/n): */

#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    int id;
    string name;
    double hw;
    double midterm;
    double final;
    double sum;
    double h;
    double m;
    double f;

public:
    Student(int a, string b, double c, double d, double e)
    {
        id = a;
        name = b;
        hw = c;
        midterm = d;
        final = e;
    }
    void couscore()
    {
        cout << "�ܳɼ�: " << 0.2 * hw + 0.3 * midterm + 0.5 * final << endl;
    }
    void disp()
    {
        cout << "ѧ������: " << name << endl;
        cout << "ѧ��ѧ��: " << id << endl;
        cout << "ƽʱ��ҵ�ɼ�: " << hw << endl;
        cout << "���п��Գɼ�: " << midterm << endl;
        cout << "��ĩ���Գɼ�: " << final << endl;
    }
    void operator*(){
        f = 0.5 * final;
        sum = 0.2 * hw + 0.3 * midterm + 0.5 * final;
        h = 0.2 * hw;
        m = 0.3 * midterm;
    }
    friend ostream &operator<<(ostream &cout, Student A)
    {
        cout << "ѧ������: " << A.name << endl;
        cout << "ѧ��ѧ��: " << A.id << endl;
        cout << "ƽʱ��ҵ�ɼ���Ȩ: " << A.h << endl;
        cout << "���п��Գɼ���Ȩ: " << A.m << endl;
        cout << "��ĩ���Գɼ���Ȩ: " << A.f << endl;
        cout << "�ܳɼ�: " << A.sum << endl;
        return cout;
    }
};


int main()
{
    int id;
    string name;
    double hw, midterm, final;
    char continue_input = 'y'; // �����Ƿ��������ı�־

    while (continue_input == 'y')
    {
        cout << "������ѧ��ѧ��: ";
        cin >> id;
        cout << "������ѧ������: ";
        cin >> name;
        cout << "������ƽʱ��ҵ�ɼ�: ";
        cin >> hw;
        cout << "���������п��Գɼ�: ";
        cin >> midterm;
        cout << "��������ĩ���Գɼ�: ";
        cin >> final;

        Student student(id, name, hw, midterm, final);

        // �������صĳ˷���������м�Ȩ�ɼ��ļ���
        student.operator*();

        cout << "ѧ����Ϣ���ɼ�����" << endl;
        cout << student << endl;

        cout << "�Ƿ��������ѧ����Ϣ��(y/n): ";
        cin >> continue_input;
    }

    return 0;
}