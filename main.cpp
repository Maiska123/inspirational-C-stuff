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

#include "test.h"
using namespace std;

vector<string> asd;

int main()
{
    asd.push_back("benis");
    asd.push_back("is");
    asd.push_back("big");
    asd.push_back("!");

    for (auto &&i : asd)
    {
        cout << i;
    }
    cout << endl;

    sort(asd.begin(), asd.end());

    for (auto i = begin(asd); i != end(asd); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    cout << count(begin(asd[1]), end(asd[1]), 'b') << endl;
    cout << "end" << endl;

    // test1();
    // test2();

    return 0;
}