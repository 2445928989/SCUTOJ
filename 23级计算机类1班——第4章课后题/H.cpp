/*题目描述
设某城市三个百货公司某个季度销售电视机的情况和价格如下所示。编写程序，将表数据用数组存放，求各百货公司的电视机营业额。
输入
无
输出
各个百货公司的电视机营业额（注意结果是表明每一个营业额是哪一家公司的，比如：1 5e+05，结果用科学计数法进行表示，三个公司的数据以换行符进行间隔，1表明是第一家百货公司）
样例输入 Copy

样例输出 Copy*/

//是的图又没了但是不重要

#include<map>
#include<iostream>
#include<iomanip>
using namespace std;
double price[3] = { 3500,3300,3800 }, sell[3][3] = { {300,250,150},{200,240,200},{280,210,180} },sum[3];
int main()
{
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                sum[i] += sell[i][j] * price[j];
            }
        }
        cout <<1<<" "<<sum[0] << "\n" << 2 << " " << sum[1] << "\n" << 3 << " " << sum[2];
        system("pause");
}
//double类型会自动把数据转化成科学计数法。
//这题一开始没有补充条件害我错一万次
