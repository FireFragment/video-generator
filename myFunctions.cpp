#include "myFunctions.h"
#include <list> 
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

list<string> myFunctions::splitStringByDelimiter(string toSplit, string delimiter) {
	toSplit = toSplit + delimiter;
	list<string> returnValue;
	size_t pos = 0;
	std::string token;
	while ((pos = toSplit.find(delimiter)) != string::npos) {
		token = toSplit.substr(0, pos);
		if(token != "") {
			returnValue.push_back(token);
		}
		toSplit.erase(0, pos + delimiter.length());
	}
	return returnValue;
}
list<string> myFunctions::splitStringByDelimiters(string toSplit, list<string> delimiters)
{
	string regex_string = "[^";

	list<string> returnValue;
	list <string> ::iterator it;
	for (it = delimiters.begin(); it != delimiters.end(); ++it) {
		regex_string += *it;
	}
	regex_string += "]+";
	regex words_regex(regex_string);
	auto words_begin = sregex_iterator(toSplit.begin(), toSplit.end(), words_regex);
	auto words_end = sregex_iterator();

	for (sregex_iterator i = words_begin; i != words_end; ++i)
		returnValue.push_back((*i).str());
	return returnValue;
}



