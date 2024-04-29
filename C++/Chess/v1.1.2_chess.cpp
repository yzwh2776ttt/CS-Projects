#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

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

Im realizing I really messed up everything when I was in college.. I got kicked out of the math department Freshman year when I
kinda hated having to go to office hours. Like now all I want to do is talk about things in mathematics.. but no one else likes math it seems
or at least they dont really want to talk about things in math. I guess everyone else has already mastered math is applying it to something more.

	"Every good physist knows 8 or 9 different ways to describe the same physics." - A quote from a lecture I watched

Im learning my first, and I think everyone else has already passed the check points im at, and thats okay.
Im just sad I rejected myself from the math department...
I was too stupid to get into the computer science department. 
Thats what this project has taught me so far.
It was moving downtown next semester, last I heard.
Im trying to remember all the projects I had to do.
I wanna sit in on 162.. but im not sure if Id be able to. 

So we can treat a chess board as a system, and it has properties that give it a state. From there we can do physics on it.

	Properties of a chess board:

		- It has some volume (# of spaces)
		- It has pieces (# of particles)
		
	Properties of pieces:
		
		- Color (White or Black)
		- Mass (Some # that disquisuishes equivalent pieces on a given team)
		- Position (Which space the piece occupies)
		
There are then three cases:
		
	(1) A space on the board is empty

	(2) A space is occupied by some white piece (+mass)

	(3) A space is occupied by some black piece (-mass)

Im still not sure how any of this is getting to how to print the chess board.. but continue. 

Like I get that were trying to do Linear Regression (???) but where does that get with printing out case-wise..
I guess because every piece has to be tracked individually. Which is now another thing, how do we disguish multiples of identical pieces occupying
different spaces. I think I want to select which piece to move only by the position, but the computer still needs to know the pieces seperately
so it can print them. Actually know that I think about it, the computer only needs to know the mass of each body (white, black, free).
Maybe not. Fuck dude, how do I print this! I know theres any easier way to do than case-wise. Theres always an easier way.

	A king is in checkmate if it has no valid moves available.
	What is a valid move.
	A move 1 space along either a row or column, or a move along either diagonal where there is no piece of the same sign mass;
	and where no piece of opposite mass has a valid move.

This brings into view that each piece of different mass has a different set of valid moves.
I guess we can think of these as the set of velocities. Thus each piece has a momentum. 
So what does that mean in terms of possible states. The set of valid moves for a given piece is its momentum.

	"A knight has a maxium of 8 possible moves. We would say the knight has a velocity of 8, in this case.
	 
	 Suppose a piece blocks one the possible moves. Then the knight has a velocity of 7. Now consider the case where the rook
	 can move freely along either a row or column. Assuming there are no pieces blocking the rook also has 7 possible moves.
	 We then say the rook has a velocity of 7 in this case. However the rook and knight do not have the same momentum, because
	 each piece has a different mass as the rook has a much higher maxium velocity of 14 compared to the knights maximum of 8."

This still has gotten me nothing about how to print whats on the chess board for a given state.

I guess now we should focus on the chess board and the idea that each space is distinguishable.

	- A position either contains some mass or doesnt.   

As far as the chess project goes, I can now read from a file we call 'history.txt' which will contain the state of the board. 
We should now be able to input a command to move a piece (We are telling the computer we would like to move some mass in the future).
From here we can check if it is valid to move that piece by checking if the piece currently resides in the set of velocities for
the future move. 

For now lets finish setting up the chess board and get some pieces on it!

Now im stuck on how to print multiple pieces on the board.

Im getting a memory leak, or in other words, ive written too much code without testing it, and I have no idea how it works. 
So I have to take it apart and put it back together, but im calling it for tonight, ive made a lot of progress.

*/

// Since most of the text is always the same, lets see if I can figure out how to easily swap the center pixels of each square.


int chess_Board[8][8]= {

	{0,0,0,0,0,0,0,0},	
	{0,0,0,0,0,0,0,0},	
	{0,0,0,0,0,0,0,0},	
	{0,0,0,0,0,0,0,0},	
	{0,0,0,0,0,0,0,0},	
	{0,0,0,0,0,0,0,0},	
	{0,0,0,0,0,0,0,0},	
	{0,0,0,0,0,0,0,0}

			};

void get_State(std::string file_Name) {

	std::string state;
	int col;
	int row_int;
	int piece;
	char row;
	
	std::fstream myFile(file_Name);

	getline(myFile, state);
		
	for (int i= 0; i < state.size(); i++) {

		if (i % 3 == 0) {

			piece= state.at(i);

			}

		else if (i % 3 == 1) {

			row= state.at(i);	

			switch (row) {

			case 'A':
				row_int= 1;
				break;

			case 'B':
				row_int= 2;
				break;

			case 'C':
				row_int= 3;
				break;

			case 'D':
				row_int= 4;
				break;

			case 'E':
				row_int= 5;
				break;

			case 'F':
				row_int= 6;
				break;

			case 'G':
				row_int= 7;
				break;
			
			case 'H':
				row_int= 8;
				break;

			default:
				row_int= 0;
				break;

				};

			} 

		else if (i % 3 == 2) {

			col= state.at(i);

			}; 

		chess_Board[col][row_int]= piece;

		};
	
	};

void print_Board() {

	for ( int i= 0; i < 8; i++) {

		if ( i % 2 == 0 ) {
		
			for (int k= 0; k < 3; k++) {	

				if (k == 1) {
				
					for (int j= 0; j < 8; j++) {

						int var= chess_Board[i][j];

						if ( j % 2 == 0) {
							
							switch (var) {

							case '1':
								std::cout << "* \u2654 *";
								break;

							default:
								std::cout << "     ";
								break;
							
								};

							}
	
						else {

							switch (var) {

							case '1':
								std::cout << "  \u2654  ";
								break;
	
							default:
								std::cout << "     ";
								break;

								};

							};
						
						};

					}

				else {

					for (int j= 0; j < 8; j++) {

						if ( j % 2 == 0) {

							std::cout << "* * *";

							}

						else {

							std::cout << "     ";

							};
						
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
	
	get_State("state.txt");

	print_Board();

}



