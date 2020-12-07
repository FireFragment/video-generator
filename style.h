#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "transition.h"
using namespace std;
/// <summary>Defines different styles of videos. 
/// <para>Contains sounds, transitions and speed of video.</para></summary>
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

	/// <returns>Escaped musicURL (all \ replaces with /)</returns>
	string getEscapedMusicURL();

	/// <summary>
	/// Time in seconds.
	/// <para>If is this value bigger than time from previous beat, addingTransition will be used instead of normalTransition.</para>
	/// </summary>
	float maximumFreqForAdddingTrans = 1;
};

