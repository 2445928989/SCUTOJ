/*编写程序，输出由字符组成的图形。输入为一个字符，及一个正整数。输出为由字符组成的图形，图形的大小由n决定。（提示：有多组输入数据）
输入为： *  1
输出为：   *
输入为：@  2
输出为：  @
          @
        @@@
输入为：#  3
输出为：  #
          #
         ###
          #
         ###
        #####
输入为：*  4
输出为：   *
          *
         ***
          *
         ***
        *****
          *
         ***
        *****
       *******
*/

#include<iostream>
using namespace std;
int main()
{   
    char a;
    int time;
    while(cin>>a>>time){
        for(int j=0;j<time;j++){
            for(int i=0;i<=j;i++){
                for(int y=1;y<time-i;y++){
                    cout<<" ";
                }
                for(float x=0;x<=i;x+=0.5){
                    cout<<a;
                }
                cout<<endl;
            }
        }
    }
    return 0; 
}
