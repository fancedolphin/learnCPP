# Some general problem for pointer

## 空指针野指针

**空指针**：指针变量指向内存中编号为0的空间

**用途：** 初始化指针变量

**注意：** 空指针指向的内存是不可以访问的

**示例1：空指针**

```C++
int main() {

//指针变量p指向内存地址编号为0的空间
int * p = NULL;

//访问空指针报错 
//内存编号0 ~255为系统占用内存，不允许用户访问
cout << *p << endl;

system("pause");

return 0;
}
```

**野指针**：指针变量指向非法的内存空间

**示例2：野指针**

```C++
int main() {

//指针变量p指向内存地址编号为0x1100的空间
int * p = (int *)0x1100;

//访问野指针报错 
cout << *p << endl;

system("pause");

return 0;
}
```

> 总结：空指针和野指针都不是我们申请的空间，因此不要访问。

## const pointer diff

``const int *p1 = &a;`` 表示p1是一个指向const int类型的指针，也就是说，p1可以改变它所指向的对象，但是不能通过p1来修改指向对象的值。 ## 保护对象的内容不被意外修改。

``int * const p2 = &a;`` 表示p2是一个指向int类型的const指针，也就是说，p2不能改变它所指向的对象，但是可以通过p2来修改指向对象的值。 ## 保护指针本身不被意外修改. 

## 指针函数数组

**案例描述：** 封装一个函数，利用冒泡排序，实现对整型数组的升序排序

例如数组：int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };

示例：

```c++
//冒泡排序函数
void bubbleSort(int * arr, int len)  //int * arr 也可以写为int arr[]
{
for (int i = 0; i < len - 1; i++)
{
    for (int j = 0; j < len - 1 - i; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}
}

//打印数组函数
void printArray(int arr[], int len)
{
for (int i = 0; i < len; i++)
{
    cout << arr[i] << endl;
}
}

int main() {

int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
int len = sizeof(arr) / sizeof(int);

bubbleSort(arr, len);

printArray(arr, len);

system("pause");

return 0;
}
```
