#include "stdafx.h"
#include "common_fun.h"
#include "game_pieces.h"

//Returns a all lowercase string to a corresponding enum value
std::string colorToString(int x){
	switch (x) {
	case piece_color::invalid:
		return "invalid";
		break;
	case piece_color::red:
		return "red";
		break;
	case piece_color::black:
		return "black";
		break;
	case piece_color::white:
		return "white";
		break;
	case piece_color::no_color:
		return " "; //no color is just white space
		break;
	default:
		return "invalid";
		break;
	}
}

//Returns a enum to the corresponding string of color or enum name
piece_color stringToEnum(std::string x) {
	//forces lower-case lettering
	change_string(x);
	if (x.compare("red") == 0) {
		return piece_color::red;
	}
	else if (x.compare("invalid") == 0) {
		return piece_color::invalid;
	}
	else if (x.compare("black") == 0) {
		return piece_color::black;
	}
	else if (x.compare("white") == 0) {
		return piece_color::white;
	}
	else if (x.compare(" ") == 0) {
		return piece_color::no_color;
	}
	//default case, for anything that is not defined
	else {
		return piece_color::invalid;
	}
}
