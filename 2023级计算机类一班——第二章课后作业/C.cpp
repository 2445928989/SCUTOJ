/*编写一个程序，输出一张表，内容是 1~256 范围内每个十进制数对应的二进制数、八进制数和十六进制数形式。第1行是标题，用制表符对齐格式(根据输出情况进行调整)显示数值表。提示，八进制数和十六进制数可以直接输出。


输入
无
输出
使用制表符对齐格式的每个数对应的十进制、二进制、八进制、十六进制数，注意二进制和八进制之间制表符的个数选择，得保证对齐（关键提示：128之后）
decimal       binary      octal       hexadecimal
1                1                1            1
2                10              2            2
3                11              3            3
……
*/

#include<iostream>
using namespace std;
int erjinzhi(int a) {
    int i = 0;
    int arr[100] = {};
    for (; i <= 99 && a != 0; i++) {
        arr[i] = a % 2;
        a = a/ 2;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << arr[j];
    }
    return 0;
}
int main()
{
 
    cout << "decimal\tbinary\t\toctal\thexadecimal\n";
    for (int a = 1; a <= 127; a++) {
        cout << dec<<a << "\t";
        erjinzhi(a);
        cout<< "\t\t" << oct<<a << "\t" <<hex<< a << endl;
    }
    for (int a = 128; a <= 256; a++) {
        cout << dec<<a << "\t";
        erjinzhi(a);
        cout << "\t" << oct << a << "\t" << hex << a << endl;
    }
    system("pause");
    return 0;
}
