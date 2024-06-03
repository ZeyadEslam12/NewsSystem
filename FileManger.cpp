#include "FileManger.h"
#include<string>
#include <fstream>
#include<vector>
#include<iostream>
#define Titles_path "titles.txt"
#define Descirbtions_path "describtions.txt"
#define IDSs_path "ids.txt"
#define category_path "category.txt"
#define categories_path "categories.txt"
#define date_path "date.txt"
#define rate_path "rate.txt"

using namespace std;


bool FileManger:: isTextInFile(const string& filePath, const string& textToFind) {
    ifstream inputFile(filePath);
    if (inputFile.peek() == ifstream::traits_type::eof()) {
        return false;
    }

    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            if (textToFind == line) {
                inputFile.close();
                return true;
            }
        }

    }
    return false;

}
void FileManger:: clearFile(const string& filePath) {
    ofstream file(filePath, ios::out | ios::trunc);
    if (file.is_open()) {
        file.close();
    }
    else {
        cout << "Unable to open file for clearing." << endl;
    }
}
int FileManger::get_id() {
    string id, line;
    ifstream file(IDSs_path);
    if (file.peek() != ifstream::traits_type::eof()) {
        while (getline(file, line)) {
            id = line;
        }
        file.close();
    }
    else {
        return 0;
    }

    ID = stoi(id);
    return ID + 1;
}

void FileManger::writeToFile(string text, string filePath) {
    ofstream file;
    file.open(filePath, ios::out | ios::app);
    if (file.is_open()) {
        file << text + "\n";
        file.close();
    }
    else {
        cout << "Unable to open file for writing." << endl;
    }
}


vector<string> FileManger::readFromFileToVector(const string& filePath) {
    vector<string> readInvc;
    ifstream file(filePath);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            readInvc.push_back(line);
        }
        file.close();
    }
    else {
        cout << "Unable to open file for reading." << endl;
    }
    return readInvc;
}