
#include <bits/stdc++.h>   

#include <iostream>
using std::wcin;
using std::wcout;

#define UNICODE 1
#include <windows.h>

#include <string>
using std::wstring;

#include <vector>
using std::begin;
using std::end;
using std::vector;

#include <algorithm>
using std::count;
using std::sort;

#include "test.hh"
#include "classes/classes.hh"

using namespace std;

vector<std::wstring> stringVector;

    using namespace std;
   

   
    std::wstring name, another;
    wchar_t asd[20];

    // auto destruct = [](wchar_t a[]) { std::wstring s; for (int i = (sizeof(a) / sizeof(int)) - 1; i >= 0; i--){ s.end (a[i]);} return s; };
    
    // returns wchar_t[] as std::wstring
    /*
    * returns wchar_t[] as std::wstring
    */
    std::wstring cToString(wchar_t* a){ std::wstring s = a; return s; }

    wchar_t str1[100] = L"Journal";
    wchar_t str2[100]= L"Dev";
    wstring phrase;


   void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    // std::wcout << "\x1B[2J\x1B[H";
        
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
    cellCount = csbi.dwSize.X *csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR) ' ',
        cellCount,
        homeCoords,
        &count
        )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
        )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition( hStdOut, homeCoords );
  
}


    int test1()
    {
        std::wstring str1 = L"aaa", str2 = L"bbb", str3 = L"ccc", str4 = L"ddd", str5 = L"eee", str6 = L"fff";

        vector vtr = {&str1, &str2, &str3, &str4, &str5, &str6};

        for (unsigned int i=0; i<vtr.size(); i++)
            std::wcout << *vtr[i] << ' ';
        std::wcout << endl;

        for ( auto &it : vtr)
            std::wcout << *it << ' ';
        std::wcout << endl;

        return 1;
    }

void test2() {
          // output 2 concatted wchar_t arrays
        std::wcout << "Concatenated std::wstring:" << endl;
        wcscat(str1, str2);
        std::wcout << str1 << endl;;

        // test input from user
        int answer = test1();
        std::wcout << "name pls: ";

        std::wcin >> name;
        std::wcout << "\nanotherOne (max len 20¨, end with ;): ";


        std::wcin.ignore();
        std::wcin.getline(asd, (sizeof(asd))); //(recommended)

        // std::wcin.ignore();
        // std::wcin.clear();
        // std::wcin.sync();

        std::wcin.clear();
        std::wcin.sync();
        std::wcout << "enter phrase: ";
        getline(std::wcin, phrase);
        // clear output screen

        clear();

        // print answers
        std::wcout << "---" << std::endl;
        std::wcout << "name is: " << name << std::endl;
        std::wcout << "another is: " << cToString(asd) << std::endl;
        std::wcout << "answer is: " << phrase << std::endl;
        printf("answer is again: %i",answer);
}

void test3(){
    stringVector.push_back(L"benis");
    stringVector.push_back(L"is");
    stringVector.push_back(L"big");
    stringVector.push_back(L"!");

    for (auto &&i : stringVector)
    {
        std::wcout << i;
    }
    std::wcout << endl;

    sort(stringVector.begin(), stringVector.end());

    for (auto i = begin(stringVector); i != end(stringVector); i++)
    {
        std::wcout << *i << " ";
    }
    std::wcout << endl;

    std::wcout << count(begin(stringVector[1]), end(stringVector[1]), 'b') << endl;
    std::wcout << "end" << endl;

}

void test4() {
    std::wstring x, y;

    std::wcout << "give me two names: ";
    std::wcin >> x >> y;
    
    std::wcout << std::endl;

    User user1(x);
    User user2(y);
    User user3;

    user1.printInfo();
    user2.printInfo();
    user3.printInfo();

    std::wcout << "lisätään osallistujat palaveriin..." << std::endl;
    
    std::vector<User*> attendees = {&user1, &user2, &user3};

    Meeting meeting(L"Eeppinen palaveri",attendees);

    meeting.attendees_.find(&user1)->second = Status::Approved;
    meeting.attendees_.find(&user2)->second = Status::Cancelled;

    meeting.printMeetingInfo();


    user1.points(Modifier::add, 1000);
    user2.points(Modifier::deduct, 10); // watch this bitches


    user1.printInfo();
    user2.printInfo();
    user3.printInfo();
}

void test5() {
    
    Accum<int> integers(0);
    Accum<std::wstring> strings(L"");

    strings += L"Hello ";
    strings += L"World";

    integers += 1;
    integers += 1;

    User userTemplate1(L"Bruh"), userTemplate2(L"DoesThisWork");
    Accum<User> users(0);

    users += userTemplate2;


}