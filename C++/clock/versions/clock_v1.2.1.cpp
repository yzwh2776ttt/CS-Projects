#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
#include <string>

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
	   and we need a for loop for HEIGHT.

	3) In order to get the scrolling effect, each digit needs its own for loop with 3 conditional in it;
		
		- if condition (1) holds for HOURS and MINUTES respectively;
		- if edge conditions are met (i.e. change from 5 to 0 in the TENS place and change from 9 to 0 in the
		  ONES place;
		- else;

		UPDATE (1/25)
		- 3 Conditions are the ZERO Case, the Updating case, and the Holding case.

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

		UPDATE (1/25)
		
		I didnt end up using these methods; though they were nice to have, I think it was more pedagogical to
		repeatively have to remind myself of when to use '/' vs '%'.

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

	int ZERO[10][6]= {

			{1,1,1,1,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,1,1,1,1},
			{1,1,1,1,1,1}

				};

	int ONES[10][6]= {

			{0,0,1,1,0,0},
			{0,0,1,1,0,0},
			{0,0,1,1,0,0},
			{0,0,1,1,0,0},
			{0,0,1,1,0,0},
			{0,0,1,1,0,0},
			{0,0,1,1,0,0},
			{0,0,1,1,0,0},
			{0,0,1,1,0,0},
			{0,0,1,1,0,0}

				};

	int TWO[10][6]= {

			{1,1,1,1,1,1},
			{1,1,1,1,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{1,1,1,1,1,1},
			{1,1,1,1,1,1},
			{1,1,0,0,0,0},
			{1,1,0,0,0,0},
			{1,1,1,1,1,1},
			{1,1,1,1,1,1}

				};

	int THREE[10][6]= {

			{1,1,1,1,1,1},
			{1,1,1,1,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{1,1,1,1,1,1},
			{1,1,1,1,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{1,1,1,1,1,1},
			{1,1,1,1,1,1}

				};

	int FOUR[10][6]= {

			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,1,1,1,1},
			{1,1,1,1,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1}

				};

	int FIVE[10][6]= {

			{1,1,1,1,1,1},
			{1,1,1,1,1,1},
			{1,1,0,0,0,0},
			{1,1,0,0,0,0},
			{1,1,1,1,1,1},
			{1,1,1,1,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{1,1,1,1,1,1},
			{1,1,1,1,1,1}

				};

	int SIX[10][6]= {

			{1,1,1,1,1,1},
			{1,1,1,1,1,1},
			{1,1,0,0,0,0},
			{1,1,0,0,0,0},
			{1,1,1,1,1,1},
			{1,1,1,1,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,1,1,1,1},
			{1,1,1,1,1,1}

				};

	int SEVEN[10][6]= {

			{1,1,1,1,1,1},
			{1,1,1,1,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1}

				};

	int EIGHT[10][6]= {

			{1,1,1,1,1,1},
			{1,1,1,1,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,1,1,1,1},
			{1,1,1,1,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,1,1,1,1},
			{1,1,1,1,1,1}

				};

	int NINE[10][6]= {

			{1,1,1,1,1,1},
			{1,1,1,1,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,1,1,1,1},
			{1,1,1,1,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1}
		
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
	

void count_UP(int HOURS, int MINUTES, int SECONDS) {

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
			for ( int i= 0; i < 10; i++ ) {

			std::cout << "   ";

			// TENS:HOURS COLUMN for loop
				for ( int j= 0; j < 6; j++ ) {

				// ZERO Condition
					if ( HOURS == 0 && MINUTES == 0 && SECONDS == 0 ) {

						if ( f > i ) {
		
							get_ASCII(0, i, j);

							}

						else {

							get_ASCII(2, i, j);

							};

						}

				// Updating Condition
					else if ( SECONDS == 0 && MINUTES == 0 && HOURS % 10 == 0 && HOURS != 0 ) {

						if ( f > i ) {

							get_ASCII(HOURS / 10, i, j);

							}

						else {

							get_ASCII((HOURS - 1) / 10, i, j);

							};

						}

				// Holding Condition
					else {

						get_ASCII(HOURS / 10, i, j);

						};				

					};

				std::cout << "   ";

			// ONES:HOURS COLUMN for loop
				for ( int j= 0; j < 6; j++ ) {

				//ZERO Condition
					if ( HOURS == 0 && MINUTES == 0 && SECONDS == 0 ) {

						if ( f > i ) {

							get_ASCII(0, i, j);
					
							}

						else {

							get_ASCII(4, i, j);

							};

						}

				// Updating Condition
					else if ( MINUTES == 0 && SECONDS == 0 ) {

						if ( f > i ) {

							get_ASCII(HOURS % 10, i, j);

							}
		
						else {

							get_ASCII((HOURS - 1) % 10, i, j);

							};

						}

				// Holding Condition
					else {

						get_ASCII(HOURS % 10, i, j);

						};
					
					};

				if (i == 1 || i == 3) {

					std::cout << "  *  ";

					}

				else {

					std::cout << "     ";

					};

			//TENS:MINUTES COLUMN for loop
				for ( int j= 0; j < 6; j++ ) {
			
				//ZERO Condition
					if ( MINUTES == 0 && SECONDS == 0 ) {

						if ( f > i ) {

							get_ASCII(0, i, j);

							}

						else {

							get_ASCII(5, i, j);

							};
					
						}

				// Updating Condition
					else if (SECONDS == 0 &&  MINUTES % 10 == 0 && MINUTES != 0 ) {

						if ( f > i ) {

							get_ASCII(MINUTES / 10, i, j);

							}

						else {

							get_ASCII((MINUTES - 1) / 10, i, j);

							};

						}

				// Holding Condition
					else {

						get_ASCII(MINUTES / 10, i, j);

						};

					};

				std::cout << "   ";


			//ONES:MINUTES COLUMN for loop
				for ( int j= 0; j < 6; j++ ) {

				// ZERO Condition 
					if ( SECONDS == 0 && MINUTES == 0) {

						if ( f > i ) {

							get_ASCII(0, i, j);

							}

						else {

							get_ASCII(9, i, j);

							};
						
						}

				// Update Condition
					else if ( SECONDS == 0 ) {

						if ( f > i ) {

							get_ASCII(MINUTES % 10, i ,j);

							}

						else {

							get_ASCII((MINUTES - 1) % 10, i, j);

							};

						}

				// Holding Condition
					else {

						get_ASCII(MINUTES % 10, i, j);

						};

					};

				if (i == 1 || i == 3) {

					std::cout << "  *  ";

					}

				else {

					std::cout << "     ";

					};

			//TENS:SECONDS COLUMN for loop
				for ( int j= 0; j < 6; j++ ) {

				// ZERO Condition
					if ( SECONDS == 0 ) {

						if ( f > i ) {

							get_ASCII(0, i, j);

							}

						else {

							get_ASCII(5, i, j);

							};

						}

				// Update Condition
					else if ( SECONDS % 10 == 0 && SECONDS != 0 ) {

						if ( f > i ) {

							get_ASCII(SECONDS / 10, i, j);

							}
					
						else {

							get_ASCII((SECONDS - 1) / 10, i, j);

							};

						}

				// Hold Condition
					else {

						get_ASCII( SECONDS / 10, i, j);

						};

					};

				std::cout << "   ";

			//ONES:SECONDS COLUMN for loop
				for ( int j= 0; j < 6; j++ ) {

				// ZERO Condition
					if ( SECONDS == 0 ) {

						if ( f > i ) {

							get_ASCII( 0, i, j );
			
							}
				
						else {

							get_ASCII( 9, i, j );;

							};
							
						}

				// Update Condition
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

	count_UP(0, 0, 0);

	};

int main() {

	std::string myString;

// Opens "parameters.txt" which will store time data 
	std::fstream File1("parameters.txt");

// Read from "parameters.txt" into a string
	getline(File1, myString);

// Finds the SECONDS substring
	int pos1= myString.find("SECONDS");
	int pos2= myString.find(";");

// Creates the SECONDS substring
	std::string str_SECONDS= myString.substr(pos1, pos2);

// Finds the SECONDS INT
	pos1= str_SECONDS.find(" ");
	pos2= str_SECONDS.find(";");

// In one step we create a substring for the SECONDS INT and convert to an INT
	int SECONDS= std::stoi(str_SECONDS.substr(pos1, pos2));

// Finds the MINUTES substring
	pos1= myString.find("MINUTES");
	pos2= myString.find(";");

// Creates the MINUTES substring
	std::string str_MINUTES= myString.substr(pos1, pos2);

// Finds the MINUTES INT
	pos1= str_MINUTES.find(" ");
	pos2= str_MINUTES.find(";");

// In one step we create a substring for the MINUTES INT and convert to an INT
	int MINUTES= std::stoi(str_MINUTES.substr(pos1, pos2));

// Finds the HOURS substring
	pos1= myString.find("HOURS");
	pos2= myString.find(";");

// Creates the HOURS substring
	std::string str_HOURS= myString.substr(pos1, pos2);

// Finds the HOURS INT
	pos1= str_HOURS.find(" ");
	pos2= str_HOURS.find(";");

// In one step we create a substring for the HOURS INT and convert to an INT
	int HOURS= std::stoi(str_HOURS.substr(pos1, pos2));

	File1.close();
	
	count_UP(HOURS, MINUTES, SECONDS);

	};



