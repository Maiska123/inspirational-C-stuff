
#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <conio.h> // vanha
#define UNICODE 1
#include <windows.h>
#include <cstdio>
#include <stdio.h>
#include <process.h>
#include <locale>
#include <clocale>
#include <codecvt>
#include <memory> // for unique_ptr and make_unique
// auto p = std::make_unique<double[]>(1'000'000); // deleted automatically after end of the scope
#include <chrono>
#include <tuple> // extended std::pair -> std::tuple
// to get invidual values like std::get<double>(tupleName) - if has two doubles - not work
#include <map>
#include <algorithm>
#include <vector>

#include "test.hh"
#include "classes.hh"

// #pragma execution_character_set( "utf-8" )

// TO MAKE EASY DEBUGGING ABOUT MEMORY USAGE
// make a debug flag so program writes out constructor and destructor messages from every class

// raw pointers to smart_ptr when want to memory mgmt to automatic

// chrono library for time management
// using namespace std::chrono;
// std::chrono::seconds s{10};
// auto ss = 10s; // can use deduced literals like s for seconds

// std::chrono can mix and match units 
// auto x = 2s;
// auto z = 150ms;
// auto y = x + z;
// ARE CONVERTED AT COMPLE-TIME!

// auto x = "Connie"s; // s as the suffix auto deduces from char*[] to string

// to switch functions from runtime to compile time
// add constexpr at front of the declaration

// to have some constant large static variables
// you can create variable template
template <typename T>
constexpr T pi = T(3.141592653589793238462643383);

// and use it like
void printTest() {
    std::wcout << "what!?" << std::endl;
    std::wcout << "pi as int is: " << pi<int> << std::endl;
    std::wcout << "pi as double is: " << pi<double> << std::endl;
    std::wcout << "pi as float is: " << pi<float> << std::endl;
}

// std::tuple<std::string,double,std::pair<std::string,int>> getUser(int id) {
//     return std::make_tuple("Username",3.8, std::pair("asd",5));
// }
// // and to get data
// auto user0 = getUser(0);
// std::wcout << std::get<0>(user0); // first object <0>, second <1> etc...

// // C++17 structured binding:
// auto [ gpa2, grade2, name2 ] = getUser(2);
// std::wcout << std::get<0>(user0);

constexpr int constantAtCompiletime() {
    return 1;
}

// auto p = std::make_unique<int> = 64;

// auto lambda = [ptr = move(p)](){
//     std::wcout << "lambda in action - value:" << *ptr << std::endl;
// }

// compiletime template constructs that needs type checking
template <typename T>
auto length(T const& value) {
    if constexpr /* <- !!! */ (std::is_integral<T>::value) {
        return value;
    } else {
        return value.length();
    }
}

void templateTypeChecking()
{
    int n{64};
    std::string s{"Jeess"};

    std::wcout << "length of n is: " << length(n) << std::endl;
    std::wcout << "length of s is: " << length(s) << std::endl;
}

void variableDeclarationInStatement() {
    std::vector<std::string> names{"name","abc"};

    if(const auto it = std::find(std::begin(names), std::end(names),"abc"); it != std::end(names)){
        *it = "***";
    } else {
        // *it usable here too
    }
}

std::map<std::wstring,std::wstring> dictionary{{L"yea",L"boi"}, {L"yeah",L"baby"}};

void autoStructuredBiding() {



    auto [pos, success] = dictionary.insert({L"yea",L"boi"});
    if (success) {std::wcout << L"insert OK!" << std::endl;}
    else {std::wcout << L"Insert failed!" << std::endl;}

    auto [pos, success] = dictionary.insert({L"ooh",L"mama"});
    if (success) {std::wcout << L"insert OK!" << std::endl;}
    else {std::wcout << L"Insert failed!" << std::endl;}


    for (const auto& [first, second] : dictionary){
        std::wcout << L"\t" << first << L" : " << second << std::endl; 
    }
}
// you can futureproof software and deprecate stuff with [[deprecated]] syntax
// you can reason with [[deprecated("this function stinks, don't use this!")]]
// [[deprecated("this function stinks, don't use this!")]]
// void stupidFunction() {
//     std::cout << "STOP USING THIS FUNCTION!" << std::endl;
// }

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

    std::setlocale(LC_ALL, ""); // for C and C++ where synced with stdio
    std::locale::global(std::locale("")); // for C++
    SetConsoleOutputCP( 65001 );
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::cout.imbue(std::locale(""));
    std::wcout.imbue(std::locale(""));
    std::wcin.imbue(std::locale(""));


    // std::wcin.imbue(std::locale(""));
    // std::wcout.imbue(std::locale(""));

    // std::wofstream wcout(fileName);
    // std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);

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

    printTest();

    auto p = std::make_unique<int>(64);

    auto lambda = [ptr = move(p)](){
        std::wcout << "lambda in action - value:" << *ptr << std::endl;
    };

    lambda();
    templateTypeChecking();

    autoStructuredBiding();

    system("pause");
    clearscr();

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
        // stupidFunction();
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