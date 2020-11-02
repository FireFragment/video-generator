#pragma once
#include <string>
#include <list> 
#include "sentence.h"
#include "style.h"
using namespace std;

class video
{
public:
	/// <param name="text">represents text of new video.</param>
	video(string text);
	/// <returns>HTML code with result video containing CSS and JS. </returns>
	string generate();
	list <sentence> sentences;
	style style;
};

