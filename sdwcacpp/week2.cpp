#include <stdio.h>
#include <iostream>
#include <stdint.h>
using namespace std;

#include <string> // for string class

void addOneTo(uint16_t *x, const uint32_t& num) {
	(*x)+= num;
}

void swapInts(uint16_t& num1,uint16_t& num2) {
	int temp;
	temp = num1;
	num1=num2;
	num2=temp;

}

void sayHello() {
	std::string name; // declare a string object
	std::cout << "Enter your name: ";
	std::cin >> name; // get input from user
	if (name[0] == 'H' || name[0] == 'h') {
		name[0] = '\''; // replace it with an apostrophe
	}
	std::cout << "Hello " << name << "\n"; // print hello message

	int vowels = 0;
	for (int i = 0; i < name.size(); i++) { // loop through each character
		char c = name[i]; // get the current character
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
		        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
			vowels++; // increment vowel count
		}
	}
	std::cout << "Your name has " << vowels << " vowels\n"; // print vowel count

}



int main() {
	uint16_t b=3,a = 2;
	printf("%i\n",b);
	addOneTo(&b,a);
	printf("%i\n",b);
	swapInts(b,a);
	sayHello();
}
typedef struct node *node_ptr; 
struct node 
{ 
int element; 
node_ptr next; 
}; 
typedef node_ptr LIST; 
typedef node_ptr position; 

