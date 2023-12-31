# array

```c++
/* 随机访问元素 */
int randomAccess(int *nums, int size) {
    // 在区间 [0, size) 中随机抽取一个数字
    int randomIndex = rand() % size;
    // 获取并返回随机元素
    int randomNum = nums[randomIndex];
    return randomNum;
}
```

在这个函数中，int *nums 表示一个指向整型数组的指针，而不是一个引用。指针和引用的区别有以下几点：

- 指针是一个变量，它存储了另一个变量的内存地址。指针需要用 * 运算符来解引用，才能访问它所指向的内存位置。引用是一个别名，它是一个已经存在的变量的另一个名称。引用和指针一样，也是通过存储对象的地址来实现的。但引用可以看作是一个常量指针，它会自动解引用，也就是说编译器会为您应用 * 运算符。
- 指针可以被重新赋值，这个特性对于实现链表、树等数据结构很有用。而引用不能被重新赋值，而且必须在初始化时就赋值。
- 指针有自己的内存地址和大小，而引用和原始变量共享同一个内存地址，不占用额外的空间。
- 指针可以直接赋值为 NULL，而引用不能。
- 指针可以有多级间接性，比如指向指针的指针，而引用只能有一级间接性。

在这个函数中，如果使用 int& nums 作为参数，那么就相当于把数组作为一个整体传递给函数，而不是传递数组的首元素地址。这样做会导致数组的长度信息丢失，无法正确地随机访问元素。因此使用 int *nums 更合适。

## 扩容数组

时间复杂度O（n）；

```c++
/* 扩展数组长度 */
int *extend(int *nums, int size, int enlarge) {
    // 初始化一个扩展长度后的数组
    int *res = new int[size + enlarge];
    // 将原数组中的所有元素复制到新数组
    for (int i = 0; i < size; i++) {
        res[i] = nums[i];
    }
    // 释放内存
    delete[] nums;
    // 返回扩展后的新数组
    return res;
}
```

## 删除数组

**/* 删除索引 index 处元素 */
void remove(int *nums, int size, int index) {
    // 把索引 index 之后的所有元素向前移动一位
    for (int i = index; i < size - 1; i++) {
        nums[i] = nums[i + 1];
    }
}
**
时间复杂度高：数组的插入和删除的平均时间复杂度均为 O（n）n为数组长度。
丢失元素：由于数组的长度不可变，因此在插入元素后，超出数组长度范围的元素会丢失。
内存浪费：我们可以初始化一个比较长的数组，只用前面一部分，这样在插入数据时，丢失的末尾元素都是“无意义”的，但这样做也会造成部分内存空间的浪费。

## 数组pros and cons

数组存储在连续的内存空间内，且元素类型相同。这种做法包含丰富的先验信息，系统可以利用这些信息来优化数据结构的操作效率。

**空间效率高:** 数组为数据分配了连续的内存块，无须额外的结构开销。
**支持随机访问:** 数组允许在O(1)时间内访问任何元素。
**缓存局部性:** 当访问数组元素时，计算机不仅会加载它，还会缓存其周围的其他数据，从而借助高速缓存来提升后续操作的执行速度。

连续空间存储是一把双刃剑，其存在以下缺点。

****插入与删除效率低:**当数组中元素较多时，插入与删除操作需要移动大量的元素。
**长度不可变:** 数组在初始化后长度就固定了，扩容数组需要将所有数据复制到新数组，开销很大。
**空间浪费:** 如果数组分配的大小超过了实际所需，那么多余的空间就被浪费了。
