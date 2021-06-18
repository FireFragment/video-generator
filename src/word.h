#pragma once
#include <string>
#include "animations/animation.h"
using namespace std;
class word
{
public:
	/// <summary>This function is like constructor, deletes all original data and creates new.</summary>
	/// <param name="textOfWord">is word as text.</param>
	void changeWord(string textOfWord);
	word(string textOfWord);
	string text;

	animation anim;

	// TODO: Add accentutation 2 description or remove it.
	/// <summary>
	/// Importance of word in range 0 - 3.
	/// </summary>
	unsigned short int accentutation = 0;
};

