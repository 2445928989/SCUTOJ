/*题目描述
编写一个程序，已知某个学生数据，包括学号、姓名、平时作业成绩、期中考试成绩、期末考试成绩。设计成员函数求该学生的总成绩并显示，设计一个 disp 函数显示该学生的信息及成绩单。
已给出了 main () 函数。成员函数 couscore的功能是求某学生的总成绩并显示，disp 函数功能是显示学生的姓名、学号和成绩单。
要求按照 main () 函数及对应的输出完成 Student 类的设计，要求 Student 类中包含学号、姓名、平时作业成绩、期中考试成绩、期末考试成绩等数据成员，包含总成绩的静态数据成员，另外包含构造函数（参数为学号、姓名、平时作业成绩、期中考试成绩、期末考试成绩）、计算总成绩的成员函数 (couscore) 以及显示成绩的成员函数 (disp)。
注：总成绩 = 平时作业成绩 * 20% + 期中考试成绩 * 30% + 期末考试成绩*50%
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
        student.couscore();
        student.disp();

        cout << "是否继续输入学生信息？(y/n): ";
        cin >> continue_input;
    }

    return 0;
}
输入
输入多个学生的学号、姓名和各项成绩
输出
参考如下：

注意上面类的成员函数里，冒号使用的英文，且后面需要有一个空格；不对最后输出的所有double型数据做任何处理，比如保留几位小数。
必须使用的关键字
class private public
禁止使用的关键字
sc/anf pri/ntf
样例输入 Copy
11
小汪
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
毛毛
99
98
99
n
样例输出 Copy
请输入学生学号: 请输入学生姓名: 请输入平时作业成绩: 请输入期中考试成绩: 请输入期末考试成绩: 总成绩: 72.5
学生姓名: 小汪
学生学号: 11
平时作业成绩: 70
期中考试成绩: 75
期末考试成绩: 72

是否继续输入学生信息？(y/n): 请输入学生学号: 请输入学生姓名: 请输入平时作业成绩: 请输入期中考试成绩: 请输入期末考试成绩: 总成绩: 94.2
学生姓名: xiaoxiao
学生学号: 12
平时作业成绩: 86
期中考试成绩: 90
期末考试成绩: 100

是否继续输入学生信息？(y/n): 请输入学生学号: 请输入学生姓名: 请输入平时作业成绩: 请输入期中考试成绩: 请输入期末考试成绩: 总成绩: 98.7
学生姓名: 毛毛
学生学号: 15
平时作业成绩: 99
期中考试成绩: 98
期末考试成绩: 99

是否继续输入学生信息？(y/n): */

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
        cout << "总成绩: " << 0.2 * hw + 0.3 * midterm + 0.5 * final << endl;
    }
    void disp(){
        cout << "学生姓名: " << name << endl;
        cout << "学生学号: " << id << endl;
        cout << "平时作业成绩: " << hw << endl;
        cout << "期中考试成绩: " << midterm << endl;
        cout << "期末考试成绩: " << final << endl;
        cout<<endl;
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
        student.couscore();
        student.disp();

        cout << "是否继续输入学生信息？(y/n): ";
        cin >> continue_input;
    }

    return 0;
}