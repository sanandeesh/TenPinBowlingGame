PlayBowling:
	g++ main.cpp BowlingGame.h BowlingGame.cpp -o PlayBowling.exe -std=c++11 -Wall

TestBowling:
	g++ CatchBDD_main.cpp catch.h BowlingGame.h BowlingGame.cpp -o CatchBDD_BowlingGame.exe -std=c++11 -Wall 

