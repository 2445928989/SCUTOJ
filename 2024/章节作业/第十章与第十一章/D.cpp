// ��Ŀ����
// ����һ��C++���룬ɾ��ȫ��ע�����ݣ���ɾ���ԡ�/*��*/���������ı����ԡ� // ����ʼ����ĩ���ı������ɾ��ע�ͺ�Ĵ��롣
//     ����
//         һ�ΰ���ע�͵Ĵ��룬ע���������ݵĸ�ʽ�����Կ��ǲ���vector<string>
//             ���������ͣ�����STOP��ʱ�򣬾�ֹͣ����Ľ���
//                 ���
//                     ɾ��ע�ͺ�Ĵ��룬������ʽ���£�

//                         �������� Copy
// // ʾ������һ������쳲��������е�ǰn���

// #include <iostream>

//     // ����쳲��������еĵ�n��
//     int
//     fibonacci(int n)
// {
//     if (n <= 1)
//     {             // ����ע�ͣ��������
//         return n; // ����n
//     }
//     else
//     {
//         return fibonacci(n - 1) + fibonacci(n - 2); /* ����ע�ͣ�
//             �ݹ����쳲��������еĵ�n��
//             ʹ�ù�ʽF(n) = F(n-1) + F(n-2)
//         */
//     }
// }

// int main()
// {
//     int n;
//     std::cout << "������Ҫ����쳲��������е�ǰn�";
//     std::cin >> n; // ����n

//     int sum = 0; // ��ʼ����Ϊ0
//     for (int i = 0; i < n; ++i)
//     {
//         int fib = fibonacci(i);                                   // �����i��
//         sum += fib;                                               // ���º�
//         std::cout << "��" << i + 1 << "�" << fib << std::endl; // �����i���ֵ
//     }

//     std::cout << "ǰ" << n << "��ĺ�Ϊ��" << sum << std::endl; // ���ǰn��ĺ�

//     return 0; // ����0��ʾ�ɹ�
// }
// STOP
//     ������� Copy ������Ҫ������ַ���������ע�ͣ������� "STOP" ֹͣ���룺
//         ɾ��ע�ͺ�Ľ����

// #include <iostream>

//     int
//     fibonacci(int n)
// {
//     if (n <= 1)
//     {
//         return n;
//     }
//     else
//     {
//         return fibonacci(n - 1) + fibonacci(n - 2);
//     }
// }

// int main()
// {
//     int n;
//     std::cout << "������Ҫ����쳲��������е�ǰn�";
//     std::cin >> n;

//     int sum = 0;
//     for (int i = 0; i < n; ++i)
//     {
//         int fib = fibonacci(i);
//         sum += fib;
//         std::cout << "��" << i + 1 << "�" << fib << std::endl;
//     }

//     std::cout << "ǰ" << n << "��ĺ�Ϊ��" << sum << std::endl;

//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>
    using namespace std;
char c;
int index;
int state;
vector<string> str(10086);
int main()
{
    cout << "������Ҫ������ַ���������ע�ͣ������� \"STOP\" ֹͣ���룺\n";
    while (c = getchar())
    {
        if (state == 0 && c == '/')
            state = 1;
        else if (state == 1 && c == '*')
            state = 2;
        else if (state == 1 && c == '/')
            state = 4;
        else if (state == 1)
        {
            str[index].push_back(c);
            state = 0;
        }

        else if (state == 2 && c == '*')
            state = 3;
        else if (state == 2)
            state = 2;

        else if (state == 3 && c == '/')
            state = 0;
        else if (state == 3)
            state = 2;
        else if (state == 4 && c == '\\')
            state = 9;
        else if (state == 9 && c == '\\')
            state = 9;
        else if (state == 9)
            state = 4;
        else if (state == 4 && c == '\n')
        {
            state = 0;
            index++;
            continue;
        }
        else if (state == 0 && c == '\'')
            state = 5;
        else if (state == 5 && c == '\\')
            state = 6;
        else if (state == 6)
            state = 5;
        else if (state == 5 && c == '\'')
            state = 0;
        else if (state == 0 && c == '\"')
            state = 7;
        else if (state == 7 && c == '\\')
            state = 8;
        else if (state == 8)
            state = 7;
        else if (state == 7 && c == '\"')
            state = 0;
        if (c == '\n')
        {
            index++;
            continue;
        }
        if ((state == 0 && c != '/') || state == 5 || state == 6 || state == 7 || state == 8)
            str[index].push_back(c);
        if (str[index] == "STOP")
        {
            break;
        }
    }
    cout << "ɾ��ע�ͺ�Ľ����\n";
    for (int i = 0; i < index; i++)
        cout << str[i] << endl;
    system("pause");
}