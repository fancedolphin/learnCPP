#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

int scores[3][3] =
{
    {100,100,100},
    {90,50,100},
    {60,70,80},
};

string names[3] = { "张三","李四","王五" };

for (int i = 0; i < 3; i++)
{
    int sum = 0;
    for (int j = 0; j < 3; j++)
    {
        sum += scores[i][j];
    }
    cout << names[i] << "同学总成绩为： " << sum << endl;
    cout<<&names[0]<<endl;
}

system("pause");

return 0;}
