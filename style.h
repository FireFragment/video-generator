#pragma once
#include "transition.h";
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/// <summary>Defines different styles of videos. 
/// <para>Can contain sounds, transitions and speed of video.</para></summary>
class style
{
public:
	style();
	vector<transition> normalTransitions = { transition() };
	/// <summary>
	/// Transitions which keeps text on screen, it just adds new text.
	/// </summary>
	vector<transition> addingTransitions;
	/// <summary>
	/// Accents text on screen, doesn't change text.
	/// </summary>
	vector<transition> accentingTransitions;
	double speed = 1;
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
	string musicURL;

	/// <returns>Escapesd musicURL (all \ replaces with /)</returns>
	string getEscapedMusicURL();
};

