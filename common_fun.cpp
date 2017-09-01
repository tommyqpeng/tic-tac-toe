// lab_0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "common_fun.h"


using namespace std;

//function to parse the file
int parsefile(vector<string> & v_name, char * file_name) {
	string temp_str;
	ifstream ifs(file_name);

	//checks if the file is openable
	if (ifs.is_open()) {
		while (ifs >> temp_str) {
			//checking for spaces
			//if (isspace(temp_str)) {
			v_name.push_back(temp_str);
			//}
		}
	}
	//if the file is not open
	else {
		cout << "Open file failed! code: " << fail_open_file << endl;
		return fail_open_file;
	}
	return success;
}

//usage message printer
int usage_message(string & prog_name, string message) {
	cout << "usage: " << prog_name << "  " << message << endl;
	return fail_arg_number;
}

void change_string(string myString) {
	for (unsigned i = 0; i < myString.size(); ++i) {
		if (myString[i] >= 'A' || myString[i] <= 'Z') {
			myString[i] = myString[i] - ('Z' - 'z');
		}
	}
}