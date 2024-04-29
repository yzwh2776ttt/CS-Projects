#include <iostream>

/* 

(2/14) 

Time for a new project because why the fuck not!

NGL im in a heat of angst rn, the tides are turning, the water is raging and now we make waves and ride them!

Fuck Lexie, Fuck Love, Fuck everything. I will become a machine and take down the truest of enemies... Jerome 'Fucking' Powell.

None of that has anything to do with Chess, but I suppose making chess and teaching my computer to play chess will be long term
investment.

"Play Chess, Not Checkers"

	-yzwh2776ttt

(2/15)

Day two, lets actually do some work on this today.

	- A chess board is 8 x 8, alternating color squares
	- I would like to make each square 3 x 3 'pixels' with a unicode chess icon in the (1,1) element
	- We need to keep reference to each square of the board individually so we can move the pieces with commands

*/

// Since most of the text is always the same, lets see if I can figure out how to easily swap the center pixels of each square.

void print_Board() {

	for ( int i= 0; i < 8; i++) {

		if ( i % 2 == 0 ) {
		
			for (int k= 0; k < 3; k++) {

				for (int j= 0; j < 8; j++) {

					if ( j % 2 == 0) {

						std::cout << "* * *";

						}

					else {

						std::cout << "     ";

						};
					
					};

				std::cout << "\n";


				};
				
			}

		else {

			for ( int k= 0; k < 3; k++ ) {

				for (int j= 0; j < 8; j++) {

					if ( j % 2 == 0) {

						std::cout << "     ";

						}

					else {

						std::cout << "* * *";

						};
					
					};

				std::cout << "\n";

				};

			};

		};

	};

		 
int main(){

	print_Board();

}



