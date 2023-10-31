
#include "../utils/common.hpp"

/* 基于链表实现的栈 */
class LinkedListStack {
  private:
    ListNode *stackTop; // 将头节点作为栈顶
    int stkSize;        // 栈的长度

  public:
    LinkedListStack() {
        stackTop = nullptr;
        stkSize = 0;
    }

    ~LinkedListStack() {
        // 遍历链表删除节点，释放内存
        freeMemoryLinkedList(stackTop);//delete[] staketop;
    }

    /* 获取栈的长度 */
    int size() {
        return stkSize;
    }

    /* 判断栈是否为空 */
    bool isEmpty() {
        return size() == 0;
    }

    /* 入栈 */
    void push(int num) {
        ListNode *node = new ListNode(num);
        node->next = stackTop;
        
        cout<<stackTop<<endl; 
        stackTop = node;
        
        cout<<stackTop<<endl;
        stkSize++;
    }

    /* 出栈 */
    void pop() {
        int num = top();
        ListNode *tmp = stackTop;
        stackTop = stackTop->next;
        // 释放内存
        delete tmp;
        stkSize--;
    }

    /* 访问栈顶元素 */
    int top() {
        if (isEmpty())
            throw out_of_range("栈为空");
        return stackTop->val;
    }

    /* 将 List 转化为 Array 并返回 */
vector<int> toVector() { // 定义一个函数，名字是toVector，没有参数，返回值是vector<int>类型
    ListNode *node = stackTop; // 定义一个指针变量node，指向链表的栈顶元素
    vector<int> res(size()); // 定义一个vector<int>类型的变量res，大小为链表的长度
    for (int i = res.size() - 1; i >= 0; i--) { // 用一个循环，从后往前遍历res中的每个位置
        res[i] = node->val; // 把当前node指向的元素的值赋给res中的对应位置
        node = node->next; // 把node指向下一个链表元素
    }
    return res; // 返回res作为函数的结果
}

};

/* Driver Code */
int main() {
    /* 初始化栈 */
    LinkedListStack *stack = new LinkedListStack();

    /* 元素入栈 */
    stack->push(1);
    stack->push(3);
    stack->push(2);
    stack->push(5);
    stack->push(4);
    cout << "栈 stack = ";
    printVector(stack->toVector());

    /* 访问栈顶元素 */
    int top = stack->top();
    cout << "栈顶元素 top = " << top << endl;

    /* 元素出栈 */
    stack->pop();
    cout << "出栈元素 pop = " << top << "，出栈后 stack = ";
    printVector(stack->toVector());

    /* 获取栈的长度 */
    int size = stack->size();
    cout << "栈的长度 size = " << size << endl;

    /* 判断是否为空 */
    bool empty = stack->isEmpty();
    cout << "栈是否为空 = " << empty << endl;

    // 释放内存
    delete stack;

    return 0;
}
