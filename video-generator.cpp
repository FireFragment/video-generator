#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <Windows.h>
#include "myFunctions.h"
#include "BeatDetector/Detector/BeatDetector.h"
#include "video.h"
using namespace std;

//function for printing the elements in a vector 
void showvector(vector <string> g)
{
    vector <string> ::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\n' << *it;
    cout << '\n';
}

int main()
{
   video video("Welcome to my video generator. It's only the draft, so the results aren't so good. But future updates will be here soon!");
   cout << "DEVELOPMENT VERSION, DO NOT USE!\n\nIt's recommended to use rhytmical musics.\nEnter the path of music: " ;
   getline(cin, video.style.musicURL);
   // Create and open a text file
   ofstream OutFile("generated.html");
   OutFile << video.generate();

   // Close the file
   OutFile.close();
   system("generated.html");
}