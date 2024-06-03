
#include<iostream>
#include <stdlib.h>
#include<string>
#include"FileManger.h"
#include <fstream>
#include <vector>
#include "admin.h"
#include "user.h"
#include "News.h"
#include<ctime>
#include <chrono>
#include <stdio.h>        
#include <time.h> 
#include<set>
#pragma warning(disable : 4996)
#define categories_path "categories.txt"


using namespace std;

string getCurrentDate()
{
	time_t now = time(nullptr);
	tm* timeinfo = localtime(&now);

	int month = timeinfo->tm_mon + 1; 
	int day = timeinfo->tm_mday;
	int year = timeinfo->tm_year + 1900;  

	return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}


int main()
{

	int choice1 = 0, choice2 = 0, choice3 = 0, choice4 = 0, flag1 = 0, flag2 = 0;
	FileManger files;
	admin admin;
	user user;
	News news;
	string title;
	string desc;
	string cat;
	string date;
	int id;
	int id2, id3;

start:

	cout << "\t\t\t\t\t\tWelcome To News \n\n";
	cout << "************************************************************************************************************************" << endl;
	cout << "Press 1 For Admins \n";
	cout << "Press 2 For Users \n";
	cout << "Enter Your Choice : ";
	while (true) {
		string input;
		cin >> input;
		bool isValidInput = true;
		for (char c : input) {
			if (!isdigit(c)) {
				isValidInput = false;
				break;
			}
		}
		if (input.empty() || !isValidInput) {
			cout << "Invalid input. Enter Your Choice ( 1 or 2 ) : ";
		}
		else {
			choice1 = stoi(input);
			if (choice1 < 0) {
				cout << "Invalid input. Enter Your Choice ( 1 or 2 ) : ";
			}
			if (choice1 != 1 && choice1 != 2) {
				cout << "Invalid input. Please enter 1 or 2: ";
			}
			else {
				break;
			}
		}
	}
	if (choice1 == 1)
	{
	start2:
		cout << endl;

			bool status = admin.LogIn();
			if (!status)
			{
				cout << "\t\tWrong Usename Or Password ! \n";
				cout << "\t\tPlease Try Agian \n";
				goto start2;
			}
			else
			{
				cout << endl;
				cout << "\t\tSuccessfully Loggedin as admin\n\n";
				flag1 = 1;
			}
		
	}
	if (flag1 == 1)
	{
		do
		{
			cout << endl;
			cout << "1- Post\n";
			cout << "2- Remove \n";
			cout << "3- update\n";
			cout << "4- to display the average rate by specific title\n";
			cout << "5- print\n";
			cout << "6- categorize \n";
			cout << "7- add category\n";
			cout << "8- display by rate : \n";
			cout << "9- log out : \n";
			cout << "10- close the program  \n";


			cin >> choice3;

			if (choice3 == 1) {
				cout << "Enter title :" << endl;
				cin >> ws;
				getline(cin, title);
				cout << "Enter description :" << endl;
				getline(cin, desc);
				cout << "Our  categories  : \n" << endl;

				vector<string> categories_temp = files.readFromFileToVector(categories_path);
				if (categories_temp.size() == 0) {
					cout << "you have 0 categories please add categories first \n";
				}
				else {
					set<string>our_categories;

					for (int i = 0; i < categories_temp.size(); i++) {
						our_categories.insert(categories_temp[i]);
					}
					int counter1 = 1;
					map<int, string>mp;
					for (auto i : our_categories) {
						cout << counter1 << " : " << i << endl;
						mp[counter1] = i;
						counter1++;
					}
					cout << " select category to this post \n";
					int op;
					cin >> op;
					if (op > our_categories.size() || op < 1) {
						cout << " the number out of scope \n";
					}
					else {
						string category = mp[op];
						date = getCurrentDate();
						admin.function.Post(title, desc, category, date);
					}
				}
			}
			if (choice3 == 2) {
				cout << "enter id: " << endl;
				cin >> id;
				admin.function.Remove(id);
			}
			else if (choice3 == 3) {
				cout << "enter id: " << endl;
				cin >> id2;
				admin.function.Update(id2);
			}
			else if (choice3 == 4) {
				cout << "enter title to get the average rate for it \n";
				string title_rate;
				cin >> ws;
				getline(cin, title_rate);
				admin.function.display_avgrate_by_title(title_rate);
			}

			else if (choice3 == 5) {
				admin.function.display_by_date();
			}
			else if (choice3 == 6) {
				admin.function.Categorize();
			}
			else if (choice3 == 7) {
				cout << " enter your new category name to add it \n";
				string newcategory;

				cin >> ws;
				getline(cin, newcategory);
				admin.function.add_category(newcategory);
			}
			
			else if (choice3 == 8) {
				admin.function.display_by_rate();
			}
			else if (choice3 == 9) {
				flag1 = 0;
				system("CLS");
				goto start;
			}
			else if (choice3 == 10) {
				exit(0);
			}
			else if (choice3 > 10 || choice3 < 1) {
				cout << "Invaild Option\nplease enter Number from 1 to 10" << endl;
			}

		} while (choice3 != 10);
	}

	else if (choice1 == 2)
	{
	start3:
		cout << endl;
		cout << "1- Registration \n";
		cout << "2- Login \n";
		cout << "Enter Your Choice : ";
		cin >> choice2;
		if (choice2 == 1)
		{
			user.Registration();
			goto start3;
		}
		else if (choice2 == 2)
		{
			bool status = user.LogIn();
			if (!status)
			{
				cout << "\t\tWrong Usename Or Password ! \n";
				cout << "\t\tPlease Try Agian \n";
				goto start3;
			}
			else
			{
				cout << endl;
				cout << "\t\tSuccessfully Loggedin as normal user\n\n";
				flag2 = 1;
			}
		}
	}
	if (flag2)
	{
		do
		{

			cout << "1- print by latest news\n";
			cout << "2- display by rate  \n";
			cout << "3- rate \n";
			cout << "4- to display by category\n";
			cout << "5- to add comment \n";
			cout << "6- to display comments\n";
			cout << "7- log out : \n";
			cout << "8- to exit the programm\n";
			int op;
			cin >> op;
			if (op == 1)
				user.function.display_by_date();
			if (op == 2)
				user.function.display_by_rate();
			if (op == 3) {
				int id;
				string rate;
				cout << "enter id for post \n";
				cin >> id;
				
				user.function.Rate_News(id);
			}
			if (op == 4)
				user.function.Categorize();
			if (op == 5) {
				int id;
				cout << "Enter id of the post you want : ";
				cin >> id;
				user.function.addcomment(id);
			}
			if (op == 6) {
				int id;
				cout << "Enter id of the post you want : ";
				cin >> id;
				user.function.displaycommentsbyid(id);

			}
			if (op == 7) {
				system("CLS");
				goto start;
			}
			if (op == 8) {
				exit(0);
			}


		} while (true);
	}
}

