#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
int*p=arr;
cout<<sizeof(p)<<endl;

cout << "����������ռ�ڴ�ռ�Ϊ�� " << sizeof(arr) << endl;
cout << "ÿ��Ԫ����ռ�ڴ�ռ�Ϊ�� " << sizeof(arr[0]) << endl;
cout << "�����Ԫ�ظ���Ϊ�� " << sizeof(arr) / sizeof(arr[0]) << endl;

//2������ͨ����������ȡ�������׵�ַ
cout << "�����׵�ַΪ�� " << arr << endl;
cout << "�����е�һ��Ԫ�ص�ַΪ�� " << &arr[0] << endl;
cout << "�����еڶ���Ԫ�ص�ַΪ�� " << &arr[1] << endl;
	return 0;
}
