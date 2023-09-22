# Some general problem for pointer

## A * and # have 


## const pointer diff

``const int *p1 = &a;`` 表示p1是一个指向const int类型的指针，也就是说，p1可以改变它所指向的对象，但是不能通过p1来修改指向对象的值。 ## 保护对象的内容不被意外修改。

``int * const p2 = &a;`` 表示p2是一个指向int类型的const指针，也就是说，p2不能改变它所指向的对象，但是可以通过p2来修改指向对象的值。 ## 保护指针本身不被意外修改. 