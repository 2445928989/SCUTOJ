/*计算某个日期是星期几。已知2018年10月29日是星期一，请编写程序，输入任何一个合法日期，输出星期几的信息。输入为：年月日，输出为星期。如输入为：2018 10 28， 输出为：7；输入为2018 10 31， 输出为：3。
（提示：有多组输入数据）*/

#include<iostream>
using namespace std;
int main() {
    int year, month, day;
    while (cin >> year >> month >> day) {
        int delta_day = 0;
        if (year < 2000) {
            for (int i = 1999; i >= year; i--) {
                if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) delta_day -= 366;
                else delta_day -= 365;
            }
        }
        else {
            for (int i = 2001; i <= year; i++) {
                if (((i - 1) % 4 == 0 && (i - 1) % 100 != 0) || (i - 1) % 400 == 0) delta_day += 366;
                else delta_day += 365;
            }
        }
        for (int i = 1; i < month; i++)
        {
            switch (i)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:delta_day += 31; break;
            case 4:
            case 6:
            case 9:
            case 11:delta_day += 30; break;
            case 2:
                if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                {
                    delta_day += 29;
                }
                else { delta_day += 28; }
                break;
            }
        }
        delta_day += day - 1;
        if (delta_day % 7 == -6)cout << 7 << endl;
        else if (delta_day % 7 > 1)cout << delta_day % 7 -1 << endl;
        else cout << delta_day % 7+6 << endl;
   
