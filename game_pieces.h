//header guard
#ifndef game_pieces
#define game_pieces
#include <string>


//enumerations
enum piece_color {
	invalid = 0,
	red = 1,
	black = 2,
	white = 3,
	no_color = 10
};

//functions declaration
std::string colorToString(int x);
piece_color stringToEnum(std::string myString);

//Structs
struct game_piece {
	piece_color piece_enum;
	std::string piece_name;
	std::string piece_print;
};

#endif