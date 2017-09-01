// lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "common_fun.h"
#include "game_pieces.h"
#include "game_board.h"
#include "TicTacToeGame_H.h"


int main(int argc, char * argv[])
{
	//checks if correct input number
	if (argc != expected_input_number) {
		return usage_message(string(argv[p_name]), "<input game mode name> (currenly only TicTacToe)");
	}

	string istr = argv[igame_name];

	if (istr.compare("TicTacToe") != 0) {
		return usage_message(string(argv[p_name]), "<input game mode name> (currenly only TicTacToe)");
	}

	TicTacToeGame game = TicTacToeGame();

	int outcome;

	outcome = game.play();

	if (outcome == success) {
		return success;
	}
	else if (outcome == quit) {
		return quit;
	}
	else if (outcome == fail_draw) {
		return fail_draw;
	}
	else { 
		return fail_play;
	}

}


