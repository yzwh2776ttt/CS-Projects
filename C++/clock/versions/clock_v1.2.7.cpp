#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cmath>
#include <time.h>

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

		REMARK (1/28)

		A small list of things that need to be added in the future.

			- Add 'ThisTime' to variables saved to 'parameters.txt'
			
		I thought there were more things.. but I guess not. 

		Im calling it for the night; I left off looking at the conditions for updating ThisTime.

		I think we need to know something about the way ERROR changes, 	
	
		UPDATE (1/30)

		Setting and Getting time data from file is fucked. Need to somehow write 'the ZERO before the 1' to file.. 
		This is making our error function useless.
	
		Im also still not sure why time data isnt being written to file correctly, however count_UP() is still working..



*/

int SECONDS;
int MINUTES;
int HOURS;
int ThisTime= 100000;
int ERROR;

void print_TIME() {

	std::cout << "print_TIME()" << "\n";
	std::cout << "SECONDS= " << SECONDS << "\n";
	std::cout << "MINUTES= " << MINUTES << "\n";
	std::cout << "HOURS= " << HOURS << "\n";
	std::cout << "\n";
	
	};

void set_TIME(std::string file_name) {

	std::fstream File1(file_name);

	File1 << "SECONDS= " << SECONDS << "; ";
	File1 << "MINUTES= " << MINUTES << "; ";
	File1 << "HOURS= " << HOURS << "; ";

	File1.close();

	};

void get_TIME(std::string file_name) {

	std::string myString;

// Opens "parameters.txt" which will store time data 
	std::fstream File1(file_name);

// Read from "parameters.txt" into a string
	getline(File1, myString);

// Finds the SECONDS substring
	int pos1= myString.find("SECONDS");
	int pos2= myString.find(";");

	//std::cout << pos1 << " " << pos2 << "\n";

// Creates the SECONDS substring
	std::string str_SECONDS= myString.substr(pos1, pos2);

	//std::cout << str_SECONDS << "\n";

// Finds the SECONDS INT
	pos1= str_SECONDS.find(" ");
	pos2= str_SECONDS.find(";");

// In one step we create a substring for the SECONDS INT and convert to an INT
	SECONDS= std::stoi(str_SECONDS.substr(pos1, pos2));

	myString.erase(0, str_SECONDS.size() + 1);

	//std::cout << myString << "\n";

// Finds the MINUTES substring
	pos1= myString.find("MINUTES");
	pos2= myString.find(";");

	//std::cout << pos1 << " " << pos2 << "\n";

// Creates the MINUTES substring
	std::string str_MINUTES= myString.substr(pos1, pos2);

	//std::cout << str_MINUTES << "\n";

// Finds the MINUTES INT
	pos1= str_MINUTES.find(" ");
	pos2= str_MINUTES.find(";");

// In one step we create a substring for the MINUTES INT and convert to an INT
	MINUTES= std::stoi(str_MINUTES.substr(pos1, pos2));

	myString.erase(0, str_MINUTES.size() + 1);

	//std::cout << myString << "\n";

// Finds the HOURS substring
	pos1= myString.find("HOURS");
	pos2= myString.find(";");

	//std::cout << pos1 << " " << pos2 << "\n";

// Creates the HOURS substring
	std::string str_HOURS= myString.substr(pos1, pos2);

	//std::cout << str_HOURS << "\n";

// Finds the HOURS INT
	pos1= str_HOURS.find(" ");
	pos2= str_HOURS.find(";");

// In one step we create a substring for the HOURS INT and convert to an INT
	HOURS= std::stoi(str_HOURS.substr(pos1, pos2));

	myString.erase(0, str_HOURS.size() + 1);

	//std::cout << myString << "\n";
	//std::cout << "\n";

	File1.close();
	
	};	

void convert_ASCII( int val ) {

	if ( val == 0 ) {

		std::cout << " ";

		};

	if ( val == 1 ) {

		std::cout << "|";

		};

	if ( val == 2 ) {

		std::cout << "/";

		};

	if ( val == 3 ) {


		};

	if ( val == 4 ) {

		std::cout << "=";

		};

	};

void get_ASCII(int val, int i, int j ) {

	int ZERO[10][6]= {

			{1,1,4,4,4,4},
			{1,1,4,4,4,4},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{4,4,4,4,1,1},
			{4,4,4,4,1,1}

				};

	int ONES[10][6]= {

			{0,0,2,2,0,0},
			{0,2,2,1,0,0},
			{2,2,1,1,0,0},
			{0,0,1,1,0,0},
			{0,0,1,1,0,0},
			{0,0,1,1,0,0},
			{0,0,1,1,0,0},
			{0,0,1,1,0,0},
			{0,0,1,1,0,0},
			{0,4,4,4,4,0}

				};

	int TWO[10][6]= {

			{4,4,4,4,4,4},
			{4,4,4,4,4,4},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{4,4,4,4,1,1},
			{4,4,4,4,1,1},
			{1,1,0,0,0,0},
			{1,1,0,0,0,0},
			{1,1,4,4,4,4},
			{1,1,4,4,4,4}

				};

	int THREE[10][6]= {

			{4,4,4,4,4,4},
			{4,4,4,4,4,4},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{4,4,4,4,4,4},
			{4,4,4,4,4,4},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{4,4,4,4,4,4},
			{4,4,4,4,4,4}

				};

	int FOUR[10][6]= {

			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,4,4,4,4},
			{1,1,4,4,4,4},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1}

				};

	int FIVE[10][6]= {

			{4,4,4,4,4,4},
			{4,4,4,4,4,4},
			{1,1,0,0,0,0},
			{1,1,0,0,0,0},
			{1,1,4,4,4,4},
			{1,1,4,4,4,4},
			{0,0,0,0,1,1},
			{0,0,0,0,1,1},
			{4,4,4,4,1,1},
			{4,4,4,4,1,1}

				};

	int SIX[10][6]= {

			{4,4,4,4,4,4},
			{4,4,4,4,4,4},
			{1,1,0,0,0,0},
			{1,1,0,0,0,0},
			{1,1,4,4,1,1},
			{1,1,4,4,1,1},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{1,1,4,4,4,4},
			{1,1,4,4,4,4}

				};

	int SEVEN[10][6]= {

			{4,4,4,4,4,4},
			{4,4,4,4,4,4},
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

			{1,1,4,4,4,4},
			{1,1,4,4,4,4},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{4,4,4,4,1,1},
			{1,1,4,4,4,4},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{4,4,4,4,1,1},
			{4,4,4,4,1,1}

				};

	int NINE[10][6]= {

			{1,1,4,4,4,4},
			{1,1,4,4,4,4},
			{1,1,0,0,1,1},
			{1,1,0,0,1,1},
			{4,4,4,4,1,1},
			{4,4,4,4,1,1},
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

void compare_TIME( int time1, int time2 ) {

	ERROR= sqrt((pow(time1, 2) + pow(time2, 2)) / 2);

	if ( ThisTime < 10000 ) {
		
		ThisTime = 10000;

		}

	else if ( time2 - time1 <  0 ) {

		ThisTime= ThisTime - ( ERROR / 1000);

		}

	else {

		ThisTime= ThisTime + ( ERROR / 1000);

		};

	};

void time_To_Int() {

// Makes some time objects or something, not sure tbh
	char time1[3];
	time_t timer;
	struct tm * timeinfo;
	time(&timer);
	timeinfo= localtime(&timer);

// Gets the current HOUR as an INT
	strftime(time1,3,"%H", timeinfo);
	int myInt1= std::stoi(time1);

// Gets the current MINUTES as an INT
	strftime(time1,3,"%M", timeinfo);
	int myInt2= std::stoi(time1);

// Gets the current SECONDS as an INT
	strftime(time1,3,"%S", timeinfo);
	int myInt3= std::stoi(time1);

// Converts to SECONDS
	int myTime1= (myInt1 * 3600) + (myInt2 * 60) + myInt3;
	
// Calls function to read initial values for HOURS, MINUTES, and SECONDS
	get_TIME("parameters.txt");

// Converts to SECONDS
	int myTime2= (HOURS * 3600) + (MINUTES * 60) + SECONDS;

// Calls function to compare and find the RMS between the two times
	compare_TIME(myTime1, myTime2);
	
	};

void count_UP() {

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

	set_TIME("parameters.txt");

	time_To_Int();

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

		// Proper or Coordinate time or something
			if ( f > 3 && f < 7) {

				if ( (i >= 1 && i <= 3) || (i >= 6 && i <= 8) ) {

					std::cout << "  ###  ";

					}
		
				else {

					std::cout << "       ";

					};

				}

			else {

				std::cout << "       ";

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

				}

		// Proper time mechanism? Or maybe this is coordinate time, idrk
			if ( f > 3 && f < 7) {

				if ( (i >= 1 && i <= 3) || (i >= 6 && i <= 8) ) {

					std::cout << "  ###  ";

					}
		
				else {

					std::cout << "       ";

					};

				}

			else {

				std::cout << "       ";

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

		usleep(ThisTime);
		
		std::cout << "\n";
		std::cout << "ThisTime= " << ThisTime;
		std::cout << "; ERROR= " << ERROR;
		std::cout << "\n";
		std::cout << "-----------------------------------------------";
		std::cout << "\n";

		};

	count_UP();

	};

int main() {

	get_TIME("parameters.txt");

	count_UP();

	};



