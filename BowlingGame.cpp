#include "BowlingGame.h"

// Constructor
BowlingGame::BowlingGame(int a, bool verbose) {
	numFrames  = a;
	iFrame     = 0;
	bVerbose   = verbose;
	// Initialize Score Sheet as 2D Array of Zeros
	scoreSheet = new int* [numFrames];
	for (int iFrm = 0; iFrm < numFrames; iFrm++) {
		scoreSheet[iFrm] = new int[3];
		scoreSheet[iFrm][0] = 0; // Ball 1
		scoreSheet[iFrm][1] = 0; // Ball 2
		scoreSheet[iFrm][2] = 0; // Bonus
	}
	// Set the Seed for Random Number Generation
	srand( (unsigned)time( NULL ) );
}

BowlingGame::~BowlingGame(void) {
	// Release Memory for Score Sheet
    for (int iFrm = 0; iFrm < numFrames; iFrm++) { delete [] scoreSheet[iFrm]; }
    delete []  scoreSheet;
}

// Query Total Number of Game Frames
int BowlingGame::getNumFrames(){
	return numFrames;
}

// Query Total Number of Game Frames
int BowlingGame::getCurrentFrame(){
	return iFrame;
}

// Query Bowler's Score at a Given Frame
int* BowlingGame::getFrameScore(int iFrm) {
	static int frameScore[3] = {};
	frameScore[0] = scoreSheet[iFrm][0];
	frameScore[1] = scoreSheet[iFrm][1];
	frameScore[2] = scoreSheet[iFrm][2];
	return frameScore;
}

// Query Bowler's Accumulated Score
int BowlingGame::getScore() {
	int totalScore = 0;
	for (int iFrm = 0; iFrm < iFrame; iFrm++) {
		totalScore += (scoreSheet[iFrm][0] + scoreSheet[iFrm][1] + scoreSheet[iFrm][2]);
	}
	return totalScore;
}


// Generate the Result of an Attempted Roll (How many pins knocked down)
// One point is scored for each pin that is knocked over. 
int BowlingGame::calculateRoll() {
	int numPins = rand()%(numPinsLeft+1); // random number from 0 to numPinsLeft
	if (bVerbose) {
		std::cout << "Rolled " << numPins << std::endl;
	}
	return numPins;
}

void BowlingGame::playNextFrame() {
	if (iFrame < numFrames) {
		// Reset Pins to Full
		numPinsLeft = numTotalPins;
		int numPoints;
		// Run Ball One
		numPoints = calculateRoll();
		numPinsLeft -= numPoints;          // Update Num Pins Left
		scoreSheet[iFrame][0] = numPoints; // Update Score Sheet
		// Run Ball Two
		numPoints = calculateRoll();
		numPinsLeft -= numPoints;          // Update Num Pins Left
		scoreSheet[iFrame][1] = numPoints; // Update Score Sheet
		// Announce Frame Outcome Label
		if (bVerbose) {
			std::cout << "Frame " << iFrame << " is ";
			if      (isSTRIKE(iFrame)) { std::cout << "a STRIKE!"    << std::endl;}
			else if (isSPARE(iFrame))  { std::cout << "a SPARE!"     << std::endl;}
			else                       { std::cout << "an Open Frame" << std::endl;}
		}
		// Add Bonus Points to Previous Frame (If Necessary)
		if (iFrame > 0) {addBonusPoints();}
		// Update Frame Index
		iFrame += 1;
	}
	else {
		std::cout << "ERROR: " << iFrame+1 << " Exceeds Total Number of Frames, " << numFrames << std::endl;
		return;
	}
	return;
}

void BowlingGame::addBonusPoints() {
	if (isSTRIKE(iFrame-1)) { // Last Frame was a Strike
		scoreSheet[iFrame-1][2] = (scoreSheet[iFrame][0] + scoreSheet[iFrame][1]);  
	}
	else if (isSPARE(iFrame-1)) { // Last Frame was Spare
		scoreSheet[iFrame-1][2] = (scoreSheet[iFrame][0]);  	
	}
	return;
}

bool BowlingGame::isSTRIKE(int iFrm) {
	if (scoreSheet[iFrm][0] == 10) {return true;}
	else {return false;}
}

bool BowlingGame::isSPARE(int iFrm) {
	if ((scoreSheet[iFrm][0] != 10) && (scoreSheet[iFrm][0]+scoreSheet[iFrm][1] == 10) ) {return true;}
	else {return false;}
}