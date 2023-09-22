# 结构体

## 结构体使用

```c++
//结构体定义
struct student
{
    //成员列表
    string name;  //姓名
    int age;      //年龄
    int score;    //分数
}stu3; //结构体变量创建方式3 


int main() {

    //结构体变量创建方式1
    struct student stu1; //struct 关键字可以省略

    stu1.name = "张三";
    stu1.age = 18;
    stu1.score = 100;

    cout << "姓名：" << stu1.name << " 年龄：" << stu1.age  << " 分数：" << stu1.score << endl;

    //结构体变量创建方式2
    struct student stu2 = { "李四",19,60 };

    cout << "姓名：" << stu2.name << " 年龄：" << stu2.age  << " 分数：" << stu2.score << endl;


    stu3.name = "王五";
    stu3.age = 18;
    stu3.score = 80;


    cout << "姓名：" << stu3.name << " 年龄：" << stu3.age  << " 分数：" << stu3.score << endl;

    system("pause");

    return 0;
}
```

**总结1:**  定义结构体时的关键字是struct，不可省略

**总结2：** 创建结构体变量时，关键字struct可以省略

**总结3：** 结构体变量利用操作符 ''.'' 访问成员

## 结构体数组

**作用：** 将自定义的结构体放入到数组中方便维护

语法： struct  结构体名 数组名[元素个数] = {  {} , {} , ... {} }

```c++

//结构体定义
struct student
    {
    //成员列表
    string name;  //姓名
    int age;      //年龄
    int score;    //分数
    }

int main() {

    //结构体数组
    struct student arr[3]=
    {
        {"张三",18,80 },
        {"李四",19,60 },
        {"王五",20,70 }
    };

    for (int i = 0; i < 3; i++)
    {
        cout << "姓名：" << arr[i].name << " 年龄：" << arr[i].age << " 分数：" << arr[i].score << endl;
    }

    system("pause");

    return 0;
    }
```

## 结构体指针

**作用：** 通过指针访问结构体中的成员

利用操作符 -> 可以通过结构体指针访问结构体属性

```c++
//结构体定义
struct student
{
    //成员列表
    string name;  //姓名
    int age;      //年龄
    int score;    //分数
};


int main() {

    struct student stu = { "张三",18,100, };

    struct student * p = &stu;

    p->score = 80; //指针通过 -> 操作符可以访问成员

    cout << "姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;

    system("pause");

    return 0;
}
```

## 结构体做函数参数

**作用：** 将结构体作为参数向函数中传递

传递方式有两种：
值传递 地址传递

```c++

//学生结构体定义
struct student
{
    //成员列表
    string name;  //姓名
    int age;      //年龄
    int score;    //分数
};

//值传递
void printStudent(student stu )
{
    stu.age = 28;
    cout << "子函数中 姓名：" << stu.name << " 年龄： " << stu.age  << " 分数：" << stu.score << endl;
}

//地址传递
void printStudent2(const student *stu)
{
    //stu->age = 28; //失败 const修饰整体
    cout << "子函数中 姓名：" << stu->name << " 年龄： " << stu->age  << " 分数：" << stu->score << endl;
}

int main() {

    student stu = { "张三",18,100};
    //值传递
    printStudent(stu);
    cout << "主函数中 姓名：" << stu.name << " 年龄： " << stu.age << " 分数：" << stu.score << endl;

    cout << endl;

    //地址传递
    printStudent2(&stu);
    cout << "主函数中 姓名：" << stu.name << " 年龄： " << stu.age  << " 分数：" << stu.score << endl;

    system("pause");

    return 0;
}
```

## 结构体案例

### example 1

学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，
    设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员
    学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值

```c++

struct Student
{
string name;
int score;
};
struct Teacher
{
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

int main() {

srand((unsigned int)time(NULL)); //随机数种子 头文件 #include <ctime>

Teacher tArray[3]; //老师数组

int len = sizeof(tArray) / sizeof(Teacher);

allocateSpace(tArray, len); //创建数据

printTeachers(tArray, len); //打印数据

system("pause");

return 0;
}
```

### 案例2

设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。

通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。

五名英雄信息如下：

		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},

```c++
//英雄结构体
struct hero
{
string name;
int age;
string sex;
};
//冒泡排序
void bubbleSort(hero arr[] , int len)
{
for (int i = 0; i < len - 1; i++)
{
    for (int j = 0; j < len - 1 - i; j++)
    {
        if (arr[j].age > arr[j + 1].age)
        {
            hero temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}
}
//打印数组
void printHeros(hero arr[], int len)
{
for (int i = 0; i < len; i++)
{
    cout << "姓名： " << arr[i].name << " 性别： " << arr[i].sex << " 年龄： " << arr[i].age << endl;
}
}

int main() {

struct hero arr[5] =
{
    {"刘备",23,"男"},
    {"关羽",22,"男"},
    {"张飞",20,"男"},
    {"赵云",21,"男"},
    {"貂蝉",19,"女"},
};

int len = sizeof(arr) / sizeof(hero); //获取数组元素个数

bubbleSort(arr, len); //排序

printHeros(arr, len); //打印

system("pause");

return 0;
}
```
