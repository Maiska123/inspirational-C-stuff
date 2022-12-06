#include <iostream>
#include <conio.h> // vanha
#include <windows.h>
#include <stdio.h>
#include <process.h>


#include "test.hh"
#include "classes.hh"

void clearscr() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

void menu(int ch) {
    HANDLE  hConsole;
	// int k = 1;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    clearscr();

    int i = 0;
    char m[5][30] = {
        ". Testaa vektoreita",
        ". Testaa sisäänsyöttöä",
        ". Testaa järjestyksiä",
        ". Palaverin luonti",
        ". Poistu",
    };

    while (i < 5)
    {
        if(ch == i+1){
            // textbackground(2);
            // SetConsoleTextAttribute(hConsole, k);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY);

            std::cout << "\n" << (i+1) << m[i];
            // cprintf("%s",m[i]);
            // textbackground(0);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        } else {
            std::cout << "\n" << (i+1) << m[i];
        }
        i++;
    }
    
}

int main()
{
    clearscr();
    int i = 1;
    int ch = ' ';
    std::string a = "go";
    
    auto op1 = [](std::string&) {
        std::cout << test1() << std::endl;
        return true;
    };

    auto op2 = [](std::string&) {
        test2();
        return true;
    };

    auto op3 = [](std::string&) {
        test3();
        return true;
    };

    auto op4 = [](std::string&) {
        test4();
        return true;
    };



    using FT = bool(std::string&); //function type alias of lambda operation
    std::vector<FT*> dataVec; //vector of function pointers

    
    using FT = bool(std::string&); //function type alias of lambda operation WITHOUT INPUT
    std::vector<FT*> vec; //vector of function pointers


    vec.push_back(op1);
    vec.push_back(op2);
    vec.push_back(op3);
    vec.push_back(op4);


    while (1)
    {
        menu(i);
        ch = getch();
        switch (ch)
        {
        case 72:
            if(i != 1){ i--; menu(i); }

            break;
        case 80:
            if(i != 5){ i++; menu(i); }

            break;
        case 13:
            if(i != 5){ clearscr(); vec[i-1](a); }
            else exit(1);
            getch();
            break;
        case 27:
            exit(1);

            break;
        
        default:
            break;
        }
    }
    

    return 0;
}



    // Status userState = Pending;

    // std::cout << "users state: " << userState << std::endl;

    // test1();
    // test2();

    // templates
    // classes
    // threading
    // threadpool
    // threadworkers