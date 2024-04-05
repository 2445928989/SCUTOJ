//// Student.cpp : Defines the entry point for the console application.

#include <cstring>

#include <iostream>

using namespace std;

class Student
{
protected:
    long number;
    char name[20];
    char sex;
    int English_score;
    int Chinese_score;
    int Math_score;
    static int English_total;
    static int Chinese_total;
    static int Math_total;
    static int total;

public:
    friend ostream &operator<<(ostream &cout, Student &A)
    {
        cout << A.number << '\t' << A.name << '\t' << A.sex << '\t' << A.English_score << '\t' << A.Chinese_score << '\t' << A.Math_score <<'\t'<<A.get_total()<< endl;
        return cout;
    }
    int getChinese()
    {
        return Chinese_score;
    }
    int getMath()
    {
        return Math_score;
    }
    int getEnglish()
    {
        return English_score;
    }
    virtual int get_total() 
    {
        return English_score + Chinese_score + Math_score;
    }
    Student() {}
    static double getAvgCh()
    {
        return (double)Chinese_total / total;
    }
    static double getAvgEn()
    {
        return (double)English_total / total;
    }
    static double getAvgMath()
    {
        return (double)Math_total / total;
    }
    int sum()
    {
        English_total += English_score;
        Chinese_total += Chinese_score;
        Math_total += Math_score;
        ++total;
        return English_score + Chinese_score + Math_score;
    }
};
class ScienceStudent : public Student
{
private:
    int phy_score;
    int che_score;
    int bio_score;
    static int phy_total;
    static int che_total;
    static int bio_total;
    static int science_total;

public:
    int sum()
    {
        Student::sum();
        phy_total += phy_score;
        che_total += che_score;
        bio_total += bio_score;
        ++science_total;
        return Chinese_score + English_score + Math_score + phy_score + che_score + bio_score;
    }
    ScienceStudent() {}
    friend istream &operator>>(istream &cin, ScienceStudent &A)
    {
        cin >> A.number >> A.name >> A.sex >> A.English_score >> A.Chinese_score >> A.Math_score >> A.phy_score >> A.che_score >> A.bio_score;
        return cin;
    }
    friend ostream &operator<<(ostream &cout, ScienceStudent &A)
    {
        cout << A.number << '\t' << A.name << '\t' << A.sex << '\t' << A.English_score << '\t' << A.Chinese_score << '\t' << A.Math_score << '\t' << A.phy_score << '\t' << A.che_score << '\t' << A.bio_score << '\t' << A.sum() << endl;
        return cout;
    }
    void static get_average()
    {
        cout << "the average of physcis:" << (double)phy_total / science_total << "\tchemistry:" << (double)che_total / science_total << "\tbiology:" << (double)bio_total / science_total << endl;
    }
    int virtual get_total()
    {
        return English_score + Chinese_score + Math_score + che_score + phy_score + bio_score;
    }
};
class LiberalArtsStudent : public Student
{
private:
    int his_score;
    int geo_score;
    int pol_score;
    static int his_total;
    static int geo_total;
    static int pol_total;
    static int lib_total;

public:
    virtual int get_total()
    {
        return English_score + Chinese_score + Math_score + his_score + geo_score + pol_score;
    }
    int sum()
    {
        Student::sum();
        his_total += his_score;
        geo_total += geo_score;
        pol_total += pol_score;
        ++lib_total;
        return Chinese_score + English_score + Math_score + his_score + geo_score + pol_score;
    }
    LiberalArtsStudent() {}
    friend istream &operator>>(istream &cin, LiberalArtsStudent &A)
    {
        cin >> A.number >> A.name >> A.sex >> A.English_score >> A.Chinese_score >> A.Math_score >> A.his_score >> A.geo_score >> A.pol_score;
        return cin;
    }
    friend ostream &operator<<(ostream &cout, LiberalArtsStudent &A)
    {
        cout << A.number << '\t' << A.name << '\t' << A.sex << '\t' << A.English_score << '\t' << A.Chinese_score << '\t' << A.Math_score << '\t' << A.his_score << '\t' << A.geo_score << '\t' << A.pol_score << '\t' << A.sum() << endl;
        return cout;
    }
    void static get_average()
    {
        cout << "the average of history:" << (double)his_total / lib_total << "\tgeography:" << (double)geo_total / lib_total << "\tpolitics:" << (double)pol_total / lib_total << endl;
    }
};
int Student::Chinese_total = 0;
int Student::English_total = 0;
int Student::Math_total = 0;
int Student::total = 0;
int ScienceStudent::phy_total = 0;
int ScienceStudent::che_total = 0;
int ScienceStudent::bio_total = 0;
int ScienceStudent::science_total = 0;
int LiberalArtsStudent::his_total = 0;
int LiberalArtsStudent::geo_total = 0;
int LiberalArtsStudent::pol_total = 0;
int LiberalArtsStudent::lib_total = 0;
void BubbleSort(Student **st, int n)

{

    int i, j;

    int work;

    for (i = 1; i < n; i++)

    {

        work = 0;

        for (j = 0; j < n - i; j++)

        {

            if (st[j]->get_total() < st[j + 1]->get_total())

            {

                swap(st[j], st[j + 1]);

                work = 1;
            }

            else

                if (st[j]->get_total() == st[j + 1]->get_total())

                if (st[j]->getChinese() < st[j + 1]->getChinese())

                {

                    swap(st[j], st[j + 1]);

                    work = 1;
                }

                else

                    if (st[j]->getChinese() == st[j + 1]->getChinese())

                    if (st[j]->getMath() < st[j + 1]->getMath())

                    {

                        swap(st[j], st[j + 1]);

                        work = 1;
                    }

                    else

                        if (st[j]->getMath() == st[j + 1]->getMath())

                        if (st[j]->getEnglish() < st[j + 1]->getEnglish())

                        {

                            swap(st[j], st[j + 1]);

                            work = 1;
                        }
        }

        if (!work)

            break;
    }
}

int main()

{

    Student *stu[10];

    ScienceStudent stu_ss[5];

    LiberalArtsStudent stu_las[5];

    int i;

    int j = 0;

    cout << "请按以下顺序输入理科生信息：\n学号\t姓名\t性别\t英语\t语文\t数学\t物理\t化学\t生物" << endl;

    for (i = 0; i < 5; i++)

    {

        cin >> stu_ss[i];

        stu[j] = &stu_ss[i];

        j++;
    }

    cout << "\n理科生成绩单：\n学号\t姓名\t性别\t英语\t语文\t数学\t物理\t化学\t生物\t总分\n";

    // SelectSort(stu_ss,5);

    for (i = 0; i < 5; i++)

        cout << stu_ss[i] << endl;

    cout << "请按以下顺序输入文科生信息：\n学号\t姓名\t性别\t英语\t语文\t数学\t历史\t地理\t政治" << endl;

    for (i = 0; i < 5; i++)

    {

        cin >> stu_las[i];

        stu[j] = &stu_las[i];

        j++;
    }

    cout << "\n文科生成绩单：\n学号\t姓名\t性别\t英语\t语文\t数学\t历史\t地理\t政治\t总分\n";

    for (i = 0; i < 5; i++)

        cout << stu_las[i] << endl;

    //        SelectSort(stu,10);

    BubbleSort(stu, 10);

    cout << "\n排序后的成绩单：\n学号\t姓名\t性别\t英语\t语文\t数学\t六科总分\n";

    for (i = 0; i < 10; i++)

        cout << *stu[i] << endl;

    cout << "The average of English:" << Student::getAvgEn() << "\tChinese:" << Student::getAvgCh() << "\tMath:" << Student::getAvgMath() << endl;

    ScienceStudent::get_average();

    LiberalArtsStudent::get_average();

    return 0;
}