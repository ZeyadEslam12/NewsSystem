#include "user.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void user::Registration()
{
	bool isTaken = true;
	while (isTaken) {
		string user;
		cout << "Select Username : ";
		cin >> ws;
		getline(cin,user);
		while (user.empty()) {
			cout << "Invalid input. Please enter a username: ";
			getline(cin, user);
		}
		string pass;
		cout << "Select Password : ";
		cin >> pass;
		while (pass.empty()) {  
			cout << "Invalid input. Please enter a password: ";
			cin >> pass;
		}
		vector<string> tmp;
		ifstream myfile1("registration user name.txt");
		if (myfile1.is_open()) {
			string line;
			while (getline(myfile1, line)) {
				tmp.push_back(line);
			}
			myfile1.close();
		}
		else {
			cout << "Unable to open file." << endl;
		}
		bool exists = false;
		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i] == user) {
				cout << "this username already exists , please try again" << endl;
				exists = true;
				break;
			}
		}
		if (!exists) {
			Username.push_back(user);
			Password.push_back(pass);
			isTaken = false;
		}
	}
	ofstream file;
	file.open("registration user name.txt", std::ios::app);
	if (file.is_open()) {
		for (const auto& user : Username) {
			file << user << '\n';
		}
		file.close();
	}
	else {
		cout << "Unable to open file." << endl;
	}
	ofstream pas;
	pas.open("registration user pass.txt", std::ios::app);
	if (pas.is_open()) {
		for (const auto& pass : Password) {
			pas << pass << '\n';
		}
		pas.close();
	}
	else {
		cout << "Unable to open file." << endl;
	}
	cout << "\t\tSuccessfully Registred !\n";

}

bool user::LogIn()
{

	string passaword;
	string username;
	cout << "Enter Username : ";
	cin >> ws;
	getline(cin, username);
	while (username.empty()) {
		cout << "Invalid input. Please enter a username: ";
		getline(cin, username);
	}
	cout << "Enter Password : ";
	cin >> passaword;
	
	while (passaword.empty()) {  
		cout << "Invalid input. Please enter a password: ";
		cin >> passaword;
	}
	ifstream myfile("registration user name.txt");
	if (myfile.is_open()) {
		string line;
		while (getline(myfile, line)) {
			Username.push_back(line);
		}
		myfile.close();
	}
	else {
		cout << "Unable to open file." << endl;
	}
	ifstream myfile2("registration user pass.txt");
	if (myfile2.is_open()) {
		string line2;
		while (getline(myfile2, line2)) {
			Password.push_back(line2);
		}
		myfile2.close();
	}
	else {
		cout << "Unable to open file." << endl;
	}
	for (int i = 0; i < Username.size(); i++) {
		if (Username[i] == username && Password[i] == passaword) {
			return true;
		}

	}
	return false;

}

