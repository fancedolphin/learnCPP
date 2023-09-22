# recursion

递：不断传入更小的参数，直到终止条件

归：从最深的函数不断向上return， 并且汇聚

**三个要素**  
1.终止条件：判断从递到归

2.递：一般输入更小参数

3.归：汇集到上一层

```c++
int rec(int n){
    if(n==1){
        return 1;
    }
    int rest= rec(n-1);
    return n+rest;
}
```

## recursion tree

先拿数字记住不懂，继续往下算，懂了最后一个就ok

```c++
int recur(int n){
    //终止条件为：f（1）=0||f（2）=1
    if (n==1 || n==2){
        return n-1;
    }
    int res= recur(n-1)+recur(n-2);
    return res
}
```

## 迭代递归对比

        |迭代                        |递归
适用问题 | 适用于简单循环任务，代码直观 |适用于子问题分解，如树、图、分治、回溯等，代码 结构简洁、清晰

```c++
/* 使用迭代模拟递归 */
int forLoopRecur(int n) {
    // 使用一个显式的栈来模拟系统调用栈
    stack<int> stack;
    int res = 0;
    // 递：递归调用
    for (int i = n; i > 0; i--) {
        // 通过“入栈操作”模拟“递”
        stack.push(i);
    }
    // 归：返回结果
    while (!stack.empty()) {
        // 通过“出栈操作”模拟“归”
        res += stack.top();
        stack.pop();
    }
    // res = 1+2+3+...+n
    return res;
}
```

### 尾递归（不重要）

向下递更小的参数，同时完成归，汇聚。

```c++
int tailRecur(int n, int res){
    if(n==0){
        return res;
    }
    return tailRecur(int n-1, int res+n);
}

```
