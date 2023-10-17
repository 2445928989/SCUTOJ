/*题目描述
猜数游戏。玩家想好了一个1~1000之内的整数，由计算机来猜这个数。如果计算机猜出的数比玩家想的大，则玩家输入1；如果计算机猜出的数比玩家想的数小，则玩家输入-1；这个过程一直进行到计算机猜中为止，玩家输入0。（为了方便程序测试，此处定义玩家猜测的数字是210）
输入
用户输入的1 或者-1 或者0
输出
程序输出猜测的数字，
为注明格式，此处放一张运行截图:(注意这不是正确运行输出，仅做实例参考）*/

#include<iostream>
using namespace std;
int main()
{
	int x=1,num[3]={0,500,1000}, time = 1;
	cout << 500 << endl;
	while (x != 0) {
		cin >> x;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2 - i; j++) {
				if (num[j] > num[j + 1]) {
					swap(num[j], num[j + 1]);
				}
			}
		}
		if (x == 1) {
			num[2] = (num[0] + num[1]) / 2;
			cout << num[2]<<endl;
			time++;
		}
		else if (x == -1) {
			num[0] = (num[1] + num[2]) / 2;
			cout << num[0] << endl;
			time++;
		}
	}
	cout << "猜了" << time << "次\n";
	system("pause");
}
