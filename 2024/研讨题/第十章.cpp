//// Student.cpp : Defines the entry point for the console application.

#include <cstring>

#include <iostream>

using namespace std;
template<typename T>
class Student
{
protected:
    long number;
    char name[20];
    char sex;
    T English_score;
    T Chinese_score;
    T Math_score;
    static T English_total;
    static T Chinese_total;
    static T Math_total;
    static T total;

public:
    friend ostream &operator<<(ostream &cout, Student &A)
    {
        cout << A.number << '\t' << A.name << '\t' << A.sex << '\t' << A.English_score << '\t' << A.Chinese_score << '\t' << A.Math_score <<'\t'<<A.get_total()<< endl;
        return cout;
    }
    T getChinese()
    {
        return Chinese_score;
    }
    T getMath()
    {
        return Math_score;
    }
    T getEnglish()
    {
        return English_score;
    }
    virtual T get_total() 
    {
        return English_score + Chinese_score + Math_score;
    }
    Student() {}
    static T getAvgCh()
    {
        return Chinese_total / total;
    }
    static T getAvgEn()
    {
        return English_total / total;
    }
    static T getAvgMath()
    {
        return Math_total / total;
    }
    T sum()
    {
        English_total += English_score;
        Chinese_total += Chinese_score;
        Math_total += Math_score;
        ++total;
        return English_score + Chinese_score + Math_score;
    }
};
template<typename T>
class ScienceStudent : public Student<T>
{
private:
    T phy_score;
    T che_score;
    T bio_score;
    static T phy_total;
    static T che_total;
    static T bio_total;
    static T science_total;

public:
    T sum()
    {
        Student<T>::sum();
        phy_total += phy_score;
        che_total += che_score;
        bio_total += bio_score;
        ++science_total;
        return Student<T>::Chinese_score + Student<T>::English_score + Student<T>::Math_score + phy_score + che_score + bio_score;
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
        cout << "the average of physcis:" << phy_total / science_total << "\tchemistry:" << che_total / science_total << "\tbiology:" << bio_total / science_total << endl;
    }
    T virtual get_total()
    {
        return Student<T>::English_score + Student<T>::Chinese_score + Student<T>::Math_score + che_score + phy_score + bio_score;
    }
};
template<typename T>
class LiberalArtsStudent : public Student<T>
{
private:
    T his_score;
    T geo_score;
    T pol_score;
    static T his_total;
    static T geo_total;
    static T pol_total;
    static T lib_total;

public:
    virtual T get_total()
    {
        return Student<T>::English_score + Student<T>::Chinese_score + Student<T>::Math_score + his_score + geo_score + pol_score;
    }
    T sum()
    {
        Student<T>::sum();
        his_total += his_score;
        geo_total += geo_score;
        pol_total += pol_score;
        ++lib_total;
        return Student<T>::Chinese_score + Student<T>::English_score + Student<T>::Math_score + his_score + geo_score + pol_score;
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
        cout << "the average of history:" << his_total / lib_total << "\tgeography:" << geo_total / lib_total << "\tpolitics:" << pol_total / lib_total << endl;
    }
};
template <typename T>
T Student<T>::Chinese_total = 0;
template <typename T>
T Student<T>::English_total = 0;
template <typename T>
T Student<T>::Math_total = 0;
template <typename T>
T Student<T>::total = 0;
template <typename T>
T ScienceStudent<T>::phy_total = 0;
template <typename T>
T ScienceStudent<T>::che_total = 0;
template <typename T>
T ScienceStudent<T>::bio_total = 0;
template <typename T>
T ScienceStudent<T>::science_total = 0;
template <typename T>
T LiberalArtsStudent<T>::his_total = 0;
template <typename T>
T LiberalArtsStudent<T>::geo_total = 0;
template <typename T>
T LiberalArtsStudent<T>::pol_total = 0;
template <typename T>
T LiberalArtsStudent<T>::lib_total = 0;
template<typename T>
void ToSort (Student<T> **st,int n){
    
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
template <typename T>
void ToSort(ScienceStudent<T> **st, int n)
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
template <typename T>
void ToSort(LiberalArtsStudent<T> **st, int n)
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

    Student<int> *stu[10];

    ScienceStudent<int> stu_ss[5];

    ScienceStudent<int> *stu_s[5];

    LiberalArtsStudent<int> stu_las[5];

    LiberalArtsStudent<int> *stu_la[5];

    int i;

    int j = 0;

    cout << "请按以下顺序输入理科生信息：\n学号\t姓名\t性别\t英语\t语文\t数学\t物理\t化学\t生物" << endl;

    for (i = 0; i < 5; i++)

    {

        cin >> stu_ss[i];

        stu[j] = &stu_ss[i];

        stu_s[i] = &stu_ss[i];

        j++;
    }

    cout << "\n理科生成绩按降序排列：\n学号\t姓名\t性别\t英语\t语文\t数学\t物理\t化学\t生物\t总分\n";

    ToSort(stu_s, 5);

    for (i = 0; i < 5; i++)

        cout << *stu_s[i] << endl;

    cout << "请按以下顺序输入文科生信息：\n学号\t姓名\t性别\t英语\t语文\t数学\t历史\t地理\t政治" << endl;

    for (i = 0; i < 5; i++)

    {

        cin >> stu_las[i];

        stu[j] = &stu_las[i];

        stu_la[i] = &stu_las[i];

        j++;
    }

    cout << "\n文科生成绩按降序排列：\n学号\t姓名\t性别\t英语\t语文\t数学\t历史\t地理\t政治\t总分\n";

    ToSort(stu_la, 5);

    for (i = 0; i < 5; i++)

        cout << *stu_la[i] << endl;

    ToSort(stu, 10);

    cout << "\n排序后的成绩单：\n学号\t姓名\t性别\t英语\t语文\t数学\t六科总分\n";

    for (i = 0; i < 10; i++)

        cout << *stu[i] << endl;

    cout << "The average of English:" << Student<int>::getAvgEn() << "\tChinese:" << Student<int>::getAvgCh() << "\tMath:" << Student<int>::getAvgMath() << endl;

    ScienceStudent<int>::get_average();

    LiberalArtsStudent<int>::get_average();

    return 0;
}