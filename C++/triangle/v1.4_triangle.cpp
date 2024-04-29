#include <iostream>
#include <unistd.h>

int ROW= 39;

int spin1= -1;
int spin2= -1;

void print(int i) {

	switch (spin2) {

	case -1:

		if (i == 0) {std::cout << "* ";}
		else {std::cout << "  ";};
		break;

	case 1:

		if (i == 0) {std::cout << "  ";}
		else {std::cout << "* ";};
		break;

		};

	};

void get_wave() {

	for (int t= 0; t < ROW; t++) {

		for (int i= 0; i < ROW; i++) {

			switch (spin1) {

			case -1:

				if (i >= t) {print(1);}
				else {print(0);};
				break;

			case 1:

				if (i + 1 >= ROW - t) {print(1);}
				else {print(0);};
				break;

				};

			};

		std::cout << "\n";
		usleep(100000);

		};

	if ( spin1 == 1 && spin2 == 1) {

		spin2= -1;

		}

	else if (spin1 == -1 && spin2 == 1) {

		spin1= 1;
	
		}

	else if (spin1 == -1 && spin2 == -1) {

		spin2= 1;

		}

	else if (spin1 == 1 && spin2 == -1) {

		spin1= -1;

		}

	get_wave();

	};

int main(){	
	
	get_wave();

};

