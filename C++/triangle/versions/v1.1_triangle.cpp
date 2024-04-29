#include <iostream>

/* 

(2/18)

Lets try and make this a quick project yeah?

All we gotta do is animate a triangle spinning using only 'std::cout'

If we treat the terminal output as a subset of R^2, then include a time component, we have a R^2 + R system.

We can then create a map from R -> R^2; I.E, For every point in R, there exists (possibly many) points in R^2 which will satisfy some condition.
The points which are true will of course depend on the choosen point in R. 

As a Zeroth level, I could choose some dimension (say 10 X 10) and an interval (say 0 to 10) and hard code each frame of the animation...

Lets do this.

*/

int animation_Blank[10][10]= {

	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},			
	{0,0,0,0,0,0,0,0,0,0},			
	{0,0,0,0,0,0,0,0,0,0},			
	{0,0,0,0,0,0,0,0,0,0},			
	{0,0,0,0,0,0,0,0,0,0},			
	{0,0,0,0,0,0,0,0,0,0},			
	{0,0,0,0,0,0,0,0,0,0},			
	{0,0,0,0,0,0,0,0,0,0},			
	{0,0,0,0,0,0,0,0,0,0},			

			};



void print(int i) {

	if (i == 0) {

		std::cout << "  ";

		}
	
	else {

		std::cout << "\\ ";

		};

	};

void animate(){

	int animation[10][10]= {

		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},			
		{0,0,0,0,0,0,0,0,0,0},			
		{0,0,0,0,0,0,0,0,0,0},			
		{0,0,0,0,0,0,0,0,0,0},			
		{0,0,0,0,0,0,0,0,0,0},			
		{0,0,0,0,0,0,0,0,0,0},			
		{0,0,0,0,0,0,0,0,0,0},			
		{0,0,0,0,0,0,0,0,0,0},			
		{0,0,0,0,0,0,0,0,0,0},			

				};

	for ( int t= 0; t < 5; t++) {

		for (int i= 0; i < 10; i++) {

			int j= (t * i) % 10;

			if (t * i >= 10) {

				break;

				}

			else {
		
				animation[i][j]= 1;

				};

			};

		for (int i= 0; i < 10; i++) {

			if (t * i >= 10 ) {
				
				break;

				}

			else {

				for (int j= 0; j < 10; j++) {
			
					print(animation[i][j]);

					};

				};

			std::cout << "\n";

			};	
		
		for (int i= 0; i < 10; i++) {

			for (int j= 0; j < 10; j++) {

				animation[i][j] = animation_Blank[i][j];

				};

			};
	
		std::cout << "\n";

		};

	};

int main(){

	animate();

};
