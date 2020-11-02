#include "video.h"
#include "myFunctions.h"
#include <iostream>
#include <ctime>
#include <cstdlib>


string video::generate() {
	string returnValue = "<!DOCTYPE html><html lang='en'><head><meta charset='utf - 8'><title>Video</title><style>" + style.baseCSS + "h1::after{animation: ";

	int anim_id = 0;
	double delay = 0;

	//Add transitions

	style.normalTransitions.push_back( transition({ transitionItem("@keyframes anim"), transitionItem(transitionItem_animId), transitionItem("{from{content:\""), transitionItem(transitionItem_previousWord), transitionItem("\";"), transitionItem("}50%{opacity:0}100%{"), transitionItem(1, "color:black;background:white;", "color: white; background: none;"), transitionItem("opacity:1;margin-right:0;content:\""), transitionItem(transitionItem_actualWord), transitionItem("\";}}") }));
	style.normalTransitions.push_back( transition({ transitionItem("@keyframes anim"), transitionItem(transitionItem_animId), transitionItem("{from{content:\""), transitionItem(transitionItem_previousWord), transitionItem("\";transform:rotateX(0deg);}50%{"), transitionItem("color: white; background: none;"), transitionItem("transform:rotateX(90deg);}50.01%{"), transitionItem(1, "color:black;background:white;", "color: white; background: none;"), transitionItem(";transform:rotateX(-90deg);}100%{transform:rotateX(0deg);margin-right:0;content:\""), transitionItem(transitionItem_actualWord), transitionItem("\";}}") }) );

    // Generating CSS animation property.
	for (list <sentence> ::iterator it = sentences.begin(); it != sentences.end(); ++it) {
		list <word> ::iterator it2;
		sentence actualSentence = *it;

		for (it2 = actualSentence.words.begin(); it2 != actualSentence.words.end(); ++it2) {
			word actualWord = *it2;
			returnValue += "anim" + to_string(anim_id) + " " + to_string(style.speed*1).erase(to_string(style.speed).find_last_not_of('0') + 1, string::npos) + "s ease " + to_string(delay).erase(to_string(delay).find_last_not_of('0') + 1, string::npos) + "0s running normal forwards, ";
			anim_id++;
			delay = delay + style.speed;
		}
		delay = delay + style.speed * style.sentences_spaces;
	}
	anim_id = 0;
	returnValue = returnValue.substr(0, returnValue.length() - 2);
	returnValue += "; content:''} ";
	string previousWordText = "";
	string previousWordsTexts = "";
	// Generating @keyframes
	for (list <sentence> ::iterator it = sentences.begin(); it != sentences.end(); ++it) {
		sentence actualSentence = *it;

		list <word> ::iterator it2;
		int i = 0;
		transition actualSentenceTransition = transition::pickTransitionFromListByIndex(style.normalTransitions, rand() % style.normalTransitions.size());
		for (it2 = actualSentence.words.begin(); it2 != actualSentence.words.end(); ++it2) {
			word actualWord = *it2;

			returnValue += actualSentenceTransition.generateCode(actualWord.text, previousWordText, previousWordsTexts, anim_id, style, actualWord.accentutation);
			previousWordText = actualWord.text;
			previousWordsTexts += actualWord.text;
			anim_id++;
		}
	}

	returnValue += "</style></head><body><h1></h1></body></html>";
	return returnValue;
} 
video::video(string text) {
	list <string> ::iterator it;
	list <string> textOfSentences = myFunctions::splitStringByDelimiters(text, { ".", "!", "?" });
	for (it = textOfSentences.begin(); it != textOfSentences.end(); ++it) {
		sentences.push_back(*it);
	}

};