/*��Ŀ����
����:��ģ�� T_Counterʵ�ֻ����������͵�+��-��*��=��>>��<< ���㣻��ģ�� T_Vector��ʵ���������㣻��ģ��T_Matrix��ʵ�־������㡣
main�������£�
int main() {
    cout << "����������������" << endl;
    T_Counter<int> int_counter1, int_counter2;
    cin >> int_counter1 >> int_counter2;
    cout << "�����ӷ������" << int_counter1 + int_counter2 << endl;
    cout << "�������������" << int_counter1 - int_counter2 << endl;
    cout << "�����˷������" << int_counter1 * int_counter2 << endl;


    cout << "����������˫���ȸ�������" << endl;
    T_Counter<double> double_counter1, double_counter2;
    cin >> double_counter1 >> double_counter2;
    cout << "˫���ȸ������ӷ������" << double_counter1 + double_counter2 << endl;
    cout << "˫���ȸ��������������" << double_counter1 - double_counter2 << endl;
    cout << "˫���ȸ������˷������" << double_counter1 * double_counter2 << endl;


    cout << "�������һ�����������ո�ָ�����" << endl;
    T_Vector<int> int_vector1, int_vector2;
    cin >> int_vector1;
    cout << "������ڶ������������ո�ָ�����" << endl;
    cin >> int_vector2;
    cout << "�����ӷ������" << int_vector1 + int_vector2 << endl;
    cout << "�������������" << int_vector1 - int_vector2 << endl;
    cout << "������˽����" << int_vector1 * int_vector2 << endl;


    cout << "�������һ������ע���һ�������������к��У�Ȼ�����������ÿ�пո�ָ����س����У���" << endl;
    T_Matrix<int> int_matrix1, int_matrix2;
    cin >> int_matrix1;
    cout << "������ڶ�������ÿ�пո�ָ����س����У���" << endl;
    cin >> int_matrix2;
    cout << "����ӷ������" << endl << int_matrix1 + int_matrix2 << endl;
    cout << "������������" << endl << int_matrix1 - int_matrix2 << endl;
    cout << "����˷������" << endl << int_matrix1 * int_matrix2 << endl;


    return 0;
}
����
������������ݣ������������������������;���
���

�������� Copy
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
������� Copy
����������������
�����ӷ������9
�������������1
�����˷������20
����������˫���ȸ�������
˫���ȸ������ӷ������9.5
˫���ȸ��������������-1.1
˫���ȸ������˷������22.26
�������һ�����������ո�ָ�����
������ڶ������������ո�ָ�����
�����ӷ������5 7 8
�������������-3 -3 -2
������˽����29
�������һ������ע���һ�������������к��У�Ȼ�����������ÿ�пո�ָ����س����У���
������ڶ�������ÿ�пո�ָ����س����У���
����ӷ������
9 14
13 13

������������
-7 -4
-1 -3

����˷������
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
    cout << "����������������" << endl;
    T_Counter<int> int_counter1, int_counter2;
    cin >> int_counter1 >> int_counter2;
    cout << "�����ӷ������" << int_counter1 + int_counter2 << endl;
    cout << "�������������" << int_counter1 - int_counter2 << endl;
    cout << "�����˷������" << int_counter1 * int_counter2 << endl;

    cout << "����������˫���ȸ�������" << endl;
    T_Counter<double> double_counter1, double_counter2;
    cin >> double_counter1 >> double_counter2;
    cout << "˫���ȸ������ӷ������" << double_counter1 + double_counter2 << endl;
    cout << "˫���ȸ��������������" << double_counter1 - double_counter2 << endl;
    cout << "˫���ȸ������˷������" << double_counter1 * double_counter2 << endl;

    cout << "�������һ�����������ո�ָ�����" << endl;
    T_Vector<int> int_vector1, int_vector2;
    cin >> int_vector1;
    cout << "������ڶ������������ո�ָ�����" << endl;
    cin >> int_vector2;
    cout << "�����ӷ������" << int_vector1 + int_vector2 << endl;
    cout << "�������������" << int_vector1 - int_vector2 << endl;
    cout << "������˽����" << int_vector1 * int_vector2 << endl;

    cout << "�������һ������ע���һ�������������к��У�Ȼ�����������ÿ�пո�ָ����س����У���" << endl;
    T_Matrix<int> int_matrix1, int_matrix2;
    cin >> int_matrix1;
    cout << "������ڶ�������ÿ�пո�ָ����س����У���" << endl;
    cin >> int_matrix2;
    cout << "����ӷ������" << endl
         << int_matrix1 + int_matrix2 << endl;
    cout << "������������" << endl
         << int_matrix1 - int_matrix2 << endl;
    cout << "����˷������" << endl
         << int_matrix1 * int_matrix2 << endl;

    return 0;
}