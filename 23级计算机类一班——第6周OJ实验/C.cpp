一个球从空中自由落下，每次落地后反弹为原高度的一半，再落下，再反弹。请编写程序计算需要经过多少次反弹才能静止（反弹的高度小于1mm时，即视为静止）。球在空中一共经历了多少米。输入为：球第一次落下时的高度（单位为米）
  ，输出为：反弹的次数以及经历的米数。（提示：有多组输入数据）

#include<iostream>
#include<iomanip>
using namespace std;
int main() {
    double fall;
    while (cin >> fall) {
        int count = 0;
        double total = fall;
        while (fall > 0.001) {
            count++;
            total += fall;
            fall /= 2;
        }
        cout << count << " " << fixed << setprecision(4) << total << endl;
    }
}
//谴责不给输入输出样例的题目……
