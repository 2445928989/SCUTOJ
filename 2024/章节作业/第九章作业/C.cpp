/*��Ŀ����
ʹ�õ�2���ж���Ľ�ְ������ϵ,��д����,����ĳ�¸���ְ�ƽ�ʦ�Ĺ�����Ϣ,���������������ÿλ��ʦ�Ĺ�������ͳ�Ƶ��µ��ܹ��ʡ�ƽ�����ʡ���߹��ʺ���͹��ʡ�
ʹ������main���������������ϵ��
int main() {
    vector<teacher*> teachers; // ����һ���洢��ְ��ָ�������

    // �����ְ����Ϣ
    int numTeachers;
    cout << "�������ְ��������";
    cin >> numTeachers;

    for (int i = 0; i < numTeachers; ++i) {
        char name[30];
        int coursetime;
        cout << "�������ְ�������Ϳ�ʱ��";
        cin >> name >> coursetime;

        int type;
        cout << "��ѡ��ְ�ƣ�1. ���� 2. ������ 3. ��ʦ����";
        cin >> type;

        teacher* t;
        if (type == 1)
            t = new professor(name, coursetime);
        else if (type == 2)
            t = new associateprofessor(name, coursetime);
        else if (type == 3)
            t = new lecturer(name, coursetime);
        else {
            cout << "��Ч��ְ�����ͣ�" << endl;
            continue;
        }

        teachers.push_back(t);
    }

    // ���ÿλ��ְ���Ĺ�����
    cout << "��ְ����������" << endl;
    for (auto t : teachers) {
        t->print();
        cout << " ���ʣ�" << t->pay() << endl;
    }

    // ͳ�Ƶ����ܹ��ʡ�ƽ�����ʡ���߹��ʺ���͹���
    int totalSalary = 0;
    int maxSalary = 0;
    int minSalary = INT_MAX; // ��ʼ��Ϊ���ֵ
    for (auto t : teachers) {
        int salary = t->pay();
        totalSalary += salary;
        maxSalary = max(maxSalary, salary);
        minSalary = min(minSalary, salary);
    }
    double averageSalary = static_cast<double>(totalSalary) / numTeachers;

    // ���ͳ�ƽ��
    cout << "�����ܹ��ʣ�" << totalSalary << endl;
    cout << "ƽ�����ʣ�" << averageSalary << endl;
    cout << "��߹��ʣ�" << maxSalary << endl;
    cout << "��͹��ʣ�" << minSalary << endl;

    // �ͷ��ڴ�
    for (auto t : teachers) {
        delete t;
    }

    return 0;
}


����
һ�����ѧ��������
ÿ��ѧ���ķ���
����ʹ�õĹؼ���
class
�������� Copy
3
yan 52
3
lu 29
1
ba 62
2
������� Copy
�������ְ���������������ְ�������Ϳ�ʱ����ѡ��ְ�ƣ�1. ���� 2. ������ 3. ��ʦ�����������ְ�������Ϳ�ʱ����ѡ��ְ�ƣ�1. ���� 2. ������ 3. ��ʦ�����������ְ�������Ϳ�ʱ����ѡ��ְ�ƣ�1. ���� 2. ������ 3. ��ʦ������ְ����������
��ʦ��yan ���ʣ�6040
���ڣ�lu ���ʣ�6450
�����ڣ�ba ���ʣ�6860
�����ܹ��ʣ�19350
ƽ�����ʣ�6450
��߹��ʣ�6860
��͹��ʣ�6040*/
#include<iostream>
#include<vector>
#include <climits>
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
class teacher : public Employee
{
protected:
    int class_number;
    int class_salary;
public:
    teacher(string str) : Employee(str, 5000) {}
    int pay(){
        return class_salary * class_number + basic_salary;
    }
    virtual void print() = 0;
};
class professor : public teacher
{
public:
    professor(string str, int x) : teacher(str)
    {
        class_number = x;
        class_salary = 50;
    }
    virtual void print()
    {
        cout << "���ڣ�" << name;
    }
};
class associateprofessor : public teacher
{
public:
    associateprofessor(string str, int x) : teacher(str)
    {
        class_number = x;
        class_salary = 30;
    }
    virtual void print()
    {
        cout << "�����ڣ�" << name;
    }
};
class lecturer : public teacher
{
public:
    lecturer(string str, int x) : teacher(str)
    {
        class_number = x;
        class_salary = 20;
    }
    virtual void print()
    {
        cout << "��ʦ��" << name;
    }
};
int main()
{
    vector<teacher*> teachers; // ����һ���洢��ְ��ָ�������

    // �����ְ����Ϣ
    int numTeachers;
    cout << "�������ְ��������";
    cin >> numTeachers;

    for (int i = 0; i < numTeachers; ++i)
    {
        char name[30];
        int coursetime;
        cout << "�������ְ�������Ϳ�ʱ��";
        cin >> name >> coursetime;

        int type;
        cout << "��ѡ��ְ�ƣ�1. ���� 2. ������ 3. ��ʦ����";
        cin >> type;

        teacher *t;
        if (type == 1)
            t = new professor(name, coursetime);
        else if (type == 2)
            t = new associateprofessor(name, coursetime);
        else if (type == 3)
            t = new lecturer(name, coursetime);
        else
        {
            cout << "��Ч��ְ�����ͣ�" << endl;
            continue;
        }

        teachers.push_back(t);
    }

    // ���ÿλ��ְ���Ĺ�����
    cout << "��ְ����������" << endl;
    for (auto t : teachers)
    {
        t->print();
        cout << " ���ʣ�" << t->pay() << endl;
    }

    // ͳ�Ƶ����ܹ��ʡ�ƽ�����ʡ���߹��ʺ���͹���
    int totalSalary = 0;
    int maxSalary = 0;
    int minSalary = INT_MAX; // ��ʼ��Ϊ���ֵ
    for (auto t : teachers)
    {
        int salary = t->pay();
        totalSalary += salary;
        maxSalary = max(maxSalary, salary);
        minSalary = min(minSalary, salary);
    }
    double averageSalary = static_cast<double>(totalSalary) / numTeachers;

    // ���ͳ�ƽ��
    cout << "�����ܹ��ʣ�" << totalSalary << endl;
    cout << "ƽ�����ʣ�" << averageSalary << endl;
    cout << "��߹��ʣ�" << maxSalary << endl;
    cout << "��͹��ʣ�" << minSalary << endl;

    // �ͷ��ڴ�
    for (auto t : teachers)
    {
        delete t;
    }

    return 0;
}