#pragma once
#include <string>
#include <vector>

using namespace std;
class FileManger
{
public:
	int ID;

	bool isTextInFile(const string& filePath, const string& textToFind);
	void clearFile(const string& filePath);
	void writeToFile(string text, string filePath); 
	vector<string>readFromFileToVector(const string& filePath);
	int get_id();

};

