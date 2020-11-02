#pragma once
#include <string>
using namespace std;
class word
{
public:
	/// <summary>This function is like constructor, deletes all original data and creates new.</summary>
	/// <param name="textOfWord">is word as text.</param>
	void changeWord(string textOfWord);
	word(string textOfWord);
	string text;

	// TODO: Add accentutation 2 description or remove it.
	/// <summary>
	/// Importance of word in range 0 - 3.
	/// <para>0: No accentutation, normal importance. 1: Automatically marked, accentutated by transition. 3: User-marked by IUPPERCASE, used special transitions</para>
	/// </summary>
	unsigned short int accentutation = 0;
};

