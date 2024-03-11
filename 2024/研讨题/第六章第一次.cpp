#include <cstring>

#include <iostream>

using namespace std;

class Student

{

private:
    long ID;

    char name[20];

    char sex;

    int English_Score;

    int Chinese_Score;

    int Math_Score;

public:
    Student(long a, const char b[], char c, int d, int e, int f)

    {

        ID = a;

        strcpy(name, b);

        sex = c;

        English_Score = d;

        Chinese_Score = e;

        Math_Score = f;
    }

    Student()

    {

        ID = 0;

        strcpy(name, "noname");

        sex = ' ';

        English_Score = 0;

        Chinese_Score = 0;

        Math_Score = 0;
    }

    Student(const Student &other)

    {

        ID = other.ID;

        strcpy(name, other.name);

        sex = other.sex;

        English_Score = other.English_Score;

        Chinese_Score = other.Chinese_Score;

        Math_Score = other.Math_Score;
    }

    ~Student()
    {
    }

    void show()

    {

        cout << "学号:" << ID << "\t姓名：" << name << "\t性别：" << sex << " 英语：" << English_Score << "\t语文：" << Chinese_Score << "\t数学：" << Math_Score << endl;
    }
};

int main()

{

    Student std_1(1001, "Li Hua", 'F', 91, 71, 81);

    Student std_2(1002, "HeXiao", 'M', 92, 72, 82);

    Student std_3 = std_1;
    Student std_4;

    std_1.show();

    std_2.show();

    std_3.show();

    std_4.show();

    return 0;
}
