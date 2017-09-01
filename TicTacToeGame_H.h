//header guard
#ifndef TicTacToeGame_H
#define TicTacToeGame_H

#include "game_pieces.h"
#include "game_board.h"
#include "common_fun.h"
#include <locale>

using namespace std;

class TicTacToeGame {

private:
	ifstream ifs;
	const char * file = "tic_tac_toe.txt";
	string prompt_str = "<x co-ord, y co-ord> to make move or <quit> to end game: ";
	unsigned int width;
	unsigned int height;
	unsigned int x; //the x-coordinate of the current move
	unsigned int y; //the y-coordinate of the current move
	unsigned int current_turn; //1 for X, 2 for O
	unsigned int total_moves;
	vector<game_piece> game_vector;

public:
	TicTacToeGame();
	int load_game();
	int load_coord();
	int prompt(unsigned int & x_, unsigned int & y_);
	bool all_fill();
	bool check_dia();
	bool check_hor();
	bool check_ver();
	friend ostream& operator<<(ostream& o_stream, const TicTacToeGame &game);
	bool done();
	bool draw();
	int turn();
	int play();

};

ostream& operator<<(ostream& o_stream, const TicTacToeGame &game);

#endif