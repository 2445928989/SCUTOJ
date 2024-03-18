/*题目描述
定义一个student 类，在该类定义中包括：一个数据成员（分数score）及两个静态数据成员（总分toal和学生人数count)；成员函数 scoretotalcount 用于设置分数、求总分和累计学生人数；静态成员函数 sum用于返回总分；静态成员函数average 用于求平均值。
在main 函数中，输入某班学生的成绩，并调用上述函数求全班学生的总分和平均分。
输入
一个班的学生总人数
每个学生的分数
输出
总分
平均分
样例输入 Copy
5
10 23 30 45 60
样例输出 Copy
168
33.6*/
#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    double score;
    static double total;
    static int count;

public:
    void scoretotalcount(double s)
    {
        score = s;
        total += s;
        ++count;
    }
    static double sum()
    {
        return total;
    }
    static double average()
    {
        return total / count;
    }
};
int Student::count = 0;
double Student::total = 0;
int n;
double s;
int main()
{
    cin >> n;
    Student *p;
    p = new Student[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        p[i].scoretotalcount(s);
    }
    cout << Student::sum() << endl;
    cout << Student::average() << endl;
    system("pause");
}