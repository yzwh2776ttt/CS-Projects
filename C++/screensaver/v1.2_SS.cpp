#include <iostream>
#include <unistd.h>

int ROW= 38;
int spin1= 1;
int x= 0;

void fill_screen(int row) {

	while (1 + 1 == 2) {

		switch (spin1) {
		case 1:

			for (int i= 0; i < ROW; i++) {

				std::cout << "\n";

				for (int j= ROW; j > i; j--) {

					std::cout << "  ";

					};

				std::cout << "* * * ";
				std::cout << "\n";
			
				for (int j= ROW; j > i; j--) {

					std::cout << "  ";

					};

				std::cout << "* * * ";
				std::cout << "\n";
			
				for (int j= ROW; j > i; j--) {

					std::cout << "  ";

					};

				std::cout << "* * * ";
				std::cout << "\n";

				usleep(100000);

				};

			spin1= -1;

		case -1:

			for (int i= 0; i < ROW; i++) {

				std::cout << "\n";

				for (int j= 0; j < i; j++) {

					std::cout << "  ";

					};

				std::cout << "* * * ";
				std::cout << "\n";
			
				for (int j= 0 ; j < i; j++) {

					std::cout << "  ";

					};

				std::cout << "* * * ";
				std::cout << "\n";
			
				for (int j= 0; j < i; j++) {

					std::cout << "  ";

					};

				std::cout << "* * * ";
				std::cout << "\n";

				usleep(100000);

				};

			spin1= 1;

			};

		};

	};

int  main() {

	fill_screen(ROW);

}
