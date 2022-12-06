
#include <bits/stdc++.h>   

#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <vector>
using std::begin;
using std::end;
using std::vector;

#include <algorithm>
using std::count;
using std::sort;

#include "test.hh"
#include "classes.hh"

using namespace std;

vector<string> stringVector;

    using namespace std;
   

   
    string name, another;
    char asd[20];

    // auto destruct = [](char a[]) { string s; for (int i = (sizeof(a) / sizeof(int)) - 1; i >= 0; i--){ s.end (a[i]);} return s; };
    
    // returns char[] as string
    /*
    * returns char[] as string
    */
    string cToString(char* a){ string s = a; return s; }

    char str1[100] = "Journal";
    char str2[100]= "Dev";
    string phrase;


   void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}


    int test1()
    {
        string str1 = "aaa", str2 = "bbb", str3 = "ccc", str4 = "ddd", str5 = "eee", str6 = "fff";

        vector vtr = {&str1, &str2, &str3, &str4, &str5, &str6};

        for (unsigned int i=0; i<vtr.size(); i++)
            cout << *vtr[i] << ' ';
        cout << endl;

        for ( auto &it : vtr)
            cout << *it << ' ';
        cout << endl;

        return 1;
    }

void test2() {
          // output 2 concatted char arrays
        cout << "Concatenated String:" << endl;
        strcat(str1, str2);
        cout << str1 << endl;;

        // test input from user
        int answer = test1();
        cout << "name pls: ";

        cin >> name;
        cout << "\nanotherOne (max len 20¨, end with ;): ";


        cin.ignore();
        cin.getline(asd, (sizeof(asd))); //(recommended)

        // cin.ignore();
        // cin.clear();
        // cin.sync();

        cin.clear();
        cin.sync();
        cout << "enter phrase: ";
        getline(cin, phrase);
        // clear output screen

        clear();

        // print answers
        cout << "---" << endl;
        cout << "name is: " << name << endl;
        cout << "another is: " << cToString(asd) << endl;
        cout << "answer is: " << phrase << endl;
        printf("answer is again: %i",answer);
}

void test3(){
    stringVector.push_back("benis");
    stringVector.push_back("is");
    stringVector.push_back("big");
    stringVector.push_back("!");

    for (auto &&i : stringVector)
    {
        cout << i;
    }
    cout << endl;

    sort(stringVector.begin(), stringVector.end());

    for (auto i = begin(stringVector); i != end(stringVector); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    cout << count(begin(stringVector[1]), end(stringVector[1]), 'b') << endl;
    cout << "end" << endl;

}

void test4() {
    std::string x, y;

    std::cout << "give me two names: ";
    std::cin >> x >> y;
    
    std::cout << std::endl;

    User user1(x);
    User user2(y);
    User user3;

    user1.printInfo();
    user2.printInfo();
    user3.printInfo();

    std::cout << "lisätään osallistujat palaveriin..." << std::endl;
    
    std::vector<User*> attendees = {&user1, &user2, &user3};

    Meeting meeting("palaveri",attendees);

    meeting.attendees_.find(&user1)->second = Status::Approved;
    meeting.attendees_.find(&user2)->second = Status::Cancelled;

    meeting.printMeetingInfo();


    user1.points(Modifier::add, 1000);
    user2.points(Modifier::deduct, 10); // watch this bitches


    user1.printInfo();
    user2.printInfo();
    user3.printInfo();
}