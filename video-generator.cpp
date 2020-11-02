#include <iostream>
#include <fstream>
#include <list>
#include "myFunctions.h"
#include "video.h"
using namespace std;

//function for printing the elements in a list 
void showlist(list <string> g)
{
    list <string> ::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\n' << *it;
    cout << '\n';
}

int main()
{
   video video("This is my video generator. It's only draft, so result isn't so good. But future updates will be here soon!");
   cout << "MINIMIZED HTML CODE" << endl << "->  Create .html file and paste there this:" << endl << endl << video.generate() << endl << endl;
   system("pause");
}