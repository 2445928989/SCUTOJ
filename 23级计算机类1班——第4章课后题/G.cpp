/*编写一下函数：
（1）      在一个二维数组中形成以下形式的n阶方阵：

（1）      去掉靠边的元素，生成新的n-2 阶方阵；
（2）      求矩阵主对角线以下元素之和；
（3）      以方阵形式输出数组
在 main 函数中调用以上函数进行测试
输入
一个正整数n，表示几阶方阵
输出
新的n-2 阶方阵
主对角线以下元素之和
以方阵形式输出数组（方阵中每行数据以一个空格隔开）

样例输入 Copy
5
样例输出 Copy
1 1 1
2 1 1
3 2 1
30
1 1 1 1 1
2 1 1 1 1
3 2 1 1 1
4 3 2 1 1
5 4 3 2 1*/

//图又双叒叕没了！

#include <iostream>
#include<algorithm>
#include<map>
#include<string>
#include<math.h>
#include<iomanip>
using namespace std;
int n;
int arr[1000][1000];
int main()
{
    while (cin>>n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j >= i)arr[i][j] = 1;
                else arr[i][j] = i - j + 1;
            }
        }
        int sum=0;
        for (int i = 0; i < n-2; i++) {
            for (int j = 0; j < n-2; j++)cout << arr[i][j]<<" ";
            cout << endl;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)sum += arr[i][j];
        }
        cout << sum << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)cout << arr[i][j] << " ";
            cout << endl;
        }
    }
}
