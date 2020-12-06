#include "sentence.h"
#include "myFunctions.h"
#include <iostream>
#include <string>
using namespace std;

sentence::sentence(string text) {
	changeSentence(text);
}
void sentence::changeSentence(string text) {
	words = {};
	vector <string> textOfSentences = myFunctions::splitStringByDelimiter(text, " ");
	vector <string> ::iterator it;
	for (it = textOfSentences.begin(); it != textOfSentences.end(); ++it) {
		words.push_back(*it);
	}
}
