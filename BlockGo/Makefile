BlockGo: General.h BlockGo.cpp Intro_MapDisplay.cpp Rule.cpp Cal_Result.cpp MCTS.cpp S_BlockGo.cpp S_Intro_MapDisplay.cpp S_Rule.cpp S_Cal_Result.cpp
	c++ -o BlockGo BlockGo.cpp Intro_MapDisplay.cpp Rule.cpp Cal_Result.cpp MCTS.cpp S_BlockGo.cpp S_Intro_MapDisplay.cpp S_Rule.cpp S_Cal_Result.cpp -lm

BlockGoStatic: BlockGo.cpp Intro_MapDisplay.cpp Rule.cpp Cal_Result.cpp MCTS.cpp S_BlockGo.cpp S_Intro_MapDisplay.cpp S_Rule.cpp S_Cal_Result.cpp
	c++ -O3 -o $@ -static $^ 

clean:
	rm -f *.o *.exe BlockGo BlockGoStatic
