#pragma once
#include <vector>
#include <string>
#include "News.h"
using namespace std;


class user
{
private:

	vector <string> Password;

public:

	vector <string> Username;
	void Registration();
	bool LogIn();
	News function;

};

