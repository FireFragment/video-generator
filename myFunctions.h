#pragma once
#include <string>
#include <list> 
#include "transition.h" 
using namespace std;
/// <summary>
/// Static functions made for this program.
/// </summary>
class myFunctions
{
public:
	/// <returns>List of substrings of <paramref name="toSplit"/>, splitted by <paramref name="delimiter"/></returns>
	/// <param name="toSplit">is string to split around delimiter.</param>
	/// <param name="delimiter" />
	static list<string> splitStringByDelimiter(string toSplit, string delimiter);

	/// <returns>List of substrings of <paramref name="toSplit"/>, splitted by all of <paramref name="delimiters"/></returns>
	/// <param name="toSplit">is string to split around delimiter.</param>
	/// <param name="delimiters" />
	static list<string> splitStringByDelimiters(string toSplit, list<string> delimiters);

};

