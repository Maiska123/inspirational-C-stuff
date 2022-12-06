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
        ". Palaverin luonti",
        ". Menuelementti",
        ". Menuelementti",
        ". Menuelementti",
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
            if(i != 5){ clearscr(); test4(); }
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