// 题目描述
// 读入一段C++代码，删除全部注释内容，即删除以“/*…*/”相括的文本和以“ // ”开始到行末的文本，输出删除注释后的代码。
//     输入
//         一段包含注释的代码，注意输入数据的格式，可以考虑采用vector<string>
//             此数据类型，输入STOP的时候，就停止输入的接收
//                 输出
//                     删除注释后的代码，整个格式如下：

//                         样例输入 Copy
// // 示例代码一：计算斐波那契数列的前n项和

// #include <iostream>

//     // 计算斐波那契数列的第n项
//     int
//     fibonacci(int n)
// {
//     if (n <= 1)
//     {             // 单行注释：基本情况
//         return n; // 返回n
//     }
//     else
//     {
//         return fibonacci(n - 1) + fibonacci(n - 2); /* 多行注释：
//             递归计算斐波那契数列的第n项
//             使用公式F(n) = F(n-1) + F(n-2)
//         */
//     }
// }

// int main()
// {
//     int n;
//     std::cout << "请输入要计算斐波那契数列的前n项：";
//     std::cin >> n; // 输入n

//     int sum = 0; // 初始化和为0
//     for (int i = 0; i < n; ++i)
//     {
//         int fib = fibonacci(i);                                   // 计算第i项
//         sum += fib;                                               // 更新和
//         std::cout << "第" << i + 1 << "项：" << fib << std::endl; // 输出第i项的值
//     }

//     std::cout << "前" << n << "项的和为：" << sum << std::endl; // 输出前n项的和

//     return 0; // 返回0表示成功
// }
// STOP
//     样例输出 Copy 请输入要处理的字符串（包括注释），输入 "STOP" 停止输入：
//         删除注释后的结果：

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
//     std::cout << "请输入要计算斐波那契数列的前n项：";
//     std::cin >> n;

//     int sum = 0;
//     for (int i = 0; i < n; ++i)
//     {
//         int fib = fibonacci(i);
//         sum += fib;
//         std::cout << "第" << i + 1 << "项：" << fib << std::endl;
//     }

//     std::cout << "前" << n << "项的和为：" << sum << std::endl;

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
    cout << "请输入要处理的字符串（包括注释），输入 \"STOP\" 停止输入：\n";
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
    cout << "删除注释后的结果：\n";
    for (int i = 0; i < index; i++)
        cout << str[i] << endl;
    system("pause");
}