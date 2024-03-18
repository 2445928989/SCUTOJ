/*题目描述
定义一个Book类，在该类定义中包括以下数据成员和成员函数。
数据成员：bookname（书名）、price （价格）和 number（存书数最）。
成员函数：display 函数显示图书的情况；borrow函数将存书数量减 1，并显示当前存书数量：restore函数将存书数量加1，并显示当时存书数量。
在main 函数中，要求创建某一种图书对象，并对该图书进行简单的显示、借阅和归还管理。
输入
借阅和归还标志：b 、r，是否继续：y， n
输出

如图所示，注意除去字母，其余是中文字符，然后之间没有空格

样例输入 Copy
b
y
r
y
r
n

样例输出 Copy
book
32
1000
b/r:
999
y/n:
b/r:
1000
y/n:
b/r:
1001
y/n:
book
32
1001*/

#include <iostream>
#include <string>
using namespace std;
class Book
{
private:
    string bookname;
    double price;
    int number;

public:
    Book(string str, double p, int n)
    {
        bookname = str;
        price = p;
        number = n;
    }
    void display()
    {
        cout << bookname << endl;
        cout << price << endl;
        cout << number << endl;
    }
    void borrow()
    {
        cout << --number << endl;
    }
    void restore()
    {
        cout << ++number << endl;
    }
};
int main()
{
    Book b1("book", 32, 1000);
    b1.display();
    char stop = 'y';
    char select;
    while (stop == 'y')
    {
        cout << "b/r:\n";
        cin >> select;
        if (select == 'b')
            b1.borrow();
        else
            b1.restore();
        cout << "y/n:\n";
        cin >> stop;
    }
    b1.display();
    system("pause");
}