#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
int*p=arr;
cout<<sizeof(p)<<endl;

cout << "整个数组所占内存空间为： " << sizeof(arr) << endl;
cout << "每个元素所占内存空间为： " << sizeof(arr[0]) << endl;
cout << "数组的元素个数为： " << sizeof(arr) / sizeof(arr[0]) << endl;

//2、可以通过数组名获取到数组首地址
cout << "数组首地址为： " << arr << endl;
cout << "数组中第一个元素地址为： " << &arr[0] << endl;
cout << "数组中第二个元素地址为： " << &arr[1] << endl;
	return 0;
}
