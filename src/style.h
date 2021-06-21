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
	vector<transitionSet> transitionsSets = { transitionSet() };
	double speed = 1;

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
	/// Relative time. See <see cref="beatGroup::getRelativeTimeAfterBeat" /> for more info about relative times.
	/// <para>If is this value bigger than relative time to previous beat, addingTransition will be used instead of normalTransition.</para>
	/// </summary>
	float maximumRelTimeDistForAddingTrans = 1.5;
	/// <summary>
	/// Time in seconds.
	/// <para>If is this value bigger than time from previous beat, accentingTransition will be used instead of normalTransition.</para>
	/// </summary>
	float maximumFreqForAccentingTrans = 0.1;
	
	/// <summary>
	/// How strong animations in the video are.
	/// </summary>
	double animationStrength = 100;
};

