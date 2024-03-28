/*题目描述
假设某销售公司有一般员工、销售员工和销售经理。月工资的计算办法是:
一般员工月薪=基本工资；
销售员工月薪=基本工资+销售额*提成率；
销售经理月薪=基本工资+职务工资+销售额*提成率。
编写程序，定义一个表示一般员工的基类 Employee，它包含三个表示员工基本信息的数据成员:编号number、姓名 name 和基本工资 basicSalary。
由 Employee 类派生表示销售员工的 Salesman 类，Salesman 类包含两个新数据成员:销售额 sales 和静态数据成员提成率commrate。
再由 Salesman 类派生表示销售经理的 Salcsmanager 类。Salesmanager 类包含新数据成员;职务工资JobSalary。
为这些类定义初始化数据的构造函数,以及输入数据input、计算工资 pay 和输出工资条 print 的成员函数。
设一般员工的基本工资是2000元，销售经理的职务工资是3000元，提成率=5/1000。在main 函数中输入若干个不同类型的员工信息测试你的类结构。
给出main的函数如下：
int main() {
    salesman obj1;
    obj1.pay();
    obj1.print();

    salesmanager obj2;
    obj2.pay();
    obj2.print();

    return 0;
}
输入
销售员工的编号、姓名、销售额；以及销售经理的编号、姓名、销售额
输出
输出上述编号、姓名及工资，如下图：

注意是英文符号



样例输入 Copy
1
新
5000
2
Nian
8000
样例输出 Copy
编号
姓名:
新本月销售额:
销售员:新 编号:1 本月工资:2025
编号:
姓名:
nian本月部门销售额:
销售经理:nian 编号:2 本月工资:5040*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class employee
{
public:
    int number;
    string name;
    int salary = 2000;
};

class salesman : public employee
{
public:
    double sales;
    static double commrate;

    void pay()
    {
        cout << "编号:";
        cin >> this->number;
        cout << "姓名:";
        cin >> this->name;
        cout << this->name << "本月销售额:";
        cin >> this->sales;
        this->salary = this->salary + this->sales * commrate;
    }

    void print()
    {
        cout << "销售员:" << this->name << " 编号:" << this->number << " 本月工资:" << salary << endl;
    }
};

class salesmanager : public salesman
{

public:
    double jobsalary = 3000;

    void pay()
    {
        cout << "编号:";
        cin >> this->number;
        cout << "姓名:";
        cin >> this->name;
        cout << this->name << "本月部门销售额:";
        cin >> this->sales;
        this->salary = this->salary + this->sales * commrate + jobsalary;
    }

    void print()
    {
        cout << "销售经理:" << this->name << " 编号:" << this->number << " 本月工资:" << salary << endl;
    }
};

double salesman::commrate = 0.005;

int main()
{

    salesman obj1;
    obj1.pay();
    obj1.print();

    salesmanager obj2;
    obj2.pay();
    obj2.print();
    system("pause");
}