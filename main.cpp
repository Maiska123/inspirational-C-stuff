
#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <conio.h> // vanha
#define UNICODE 1
#include <windows.h>
#include <cstdio>
#include <stdio.h>
#include <process.h>

#include "test.hh"
#include "classes.hh"

// #pragma execution_character_set( "utf-8" )

void ClearScreen() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::wcout << "\x1B[2J\x1B[H";
}


void clearscr()
  {
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

void menu(int ch) {
    SetConsoleOutputCP( 65001 );
    _setmode(_fileno(stdout), _O_U16TEXT);
    HANDLE  hConsole;
	// int k = 1;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect); 

    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 800, 600, TRUE);

    clearscr();

    int i = 0;
    wchar_t m[5][30] = {
        L". Testaa vektoreita",
        L". Testaa sisäänsyöttöä",
        L". Testaa järjestyksiä",
        L". Palaverin luonti",
        L". Poistu",
    };

    while (i < 5)
    {
        if(ch == i+1){
            // textbackground(2);
            // SetConsoleTextAttribute(hConsole, k);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY);

            std::wcout << "\n" << (i+1) << m[i];
            // cprintf("%s",m[i]);
            // textbackground(0);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        } else {
            std::wcout << "\n" << (i+1) << m[i];
        }
        i++;
    }
    
}

int main()
{
    clearscr();
    int i = 1;
    int ch = ' ';
    std::wstring a = L"go";
    
    auto op1 = [](std::wstring&) {
        std::wcout << test1() << std::endl;
        return true;
    };

    auto op2 = [](std::wstring&) {
        test2();
        return true;
    };

    auto op3 = [](std::wstring&) {
        test3();
        return true;
    };

    auto op4 = [](std::wstring&) {
        test4();
        return true;
    };



    using FT = bool(std::wstring&); //function type alias of lambda operation
    std::vector<FT*> dataVec; //vector of function pointers

    
    using FT = bool(std::wstring&); //function type alias of lambda operation WITHOUT INPUT
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

    // std::wcout << "users state: " << userState << std::endl;

    // test1();
    // test2();

    // templates
    // classes
    // threading
    // threadpool
    // threadworkers