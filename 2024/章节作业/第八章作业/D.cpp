/*题目描述
使用课本中244页第5题定义的 Vector 类，定义它的派生类 Matrix，实现矩阵的基本运算
给出main函数如下：
int main() {
    Matrix A(2, 2);
    Matrix B(2, 2);

    cout << "矩阵 A:" << endl;
    cout << A << endl;

    cout << "矩阵 B:" << endl;
    cout << B << endl;

    Matrix C = A * B;
    cout << "矩阵 C = A * B:" << endl;
    cout << C << endl;

    Matrix D = A + B;
    cout << "矩阵 C = A + B:" << endl;
    cout << D << endl;

    Matrix E = A - B;
    cout << "矩阵 C = A * B:" << endl;
    cout << E << endl;

    return 0;
}
输入
四个数字，分别是两个矩阵的行数和列数
输出
示例如下：

注意之间的空格和换行

样例输入 Copy
3 3 3 3
样例输出 Copy
矩阵 A:
1 1 1
1 1 1
1 1 1

矩阵 B:
1 1 1
1 1 1
1 1 1

矩阵 C = A * B:
3 3 3
3 3 3
3 3 3

矩阵 C = A + B:
2 2 2
2 2 2
2 2 2

矩阵 C = A - B:
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

    cout << "矩阵 A:" << endl;
    cout << A << endl;

    cout << "矩阵 B:" << endl;
    cout << B << endl;

    Matrix C = A * B;
    cout << "矩阵 C = A * B:" << endl;
    cout << C << endl;

    Matrix D = A + B;
    cout << "矩阵 C = A + B:" << endl;
    cout << D << endl;

    Matrix E = A - B;
    cout << "矩阵 C = A - B:" << endl;
    cout << E << endl;

    return 0;
}