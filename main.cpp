/* ========================================================================
 Name:     main.cpp
 Descr:    Entry point executable to run a single-player ten point bowling game. 
           The included class, BowlingGame, implements the game logic and stores the score sheet.
 Author:   Sanandeesh Kamat 
 Source:   
  ========================================================================= */
// Compile with:
// g++ main.cpp BowlingGame.h BowlingGame.cpp -std=c++11 -o PlayBowling.exe -Wall
// Run with:
// ./PlayBowling.exe


 #include <iostream> // cout, cin
 #include "BowlingGame.h"

int main() {
	// Query User for Total Number of Frames
	int numFrames;	
	std::cout << "Enter the Desired Number of Frames for this Game ..." << std::endl;
	std::cin  >> numFrames;
	if ( (numFrames <= 1)) { // Error Checking (Must be > 1)
		std::cout << "ERROR: numFrames must be >1." << std::endl;
		return 0;
	}

	// Initialize the Bowling Game Class
	BowlingGame bowlingGame = BowlingGame(numFrames);
	
	// Run the Game
	for (int iFrame = 0; iFrame < numFrames; iFrame++) {
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "Playing Frame " << iFrame << std::endl;
		bowlingGame.playNextFrame();
		std::cout << "Total Score: "  << bowlingGame.getScore() << std::endl;
	}
	return 0;
}
