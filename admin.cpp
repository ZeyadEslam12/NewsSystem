#include "admin.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

bool admin::LogIn()
{
	string passaword;
	string username;
	cout << "Enter Username : ";
	cin >> username;
	while (true) {
		bool isValidInput = true;
		for (char c : username) {
			if (!isalpha(c)) {  
				isValidInput = false;
				break;
			}
		}
		if (username.empty() || !isValidInput) { 
			cout << "Invalid input. Please enter a username (letters only): ";
			cin >> username;
		}
		else {
			break;
		}
	}
	for (char& c : username) {
		c = std::tolower(c);
	}
	cout << "Enter Password : ";
	cin >> passaword;
	while (passaword.empty()) {  
		cout << "Invalid input. Please enter a password: ";
		cin >> passaword;
	}

	if (username == "admin" && passaword == "admin")
	{

		return true;

	}

	
	return false;
}

