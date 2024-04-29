#include <iostream>

int sum(int myNum) {

	int sum= 0;

	for (int i= 0; i <= myNum; i++) {

		sum= i + sum;		
	
		};

	return sum;

	};


int main() {

	std::cout << sum(10);
	std::cout << "\n";

}
