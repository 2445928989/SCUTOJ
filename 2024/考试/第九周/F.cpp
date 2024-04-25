/*��Ŀ����


�ڴ�ѧ�ڼ䣬ѧ����ѧ����ʵ��ѧ�ֺͿγ�ѧ����ɣ�����У����֯��Ժ����֯���༶��ѧ���ɲ���������һ����ʵ��ѧ�֡�
���һ�������ʵ�ּ���ѧ������ѧ�ֲ���ʾ�����ȶ���һ��Student�ĳ����࣬�ṩ�й�ͬ��������Ĵ��麯�����ɴ���������SchoolStuLeader�ࡢFacultiesStuLeader�ࡢClassStuLeader���RegStudent�ࡣ
ÿһ������ѧ�ּ��㷽ʽ���£�
У����֯ѧ���ɲ���ʵ��ѧ�� = ����ְʱ���������� * 0.01 + 2��/ 5
Ժ����֯ѧ���ɲ���ʵ��ѧ�� = ����ְʱ���������� * 0.01 + 1��/ 5
�༶ѧ���ɲ���ʵ��ѧ�� = ����ְʱ���������� * 0.01 + 0.8��/ 5
����ְѧ����ʵ��ѧ�� = ����ʵ��ʱ����Сʱ�� * 0.005
��ѧ�� = ʵ��ѧ�֣�������ְʱ����ʵ��ʱ�����������룩 + �γ�ѧ�֣��������룩
��֪ĳ��ѧ�����ݣ�����ѧ�š�������ʵ��ѧ�֡��γ�ѧ�֡���ƺ������ѧ������ѧ�ֲ���ʾ�����һ��disp��ʾ��ѧ������Ϣ����ѧ�֡��������������࣬�ڵڶ��������ṩȫ��������ʵ�֡��ڲ��Ժ�����ʹ�û���ָ��ʵ�ֲ�ͬ���������Ĳ�����
main�������£�
int main() {
    Student* student;
    cout << "������У��ѧ���ɲ�����Ϣ������ѧ�ţ����֣���ְ�������γ�ѧ�֣�" << endl;
    int id;
    string n;
    double days;
    double course;
    cin >> id >> n >> days >> course;
    student = new SchoolStuLeader(id, n, days, course);
    student->calculateCredits(); // ��������õ�ʵ��ѧ��
    student->getTotalCredit(); // ������ѧ��
    student->disp(); // ��ʾ��Ϣ

    cout << "������Ժ��ѧ���ɲ�����Ϣ������ѧ�ţ����֣���ְ�������γ�ѧ�֣�" << endl;
    cin >> id >> n >> days >> course;
    student = new FacultiesStuLeader(id, n, days, course);
    student->calculateCredits();
    student->getTotalCredit();
    student->disp();

    cout << "������༶ѧ���ɲ�����Ϣ������ѧ�ţ����֣���ְ�������γ�ѧ�֣�" << endl;
    cin >> id >> n >> days >> course;
    student = new ClassStuLeader(id, n, days, course);
    student->calculateCredits();
    student->getTotalCredit();
    student->disp();

    cout << "�������ѧ���ɲ�����Ϣ������ѧ�ţ����֣�����ʵ��ʱ�����γ�ѧ�֣�" << endl;
    double hours;
    cin >> id >> n >> hours >> course;

    student = new RegStudent(id, n, hours, course);
    student->calculateCredits();
    student->getTotalCredit();
    student->disp();

    return 0;

}


����
ѧ�š����֡���ְ������ʵ��ʱ�������γ�ѧ��
���
ѧ���ĵ���ְ��2��ѧ�š���������ѧ�֣��ο�����

����ʹ�õĹؼ���
class public protected
��ֹʹ�õĹؼ���
pri/ntf sca/nf
�������� Copy
1 LL 500 45
2 HH 300 40
3 KK 300 45
4 LI 40 30
������� Copy
������У��ѧ���ɲ�����Ϣ������ѧ�ţ����֣���ְ�������γ�ѧ�֣�
У��ѧ���ɲ���
ѧ�ţ�1��������LL
��ѧ�֣�46.4
������Ժ��ѧ���ɲ�����Ϣ������ѧ�ţ����֣���ְ�������γ�ѧ�֣�
Ժ��ѧ���ɲ���
ѧ�ţ�2��������HH
��ѧ�֣�40.8
������༶ѧ���ɲ�����Ϣ������ѧ�ţ����֣���ְ�������γ�ѧ�֣�
�༶ѧ���ɲ���
ѧ�ţ�3��������KK
��ѧ�֣�45.76
�������ѧ���ɲ�����Ϣ������ѧ�ţ����֣�����ʵ��ʱ�����γ�ѧ�֣�
��ͨѧ����
ѧ�ţ�4��������LI
��ѧ�֣�30.2*/
#include <iostream>
#include <string>
using namespace std;
class Student{
    protected:
        int id;
        string name;
        double course;
        double credits;

    public:
        Student(int a,string b,double c){
            id = a;
            name = b;
            course = c;
        }
        virtual void calculateCredits() = 0;
        virtual void getTotalCredit() = 0;
        virtual void disp() = 0;
};
class SchoolStuLeader :public Student
{
private:
    int days;
public:
    SchoolStuLeader(int a,string b,double c,int d):Student(a,b,d){
        days = c;
    }
    virtual void calculateCredits()
    {
        credits = (days * 0.01 + 2) / 5;
    }
    virtual void getTotalCredit(){
        credits += course;
    }
    virtual void disp(){
        cout << "У��ѧ���ɲ���\n";
        cout << "ѧ�ţ�" << id << "��������" << name << endl;
        cout << "��ѧ�֣�" << credits << endl;
    }
};
class FacultiesStuLeader : public Student
{
private:
    int days;

public:
    FacultiesStuLeader(int a, string b, double c, int d) : Student(a, b, d)
    {
        days = c;
    }
    virtual void calculateCredits()
    {
        credits = (days * 0.01 + 1) / 5;
    }
    virtual void getTotalCredit()
    {
        credits += course;
    }
    virtual void disp()
    {
        cout << "Ժ��ѧ���ɲ���\n";
        cout << "ѧ�ţ�" << id << "��������" << name << endl;
        cout << "��ѧ�֣�" << credits << endl;
    }
};
class ClassStuLeader : public Student
{
private:
    int days;

public:
    ClassStuLeader(int a, string b, double c, int d) : Student(a, b, d)
    {
        days = c;
    }
    virtual void calculateCredits()
    {
        credits = (days * 0.01 + 0.8) / 5;
    }
    virtual void getTotalCredit()
    {
        credits += course;
    }
    virtual void disp()
    {
        cout << "�༶ѧ���ɲ���\n";
        cout << "ѧ�ţ�" << id << "��������" << name << endl;
        cout << "��ѧ�֣�" << credits << endl;
    }
};
class RegStudent : public Student
{
private:
    int hours;
    public:
        RegStudent(int a, string b, double c, int d) : Student(a, b, d)
        {
            hours = c;
        }
        virtual void calculateCredits()
        {
            credits = hours * 0.005;
        }
        virtual void getTotalCredit()
        {
            credits += course;
        }
        virtual void disp()
        {
            cout << "��ͨѧ����\n";
            cout << "ѧ�ţ�" << id << "��������" << name << endl;
            cout << "��ѧ�֣�" << credits << endl;
        }
};
int main()
{
    Student *student;
    cout << "������У��ѧ���ɲ�����Ϣ������ѧ�ţ����֣���ְ�������γ�ѧ�֣�" << endl;
    int id;
    string n;
    double days;
    double course;
    cin >> id >> n >> days >> course;
    student = new SchoolStuLeader(id, n, days, course);
    student->calculateCredits(); // ��������õ�ʵ��ѧ��
    student->getTotalCredit();   // ������ѧ��
    student->disp();             // ��ʾ��Ϣ

    cout << "������Ժ��ѧ���ɲ�����Ϣ������ѧ�ţ����֣���ְ�������γ�ѧ�֣�" << endl;
    cin >> id >> n >> days >> course;
    student = new FacultiesStuLeader(id, n, days, course);
    student->calculateCredits();
    student->getTotalCredit();
    student->disp();

    cout << "������༶ѧ���ɲ�����Ϣ������ѧ�ţ����֣���ְ�������γ�ѧ�֣�" << endl;
    cin >> id >> n >> days >> course;
    student = new ClassStuLeader(id, n, days, course);
    student->calculateCredits();
    student->getTotalCredit();
    student->disp();

    cout << "�������ѧ���ɲ�����Ϣ������ѧ�ţ����֣�����ʵ��ʱ�����γ�ѧ�֣�" << endl;
    double hours;
    cin >> id >> n >> hours >> course;

    student = new RegStudent(id, n, hours, course);
    student->calculateCredits();
    student->getTotalCredit();
    student->disp();

    return 0;
}
