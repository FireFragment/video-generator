#include "video.h"

string video::generate() {
	string animationProperty;
	string keyframesCode;
	string HTML;

	//Count of already added <h1> elements in HTML variable
	int HTMLElementsCount;
	int anim_id = 0;
	double delay = 0;

	//Add transitions

	style.transitionsSets.push_back(transitionSet(transition::emptyTransition() + "@keyframes a" + transition::transitionItem::transitionItem_animId + "{from{content:\"" + transition::transitionItem::transitionItem_previousWord + "\";}50%{opacity:0}100%{" + transition::transitionItem(1, "color:black;background:white;", "color: white; background: none;") + "opacity:1;margin-right:0;content:\"" + transition::transitionItem::transitionItem_actualWord + "\";}}"));
	/*	style.normalTransitions.push_back(transition::emptyTransition() + "@keyframes a" + transitionItem_animId + "{from{content:\"" + transitionItem_previousWord + "\";transform:rotateX(0deg);}50%{color:white;background:none;transform:rotateX(90deg);}50.01%{" + transitionItem(1, "color:black;background:white;", "color: white; background: none;") + "transform:rotateX(-90deg);}100%{transform:rotateX(0deg);margin-right:0;content:\"" +transitionItem_actualWord + "\";}}" );
		style.addingTransitions.push_back(transition::emptyTransition(transition_adding) + "@keyframes a" + transitionItem_animId + "{from{content:\"" + transitionItem_previousWord + "\";}100%{content:\"" + transitionItem_actualWord + "\";}}" );
	*/
	// Generating CSS animation property.
	cout << "Analyzing music, please wait..." << endl;
	vector<beat> beats = myFunctions::getBeats(style.musicURL, 5, getNeededTransitionsCount(), true);
	vector<beat> ::iterator beatsIt = beats.begin();
	anim_id = 0;
	string previousWordText = "";



	transitionSet actualSentenceTransitionSet = style.transitionsSets[rand() % style.transitionsSets.size()];
	for (vector<word> ::iterator it = words.begin(); it != words.end(); ++it) {
		// Generating CSS animation property
		word actualWord = *it;

		beat actualBeat = *beatsIt;
		double delayFromPreviousAnim = actualBeat.time - delay;
		delay = actualBeat.time;
		animationProperty += "a" + to_string(anim_id) + " " + myFunctions::doubleToString(delayFromPreviousAnim * (double)style.speed) + "0s ease " + myFunctions::doubleToString(delay) + "0s running normal forwards,";


		bool atEnd = beatsIt == beats.end();
		if (beatsIt == beats.end()) {
			beatsIt = beats.begin();
		}
		++beatsIt;

		// Generating @keyframes
		if (delayFromPreviousAnim >= style.maximumFreqForAdddingTrans) {
			keyframesCode += actualSentenceTransitionSet.normalTransition.generateCode(actualWord.text, previousWordText, anim_id, style, actualWord.accentutation);
			previousWordText = "";
		}
		else
			keyframesCode += actualSentenceTransitionSet.addingTransition.generateCode(previousWordText + " " + actualWord.text, previousWordText, anim_id, style, actualWord.accentutation);
		previousWordText += " " + actualWord.text;

		anim_id++;
	}

	//Removing ", " at end of animation property
	animationProperty = animationProperty.substr(0, animationProperty.length() - 1);

	return "<!DOCTYPE html><html lang='en'><head><meta charset='utf - 8'><title>Video</title><script>var audio=new Audio('" + style.getEscapedMusicURL() + "');audio.play()</script><style>" + style.baseCSS + "h1::after{animation: " + animationProperty + ";content:''} " + keyframesCode + "</style></head><body><h1></h1></body></html><!-- Generated with Maty1000's video generator. -->";
}
unsigned short int video::getNeededTransitionsCount()
{

	return words.size();
}

video::video(string text) {
	vector <string> ::iterator it;
	vector <string> textOfWords = myFunctions::splitStringByDelimiters(text, { " " });
	for (it = textOfWords.begin(); it != textOfWords.end(); ++it) {
		words.push_back(*it);
	}

};
