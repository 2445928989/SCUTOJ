/*��Ŀ����
ĳѧУ��ְ���Ĺ��ʼ��㷽��Ϊ:

���н�ְ�����л������ʣ���ʦ��5000Ԫ��������Ա��3000��ʵ������Ա��2000��

��ʦ�¹���Ϊ��������+��ʱ��������ʱ��������ְ�ƺͿ�ʱ���㡣���磬ÿ��ʱ���ڲ��� 50Ԫ�������ڲ��� 30 Ԫ����ʦ���� 20 Ԫ��

������Ա��нΪ��������+ְ���ʡ�

ʵ������Ա��нΪ��������+�����ղ����������ղ��������ղ������¹����������ղ���50Ԫ��
�¹�����22��
�����ְ�������࣬������ʦ�ࡢ������Ա���ʵ�����࣬ʹ������main���������������ϵ��

int main() {
    professor pobj("��Сƽ", 32);
    pobj.print();
    cout <<  " ���ʣ�" << pobj.pay() << endl;

    associateprofessor apobj("������", 56);
    apobj.print();
    cout <<  " ���ʣ�" << apobj.pay() << endl;

    lecturer lobj("�δ�", 72);
    lobj.print();
    cout <<  " ���ʣ�" << lobj.pay() << endl;

    // ������������
    Manager mobj("�ž���", 1000);
    mobj.print();
    cout << " ���ʣ�" << mobj.pay() << endl;

    LabStaff lsobj("�Լ���Ա", 50);
    lsobj.print();
    cout << " ���ʣ�" << lsobj.pay() << endl;

return 0;
}

���
���£�

����ʹ�õĹؼ���
class
�������� Copy

������� Copy
���ڣ���Сƽ ���ʣ�6600
�����ڣ������� ���ʣ�6680
��ʦ���δ� ���ʣ�6440
������Ա���ž��� ���ʣ�4000
ʵ������Ա���Լ���Ա ���ʣ�3100*/

#include <iostream>
#include <string>
using namespace std;
class Employee
{
protected:
    double basic_salary;
    string name;

public:
    Employee(string str, int a)
    {
        name = str;
        basic_salary = a;
    }
};
class Teacher : public Employee
{
protected:
    int class_number;
    int class_salary;

public:
    Teacher(string str) : Employee(str, 5000) {}
};
class professor : Teacher
{
public:
    professor(string str, int x) : Teacher(str)
    {
        class_number = x;
        class_salary = 50;
    }
    void print()
    {
        cout << "���ڣ�" << name;
    }
    int pay()
    {
        return basic_salary + class_number * class_salary;
    }
};
class associateprofessor : Teacher
{
public:
    associateprofessor(string str, int x) : Teacher(str)
    {
        class_number = x;
        class_salary = 30;
    }
    void print()
    {
        cout << "�����ڣ�" << name;
    }
    int pay()
    {
        return basic_salary + class_number * class_salary;
    }
};
class lecturer : Teacher
{
public:
    lecturer(string str, int x) : Teacher(str)
    {
        class_number = x;
        class_salary = 20;
    }
    void print()
    {
        cout << "��ʦ��" << name;
    }
    int pay()
    {
        return basic_salary + class_number * class_salary;
    }
};
class Manager : public Employee
{
private:
    int position_salary;

public:
    Manager(string str, int a) : Employee(str, 3000)
    {
        position_salary = a;
    }
    void print()
    {
        cout << "������Ա��" << name;
    }
    int pay()
    {
        return basic_salary + position_salary;
    }
};
class LabStaff : public Employee
{
private:
    int day_salary;
    const int work_day = 22;

public:
    LabStaff(string str, int a) : Employee(str, 2000)
    {
        day_salary = a;
    }
    void print()
    {
        cout << "ʵ������Ա��" << name;
    }
    int pay()
    {
        return basic_salary + day_salary * work_day;
    }
};
main()
{
    professor pobj("��Сƽ", 32);
    pobj.print();
    cout << " ���ʣ�" << pobj.pay() << endl;

    associateprofessor apobj("������", 56);
    apobj.print();
    cout << " ���ʣ�" << apobj.pay() << endl;

    lecturer lobj("�δ�", 72);
    lobj.print();
    cout << " ���ʣ�" << lobj.pay() << endl;

    // ������������
    Manager mobj("�ž���", 1000);
    mobj.print();
    cout << " ���ʣ�" << mobj.pay() << endl;

    LabStaff lsobj("�Լ���Ա", 50);
    lsobj.print();
    cout << " ���ʣ�" << lsobj.pay() << endl;

    return 0;
}