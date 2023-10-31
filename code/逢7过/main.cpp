#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char *argv[]) {
	
	for(int i=1;i<101;i++){
		if(i%7==7||i%7==0||i/10==7){
			cout<<i<<endl;
		}
	}
	return 0;
}
