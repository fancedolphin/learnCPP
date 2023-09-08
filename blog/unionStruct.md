# Why union need determine the explicitly initialized elements of the aggregate

## example

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
