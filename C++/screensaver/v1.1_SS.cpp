#include <iostream>

int ROW= 39;

void fill_screen(int row) {

	std::cout << "\n";

	for (int j= 0; j < row / 2; j++) {	

		for (int i= 0; i < row; i++) {

			if ((i / 3) % 2 == 0) { 
			
				std::cout << "* ";

				}

			else {

				std::cout << "  ";

				};

			};

		std::cout << "\n";

		};

	std::cout << "\n";

	};


int  main() {

	fill_screen(ROW);

}
