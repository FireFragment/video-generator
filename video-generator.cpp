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
   video video("Welcome to my video generator. Firstly: this is just the development draft, so it's pretty unusable yet. But I plan to make it better this to summer. When it will be complete, you will be able to make a video from plain text and your favorite music. But not now, you have to wait a bit.");
   cout << "DEVELOPMENT VERSION, DO NOT USE!\n\nIt's recommended to use rhytmical musics.\nEnter the path of music: " ;
   getline(cin, video.style.musicURL);
   // Create and open a text file
   ofstream OutFile("generated.html");
   OutFile << video.generate();

   // Close the file
   OutFile.close();
   system("generated.html");
}