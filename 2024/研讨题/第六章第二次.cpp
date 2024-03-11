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

    static int English_total;

    static int Chinese_total;

    static int Math_total;

    static int count;

public:
    Student(long a, const char b[], char c, int d, int e, int f)

    {

        ID = a;

        strcpy(name, b);

        sex = c;

        English_Score = d;

        Chinese_Score = e;

        Math_Score = f;

        English_total += d;

        Chinese_total += e;

        Math_total += f;

        count++;

    }

    Student()

    {

        ID = 0;

        strcpy(name, "noname");

        sex = ' ';

        English_Score = 0;

        Chinese_Score = 0;

        Math_Score = 0;

        count++;
    }

    Student(const Student &other)

    {

        ID = other.ID;

        strcpy(name, other.name);

        sex = other.sex;

        English_Score = other.English_Score;

        Chinese_Score = other.Chinese_Score;

        Math_Score = other.Math_Score;

        English_total += other.English_Score;

        Chinese_total += other.Chinese_Score;

        Math_total += other.Math_Score;

        count++;
    }

    ~Student()
    {
        English_total -= English_Score;

        Chinese_total -= Chinese_Score;

        Math_total -= Math_Score;

        count--;
    }

    static double avg_eng()
    {
        return (double)English_total / count;
    }
    static double avg_chi()
    {
        return (double)Chinese_total / count;
    }
    static double avg_math()
    {
        return (double)Math_total / count;
    }
};

int Student::English_total = 0;

int Student::Chinese_total = 0;

int Student::Math_total = 0;

int Student::count = 0;

int main()

{

    Student std_1(1001, "Li Hua", 'F', 91, 71, 81);

    Student std_2(1002, "HeXiao", 'M', 92, 72, 82);

    Student std_3 = std_1, std_4;

    cout << "英语的平均分是：" << Student::avg_eng() << endl

         << "中文的平均分是：" << Student::avg_chi() << endl

         << "数学的平均分是：" << Student::avg_math() << endl;

    return 0;
}