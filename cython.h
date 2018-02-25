#pragma once

#include "lainlib.h"


bool is_blank(char test) {
	return test == ' ' || test == '\t';
}

string num2str(double num) {
	stringstream ss;
	ss << num;
	return ss.str();
}

string braceless(ifstream &raw) {

	string line(""), ans("");

	bool wait_flag(false);	// move to next line without seeing non-blank char
	bool str_flag(false);	// target char in string, we just ignore it
	bool dict_flag(false);	// in case the use of dict being removed
	int counter = 0;		// indent counter
	char prior_nonblank(0);	// record prior non-blank char
	while (std::getline(raw, line)) {	// Process each line

		for (char ch : line) {

			if (str_flag) {	// in string

				if (ch == '\'') {
					ans += '\'';
					str_flag = false;
				}
				else ans += ch;

			} else {	// not in a string

				if (ch == '{') {
					if (prior_nonblank == '=') {	// go to dict mode
						ans += '{';
						dict_flag = true;

					} else {	// remove '{' and add ':', then move to next line
						ans += ":\n";
						counter += 1;
						wait_flag = true;
						dict_flag = false;
					}
					
				}
				else if (ch == '}') {
					if (dict_flag) {	// leave dict mode
						ans += '}';
						dict_flag = false;

					} else {	// remove '{', then move to next line
						ans += '\n';
						counter -= 1;
						dict_flag = false;
					}
					
				}
				else if (ch == '\'') {	// turn to string mode
					ans += '\'';
					str_flag = true;
				}
				else if (ch == ';' && counter) {	// move to next line
					ans += '\n';
					wait_flag = true;
					dict_flag = false;
				}
				else if (!is_blank(ch) && wait_flag) {	// ignore blank before real char
														// and add correct '\t'
					for (int i = 0; i < counter; i++) ans += '\t';
					ans += ch;
					wait_flag = false;
				}
				else if (is_blank(ch) && wait_flag && counter)	continue;
				else ans += ch;

			}

			if (!is_blank(ch))	prior_nonblank = ch;
		}// end for

		ans += "\n";
		wait_flag = true;

	}// end while

	return ans;
}










