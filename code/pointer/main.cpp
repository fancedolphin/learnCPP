#include <iostream>
using namespace std;

int main() {
	int b = 5;
	int a = 10;

	int * p;
	p = &a; //ָ��ָ������a�ĵ�ַ

	cout << *p << endl; //* ������
	cout << sizeof(p) << endl;
	cout << sizeof(char *) << endl;
	cout << sizeof(float *) << endl;
	cout << sizeof(double *) << endl;
	
		//const���ε���ָ�룬ָ��ָ����Ըģ�ָ��ָ���ֵ�����Ը���
	const int * p1 = &a; 
	p1 = &b; //��ȷ
	//*p1 = 100;  ����
	

	//const���ε��ǳ�����ָ��ָ�򲻿��Ըģ�ָ��ָ���ֵ���Ը���
	int * const p2 = &a;
	//p2 = &b; //����
	*p2 = 100; //��ȷ

    //const������ָ�������γ���
	const int * const p3 = &a;
	//p3 = &b; //����
	//*p3 = 100; //����

	system("pause");
	

	return 0;
}
