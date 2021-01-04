#include "video.h"

string video::generate() {
	string returnValue = "<!DOCTYPE html><html lang='en'><head><meta charset='utf - 8'><title>Video</title><script>var audio=new Audio('" + style.getEscapedMusicURL() + "');audio.play()</script><style>" + style.baseCSS + "h1::after{animation: ";
	string animationProperty = "";
	string keyframesCode = "";
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


	for (vector <sentence> ::iterator it = sentences.begin(); it != sentences.end(); ++it) {
		sentence actualSentence = *it;

		vector <word> ::iterator it2;
		int i = 0;
		
		transitionSet actualSentenceTransitionSet = style.transitionsSets[rand() % style.transitionsSets.size()];
		for (it2 = actualSentence.words.begin(); it2 != actualSentence.words.end(); ++it2) {
			// Generating CSS animation property
			word actualWord = *it2;

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
	}
	//Removing ", " at end of animation property
	animationProperty = animationProperty.substr(0, animationProperty.length() - 1);
	returnValue += animationProperty + ";content:''} " + keyframesCode + "</style></head><body><h1></h1></body></html><!-- Generated with Maty1000's video generator. -->";
	return returnValue;
}
unsigned short int video::getNeededTransitionsCount()
{
	unsigned short int returnValue = 0;
	for (vector <sentence> ::iterator it = sentences.begin(); it != sentences.end(); ++it) 
		returnValue += (*it).words.size();
	return returnValue - 1;
}

video::video(string text) {
	vector <string> ::iterator it;
	vector <string> textOfSentences = myFunctions::splitStringByDelimiters(text, { ".", "!", "?" });
	for (it = textOfSentences.begin(); it != textOfSentences.end(); ++it) {
		sentences.push_back(*it);
	}

};
