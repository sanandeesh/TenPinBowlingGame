/* ========================================================================
 Name:     CatchBDD_main.cpp
 Descr:    Entry point executable to test a single-player ten point bowling game. Uses the Catch2 testing framework.
           The included class, BowlingGame, implements the game logic and stores the score sheet.
 Author:   Sanandeesh Kamat 
 Source:   
  ========================================================================= */
// Compile with:
// g++ -std=c++11 -Wall -o CatchBDD_BowlingGame.exe CatchBDD_main.cpp catch.h BowlingGame.h BowlingGame.cpp
// Run with:
// ./CatchBDD_BowlingGame.exe --reporter compact --success


/* Features of BowlingGame to Test
    1. Total number of game frames initializes as specified by the constructor (i.e. numFrames).
    2. Frame index (i.e. iFrame) initializes to 0.
    3. iFrame increments after each playNextFrame() call.
    4. (Roll1 + Roll2) must be within [0,...,10].
    5. Bonus points for SPARE and STRIKE must be awarded correctly (retroactively based on next frame scores)
    6. Running score accumulated from getFrameScore() must agree with getScore() at each frame.
    7. Only numFrames frames can be played. (i.e. iFrame and scoreSheet will no longer update beyond numFrames)
*/

// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.h"
#include "BowlingGame.h"

SCENARIO( "BowlingGame class performs single-player 10-pin bowling.") {

    GIVEN( "A BowlingGame instance, ..." ) {

        // Initialize the Bowling Game Class
        int numFrames = 20;
        BowlingGame bowlingGame = BowlingGame(numFrames, false); // Silence cout outputs

        // Verify that total number of frames has been set to numFrames.
        REQUIRE( bowlingGame.getNumFrames() == numFrames );
        
        // Verify that iFrame initializes to 0
        REQUIRE( bowlingGame.getCurrentFrame() == 0 );

        int lastBonus, currBall1, currBall2; // For verifying bonus points in ln 50, 54.
        int runningScore = 0;                // For verifying agreement between ScoreSheet and getScore()
        
        // Play Bowling for 'numFrames' Frames
        for (int iFrm = 0; iFrm < numFrames; iFrm++) {
            // Two Rolls for Next Frame
            bowlingGame.playNextFrame();
            // Verify that current frame increments
            REQUIRE( bowlingGame.getCurrentFrame() == (iFrm+1) );
            // Verify that (Roll1 + Roll2) is within bounds [0,...,10]
            currBall1 = bowlingGame.getFrameScore(iFrm)[0];
            currBall2 = bowlingGame.getFrameScore(iFrm)[1];
            REQUIRE((currBall1+currBall2) >= 0);
            REQUIRE((currBall1+currBall2) <= 10);
            runningScore += currBall1 + currBall2;
            if (iFrm > 0) {
                lastBonus = bowlingGame.getFrameScore(iFrm-1)[2];
                runningScore += lastBonus;
                // Verify bonus points for SPARES and STRIKES (Stored in third element of the frame array)
                if (bowlingGame.isSTRIKE(iFrm-1)) { // STRIKE!
                    //         Bonus      =   Ball 1     +   Ball 2
                    REQUIRE(lastBonus == (currBall1 + currBall2));
                }   
                else if (bowlingGame.isSPARE(iFrm-1)) { // SPARE!
                    //         Bonus      =   Ball 1
                    REQUIRE(lastBonus == currBall1);    
                }
            }
            // Verify agreement between ScoreSheet and getScore()
            REQUIRE(runningScore == bowlingGame.getScore());
        }

        // Verify that no more frames can be played past numFrames by running playNextFrame() again.
        // NOTE: This will deliberately invoke an 'ERROR' message from BowlingGame class.
        bowlingGame.playNextFrame();
        REQUIRE( bowlingGame.getCurrentFrame() == numFrames ); // No longer increments
    }
}
