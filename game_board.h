#ifndef game_board
#define game_board

#include "game_pieces.h"
#include "common_fun.h"

using namespace std;

int parseDim(ifstream & input_stream, unsigned int & x, unsigned int & y);
int parsePieces(ifstream & input_stream, vector<game_piece> & gpv, unsigned x, unsigned y);
int print_game(vector<game_piece> & gpv, unsigned int x, unsigned int y);


#endif