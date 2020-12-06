#pragma once

#include <vector> 
#include <iostream>
#include <algorithm>
#include <regex>
#include <Windows.h>
#include "transition.h" 
#include "BeatDetector/Detector/BeatDetector.h" 
using namespace std;
/// <summary>
/// Static functions made for this program.
/// </summary>
class myFunctions
{
public:
	/// <returns>vector of substrings of <paramref name="toSplit"/>, splitted by <paramref name="delimiter"/></returns>
	/// <param name="toSplit">is string to split around delimiter.</param>
	/// <param name="delimiter" />
	static vector<string> splitStringByDelimiter(string toSplit, string delimiter);

	/// <returns>vector of substrings of <paramref name="toSplit"/>, splitted by all of <paramref name="delimiters"/></returns>
	/// <param name="toSplit">is string to split around delimiter.</param>
	/// <param name="delimiters" />
	static vector<string> splitStringByDelimiters(string toSplit, vector<string> delimiters);
	/// <summary>
	/// Gets beats from adress
	/// </summary>
	/// <param name="url"> is adress of sound to get beats from that</param>
	/// <param name="sensitivity">Optional, default is 3. Higher value considers more moments as beats, lower is less beats for seconds. 1 is default</param>
	/// <param name="count">Optional, number of required beats. If undefined or 0, function will return all beats in song</param>
	/// <param name="echoProgress">Optional, if true, progress of detection will be written to console. Defaultly false.</param>
	/// <returns></returns>
	static vector<TimeStamp> getBeats(string url, float sensitivity = 3, unsigned short int count = 0, bool echoProgress = false);
	static string doubleToString(double num);
};

