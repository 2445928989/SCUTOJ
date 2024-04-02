/*��Ŀ����
ʹ���麯����д�����������Բ��������������������������Բ���嶼���Կ�����Բ�̳ж�������ˣ����԰�Բ�� Circle ��Ϊ���ࡣ�� Circle ���ж���һ�����ݳ�Ա radius �������麯�� area �� volume�� �� Circle ������ Sphere ��� Column �ࡣ���������ж��麯�� area �� volume ���¶��壬�ֱ��������Բ�������������������ƺ����Ժ���ʹ������main�������ԣ�
int main() {
    circle* p;
    double rsphere;
    double rcolumn, hcolumn;
    cin >> rsphere >> rcolumn >> hcolumn;
    sphere sobj(rsphere);
    p = &sobj;

    cout << "����:" << endl;
    cout << "��� = " << p->volume() << endl;
    cout << "����� = " << p->area() << endl;

    column cobj(rcolumn, hcolumn);
    p = &cobj;

    cout << "Բ���壺" << endl;
    cout << "��� = " << p->volume() << endl;
    cout << "����� = " << p->area() << endl;

    return 0;
}
����
����İ뾶��Բ����İ뾶�͸�
���
������£�ע��Բ����ͳһȡ3.14�������С��λ����������

����ʹ�õĹؼ���
class
�������� Copy
5 5 8
������� Copy
����:
��� = 523.333
����� = 314
Բ���壺
��� = 628
����� = 408.2*/

#include <iostream>
using namespace std;
const double PI = 3.14;
class circle
{
protected:
    double radius;

public:
    virtual double area() = 0;
    virtual double volume() = 0;
    circle(double r)
    {
        radius = r;
    }
};
class sphere : public circle
{
public:
    sphere(double r) : circle(r) {}
    virtual double area()
    {
        return 4 * PI * radius * radius;
    }
    virtual double volume()
    {
        return 4.0 / 3 * PI * radius * radius * radius;
    }
};
class column : public circle
{
private:
    double height;

public:
    column(double r, double h) : circle(r) { height = h; }
    virtual double area()
    {
        return 2 * PI * radius * radius + 2 * PI * radius * height;
    }
    virtual double volume()
    {
        return PI * radius * radius * height;
    }
};
int main()
{
    circle *p;
    double rsphere;
    double rcolumn, hcolumn;
    cin >> rsphere >> rcolumn >> hcolumn;
    sphere sobj(rsphere);
    p = &sobj;

    cout << "����:" << endl;
    cout << "��� = " << p->volume() << endl;
    cout << "����� = " << p->area() << endl;

    column cobj(rcolumn, hcolumn);
    p = &cobj;

    cout << "Բ���壺" << endl;
    cout << "��� = " << p->volume() << endl;
    cout << "����� = " << p->area() << endl;

    return 0;
}