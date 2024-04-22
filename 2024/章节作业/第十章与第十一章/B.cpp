/*题目描述
定义:类模板 T_Counter实现基本数据类型的+、-、*、=、>>、<< 运算；类模板 T_Vector，实现向量运算；类模板T_Matrix，实现矩阵运算。
main函数如下：
int main() {
    cout << "请输入两个整数：" << endl;
    T_Counter<int> int_counter1, int_counter2;
    cin >> int_counter1 >> int_counter2;
    cout << "整数加法结果：" << int_counter1 + int_counter2 << endl;
    cout << "整数减法结果：" << int_counter1 - int_counter2 << endl;
    cout << "整数乘法结果：" << int_counter1 * int_counter2 << endl;


    cout << "请输入两个双精度浮点数：" << endl;
    T_Counter<double> double_counter1, double_counter2;
    cin >> double_counter1 >> double_counter2;
    cout << "双精度浮点数加法结果：" << double_counter1 + double_counter2 << endl;
    cout << "双精度浮点数减法结果：" << double_counter1 - double_counter2 << endl;
    cout << "双精度浮点数乘法结果：" << double_counter1 * double_counter2 << endl;


    cout << "请输入第一个个向量（空格分隔）：" << endl;
    T_Vector<int> int_vector1, int_vector2;
    cin >> int_vector1;
    cout << "请输入第二个个向量（空格分隔）：" << endl;
    cin >> int_vector2;
    cout << "向量加法结果：" << int_vector1 + int_vector2 << endl;
    cout << "向量减法结果：" << int_vector1 - int_vector2 << endl;
    cout << "向量点乘结果：" << int_vector1 * int_vector2 << endl;


    cout << "请输入第一个矩阵（注意第一行先输入矩阵的行和列，然后再输入矩阵，每行空格分隔，回车换行）：" << endl;
    T_Matrix<int> int_matrix1, int_matrix2;
    cin >> int_matrix1;
    cout << "请输入第二个矩阵（每行空格分隔，回车换行）：" << endl;
    cin >> int_matrix2;
    cout << "矩阵加法结果：" << endl << int_matrix1 + int_matrix2 << endl;
    cout << "矩阵减法结果：" << endl << int_matrix1 - int_matrix2 << endl;
    cout << "矩阵乘法结果：" << endl << int_matrix1 * int_matrix2 << endl;


    return 0;
}
输入
三种运算的数据，包括整数、浮点数、向量和矩阵
输出

样例输入 Copy
5 4
4.2 5.3
1 2 3
4 5 5
2 2
1 5
6 5
2 2
8 9
7 8
样例输出 Copy
请输入两个整数：
整数加法结果：9
整数减法结果：1
整数乘法结果：20
请输入两个双精度浮点数：
双精度浮点数加法结果：9.5
双精度浮点数减法结果：-1.1
双精度浮点数乘法结果：22.26
请输入第一个个向量（空格分隔）：
请输入第二个个向量（空格分隔）：
向量加法结果：5 7 8
向量减法结果：-3 -3 -2
向量点乘结果：29
请输入第一个矩阵（注意第一行先输入矩阵的行和列，然后再输入矩阵，每行空格分隔，回车换行）：
请输入第二个矩阵（每行空格分隔，回车换行）：
矩阵加法结果：
9 14
13 13

矩阵减法结果：
-7 -4
-1 -3

矩阵乘法结果：
43 49
83 94*/
#include<iostream>
using namespace std;
template<typename T>
class T_Counter{
    T Data;
    public:
    T_Counter(){}
    T_Counter(T data){
        Data = data;
    }
    T operator+(T_Counter<T>other){
        return Data + other.Data;
    }
    T operator-(T_Counter<T> other)
    {
        return Data - other.Data;
    }
    T operator*(T_Counter<T> other)
    {
        return Data * other.Data;
    }
    friend istream& operator>>(istream& cin,T_Counter<T> &A){
        cin >> A.Data;
        return cin;
    }
    friend ostream& operator<<(ostream& cout,T_Counter<T> A){
        cout << A.Data;
        return cout;
    }
};
template<typename T>
class T_Vector{
    T_Counter<T> A;
    T_Counter<T> B;
    T_Counter<T> C;
    public:
    friend istream &operator>>(istream &cin, T_Vector<T> &V)
    {
        cin >>  V.A>>V.B>>V.C;
        return cin;
    }
    friend ostream &operator<<(ostream &cout, T_Vector<T> V)
    {
        cout << V.A<<' '<<V.B<<' '<<V.C;
        return cout;
    }
    T_Vector<T> operator+(T_Vector<T> other)
    {
        T_Vector temp;
        temp.A = A + other.A;
        temp.B = B + other.B;
        temp.C = C + other.C;
        return temp;
    }
    T_Vector<T> operator-(T_Vector<T> other)
    {
        T_Vector temp;
        temp.A = A - other.A;
        temp.B = B - other.B;
        temp.C = C - other.C;
        return temp;
    }
    T operator*(T_Vector<T> other)
    {
        T temp;
        temp += A * other.A;
        temp += B * other.B;
        temp += C * other.C;
        return temp;
    }
};
template<typename T>
class T_Matrix{
    T_Counter<T> **Data;
    int n;
    int m;
    public:
    friend istream& operator>>(istream& cin,T_Matrix<T> &A){
        cin >> A.n >> A.m;
        A.Data = new T_Counter<T> *[A.n];
        for (int i = 0; i < A.n;i++){
            A.Data[i] = new T_Counter<T>[A.m];
        }
        for (int i = 0; i < A.n;i++){
            for (int j = 0; j < A.m;j++){
                cin >> A.Data[i][j];
            }
        }
        return cin;
    }
    friend ostream& operator<<(ostream& cout,T_Matrix<T> A){
        for (int i = 0; i < A.m;i++){
            for (int j = 0; j < A.n;j++){
                cout << A.Data[i][j] << ' ';
            }
            cout << endl;
        }
        return cout;
    }
    T_Matrix(){}
    T_Matrix(int x,int y){
        m = x, n = y;
        Data = new T_Counter<T> *[x];
        for (int i = 0; i < x; i++)
        {
            Data[i] = new T_Counter<T>[y];
        }
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                Data[i][j] = 0;
            }
        }
    }
    T_Matrix<T> operator+(T_Matrix<T>other){
        T_Matrix temp(m, n);
        for (int i = 0; i < n;i++){
            for (int j = 0; j < m;j++){
                temp.Data[i][j] = Data[i][j] + other.Data[i][j];
            }
        }
        return temp;
    }
    T_Matrix<T> operator-(T_Matrix<T> other)
    {
        T_Matrix temp(m, n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                temp.Data[i][j] = Data[i][j] - other.Data[i][j];
            }
        }
        return temp;
    }
    T_Matrix<T> operator*(T_Matrix<T> other)
    {
        T_Matrix temp(m, n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                temp.Data[i][j] = 0;
                for (int t = 0; t < n;t++){
                    temp.Data[i][j] = temp.Data[i][j]+Data[i][t] * other.Data[t][j];
                }
            }
        }
        return temp;
    }
};
int main()
{
    cout << "请输入两个整数：" << endl;
    T_Counter<int> int_counter1, int_counter2;
    cin >> int_counter1 >> int_counter2;
    cout << "整数加法结果：" << int_counter1 + int_counter2 << endl;
    cout << "整数减法结果：" << int_counter1 - int_counter2 << endl;
    cout << "整数乘法结果：" << int_counter1 * int_counter2 << endl;

    cout << "请输入两个双精度浮点数：" << endl;
    T_Counter<double> double_counter1, double_counter2;
    cin >> double_counter1 >> double_counter2;
    cout << "双精度浮点数加法结果：" << double_counter1 + double_counter2 << endl;
    cout << "双精度浮点数减法结果：" << double_counter1 - double_counter2 << endl;
    cout << "双精度浮点数乘法结果：" << double_counter1 * double_counter2 << endl;

    cout << "请输入第一个个向量（空格分隔）：" << endl;
    T_Vector<int> int_vector1, int_vector2;
    cin >> int_vector1;
    cout << "请输入第二个个向量（空格分隔）：" << endl;
    cin >> int_vector2;
    cout << "向量加法结果：" << int_vector1 + int_vector2 << endl;
    cout << "向量减法结果：" << int_vector1 - int_vector2 << endl;
    cout << "向量点乘结果：" << int_vector1 * int_vector2 << endl;

    cout << "请输入第一个矩阵（注意第一行先输入矩阵的行和列，然后再输入矩阵，每行空格分隔，回车换行）：" << endl;
    T_Matrix<int> int_matrix1, int_matrix2;
    cin >> int_matrix1;
    cout << "请输入第二个矩阵（每行空格分隔，回车换行）：" << endl;
    cin >> int_matrix2;
    cout << "矩阵加法结果：" << endl
         << int_matrix1 + int_matrix2 << endl;
    cout << "矩阵减法结果：" << endl
         << int_matrix1 - int_matrix2 << endl;
    cout << "矩阵乘法结果：" << endl
         << int_matrix1 * int_matrix2 << endl;

    return 0;
}