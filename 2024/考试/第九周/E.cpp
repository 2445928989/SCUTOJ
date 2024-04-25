/*题目描述
编写程序，在上一题的基础上，设计一个学生类student，包括学号、姓名和平时作业成绩、期中考试成绩、期末考试成绩，利用重载运算符“*”计算该学生各项成绩加权后的成绩，利用重载运算符“<<”输出该学生的成绩单。
给出main函数，要求自己设计类和函数，实现功能：

int main() {
    int id;
    string name;
    double hw, midterm, final;
    char continue_input = 'y'; // 控制是否继续输入的标志

    while (continue_input == 'y') {
        cout << "请输入学生学号: ";
        cin >> id;
        cout << "请输入学生姓名: ";
        cin >> name;
        cout << "请输入平时作业成绩: ";
        cin >> hw;
        cout << "请输入期中考试成绩: ";
        cin >> midterm;
        cout << "请输入期末考试成绩: ";
        cin >> final;

        Student student(id, name, hw, midterm, final);

        // 调用重载的乘法运算符进行加权成绩的计算
        student.operator*();

        cout << "学生信息及成绩单：" << endl;
        cout << student << endl;

        cout << "是否继续输入学生信息？(y/n): ";
        cin >> continue_input;
    }

    return 0;
}
输入
多个学生姓名、各成绩。
输出
参考如下：

必须使用的关键字
class operator*
禁止使用的关键字
sca/nf pr/intf
样例输入 Copy
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
样例输出 Copy
请输入学生学号: 请输入学生姓名: 请输入平时作业成绩: 请输入期中考试成绩: 请输入期末考试成绩: 学生信息及成绩单：
学生姓名: xiaohuahua
学生学号: 1
平时作业成绩加权: 16
期中考试成绩加权: 27
期末考试成绩加权: 42.5
总成绩: 85.5

是否继续输入学生信息？(y/n): 请输入学生学号: 请输入学生姓名: 请输入平时作业成绩: 请输入期中考试成绩: 请输入期末考试成绩: 学生信息及成绩单：
学生姓名: nike
学生学号: 2
平时作业成绩加权: 19
期中考试成绩加权: 28.8
期末考试成绩加权: 49
总成绩: 96.8

是否继续输入学生信息？(y/n): */

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
        cout << "总成绩: " << 0.2 * hw + 0.3 * midterm + 0.5 * final << endl;
    }
    void disp()
    {
        cout << "学生姓名: " << name << endl;
        cout << "学生学号: " << id << endl;
        cout << "平时作业成绩: " << hw << endl;
        cout << "期中考试成绩: " << midterm << endl;
        cout << "期末考试成绩: " << final << endl;
    }
    void operator*(){
        f = 0.5 * final;
        sum = 0.2 * hw + 0.3 * midterm + 0.5 * final;
        h = 0.2 * hw;
        m = 0.3 * midterm;
    }
    friend ostream &operator<<(ostream &cout, Student A)
    {
        cout << "学生姓名: " << A.name << endl;
        cout << "学生学号: " << A.id << endl;
        cout << "平时作业成绩加权: " << A.h << endl;
        cout << "期中考试成绩加权: " << A.m << endl;
        cout << "期末考试成绩加权: " << A.f << endl;
        cout << "总成绩: " << A.sum << endl;
        return cout;
    }
};


int main()
{
    int id;
    string name;
    double hw, midterm, final;
    char continue_input = 'y'; // 控制是否继续输入的标志

    while (continue_input == 'y')
    {
        cout << "请输入学生学号: ";
        cin >> id;
        cout << "请输入学生姓名: ";
        cin >> name;
        cout << "请输入平时作业成绩: ";
        cin >> hw;
        cout << "请输入期中考试成绩: ";
        cin >> midterm;
        cout << "请输入期末考试成绩: ";
        cin >> final;

        Student student(id, name, hw, midterm, final);

        // 调用重载的乘法运算符进行加权成绩的计算
        student.operator*();

        cout << "学生信息及成绩单：" << endl;
        cout << student << endl;

        cout << "是否继续输入学生信息？(y/n): ";
        cin >> continue_input;
    }

    return 0;
}