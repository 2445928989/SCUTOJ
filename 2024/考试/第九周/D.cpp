/*��Ŀ����
��дһ��������֪ĳ��ѧ�����ݣ�����ѧ�š�������ƽʱ��ҵ�ɼ������п��Գɼ�����ĩ���Գɼ�����Ƴ�Ա�������ѧ�����ܳɼ�����ʾ�����һ�� disp ������ʾ��ѧ������Ϣ���ɼ�����
�Ѹ����� main () ��������Ա���� couscore�Ĺ�������ĳѧ�����ܳɼ�����ʾ��disp ������������ʾѧ����������ѧ�źͳɼ�����
Ҫ���� main () ��������Ӧ�������� Student �����ƣ�Ҫ�� Student ���а���ѧ�š�������ƽʱ��ҵ�ɼ������п��Գɼ�����ĩ���Գɼ������ݳ�Ա�������ܳɼ��ľ�̬���ݳ�Ա������������캯��������Ϊѧ�š�������ƽʱ��ҵ�ɼ������п��Գɼ�����ĩ���Գɼ����������ܳɼ��ĳ�Ա���� (couscore) �Լ���ʾ�ɼ��ĳ�Ա���� (disp)��
ע���ܳɼ� = ƽʱ��ҵ�ɼ� * 20% + ���п��Գɼ� * 30% + ��ĩ���Գɼ�*50%
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
        student.couscore();
        student.disp();

        cout << "�Ƿ��������ѧ����Ϣ��(y/n): ";
        cin >> continue_input;
    }

    return 0;
}
����
������ѧ����ѧ�š������͸���ɼ�
���
�ο����£�

ע��������ĳ�Ա�����ð��ʹ�õ�Ӣ�ģ��Һ�����Ҫ��һ���ո񣻲���������������double���������κδ������籣����λС����
����ʹ�õĹؼ���
class private public
��ֹʹ�õĹؼ���
sc/anf pri/ntf
�������� Copy
11
С��
70
75
72
y
12
xiaoxiao
86
90
100
y
15
ëë
99
98
99
n
������� Copy
������ѧ��ѧ��: ������ѧ������: ������ƽʱ��ҵ�ɼ�: ���������п��Գɼ�: ��������ĩ���Գɼ�: �ܳɼ�: 72.5
ѧ������: С��
ѧ��ѧ��: 11
ƽʱ��ҵ�ɼ�: 70
���п��Գɼ�: 75
��ĩ���Գɼ�: 72

�Ƿ��������ѧ����Ϣ��(y/n): ������ѧ��ѧ��: ������ѧ������: ������ƽʱ��ҵ�ɼ�: ���������п��Գɼ�: ��������ĩ���Գɼ�: �ܳɼ�: 94.2
ѧ������: xiaoxiao
ѧ��ѧ��: 12
ƽʱ��ҵ�ɼ�: 86
���п��Գɼ�: 90
��ĩ���Գɼ�: 100

�Ƿ��������ѧ����Ϣ��(y/n): ������ѧ��ѧ��: ������ѧ������: ������ƽʱ��ҵ�ɼ�: ���������п��Գɼ�: ��������ĩ���Գɼ�: �ܳɼ�: 98.7
ѧ������: ëë
ѧ��ѧ��: 15
ƽʱ��ҵ�ɼ�: 99
���п��Գɼ�: 98
��ĩ���Գɼ�: 99

�Ƿ��������ѧ����Ϣ��(y/n): */

#include<iostream>
#include<string>
using namespace std;
class Student{
private:
    int id;
    string name;
    double hw;
    double midterm;
    double final;
public:
    Student(int a,string b,double c,double d,double e){
        id = a;
        name = b;
        hw = c;
        midterm = d;
        final = e;
    }
    void couscore(){
        cout << "�ܳɼ�: " << 0.2 * hw + 0.3 * midterm + 0.5 * final << endl;
    }
    void disp(){
        cout << "ѧ������: " << name << endl;
        cout << "ѧ��ѧ��: " << id << endl;
        cout << "ƽʱ��ҵ�ɼ�: " << hw << endl;
        cout << "���п��Գɼ�: " << midterm << endl;
        cout << "��ĩ���Գɼ�: " << final << endl;
        cout<<endl;
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
        student.couscore();
        student.disp();

        cout << "�Ƿ��������ѧ����Ϣ��(y/n): ";
        cin >> continue_input;
    }

    return 0;
}