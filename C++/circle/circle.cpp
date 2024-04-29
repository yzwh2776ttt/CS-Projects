#include <iostream>

int max= 3;

int sum(int myNum) {

	int sum= 0;

	for (int i= 0; i <= myNum; i++) {

		sum= i + sum;		
	
		};

	return sum;

	};


void make_circle() {

// State #1

	for (int i= 0; i < max; i++) {

		for (int j= 0; j < max - i; j++) {

			for (int k= 0; k < i; k++) {

				std::cout << "  ";

				};

			std::cout << "* ";
			std::cout << "\n";
			
			};

		};


// State #2

	for (int i= 1; i <= max; i++) {

		for (int j= 0; j < max; j++) {

			std::cout << "  ";

			};

		for (int j= 0; j < sum(i - 1); j++) {

			std::cout << "  ";

			};
		
		for (int k= 0; k < i; k++) {
		
			std::cout << "* ";

			};

		if (i == max) {

			break;

			};

		std::cout << "\n";

		};

// State #3

	for (int i= 0; i < max; i++) {

		

		};

	};

int main() {

	make_circle();

}
