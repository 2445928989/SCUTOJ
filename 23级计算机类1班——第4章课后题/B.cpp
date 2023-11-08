/*题目描述
输入产生 10 个互不相同的两位整数存放到一维数组中，并输出其中的素数。
输入
10个不同的两位整数
输出
其中存在的素数
样例输入 Copy
11 14 78 65 24 16 35 28 64 88
15 65 32 17 28 16 33 31 13 71
样例输出 Copy
11
17 31 13 71*/

#include<iostream>
using namespace std;
int a[10];
int main()
{
    while (cin >> a[0]) {
        for (int i = 1; i < 10; i++)cin >> a[i];
        for (int i = 0; i < 10; i++) {
            bool flag = 0;
            for (int j = 2; j * j <= a[i]; j++) {
                if (a[i] % j == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}/*注意这题while()里面不能写true或者1！
学校的OJ跳出循环的方式是输入一个非法的数据或者类似于EOF那样的东西，
如果写true而不是cin>>a[0]，他就会认为你只是把这个非法的数据输入进了a[0]里面，
while循环会继续运作而不是跳出，导致答案错误WA！
太抽象了！！！让我交了几十次！！*/
