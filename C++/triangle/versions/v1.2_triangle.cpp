#include <iostream>
#include <unistd.h>

/* 

(2/18)

Lets try and make this a quick project yeah?

All we gotta do is animate a triangle spinning using only 'std::cout'

If we treat the terminal output as a subset of R^2, then include a time component, we have a R^2 + R system.

We can then create a map from R -> R^2; I.E, For every point in R, there exists (possibly many) points in R^2 which will satisfy some condition.
The points which are true will of course depend on the choosen point in R. 

As a Zeroth level, I could choose some dimension (say 10 X 10) and an interval (say 0 to 10) and hard code each frame of the animation...

Lets do this.

Update: This project got torn apart, but Im learning how to better use instance variables, and Im learning how to better create and use matrices from a code stand point.
I still have a lot to learn about matrices mathematically though. I think I want to look at Analysis again tomorrow and then come back to this project.

*/

int ROW= 10;
int COLUMN= ROW * 2 - 1;

int row= 10;
int column= row * 2 - 1;

void print(int i) {

	if (i == 0) {

		std::cout << "  ";

		}
	
	else {

		std::cout << "$ ";

		};

	};

void animate() {

	for (int t= 0; t < ROW; t++ ) {
	
		std::cout << "\n";
		std::cout << "\n";

		for (int i= 0; i < (ROW - row); i++) {

			std::cout << "\n";

			};

		for (int i= 0; i < row; i++) {
		
			for (int k= 0; k < (ROW - row); k++) {

				std::cout << "  ";

				};
		
			for (int j= 0; j < column; j++) {

				// We now have a 10 x 20 grid. How make triangle? Brain is smooth. Theres a white board in front of me.. Im tempted to use it. I could just use my ipad, but something is compelling me to use the white board. 
		
				if ( i == 0 ) {

					print(1);

					}

				else if ( i == j ) {

					print(1);
					
					}

				else if ( j == column - i - 1) {

					print(1);

					}

				else {

					print(0);

					};
				
				};
			
			std::cout << "\n";
			
			};

		column= column - 2;

		row--;

		usleep(1000000);
		
		animate();

		};

	};

int main(){

	animate();
	
};

