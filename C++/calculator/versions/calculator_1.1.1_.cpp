#include <iostream>
#include <unistd.h>

/*

(2/6)
This project was inspired by Mad Minutes.

I think what we want to work towards is having a random number generator that we then print
the proof of with varying operations being performed. 

A couple ideas:
	
	- Read file with numbers in it

I guess one idea..

*/

void do_Addition(int val1, int val2) {

	std::cout << "\n";
	
//Line 1
	std::cout << val1;
	std::cout << " + ";
	std::cout << val2;
	std::cout << " = ";
	std::cout << "( ";
	std::cout << (val1 / 10 ) * 10;
	std::cout << " + ";
	std::cout << val1 % 10;
	std::cout << " ) + ( ";
	std::cout << (val2 / 10 ) * 10;
	std::cout << " + ";
	std::cout << val2 % 10;
	std::cout << " )";
	std::cout << "\n";

//Line 2
	std::cout << "\n";
	std::cout << "     ";
	std::cout << " = ";
	std::cout << "( ";
	std::cout << (val1 / 10 ) * 10;
	std::cout << " + ";
	std::cout << (val2 / 10 ) * 10;
	std::cout << " ) + ( ";
	std::cout << val1 % 10;
	std::cout << " + ";
	std::cout << val2 % 10;
	std::cout << " )";
	std::cout << "\n";

//Line 3
	std::cout << "\n";
	std::cout << "     ";
	std::cout << " = ( ";
	std::cout << ((val1 / 10 ) * 10 ) + ((val2 / 10 ) * 10 );
	std::cout << " ) + ( ";
	std::cout << (val1 % 10) + (val2 % 10);
	std::cout << " )";
	std::cout << "\n";

//Line 4
	std::cout << "\n";
	std::cout << "     ";
	std::cout << " = ";
	std::cout << val1 + val2;
	std::cout << "\n";

	std::cout << "		";
	std::cout << "\u220E";
	std::cout << "\n";

	};

int main() {

	for (int i= 0; i < 5; i++ ) {
		
		for(int j= 0; j < 10; j++ ) {

			do_Addition(i, j);
			usleep(1000000);

			};

		};

};
