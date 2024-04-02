/*题目描述
某学校教职工的工资计算方法为:

所有教职工都有基本工资：教师：5000元，管理人员：3000，实验室人员：2000。

教师月工资为基本工资+课时补贴，课时补贴根据职称和课时计算。例如，每课时教授补贴 50元，副教授补贴 30 元，讲师补贴 20 元。

管理人员月薪为基本工资+职务工资。

实验室人员月薪为基本工资+工作日补贴，工作日补贴等于日补贴×月工作日数，日补贴50元。
月工作数22天
定义教职工抽象类，派生教师类、管理人员类和实验室类，使用以下main函数测试这个类体系。

int main() {
    professor pobj("李小平", 32);
    pobj.print();
    cout <<  " 工资：" << pobj.pay() << endl;

    associateprofessor apobj("王芳芳", 56);
    apobj.print();
    cout <<  " 工资：" << apobj.pay() << endl;

    lecturer lobj("何大建", 72);
    lobj.print();
    cout <<  " 工资：" << lobj.pay() << endl;

    // 测试新增的类
    Manager mobj("张经理", 1000);
    mobj.print();
    cout << " 工资：" << mobj.pay() << endl;

    LabStaff lsobj("赵技术员", 50);
    lsobj.print();
    cout << " 工资：" << lsobj.pay() << endl;

return 0;
}

输出
如下：

必须使用的关键字
class
样例输入 Copy

样例输出 Copy
教授：李小平 工资：6600
副教授：王芳芳 工资：6680
讲师：何大建 工资：6440
管理人员：张经理 工资：4000
实验室人员：赵技术员 工资：3100*/

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
        cout << "教授：" << name;
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
        cout << "副教授：" << name;
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
        cout << "讲师：" << name;
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
        cout << "管理人员：" << name;
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
        cout << "实验室人员：" << name;
    }
    int pay()
    {
        return basic_salary + day_salary * work_day;
    }
};
main()
{
    professor pobj("李小平", 32);
    pobj.print();
    cout << " 工资：" << pobj.pay() << endl;

    associateprofessor apobj("王芳芳", 56);
    apobj.print();
    cout << " 工资：" << apobj.pay() << endl;

    lecturer lobj("何大建", 72);
    lobj.print();
    cout << " 工资：" << lobj.pay() << endl;

    // 测试新增的类
    Manager mobj("张经理", 1000);
    mobj.print();
    cout << " 工资：" << mobj.pay() << endl;

    LabStaff lsobj("赵技术员", 50);
    lsobj.print();
    cout << " 工资：" << lsobj.pay() << endl;

    return 0;
}