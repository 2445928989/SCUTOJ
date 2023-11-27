/*题目描述
已知XYZ+YZZ=532，其中X、Y和Z为数字，编写程序求出X、Y和Z的值
输入
无
输出
X Y Z的值，如
x=
y=
z=*/

#include<iostream>
using namespace std;
int main() {
    for (int x = 1; x <= 9; x++) {
        for (int y =1; y <= 9; y++) {
            for (int z = 1; z <= 9; z++) {
                 
                if (x *100+ y *10+ z + y *100+ z *10+ z == 532) {
                    cout << "x=" << x << endl << "y=" << y << endl << "z=" << z << endl;
 
                }
            }
 
        }
    }
    system("pause");
    return 0;
}
