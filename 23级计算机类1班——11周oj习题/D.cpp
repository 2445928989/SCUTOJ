/*题目描述
给定两幅大小相同(m×n个像素点)的黑白图像，请编写程序计算两幅图像的相似度。图像相似度定义：两幅图像对应位置颜色相同的部分占整幅图像的比例。
输入
第一行：2个int， m（行）和n（列），m*n<9999
第二行：m×n个bool，第一幅图像的m×n个像素点的值（0表示白色、1表示黑色），以行为主序输入
第三行：m×n个bool，第二幅图像的m×n个像素点的值（0表示白色、1表示黑色），以行为主序输入

输出
1个double，表示相似度，保留3位小数
样例输入 Copy
2 2
1 1 1 0
0 0 1 0
2 2
0 0 0 1
0 0 0 1
4 5
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1
样例输出 Copy
0.500
1.000
0.900*/

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int m, n;
bool a[10000],b;
int main() {
    while (cin >> m>>n) {
        int same = 0;
        for (int j = 0; j < n * m; j++)cin >> a[j];
        for (int j = 0; j < n * m; j++) {
            cin >> b;
            if (b == a[j])same++;
        }
        cout << fixed << setprecision(3) << (double)same / (m * n) << endl;
    }
    system("pause");
}
