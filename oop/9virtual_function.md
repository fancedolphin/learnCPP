# inheritance with virtual functions

1. non-virtual： 不希望derived class override
2. 虚函数：如果希望子类重新定义，则可以把函数声明为虚函数，但同时你需要自己写一个默认定义。
3. 纯虚函数：自己不给默认，希望子类一定去定义

```c++
class Shape{
public:
    virtual void draw() const = 0; //纯虚函数,pure vitual
    vitual void error(const std::string& msg); //非纯虚函数, impure virtual
    int objectID() const; //non-virtual
}
```

通过子类对象调用父类函数
为什么父类函数会跑到子类执行

子类中没有函数OnFileOpen()，myDoc.OnFileOpen() 的全名是 CDocument::OnFileOpen(&myDoc)，所以才能找到 CDocument类中的OnFileOpen 函数。

CDocument::OnFileOpen(&myDoc); 中传入了 myDoc 的地址，调用Serialize 的时候，编译器通过this 进行调用，即this->Serialize()，而this就是myDoc， 也就调用了CMyDoc 类的Serialized() 函数。

``myDoc.OnFileOpen()``的执行流程：

调用``CDocument``的``OnFileOpen``函数；
在``OnFileOpen`` 函数里调用了CMyDoc的 ``Serialize()`` 函数；
执行完了``Seriazlize()`` 函数后又回到``OnFileOpen()``函数中继续执行；
``OnFileOpen`` 函数执行完毕后，回到``main`` 函数中。

```c++
myDoc.onFileOpen();//CDocument::OnFileOpen(&myDoc);
this>Serialize();//父类读到this，指针指向子类，跳到子类执行内容
```

## 构造和析构顺序

Derived 的构造函数**先调用 Component** 的 default 构造函数，然后调用 **Base 的** default 构造函数，然后才执行自己。

``Derived::Derived(...): Component(), Base() {...}``

Derived 的析构函数首先执行自己，然后调用 Base 的析构函数，然后调用 Component 的析构函数。

``Derived::~Derived(...) {... ~Base(), ~Component() }``

```c++

//自己编写
#include <iostream>
using namespace std;

class Component {
public:
    Component() {
        cout << "Component constructor" << endl;
    }

    bool test() {
        return true;
    }

    ~Component() {
        cout << "Component destructor" << endl;
    }
};

class Base {
public:
    Base() {
        cout << "Base constructor" << endl;
    }

    ~Base() {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
protected:
    Component component;
public:
    Derived() {
        cout << "Derived constructor" << endl;
    }
    bool test() { return component.test(); }

    ~Derived() {
        cout << "Derived destructor" << endl;
    }
};


int main() {
    Derived obj;
    return 0;
}

```
