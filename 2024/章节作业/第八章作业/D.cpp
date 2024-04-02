/*��Ŀ����
ʹ�ÿα���244ҳ��5�ⶨ��� Vector �࣬�������������� Matrix��ʵ�־���Ļ�������
����main�������£�
int main() {
    Matrix A(2, 2);
    Matrix B(2, 2);

    cout << "���� A:" << endl;
    cout << A << endl;

    cout << "���� B:" << endl;
    cout << B << endl;

    Matrix C = A * B;
    cout << "���� C = A * B:" << endl;
    cout << C << endl;

    Matrix D = A + B;
    cout << "���� C = A + B:" << endl;
    cout << D << endl;

    Matrix E = A - B;
    cout << "���� C = A * B:" << endl;
    cout << E << endl;

    return 0;
}
����
�ĸ����֣��ֱ����������������������
���
ʾ�����£�

ע��֮��Ŀո�ͻ���

�������� Copy
3 3 3 3
������� Copy
���� A:
1 1 1
1 1 1
1 1 1

���� B:
1 1 1
1 1 1
1 1 1

���� C = A * B:
3 3 3
3 3 3
3 3 3

���� C = A + B:
2 2 2
2 2 2
2 2 2

���� C = A - B:
0 0 0
0 0 0
0 0 0*/
#include <iostream>
using namespace std;
class Matrix
{
    int **a;
    int x, y;

public:
    Matrix(int x, int y)
    {
        a = new int *[x];
        for (int i = 0; i < x; i++)
        {
            a[i] = new int[y];
            for (int j = 0; j < y; j++)
            {
                a[i][j] = 1;
            }
        }
        this->x = x;
        this->y = y;
    }
    friend ostream &operator<<(ostream &cout, Matrix T)
    {
        for (int i = 0; i < T.x; i++)
        {
            for (int j = 0; j < T.y; j++)
            {
                cout << T.a[i][j] << " ";
            }
            cout << endl;
        }
        return cout;
    }
    friend Matrix operator+(Matrix A, Matrix B)
    {
        Matrix T(A.x, A.y);
        for (int i = 0; i < T.x; i++)
        {
            for (int j = 0; j < T.y; j++)
            {
                T.a[i][j] = A.a[i][j] + B.a[i][j];
            }
        }
        return T;
    }
    friend Matrix operator-(Matrix A, Matrix B)
    {
        Matrix T(A.x, A.y);
        for (int i = 0; i < T.x; i++)
        {
            for (int j = 0; j < T.y; j++)
            {
                T.a[i][j] = A.a[i][j] - B.a[i][j];
            }
        }
        return T;
    }
    friend Matrix operator*(Matrix A, Matrix B)
    {
        Matrix T(A.x, A.y);
        for (int i = 0; i < T.x; i++)
        {
            for (int j = 0; j < T.y; j++)
            {
                T.a[i][j] = A.x;
            }
        }
        return T;
    }
};
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    Matrix A(a, b), B(c, d);

    cout << "���� A:" << endl;
    cout << A << endl;

    cout << "���� B:" << endl;
    cout << B << endl;

    Matrix C = A * B;
    cout << "���� C = A * B:" << endl;
    cout << C << endl;

    Matrix D = A + B;
    cout << "���� C = A + B:" << endl;
    cout << D << endl;

    Matrix E = A - B;
    cout << "���� C = A - B:" << endl;
    cout << E << endl;

    return 0;
}