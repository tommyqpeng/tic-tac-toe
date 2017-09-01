#include "stdafx.h"
#include "TicTacToeGame_H.h"


using namespace std;

//Constructor
TicTacToeGame::TicTacToeGame(){
	load_game();
	current_turn = 1; //X goes first
	total_moves = 0;
}

//Loads the game with .txt data
int TicTacToeGame::load_game() {
	ifs = ifstream(file);

	if (ifs.is_open()) {

		int checker = parseDim(ifs, width, height);
		while (checker == fail_read_line_parse_dim) {
			checker = parseDim(ifs, width, height);
		}
		if (checker == fail_parse_dimensions) {
			return fail_parse_dimensions;
		}

		//creates an empty game piece
		game_piece empty_piece;
		empty_piece.piece_enum = no_color;
		empty_piece.piece_name = "";
		empty_piece.piece_print = " ";
		//pushes back enough pieces through for loop
		for (unsigned int index = 0; index < width*height; ++index) {
			game_vector.push_back(empty_piece);
		}

		//parses the game pieces
		if (parsePieces(ifs, game_vector, width, height) == success) {
			return success;
		}
		else {
			return fail_parse_pieces;
		}

	}
	else {
		return fail_open_file;
	}

}

//Checks if the game is done, note that for any given input, we only need to check the row, diagonal and column that the input is in
bool TicTacToeGame::done() {
	if (check_dia() || check_hor() || check_ver()) {
		return true;
	}
	else {
		return false;
	}
}

//Checks the horizontal row of the current input
bool TicTacToeGame::check_hor() {
	string shape;
	if (current_turn == 1){
		shape = "X";
	}
	if (current_turn == 2){
		shape = "O";
	}
	for (unsigned int i = 1; i < 4; ++i) {
		int index = width * (x + 1) + 1 + i;
		if (game_vector[index].piece_print.compare(shape) != 0) {
			return false;
		}
	}
	return true;
}

//Checks the vertical column of the current input
bool TicTacToeGame::check_ver() {
	string shape;
	if (current_turn == 1){
		shape = "X";
	}
	if (current_turn == 2){
		shape = "O";
	}
	for (unsigned int i = 1; i < 4; ++i) {
		int index = width * (i + 1) + 1 + y;;
		if (game_vector[index].piece_print.compare(shape) != 0) {
			return false;
		}
	}
	return true;
}

//Checks the diagonals for completion, forced check
bool TicTacToeGame::check_dia(){
	string shape;
	if (current_turn == 1){
		shape = "X";
	}
	if (current_turn == 2){
		shape = "O";
	}
	if ((game_vector[26].piece_print.compare(shape) == 0 && game_vector[21].piece_print.compare(shape) == 0 && game_vector[16].piece_print.compare(shape) == 0) ||
		(game_vector[28].piece_print.compare(shape) == 0 && game_vector[21].piece_print.compare(shape) == 0 && game_vector[14].piece_print.compare(shape) == 0) ) {
		return true;
	}
	return false;
}

//Checks through every square to see if there is a space left
bool TicTacToeGame::all_fill(){
	for (unsigned int i = 1; i < 4; ++i) {
		for (unsigned int j = 1; j < 4; ++j) {
			int index = width * (i + 1) + 1 + j;
			if (game_vector[index].piece_print.compare(" ") == 0) {
				return true;
			}
		}
	}
		return false;
}

//Checks if the match is a draw
bool TicTacToeGame::draw() {
	if (all_fill() || done()) {
		return false;
	}
	return true;
}

//Dictates how a turn would go
int TicTacToeGame::turn() {
	if (current_turn == 1) {
		cout << "Player X turn..." << endl; 
	}	
	if (current_turn == 2) {
		cout << "Player O turn..." << endl;
	}
	unsigned int x_cor;
	unsigned int y_cor;
	bool turn_valid = true;
	int turn_enum;
	while (turn_valid) {
		turn_enum = prompt(x_cor, y_cor);
		if (turn_enum == quit) {
			turn_valid = false;
			return quit;
		}
		else if (turn_enum == success) {
			turn_valid = false;
		}
	}
	unsigned int index = width * (x_cor + 1) + 1 + y_cor;
	game_piece temp_piece;
	temp_piece.piece_enum = no_color;
	temp_piece.piece_name = "";
	if (current_turn == 1) {
		temp_piece.piece_print = "X";
	}
	if (current_turn == 2) {
		temp_piece.piece_print = "O";
	}
	game_vector[index] = temp_piece;
	total_moves++;
	cout << *this;
	cout << endl;
	cout << "Player " << temp_piece.piece_print << ": " << x_cor << ", " << y_cor << endl;
	return success;
}

//Prompts user input and reads it, returns different enums for different outcomes
int TicTacToeGame::prompt(unsigned int & x_, unsigned int & y_) {
		string input;
		cout << prompt_str << endl;
		getline(cin, input);
		if (input.compare("quit") == 0) {
			cout << "You have quit." << endl;
			return quit;
		}
		else {
			int dummy;
			bool digit_bool = true;
			char comma = ',';
			locale loc;
			char temp_char;
			//checks if all characters are numbers
			for (int i = 0; i < input.length(); ++i) {
				temp_char = input[i];
				if (temp_char == comma) {
					input[i] = ' ';
					temp_char = ' ';
				}
				if (!isdigit(temp_char) && temp_char != ' ') {
					digit_bool = false;
					cout << "The format of the co-ordinate is incorrect." << endl;
					return fail_prompt;
				}
			}
			if (digit_bool) {
				istringstream iss(input);
				//checks if assignment is ok, only 2 coord
				if (iss >> x_ && iss >> y_ && !(iss >> dummy)) {
					//checks if it is in the co-ordinate bounds for tictactoe
					if (x_ < 4 && x_ > 0 && y_ < 4 && y_ > 0) {
						unsigned int index = width * (x_ + 1) + 1 + y_;
						//checks if the index position is vacant
						if (game_vector[index].piece_print.compare(" ") == 0) {
							x = x_;
							y = y_;
							return success;
						}
						else {
							cout << "Co-ordinate already taken." << endl;
							return fail_prompt;
						}
					}
					else {
						cout << "Co-ordinate out of bounds." << endl;
						return fail_prompt;
					}
				}
				else {
					cout << "Too many co-ordinates." << endl;
					return fail_prompt;
				}
			}
		}
		return fail_prompt;
}

//Function for actual game play direction
int TicTacToeGame::play(){
	cout << *this;
	while (turn() != quit) {
		if (done()) {
			if (current_turn == 1) {
				cout << "Player X wins." << endl;
				return success;
			}
			else if (current_turn == 2) {
				cout << "Player O wins." << endl;
				return success;
			}
		}
		else if (draw()) {
			cout << "After " << total_moves << " moves, game is a draw." << endl;
			return fail_draw;
		}
		else {
			if (current_turn == 1) {
				current_turn = 2;
			}
			else if (current_turn == 2) {
				current_turn = 1;
			}
		}
	}
	return quit;
}

//Outstream operator
ostream& operator<<(ostream& o_stream, const TicTacToeGame &game) {
	for (unsigned int height_ind = 0; height_ind < game.height; ++height_ind) {
		//size minus the width, gets the last row, and progressively earlier rows with the inner loop index
		int access_ind = game.game_vector.size() - ((height_ind + 1) * game.width) - 1;
		for (unsigned int width_ind = 0; width_ind < game.width; ++width_ind) {
			access_ind = access_ind++;
			o_stream << game.game_vector[access_ind].piece_print;
		}
		o_stream << endl;
	}
	return o_stream;
}