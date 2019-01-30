# TenPinBowlingGame
Implements a single player 10 pin bowling game, and includes a BDD test using the Catch2 testing framework.

# Overview
This repository includes C++ software which implements a single player 10-pin bowling game. 
The game functionality is implemented within the BowlingGame class (BowlingGame.h and BowlingGame.cpp).
The game is played through main.cpp, which is the entry point of 'PlayBowling.exe'.
The game is tested through CatchBDD_main.cpp, which is the entry point of 'CatchBDD_BowlingGame.exe'.

# Build/Run Instructions
1. Open a terminal and navigate to the root directory of this repository.

2. To build the main executable, PlayBowling.exe, run:

	> make PlayBowling
	
	PlayBowling.exe will appear in the root directory.

3. Run: 
	> ./PlayBowling.exe
	
	The screen prompts the user to enter the number of frames. This must be > 1.
	
	The outcome of each frame and the final score will appear on the screen.

4. To build the test executable, CatchBDD_BowlingGame.exe, run:
	> make TestBowling
	CatchBDD_BowlingGame.exe will appear in the root directory.

5. Run:
	> ./CatchBDD_BowlingGame.exe --reporter compact --success
	
	The Catch2 compact test report will appear on the screen.

# BowlingGame Class Description
Two balls are rolled against 10 pins at each frame. 
A uniformly distributed random number of pins from (0 to 10) and (0 to numPinsLeft) are knocked down for rolls 1 and 2, respectively. Each frame is categorized as Open Frame, SPARE, or STRIKE and bonus points are awarded accordingly. 
A score sheet is maintained as a 2D array.

# Example Outputs 
1. Main executable outputs:
```
Enter the Desired Number of Frames for this Game ...
5
-------------------------------------
Playing Frame 0
Rolled 1
Rolled 7
Frame 0 is an Open Frame
Total Score: 8
-------------------------------------
Playing Frame 1
Rolled 1
Rolled 8
Frame 1 is an Open Frame
Total Score: 17
-------------------------------------
Playing Frame 2
Rolled 10
Rolled 0
Frame 2 is a STRIKE!
Total Score: 27
-------------------------------------
Playing Frame 3
Rolled 3
Rolled 5
Frame 3 is an Open Frame
Total Score: 43
-------------------------------------
Playing Frame 4
Rolled 10
Rolled 0
Frame 4 is a STRIKE!
Total Score: 53
```

2. Test executable outputs:
```
CatchBDD_main.cpp:39: passed: bowlingGame.getNumFrames() == numFrames for: 20 == 20
CatchBDD_main.cpp:42: passed: bowlingGame.getCurrentFrame() == 0 for: 0 == 0
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 1 == 1
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 8 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 8 <= 10
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 8 == 8
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 2 == 2
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 10 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 10 <= 10
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 18 == 18
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 3 == 3
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 2 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 2 <= 10
CatchBDD_main.cpp:69: passed: lastBonus == currBall1 for: 2 == 2
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 22 == 22
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 4 == 4
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 3 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 3 <= 10
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 25 == 25
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 5 == 5
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 10 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 10 <= 10
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 35 == 35
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 6 == 6
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 10 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 10 <= 10
CatchBDD_main.cpp:69: passed: lastBonus == currBall1 for: 9 == 9
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 54 == 54
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 7 == 7
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 7 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 7 <= 10
CatchBDD_main.cpp:69: passed: lastBonus == currBall1 for: 2 == 2
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 63 == 63
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 8 == 8
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 7 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 7 <= 10
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 70 == 70
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 9 == 9
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 3 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 3 <= 10
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 73 == 73
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 10 == 10
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 10 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 10 <= 10
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 83 == 83
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 11 == 11
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 9 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 9 <= 10
CatchBDD_main.cpp:69: passed: lastBonus == currBall1 for: 3 == 3
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 95 == 95
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 12 == 12
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 9 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 9 <= 10
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 104 == 104
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 13 == 13
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 10 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 10 <= 10
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 114 == 114
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 14 == 14
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 1 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 1 <= 10
CatchBDD_main.cpp:69: passed: lastBonus == currBall1 for: 1 == 1
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 116 == 116
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 15 == 15
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 8 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 8 <= 10
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 124 == 124
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 16 == 16
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 10 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 10 <= 10
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 134 == 134
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 17 == 17
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 10 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 10 <= 10
CatchBDD_main.cpp:65: passed: lastBonus == (currBall1 + currBall2) for: 10 == 10
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 154 == 154
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 18 == 18
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 9 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 9 <= 10
CatchBDD_main.cpp:69: passed: lastBonus == currBall1 for: 1 == 1
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 164 == 164
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 19 == 19
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 7 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 7 <= 10
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 171 == 171
CatchBDD_main.cpp:52: passed: bowlingGame.getCurrentFrame() == (iFrm+1) for: 20 == 20
CatchBDD_main.cpp:56: passed: (currBall1+currBall2) >= 0 for: 10 >= 0
CatchBDD_main.cpp:57: passed: (currBall1+currBall2) <= 10 for: 10 <= 10
CatchBDD_main.cpp:73: passed: runningScore == bowlingGame.getScore() for: 181 == 181
ERROR: 21 Exceeds Total Number of Frames, 20
CatchBDD_main.cpp:79: passed: bowlingGame.getCurrentFrame() == numFrames for: 20 == 20
Passed 1 test case with 90 assertions.
```
