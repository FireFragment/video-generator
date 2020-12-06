#pragma once
#include <string>
#include <vector> 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "sentence.h"
#include "style.h"
#include "myFunctions.h"
using namespace std;

class video
{
public:
	/// <param name="text">represents text of new video.</param>
	video(string text);
	/// <returns>HTML code with result video containing CSS and JS. </returns>
	string generate();
	vector <sentence> sentences;
	style style;
private:
	/// <returns>Count of transitions in video.</returns>
	unsigned short int getNeededTransitionsCount();
};

