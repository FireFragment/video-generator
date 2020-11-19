#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <Windows.h>
#include "myFunctions.h"
#include "BeatDetector/Detector/BeatDetector.h"
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
   cout << "DEVELOPMENT VERSION, DO NOT USE!\n\nIt's recommended to use rhytmical musics.\nEnter URL of music: " ;
   getline(cin, video.style.musicURL);
   // Create and open a text file
   ofstream OutFile("generated.html");
   OutFile << video.generate();

   // Close the file
   OutFile.close();
   system("generated.html");
}