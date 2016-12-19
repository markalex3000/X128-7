// Make a simple calculator
// Input:  double double char (+. -. *. /)
// Outpur:  "The (sum, difference, product etc.) of double and double is: whatever."
// Modified to take single digit or number words as operands

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }

inline void simple_error(string s)	// write ``error: s and exit program
{
	cerr << "error: " << s << '\n';
	keep_window_open();		// for some Windows environments
	exit(1);
}

int get_digit_from_string(string s);

int main() {
	int first_int{ 0 }, second_int{ 0 };
	double result{ 0.0 };
	string first_str{}, second_str{};

	char the_operator{ 'x' };

	cout << "Enter two numbers between zero and nine inclusive as digits or number words and an operator ('+', '-', '*' or '/'): ";
	cin >> first_str;
	cin >> second_str;
	cin >> the_operator;

	first_int = get_digit_from_string(first_str);
	second_int = get_digit_from_string(second_str);

	if(first_int == -1) simple_error("First operaned is bad!\n\n");
	if(second_int == -1) simple_error("Seocnd operaned is bad!\n\n");

	switch (the_operator) {
	case '+':
		result = first_int + second_int;
		cout << "The sum of " << first_str << " and " << second_str << " is " << result << ".\n";
		break;
	case '-':
		result = first_int - second_int;
		cout << first_str << " minus " << second_str << " is: " << result << ".\n";
		break;
	case '*':
		result = first_int * second_int;
		cout << "The product of " << first_str << " and " << second_str << "is: " << result << ".\n";
		break;
	case '/':
		if (second_int == 0)
		{
			simple_error("Can't divide by zero - exiting program.\n\n");
		}
		else {
			result = first_int / second_int;
			cout << first_str << " divided by " << second_str << " is " << result << ".\n";
			break;
		}
	default:
		break;
	}
	keep_window_open();
}

int get_digit_from_string(string s_buffer) {
	vector<string> number_strings = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

		// test length of s_buffer.  if 1 might have a single digit, else might have a valid number string

		if (s_buffer.length() == 1) {   // check to see if a valid digit
			if (s_buffer[0] >= '0' && s_buffer[0] <= '9') {
				return(s_buffer[0] - 48);
			}
			else return(-1);
		}
		else { // we might have a valid number string
			for (int i = 0; i <= 9; i++) {
				if (s_buffer == number_strings[i]) {  // we have a match
					return(i);
				}
			}
			}
		return(-1);
}
