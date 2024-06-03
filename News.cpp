#include "News.h"
#include"FileManger.h"
#include<set>
#include<string>
#include<stack>
#include<map>
#include<algorithm>
#include <fstream>
#include<vector>
#define Titles_path "titles.txt"
#define Descirbtions_path "describtions.txt"
#define IDSs_path "ids.txt"
#define category_path "category.txt"
#define categories_path "categories.txt"
#define date_path "date.txt"
#define rate_path "rate.txt"
#define comment_path "comment.txt"

#define LW_IDtemp vector<string> IDtemp = files.readFromFileToVector(IDSs_path);
#define LW_TItemp vector<string> Titemp = files.readFromFileToVector(Titles_path);
#define LW_DEtemp vector<string> DEStemp = files.readFromFileToVector(Descirbtions_path);
#define LW_CAtemp vector<string> cattemp = files.readFromFileToVector(category_path);
#define LW_OCtemp vector<string> out_categories = files.readFromFileToVector(categories_path);
#define LW_DAtemp vector<string> datetemp = files.readFromFileToVector(date_path);
#define LW_RAtemp vector<string> ratetemp = files.readFromFileToVector(rate_path);
#define LW_COtemp vector<string> commenttemp = files.readFromFileToVector(comment_path);

#define CL_IDtemp files.clearFile(IDSs_path);
#define CL_DEtemp files.clearFile(Descirbtions_path);
#define CL_TItemp files.clearFile(Titles_path);
#define CL_DAtemp files.clearFile(date_path);
#define CL_CAtemp files.clearFile(category_path);
#define CL_RAtemp files.clearFile(rate_path);
#define CL_COtemp files.clearFile(comment_path);







int ID;
using namespace std;



string comment_without_id(string x)
{
    string y = "";
    int index;
    for (int i = x.size() - 1; i >= 0; i--) {
        if (x[i] == 32) {
            index = i;
            break;
        }
    }
    for (int i = 0; i < index; i++) y += x[i];
    return y;
}

int get_index_from_string(string x)
{
    string y = "";
    for (int i = x.size() - 1; i >= 0; i--) {
        if (x[i] == 32) break;
        if (x[i] >= 48 && x[i] <= 57) {
            y += x[i];
        }
    }
    reverse(y.begin(), y.end());
    return stoi(y);
}



bool compare_dates(const pair<string, int > & date1 , const pair<string, int > & date2) {
    int month1, day1, year1, month2, day2, year2;

    int counter = 0;
    string temp1;
    for (int i = 0; i < date1.first.size(); i++)
    {

        temp1 += date1.first[i];
        if (date1.first[i] == '/')
        {
            if (counter == 0)
                month1 = stoi(temp1);
            else if (counter == 1)
                day1 = stoi(temp1);


            counter++;
            temp1 = "";
        }

    }
    year1 = stoi(temp1);
    counter = 0;
    string temp2;
    for (int i = 0; i < date2.first.size(); i++)
    {

        temp2 += date2.first[i];
        if (date2.first[i] == '/')
        {
            if (counter == 0)
                month2 = stoi(temp2);
            else if (counter == 1)
                day2 = stoi(temp2);


            counter++;
            temp2 = "";
        }

    }
    year2 = stoi(temp2);

    if (year1 != year2) {
        return year1 > year2;
    }

    if (month1 != month2) {
        return month1 > month2;
    }

    return day1 > day2;
}

void sort_dates(vector<pair<string,int>>& dates) {
    sort(dates.begin(), dates.end(), compare_dates);
}






FileManger files;




void News::Post(string title, string description, string cat, string date)
{
    files.writeToFile(title, Titles_path);
    files.writeToFile(description, Descirbtions_path);
    string tempID = to_string(files.get_id());
    files.writeToFile(tempID, IDSs_path);
    files.writeToFile(cat, category_path);
    files.writeToFile(date, date_path);
    files.writeToFile("Unrated yet", rate_path);

}


void News::Remove(int id)
{

   
        LW_IDtemp LW_CAtemp  LW_DAtemp LW_DEtemp LW_COtemp LW_RAtemp LW_TItemp LW_OCtemp
    string tempid = to_string(id);

    if (!files.isTextInFile(IDSs_path, tempid)) {
        cout << "ID out of scope \n";
        return;
    }
    int index = -1;
    bool flag = 0;
    for (int i = 0; i < IDtemp.size(); i++)
    {
        if (IDtemp[i] == tempid)
        {
            index = i;
            flag = 1;
        }
    }
    if (flag) {
        IDtemp.erase(IDtemp.begin() + index);
        Titemp.erase(Titemp.begin() + index);
        DEStemp.erase(DEStemp.begin() + index);
        datetemp.erase(datetemp.begin() + index);
        cattemp.erase(cattemp.begin() + index);
        ratetemp.erase(ratetemp.begin() + index);

        CL_IDtemp CL_DEtemp CL_TItemp CL_DAtemp CL_CAtemp CL_RAtemp CL_COtemp


        for (int i = 0; i < commenttemp.size(); i++) {
        if (id != get_index_from_string(commenttemp[i])) {
            files.writeToFile(commenttemp[i], comment_path);
        }
    }


        for (int i = 0; i < IDtemp.size(); i++) {
            files.writeToFile(IDtemp[i], IDSs_path);
            files.writeToFile(Titemp[i], Titles_path);
            files.writeToFile(DEStemp[i], Descirbtions_path);
            files.writeToFile(datetemp[i], date_path);
            files.writeToFile(cattemp[i], category_path);
            files.writeToFile(ratetemp[i], rate_path);

        }
    }
    cout << "\n\n##################    Removed    ###################\n\n";

}

void News::Update(int id)
{


    LW_IDtemp LW_CAtemp  LW_DAtemp LW_DEtemp LW_TItemp 

    int index;

    string tempid = to_string(id);


    if (!files.isTextInFile(IDSs_path, tempid)) {
        cout << "ID out of scope \n";
        return;
    }
    for (int i = 0; i < IDtemp.size(); i++)
    {
        int temp = stoi(IDtemp[i]);
        if (temp == id)
            index = i;
    }
    cout << "To update title enter (1)\nTo update description enter (2) \nTo update both enter (3)\n";
    int choice;
    cin >> choice;
    string newtitle;
    string newdescription;
    switch (choice)
    {
    case 1:
        cout << "enter new title \n";
        cin >> ws;
        getline(cin, newtitle);
        Titemp[index] = newtitle;
        break;
    case 2:
        cout << "enter new description \n";
        cin >> ws;
        getline(cin, newdescription);
        DEStemp[index] = newdescription;
        break;
    case 3:
        cout << "enter new title \n";
        cin >> ws;
        getline(cin, newtitle);
        Titemp[index] = newtitle;
        cout << "enter new description \n";
        getline(cin, newdescription);
        DEStemp[index] = newdescription;
        break;

    default:
        cout << "invalid option\n";
        return;
    }


    CL_IDtemp CL_DEtemp CL_TItemp CL_DAtemp CL_CAtemp

    for (int i = 0; i < IDtemp.size(); i++) {
        files.writeToFile(IDtemp[i], IDSs_path);
        files.writeToFile(Titemp[i], Titles_path);
        files.writeToFile(DEStemp[i], Descirbtions_path);
        files.writeToFile(datetemp[i], date_path);
        files.writeToFile(cattemp[i], category_path);

    }
    cout << "\n\n##################    Updated    ###################\n\n";
}

void News::add_category(string new_category) {
    files.writeToFile(new_category, categories_path);
}

void News::display_avgrate_by_title(string title) {

    vector<string> ratetemp = files.readFromFileToVector(rate_path);
    vector<string> Titemp = files.readFromFileToVector(Titles_path);

    for (int i = 0; i < Titemp.size(); i++) {
        if (title == Titemp[i]) {
            cout << "The avg rate for this title is : ";
            cout << ratetemp[i] << endl;
            return;
        }
    }
    cout << "The title doesn't exist\n";
}


void News::Rate_News(int id) {

    vector<string> ratetemp = files.readFromFileToVector(rate_path);
    vector<string> IDtemp = files.readFromFileToVector(IDSs_path);

    string tempid = to_string(id);
    int index = -1;
    if (!files.isTextInFile(IDSs_path, tempid)) {
        cout << "ID out of scope \n";
        return;
    }

    
    cout << "enter rate from 1 to 5  \n";
    cin >> rate;
    while (rate < "1" || rate > "5")
    {
        cout << "Please Enter number form 1 to 5 \n";
        cin >> rate;
    }



    for (int i = 0; i < IDtemp.size(); i++)
    {
        int temp = stoi(IDtemp[i]);
        if (temp == id)
            index = i;
    }

    if (ratetemp[index] == "Unrated yet")
        ratetemp[index] = rate;
    else {
        float new_rate = strtof(rate.c_str(), NULL);
        float cur_rate = strtof(ratetemp[index].c_str(), NULL);

        float total_rate = (new_rate + cur_rate) / 2;
        string s_rate = to_string(total_rate);
        ratetemp[index] = s_rate;
    }


    files.clearFile(rate_path);

    for (int i = 0; i < IDtemp.size(); i++) {
        files.writeToFile(ratetemp[i], rate_path);
    }
}

void News::display_by_rate() {

    LW_IDtemp LW_CAtemp  LW_DAtemp LW_DEtemp LW_COtemp LW_RAtemp LW_TItemp LW_OCtemp

    vector<pair<string, int>> v;
    pair <string, int> p;
    int ind = 0;
    
    for (auto it: ratetemp)
    {
        p.first = it;
        p.second = ind;
        v.push_back(p);
        ind++;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

   
    for (auto it2 : v)
    {
        if (ratetemp[it2.second] < "2" or ratetemp[it2.second] == "Unrated yet")continue;
        cout << "************************************************************************************************************************" << endl;
        cout << "\t\t\t\t\t\tID : " << IDtemp[it2.second] << endl << " \nTitle : " << Titemp[it2.second] << endl << endl;
        cout << "Description : " << DEStemp[it2.second] << "\n\n" << "category : " << cattemp[it2.second] << endl << endl;
        cout << "date : " << datetemp[it2.second] << endl << endl;
        cout << "Rate : " << ratetemp[it2.second] << endl << endl;
        cout << "************************************************************************************************************************" << endl;
        cout << endl;

    }

}
void News::Categorize() {

    LW_IDtemp LW_CAtemp  LW_DAtemp LW_DEtemp LW_COtemp LW_RAtemp LW_TItemp LW_OCtemp
    set<string>st;

    int big_coutner=0;


    for (int i = 0; i < out_categories.size(); i++) {
        st.insert(out_categories[i]);
    }


    cout << "the list of categories :\n";
    int counter1 = 1;
    map<int, string>mp;
    for (auto i : st) {
        cout << counter1 << " : " << i << endl;
        mp[counter1] = i;
        counter1++;
    }

    int num_categories;
    cout << "select number of categories you want from 1 to "<<st.size()<<endl;
    {
        cin >> num_categories;
        do {
            
            if (num_categories <= 0 || num_categories > st.size()) {
                cout << "the choise number " << num_categories << " out of scope \n\n\n";

                cout << "please!!\nselect from 1 to " << st.size() << ": ";
                cin >> num_categories;
            }
        } while (num_categories <= 0 || num_categories > st.size());
    }
    
    

    cout << "select category\n";

    vector<int> selected_category(num_categories);
    int new_select = 1 , count_category=0;
    map<int, int >duplicated;
    while (count_category!=num_categories)
    {
        cout << "Select the " << count_category+1 << " category: ";
        cin >> new_select;
        if (duplicated[new_select] >0)
        {
            cout << "this number is duplicated\n";
        }
        if (duplicated[new_select] == 0)
        {
            selected_category[count_category] = new_select;
            duplicated[new_select]++;
            count_category++;
        }
        while (new_select <= 0 ||new_select>st.size())
        {
            cout << "This is out of scope\n\nplease wirte right number : ";
            
            cin >> new_select;
            
            if (duplicated[new_select] == 0)
            {
                selected_category[count_category] = new_select;
                duplicated[new_select]++;
                count_category++;
            }
            
        }
       
    }
    map<string, int>check;
    int i = 0;
    while (num_categories--)
    {
      
        
        string category = mp[selected_category[i]];
        check[category]++;
        int cnt = 0;
        if (check[category] == 1)
        {
            for (int i = 0; i < cattemp.size(); i++) 
            {
                if (cattemp[i] == category)
                {
                    big_coutner = 1;
                    cout << "************************************************************************************************************************" << endl;
                    cout << "\t\t\t\t\t\tID : " << IDtemp[i] << endl << " \nTitle : " << Titemp[i] << endl << endl;
                    cout << "Description : " << DEStemp[i] << "\n\n" << "category : " << cattemp[i] << endl << endl;
                    cout << "date : " << datetemp[i] << endl << endl;
                    cout << "Rate : " << ratetemp[i] << endl << endl;
                    cout << "************************************************************************************************************************" << endl;
                    cout << endl;
                }
            }
        }
        i++;
        
    }
    if (big_coutner == 0)
        cout << "NO posts in your categories\n\n";
    
}



void News::display_by_date() {

    LW_IDtemp LW_CAtemp  LW_DAtemp LW_DEtemp LW_COtemp LW_RAtemp LW_TItemp LW_OCtemp

    vector<pair<string, int>> v;
    pair <string, int> p;
    int ind = 0;
    for (auto it : datetemp)
    {
        p.first = it;
        p.second = ind;
        v.push_back(p);
        ind++;
    }
    sort_dates(v);
  

    for (auto it2 : v )
    {
        cout << "\t\t\t\t\t\tID : " << IDtemp[it2.second]<<endl << " \nTitle : " << Titemp[it2.second] << endl<<endl;
        cout << "Description : " << DEStemp[it2.second] << "\n\n" << "category : " << cattemp[it2.second] << endl<<endl;
        cout << "date : " << datetemp[it2.second] << endl<<endl;
        cout << "Rate : " << ratetemp[it2.second] << endl<<endl;
        cout << "************************************************************************************************************************" << endl;
        cout << endl;
    }

}

void News::displaycommentsbyid(int id)
{

    bool found = 0;

  

    if (!files.isTextInFile(IDSs_path,to_string(id))) {
        cout << "ID out of scope \n";

        return;
    }

    
       
    
    
    LW_COtemp
    cout << "************************************************************************************************************************" << endl;

    for (int i = 0; i < commenttemp.size(); i++) {
        if (id == get_index_from_string(commenttemp[i])) {
            cout << "\nComment : " << comment_without_id(commenttemp[i]) << endl;
            found = 1;
        }
    }
    cout << endl;

    if (!found)
        cout << "There is no comments in this post\n\n";

    cout << "************************************************************************************************************************" << endl;
}


void News::addcomment(int id)
{
    bool found = 0;


     if (!files.isTextInFile(IDSs_path,to_string(id))) {
        cout << "ID out of scope \n";

        return;
    }

    
       
    
    string comment;
    cout << "Enter your comment : ";
    cin >> ws;
    getline(cin, comment);
    comment += " ";
    comment += to_string(id);
    files.writeToFile(comment, comment_path);
}
