/* ========================================================================
 Descr:    Implements the ten point bowling game logic and stores the score sheet.
 Author:   Sanandeesh Kamat 
 Source:   
  ========================================================================= */
#include  <ctime>    // time()
#include  <cstdlib>  // srand(), rand()
 #include <iostream> // cout

class BowlingGame {	
	// ------------------------------ PRIVATE -------------------------------- //
	private:
	int   numFrames;   // Total number of frames in this game.
    int** scoreSheet = NULL;
    int   iFrame;      // Current frame
    int   numPinsLeft; // Number of pins left during a given frame. (0...10)
    bool  bVerbose;    // Produce cout messages to screen.
    // Generate the Result of an Attempted Roll
    int calculateRoll();
    // Retroactively Add Bonus Points to scoreSheet
    void addBonusPoints();

    // ------------------------------ PUBLIC -------------------------------- //
    public:
    BowlingGame(int, bool = true);
    ~BowlingGame();

    // Query Total Number of Game Frames
    int getNumFrames();
    // Query Current Frame Index
    int getCurrentFrame();
    // Query Bowler's Score at a Given Frame
    int* getFrameScore(int);
    // Query Bowler's Accumulated Score
    int getScore();
    // Run Next Frame
    void playNextFrame();
    // Determine if All Pins were Knocked Down at a Given Frame (For Bonus Points)
    bool isSTRIKE(int);
    bool isSPARE(int);

    const int numTotalPins = 10;
    
};