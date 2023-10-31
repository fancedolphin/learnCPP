# list

```c++
int <vector> nums={1,3,2,4,5};//c++中vector就是list
    /* 尾部添加元素 */
    nums.push_back(1);

    nums.clear();
    cout << "清空列表后 nums = ";
    printVector(nums);

    nums.insert(nums()+3,6);
    nums.erase(nusm()+3);

    nums.insert(nums.end(), nums1.begin(), nums1.end()); 
```

## problems

**C++ STL 里面的 std::list 已经实现了双向链表，但好像一些算法的书上都不怎么直接用这个，
是不是有什么局限性呢?** 

一方面，我们往往更青睐使用数组实现算法，而只有在必要时才使用链表，主要有两个原因。

‧ 空间开销：由于每个元素需要两个额外的指针（一个用于前一个元素，一个用于后一个
元素），所以 std::list 通常比 std::vector 更占用空间。

‧ 缓存不友好：由于数据不是连续存放的，std::list 对缓存的利用率较低。一般情况下，
std::vector 的性能会更好。

另一方面，必要使用链表的情况主要是二叉树和图。栈和队列往往会使用编程语言提供的
stack 和 queue ，而非链表。
