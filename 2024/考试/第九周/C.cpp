/*��Ŀ����
ΪComplex������ == �� != ��һԪ��(-)��>>���������������еȲ�������Ϊ������z1=a+bi����z2=c+di�����ҽ���a����c��b����d�������󸺵Ĳ�������Ϊ�����z=a+bi��һ������, -zΪ-a-bi��ΪComplex���������Ʋ�����>>��������ݡ�
class Complex
{ public:
    // TODO: ���� ==
    // TODO: ���� !=
    // TODO: ���� -
    // TODO: ���� >>

  private:
      double  Real, Image ;
};

���Ժ�����
int main()
{
    double r, i;
    cin >> r >> i;
    Complex c1(r, i);
    Complex c;
    c = -c1;
    cout >> c << endl;
    cout << (c1 != c) << endl;
    cout << (c1 == c) << endl;
}

����
������ʵ�����鲿
���
������Ժ���
����ʹ�õĹؼ���
class operator
�������� Copy
2.1 3.4
������� Copy
(-2.1 + -3.4i)
1
0
��ʾ
����Ҫѭ������*/
#include <iostream>
#include <string>
using namespace std;
class Complex
{
public:
    // TODO: ���� ==
    // TODO: ���� !=
    // TODO: ���� -
    // TODO: ���� >>
    Complex() {}
    Complex(double a, double b)
    {
        Real = a;
        Image = b;
    }
    bool operator==(Complex other)
    {
        return (Real == other.Real && Image == other.Image);
    }
    bool operator!=(Complex other)
    {
        return !(*this == other);
    }
    friend ostream &operator>>(ostream &cout, Complex A)
    {
        cout << "(" << A.Real << " + " << A.Image << "i)";
        return cout;
    }
    Complex operator-()
    {
        Complex t(-Real, -Image);
        return t;
    }

private:
    double Real, Image;
};

int main()
{
    double r, i;
    cin >> r >> i;
    Complex c1(r, i);
    Complex c;
    c = -c1;
    cout >> c << endl;
    cout << (c1 != c) << endl;
    cout << (c1 == c) << endl;
    system("pause");
}
