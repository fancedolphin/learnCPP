#include <iostream>
#include <ctime>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Student{
	string name;
	int score;
};
struct Teacher{
	string name;
	Student sArray[5];
	
};

void allocateSpace(Teacher tArray[] , int len)
{
string tName = "教师";
string sName = "学生";
string nameSeed = "ABCDE";
for (int i = 0; i < len; i++)
{
    tArray[i].name = tName + nameSeed[i];
    
    for (int j = 0; j < 5; j++)
    {
        tArray[i].sArray[j].name = sName + nameSeed[j];
        tArray[i].sArray[j].score = rand() % 61 + 40;
    }
}
}

void printTeachers(Teacher tArray[], int len)
{
for (int i = 0; i < len; i++)
{
    cout << tArray[i].name << endl;
    for (int j = 0; j < 5; j++)
    {
        cout << "\t姓名：" << tArray[i].sArray[j].name << " 分数：" << tArray[i].sArray[j].score << endl;
    }
}
}

int main(int argc, char** argv) {
srand((unsigned int)time(NULL)); //随机数种子 头文件 #include <ctime>

Teacher tArray[3]; //老师数组

int len = sizeof(tArray) / sizeof(Teacher);

allocateSpace(tArray, len); //创建数据

printTeachers(tArray, len); //打印数据

system("pause");

return 0;
	
	return 0;
}
