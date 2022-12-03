    #include <iostream>
    #include <string>
    #include <vector>
    #include <bits/stdc++.h>    

    #include "test.h"
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

    int main()
    {
        // output 2 concatted char arrays
        cout << "Concatenated String:" << endl;
        strcat(str1, str2);
        cout << str1 << endl;;

        // test input from user
        int answer = test1();
        cout << "name pls: ";

        cin >> name;
        cout << "\nanotherOne (max len 20¨, end with ;): ";

        cin.getline(asd, (sizeof(asd)),';'); //(recommended)

        // clear output screen
        clear();

        // print answers
        cout << "---" << endl;
        cout << "name is: " << name << endl;
        cout << "another is: " << cToString(asd) << endl;
        cout << "answer is: " << answer << endl;
        printf("answer is again: %i",answer);
        return 0;
    }