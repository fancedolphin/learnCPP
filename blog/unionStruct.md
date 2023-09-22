# explicitly initialized elements of the aggregate

## what is aggregate initialized

在C++中使用聚合初始化语法的例子如下：

```c++
// 定义一个结构体类型
struct Point {
    int x;
    int y;
};

// 定义一个类类型
class Date {
public:
    int year;
    int month;
    int day;
};

int main() {
    // 用花括号括起来的初始值列表来初始化一个数组
    int arr[3] = {1, 2, 3};

    // 用花括号括起来的初始值列表来初始化一个结构体对象
    Point p = {10, 20};

    // 用花括号括起来的初始值列表来初始化一个类对象
    Date d = {2023, 9, 8};
}
```

## some problems

```c++
union u { int a; const char* b; };
 
u a = {1};                   // OK: explicitly initializes member `a`
u b = {0, "asdf"};           // error: explicitly initializes two members
 
// C++20 designated initializer lists
u d = {.b = "asdf"};         // OK: can explicitly initialize a non-initial member
u e = {.a = 1, .b = "asdf"}; // error: explicitly initializes two members
```

## explaination

B is wrong because a union can only hold one of its non-static data members at a time. You cannot explicitly initialize two members of a union. You can only initialize the first member of the union, or use a designated initializer to specify which member to initialize.

 If you want to initialize both members of the union, you need to use a struct instead of a union.

 ```c++
 struct s {int a;
    const char* b;
}
 s b = {0, "asdf"};

struct S
{
    int a;
    const char* b;
    int c;
    int d = b[a];
};
 
// initializes ss.a with 1,
//             ss.b with "asdf",
//             ss.c with the value of an expression of the form int{} (that is, 0),
//         and ss.d with the value of ss.b[ss.a] (that is, 's')
S ss = {1, "asdf"};
```

However, d is an int type, so it cannot store a char value directly. Instead, it stores the ASCII code of the character ‘s’, which is 115. If you print d as an int, you will see 115. If you print d as a char, you will see ‘s’. This is because the same binary representation can be interpreted differently depending on the data type.
D:\learningc++\aggregateinit
