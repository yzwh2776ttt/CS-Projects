#include <iostream>
#include <unistd.h>

/*
Well I guess were doing this again... because computers are a wonderful tool and the universe is damning sometimes.

So let us formally state our purpose; *clears throat* "Why are you doing all of this" "Too further challenge our
understanding of the universe and to 'get better'."

I wanted to do a sort of recap of what worked last time, what didnt work, and what could be improved.
	
Obviously we were excited to move onto the "root finding", or perhaps better stated as the "synchronization" problem.

But I think we might be able to make a better program and probably do it twice as fast!

List of "things":

	1) HOURS changes when MINUTES == 0, and when SECONDS == 0;

	2) In general we need a for loop for SECONDS, we need a for loop for FRAMES, we need a for loop for the WIDTH,
	   and we need a for loop for the height.

	3) In order to get the scrolling effect, each digit needs its own for loop with 3 conditional in it;
		
		- if condition (1) holds for HOURS and MINUTES respectively;
		- if edge conditions are met (i.e. change from 5 to 0 in the TENS place and change from 9 to 0 in the
		  ONES place;
		- else;

	4) In light of (3), semicolons do not belong between if and else statements

	5) A strategy that seems rewarding was the get_ONES() and get_TENS() methods, along with the get_INT(), get_ASCII(),
	   and convert_ASCII() methods, to efficiently print numbers.
		
		- convert_ASCII(int val): convert_ASCII() is passed a value and conditionally checks which character to
		  print using the value.
 
		- get_ASCII(int val, int i, int j): get_ASCII() is passed an integer val, which is the digit to be
		  displayed; an integer i, which is the ASCII column data, and an integer j, which is the ASCII
		  row data. This method contains the ASCII data in matrix form. Last time I used an 8 X 10 matrix;
		  I think doing a smaller matrix might be good? The clock was a little big (LMAO, personally I LOVE
		  BIG CLOCK), I could do like a standard 3 X 5. So, in final, ill do a 3 X 5 matrix and Id like to formally
		  state that im writing all of this because it will be hard coded, so it is good to have it solved before we		      
		  get into writing the program. 

		- get_INT(int val, int i, int j): get_INT() is passed an integer val, which is the digit to be displayed;
	 	  an integer i, which is the ASCII column data; an integer j, which is the ASCII row data. Calls get_ASCII 

		- get_ONES(int val, int i, int j): get_ONES() 

*/

void convert_ASCII( int val ) {

	if ( val == 0 ) {

		std::cout << " ";

		};

	if ( val == 1 ) {

		std::cout << "*";

		};

	};

void get_ASCII(int val, int i, int j ) {

	int ZERO[5][3]= {

			{1,1,1},
			{1,0,1},
			{1,0,1},
			{1,0,1},
			{1,1,1}

				};

	int ONES[5][3]= {

			{0,1,0},
			{1,1,0},
			{0,1,0},
			{0,1,0},
			{1,1,1}

				};

	int TWO[5][3]= {

			{1,1,1},
			{0,0,1},
			{1,1,1},
			{1,0,0},
			{1,1,1}

				};

	int THREE[5][3]= {

			{1,1,1},
			{0,0,1},
			{1,1,1},
			{0,0,1},
			{1,1,1}

				};

	int FOUR[5][3]= {

			{1,0,1},
			{1,0,1},
			{1,1,1},
			{0,0,1},
			{0,0,1}

				};

	int FIVE[5][3]= {

			{1,1,1},
			{1,0,0},
			{1,1,1},
			{0,0,1},
			{1,1,1}

				};

	int SIX[5][3]= {

			{1,1,1},
			{1,0,0},
			{1,1,1},
			{1,0,1},
			{1,1,1}

				};

	int SEVEN[5][3]= {

			{1,1,1},
			{0,0,1},
			{0,0,1},
			{0,0,1},
			{0,0,1}
				};

	int EIGHT[5][3]= {

			{1,1,1},
			{1,0,1},
			{1,1,1},
			{1,0,1},
			{1,1,1}

				};

	int NINE[5][3]= {

			{1,1,1},
			{1,0,1},
			{1,1,1},
			{0,0,1},
			{0,0,1}
		
				};

	if ( val == 0 ) {

		convert_ASCII(ZERO[i][j]);	
		
		};

	if ( val == 1 ) {

		convert_ASCII(ONES[i][j]);

		};

	if ( val == 2 ) {

		convert_ASCII(TWO[i][j]);

		};

	if ( val == 3 ) {

		convert_ASCII(THREE[i][j]);

		};

	if ( val == 4 ) {

		convert_ASCII(FOUR[i][j]);

		};

	if ( val == 5 ) {

		convert_ASCII(FIVE[i][j]);

		};

	if ( val == 6 ) {

		convert_ASCII(SIX[i][j]);

		};

	if ( val == 7 ) {

		convert_ASCII(SEVEN[i][j]);

		};

	if ( val == 8 ) {

		convert_ASCII(EIGHT[i][j]);

		};

	if ( val == 9 ) {

		convert_ASCII(NINE[i][j]);

		};

	};
	

void count_UP() {

// Variables for counting 
	int HOURS= 0;
	int MINUTES= 59;
	int SECONDS= 30;


// SECONDS for loop
	for ( int t= 0; t < 60 * 60 * 24; t++ ) {

		SECONDS++;

		if ( SECONDS % 60 == 0 ) {

			MINUTES++;
			SECONDS= 0;

			if ( MINUTES % 60 == 0 ) {

				HOURS++;
				MINUTES= 0;

				if ( HOURS % 24 == 0 ) {

					HOURS= 0;

					};

				};

			};

	// FRAMES for loop
		for ( int f= 0; f < 10; f++ ) {

		// ROW for loop
			for ( int i= 0; i < 5; i++ ) {

			std::cout << "   ";

			// TENS:HOURS COLUMN for loop
				for ( int j= 0; j < 3; j++ ) {

					if ( MINUTES == 0 && SECONDS == 0 && HOURS / 10 != 0 ) {

						if ( f < i ) { 

							get_ASCII(HOURS / 10, i, j);
						
							}

						else {

							get_ASCII(HOURS / 10 - 1, i, j);

							};

						}
					
					else if ( MINUTES == 0 && SECONDS == 0 && HOURS == 0 ) {

						if ( f > i ) {
	
							get_ASCII(0, i, j);

							}

						else {

							get_ASCII(2, i, j);

							}; 

						}

					else {

						get_ASCII(HOURS / 10, i, j);

						};

					};

				std::cout << "   ";

			// ONES:HOURS COLUMN for loop
				for ( int j= 0; j < 3; j++ ) {

					get_ASCII(HOURS % 10, i, j);	

					};

				std::cout << "   ";

			//TENS:MINUTES COLUMN for loop
				for ( int j= 0; j < 3; j++ ) {
			
					if ( MINUTES == 0 && SECONDS == 0 ) {

						if ( f > i ) {

							get_ASCII(0, i, j);

							}

						else {

							get_ASCII(5, i, j);

							};
					
						}

					else if ( MINUTES % 10 == 0 && MINUTES != 0 ) {

						if ( f > i ) {

							get_ASCII(MINUTES / 10, i, j);

							}

						else {

							get_ASCII((MINUTES - 1) / 10, i, j);

							};

						}

					else {

						get_ASCII(MINUTES / 10, i, j);

						};

					};

				std::cout << "   ";


			//ONES:MINUTES COLUMN for loop
				for ( int j= 0; j < 3; j++ ) {

					if ( SECONDS == 0 ) {

						if ( f > i ) {

							get_ASCII(MINUTES % 10, i, j);

							}
			
						else {

							get_ASCII((MINUTES - 1) % 10, i, j);

							};

						}

					else if ( MINUTES == 0 && SECONDS == 0 ) {

						if ( f > i ) {

							get_ASCII(0, i, j);

							}

						else {

							get_ASCII(9, i, j);

							};

						}
	
					else {

						get_ASCII(MINUTES % 10, i, j);

						};

					};

				std::cout << "   ";

			//TENS:SECONDS COLUMN for loop
				for ( int j= 0; j < 3; j++ ) {

					if ( SECONDS == 0 ) {

						if ( f > i ) {

							get_ASCII(0, i, j);

							}

						else {

							get_ASCII(5, i, j);

							};

						}

					else if ( SECONDS % 10 == 0 && SECONDS != 0 ) {

						if ( f > i ) {

							get_ASCII(SECONDS / 10, i, j);

							}
					
						else {

							get_ASCII((SECONDS - 1) / 10, i, j);

							};

						}

					else {

						get_ASCII( SECONDS / 10, i, j);

						};

					};

				std::cout << "   ";

			//ONES:SECONDS COLUMN for loop
				for ( int j= 0; j < 3; j++ ) {

					if ( SECONDS == 0 ) {

						if ( f > i ) {

							get_ASCII( 0, i, j );
			
							}
				
						else {

							get_ASCII( 9, i, j );;

							};
							
						}

					else {

						if ( f > i ) {

							get_ASCII( SECONDS % 10, i, j );

							}

						else {

							get_ASCII( (SECONDS - 1) % 10, i, j );

							};

						};						

					};

				std::cout << "   ";
				std::cout << "\n";

				};

			usleep(100000);
			std::cout << "\n";

			};

		};

	count_UP();

	};

int main() {

	count_UP();

	};



