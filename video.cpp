#include "video.h"


string video::generate() {
	string returnValue = "<!DOCTYPE html><html lang='en'><head><meta charset='utf - 8'><title>Video</title><script>var audio=new Audio('" + style.getEscapedMusicURL() + "');audio.play()</script><style>" + style.baseCSS + "h1::after{animation: ";

	int anim_id = 0;
	double delay = 0;

	//Add transitions

	style.normalTransitions.push_back(transition::emptyTransition() + "@keyframes a" + transitionItem_animId + "{from{content:\"" + transitionItem_previousWord + "\";}50%{opacity:0}100%{" + transitionItem(1, "color:black;background:white;", "color: white; background: none;") + "opacity:1;margin-right:0;content:\"" + transitionItem_actualWord + "\";}}");
	style.normalTransitions.push_back(transition::emptyTransition() + "@keyframes a" + transitionItem_animId + "{from{content:\"" + transitionItem_previousWord + "\";transform:rotateX(0deg);}50%{color:white;background:none;transform:rotateX(90deg);}50.01%{" + transitionItem(1, "color:black;background:white;", "color: white; background: none;") + ";transform:rotateX(-90deg);}100%{transform:rotateX(0deg);margin-right:0;content:\"" +transitionItem_actualWord + "\";}}" );

    // Generating CSS animation property.
	cout << "Analyzing music, please wait..." << endl;
	list<TimeStamp> beats = myFunctions::getBeats(style.musicURL, 1, getNeededTransitionsCount(), true);
	list<TimeStamp> ::iterator beatsIt = beats.begin();
	for (list <sentence> ::iterator it = sentences.begin(); it != sentences.end(); ++it) {
		list <word> ::iterator it2;
		sentence actualSentence = *it;

		for (it2 = actualSentence.words.begin(); it2 != actualSentence.words.end(); ++it2) {
			word actualWord = *it2;
			TimeStamp actualBeat = *beatsIt;
			double delayFromPreviousAnim = (actualBeat.getMilliseconds() / double(100) + actualBeat.getSeconds()) - delay;
			delay = actualBeat.getMilliseconds() / double(100) + actualBeat.getSeconds();
			returnValue += "a" + to_string(anim_id) + " " + myFunctions::doubleToString(delayFromPreviousAnim * (double)style.speed) + "0s ease "  + myFunctions::doubleToString(delay) + "0s running normal forwards, ";
			anim_id++;
			
			bool atEnd = beatsIt == beats.end();
			if (beatsIt == beats.end()) {
				beatsIt = beats.begin();
			}
			++beatsIt;
		}
		
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

	returnValue += "</style></head><body><h1></h1></body></html><!-- Generated with Maty1000's video generator. -->";
	return returnValue;
}
unsigned short int video::getNeededTransitionsCount()
{
	unsigned short int returnValue = 0;
	for (list <sentence> ::iterator it = sentences.begin(); it != sentences.end(); ++it) 
		returnValue += (*it).words.size();
	return returnValue - 1;
}

video::video(string text) {
	list <string> ::iterator it;
	list <string> textOfSentences = myFunctions::splitStringByDelimiters(text, { ".", "!", "?" });
	for (it = textOfSentences.begin(); it != textOfSentences.end(); ++it) {
		sentences.push_back(*it);
	}

};
