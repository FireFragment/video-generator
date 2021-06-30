#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "transitionSet.h"
using namespace std;
/// <summary>Defines different styles of videos. 
/// <para>Contains sounds, transitions and speed of video.</para></summary>
class style
{
public:
	style();
	double speed = 1;

	/// <summary>
	/// Name of font from Google fonts (https://fonts.google.com/) used by style.
	/// </summary>
	string normalFont = "Josefin Sans";

	string baseCSS; // Assigned in constructor.
	string musicURL;

	/// <returns>Escaped musicURL (all \ replaces with /)</returns>
	string getEscapedMusicURL();
	
	/// <summary>
	/// How strong animations in the video are.
	/// </summary>
	double animationStrength = 100;
};

