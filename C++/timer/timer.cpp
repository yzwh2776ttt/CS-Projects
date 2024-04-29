#include <iostream>
#include <unistd.h>

// This program outputs the message "Hello World!" to the monitor

int main(){
	
	int minutes = 5;
	int seconds = minutes * 60;
	
	std:: cout << "Hello World!\n";

	for (int i = 1; i <= seconds; i++) {

		int minutes_remaining = (seconds - i ) / 60;
		int seconds_remaining = (seconds - i ) % 60;
		std:: cout << minutes_remaining << " Minutes and " << seconds_remaining <<  " Seconds\n";
		sleep(1);

	}
	return 0;

	}

