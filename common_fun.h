//header guard
#ifndef common_fun
#define common_fun

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

//enumerations
enum arr_ind {
	p_name = 0,
	igame_name = 1,
	expected_input_number = 2
};

enum succ {
	success = 0,
	fail_open_file = 1,
	fail_arg_number = 2,
	fail_parse_dimensions = 3,
	fail_parse_pieces = 4,
	fail_dim_mismatch = 5,
	fail_print_error = 6,
	fail_read_line_parse_dim = 7,
	fail_arg_not_found = 8,
	fail_prompt = 9,
	fail_play = 10,
	fail_draw = 888,
	quit = 999
};

//functions declaration
int parseFile(vector<string> & v_name, char * file_name);
int usage_message(string & prog_name, string message);
void change_string(string myString);

#endif