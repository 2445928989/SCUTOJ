/*题目描述
把以下程序中的 print()函数改写为等价的递归函数。
#include <iostream>
using namespace std;
void print ( int w )
{ for( int i = 1 ; i <= w ; i ++)
{ for ( int j = 1 ; j <= i ; j ++)
cout << i << ” ” ;
cout << endl ;
}
}
int main ()
{ print( 5 ) ; }
运行显示：
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5

输入
无
输出
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
（注意以一个空格间隔）*/

#include <iostream>
using namespace std;
void print(int a,int w)
{
	if (a > w) return;
	for (int i = 0; i < a; i++)cout << a << " ";
	cout << endl;
	a++;
	print(a, w);
}
int main()
{
	int a = 1;
	print(a,5);
	system("pause");
}
