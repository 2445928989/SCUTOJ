/*题目描述
我们一般用年龄表示一个人的大小，但是也可以用月、周、天表示。给定你的出生日期和指定日期，先计算日期有效性，若日期无效，输出"invalid date!"，若当前日期小于出生日期，输出"wrong enddate!"，输出你的月龄（不足1月按1月计算）、周龄（不足1周按1周计算）和天龄，年份范围在1900~3000。
输入
六个int，表示两个日期，一行一个日期
输出
三个int，表示月龄、周龄和天龄
样例输入 Copy
1900 2 29
2000 2 29
2000 12 30
2000 1 30
2000 2 29
2004 2 29
2000 2 29
2000 4 29
样例输出 Copy
invalid date!
wrong enddate!
49 209 1461
2 9 60
提示
闰年满足：年份能被4整除且不能被100整除 或者 能被400整除;一周=7天；一月=30天；*/

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int year, month, day, b_year, b_month, b_day, b_sumday, sumday;
bool runnian(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)return 1;
    return 0;
}
int main() {
    while (cin >> b_year) {
        cin >> b_month >> b_day >> year >> month >> day;
        b_sumday = 0;
        sumday = 0;
        bool flag = 0;
        if (b_month > 12 || b_month < 1 || month > 12 || month < 1 ) {
            flag = 1;
        }
        switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: {
            if (day > 31 || day <= 0) {
                flag = 1;
            }
            break;
        }
        case 4:
        case 6:
        case 9:
        case 11: {
            if (day > 30 || day <= 0) {
                flag = 1;
            }
            break;
        }
        case 2: {
            if ((runnian(year) && (day > 29 || day <= 0)) || (!runnian(year) && (day > 28 || day <= 0))) {
                flag = 1;
            }
            break;
        }
        }
        switch (b_month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: {
            if (b_day > 31 || b_day <= 0) {
                flag = 1;
            }
            break;
        }
        case 4:
        case 6:
        case 9:
        case 11: {
            if (b_day > 30 || b_day <= 0) {
                flag = 1;
            }
            break;
        }
        case 2: {
            if ((runnian(b_year) && (b_day > 29 || b_day <= 0)) || (!runnian(b_year) && (b_day > 28 || b_day <= 0))) {
                flag = 1;
            }
            break;
        }
        }
        if (flag == 1) {
            cout << "invalid date!" << endl;
            continue;
        }
        //上面是判断是否有效
        if (b_year > year || b_year == year && b_month > month || b_year == year && b_month == month && b_day >= day) {
            cout << "wrong enddate!" << endl;
            continue;
        }
        //上面判断是否小于出生日期
        for (int i = b_year; i < year; i++) {
            if (runnian(i))sumday += 366;
            else sumday += 365;
        }
        for (int i = 1; i < month; i++) {
            switch (i) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: {
                sumday += 31;
                break;
            }
            case 4:
            case 6:
            case 9:
            case 11: {
                sumday += 30;
                break;
            }
            case 2: {
                if (runnian(year))sumday += 29;
                else sumday += 28;
                break;
            }
            }
        }
        sumday += day;
        for (int i = 1; i < b_month; i++) {
            switch (i) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: {
                b_sumday += 31;
                break;
            }
            case 4:
            case 6:
            case 9:
            case 11: {
                b_sumday += 30;
                break;
            }
            case 2: {
                if (runnian(b_year))b_sumday += 29;
                else b_sumday += 28;
                break;
            }
            }
        }
        b_sumday += b_day;
        double dday = sumday - b_sumday;
        cout << (int)ceil(dday / 30) << " " << (int)ceil(dday / 7) << " " << (int)dday << endl;
    }
    system("pause");
}
