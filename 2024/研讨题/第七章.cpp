#include <cstring>

#include <iostream>

using namespace std;

class Student
{
private:
    long number;
    char name[20];
    char sex;
    int English_score;
    int Chinese_score;
    int Math_score;

public:
    int total_score() const
    {
        return English_score + Chinese_score + Math_score;
    }
    bool operator>(const Student &other) const
    {
        return total_score() > other.total_score();
    }
    friend istream &operator>>(istream &cin, Student &s);
    friend ostream &operator<<(ostream &cout, const Student &s);
};
istream &operator>>(istream &cin, Student &s)
{
    cin >> s.number >> s.name >> s.sex >> s.English_score >> s.Chinese_score >> s.Math_score;
    return cin;
}
ostream &operator<<(ostream &cout, const Student &s)
{
    cout << s.number << '\t' << s.name << '\t' << s.sex << '\t' << s.English_score << '\t' << s.Chinese_score << '\t' << s.Math_score << '\t' << s.total_score() << endl;
    return cout;
}
void SelectSort(Student *st, int n) // 选择排序

{

    int i, j, t;

    Student temp;

    for (i = 0; i < n - 1; i++)

    {

        t = i;

        for (j = i + 1; j < n; j++)

            if (st[j] > st[t]) // 隐式调用类型转换函数

                t = j;

        if (t != i)

        {

            temp = st[i];

            st[i] = st[t];

            st[t] = temp;
        }
    }

    return;
}

int main()

{

    Student stu[5];

    int i;

    cout << "请按以下顺序输入学生信息：\n学号\t姓名\t性别\t英语\t语文\t数学" << endl;

    for (i = 0; i < 5; i++)

        cin >> stu[i]; // 调用重载的提取运算符

    cout << "\n按总分降序排列：\n学号\t姓名\t性别\t英语\t语文\t数学\t总分\n";

    SelectSort(stu, 5);

    for (i = 0; i < 5; i++)

        cout << stu[i] << endl; // 调用重载的插入运算符
    system("pause");
    return 0;
}