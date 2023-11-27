/*求表达式 x+xx+xxx+…+xxx…x之和，其中x是任意一位数字，累加的项数以及每个加数上的数字位数由n决定。例如当n=5, x为3时，则为求3+33+333+3333+33333之和。程序的输入为x和n，输出为上述表达式的和数。
（提示：有多组输入数据）*/

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int x,n;
    while(cin>>x>>n){
        int num=0,sum=0;
        for(int i=0;i<n;i++){
            num+=x*pow(10,i);
            sum+=num;   
        }
        cout<<sum<<endl;
    }
    return 0; 
}
