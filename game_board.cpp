#include "stdafx.h"
#include "game_board.h"
#include <vector>

using namespace std;

//parses the dimensions of the board from the input stream
int parseDim(ifstream &input_stream, unsigned &x, unsigned &y){
	string temp_string;
	try {
		getline(input_stream, temp_string);
		istringstream is(temp_string);
		//checks that the istringstream is valid
		if (is) {
			//checks if the numbers are properly stored
			if (is >> x && is >> y) {
				return success;
			}
		}
		return fail_read_line_parse_dim;
	}
	catch (...) {
		return fail_parse_dimensions;
	}
}

//parses the game pieces from the input stream
int parsePieces(ifstream & input_stream, vector<game_piece> & gpv, unsigned int x, unsigned int y) {
	string temp_string, temp_color, temp_name, temp_display;
	unsigned int temp_x_co, temp_y_co;
	bool one_good = false;

	while (getline(input_stream, temp_string)) {
		istringstream is(temp_string);
		if (is >> temp_color && is >> temp_name && is >> temp_display && is >> temp_x_co && is >> temp_y_co) {
			piece_color temp_enum = stringToEnum(temp_color);
			if (temp_x_co < x && temp_y_co < y) {
				unsigned int index = x * temp_x_co + temp_y_co;
				gpv[index].piece_enum = temp_enum;
				gpv[index].piece_name = temp_name;
				gpv[index].piece_print = temp_display;
				one_good = true;
			}
		}
	}
	if (one_good) {
		return success;
	}
	else {
		return fail_parse_pieces;
	}
}

int print_game(vector<game_piece> & gpv, unsigned int x, unsigned int y){
	int access_ind;
	if (gpv.size() != x*y){
		return fail_dim_mismatch;
	}
	try {
		for (unsigned int height_ind = 0; height_ind < y; ++height_ind) {
			//size minus the width, gets the last row, and progressively earlier rows with the inner loop index
			access_ind = gpv.size() - ((height_ind + 1) * x) - 1;
			for (unsigned int width_ind = 0; width_ind < x; ++width_ind) {
				access_ind = access_ind++;
				cout << gpv[access_ind].piece_print;
			}
			cout << endl;
		}
		return success;
	}
	catch (...) {
		return fail_print_error;
	}
}