#pragma once
#include "word.h"
#include <string>
#include <list> 
using namespace std;
class sentence
{
public:
	list<word> words;

	/// <summary>This constructor creates <c>sentence</c> object from text. </summary>
	/// <param name="text">is sentence as text.</param>
	sentence(string text);
	/// <summary>This function is like constructor, deletes all original data and creates new.</summary>
    /// <param name="text">is sentence as text.</param>
	void changeSentence(string text); 
};

