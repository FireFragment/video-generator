#pragma once
#include "transition.h";
#include <list>;
#include <string>;
#include <algorithm>
using namespace std;
/// <summary>Defines different styles of videos. 
/// <para>Can contain sounds, transitions and speed of video.</para></summary>
class style
{
public:
	style();
	//	list<transition> transitions = {transition()};
	list<transition> normalTransitions = { transition() };
	list<transition> accentTransitions;
	list<transition> endTransitions;
	double speed = 0.3;
	/// <summary>
	/// Speed * this value = spaces between sentences in seconds.
	/// </summary>
	double sentences_spaces = 3;

	/// <summary>
	/// Name of font from Google fonts (https://fonts.google.com/) used by style.
	/// </summary>
	string normalFont = "Josefin Sans";
	string accentFont = "Permanent Marker";

	string baseCSS; // Assigned in constructor.
};

