#pragma once
#include <iostream>
#include <vector>
#include <string>
#include<map>
#include<time.h>
using namespace std;
class News
{
public:
    string title;
    string description;
    string category;
    string date;
    string rate;

    int id = 0;
    void displaycommentsbyid(int id);
    void addcomment(int id);
    void Post(string, string, string, string);
    void Remove(int);
    void Update(int);
    void Print_by_latest();
    void Categorize();
    void display_avgrate_by_title(string tit);
    void Rate_News(int);
    void display_by_rate();
    void add_category(string);
    void display_by_date();

};