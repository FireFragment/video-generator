#include "video.h"

const string video::generate() {
	cout << generateHTML();

	string animationProperty;
	string keyframesCode;
	string HTML;

	//Count of already added <h1> elements in HTML variable
	int HTMLElementsCount;
	int anim_id = 0;
	double delay = 0;

	// Generating CSS animation property.
	cout << "Analyzing music, please wait..." << endl;
	beatGroup beats = helperFunctions::getBeats(style.musicURL, 3, getNeededTransitionsCount(), true);
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
		animationProperty += "a" + to_string(anim_id) + " " + helperFunctions::doubleToString(delayFromPreviousAnim * (double)style.speed) + "0s ease " + helperFunctions::doubleToString(delay) + "0s running normal forwards,";


		bool atEnd = beatsIt == beats.end();
		if (beatsIt == beats.end()) {
			beatsIt = beats.begin();
		}
		++beatsIt;
		/*
		// Generating @keyframes
		if (beats.getRelativeTimeAfterBeat(beatsIt - 1) >= style.maximumRelTimeDistForAddingTrans) {
			keyframesCode += actualSentenceTransitionSet.normalTransition.generateCode(actualWord.text, previousWordText, anim_id, style, actualWord.accentutation);
			previousWordText = "";
		}
		else
			keyframesCode += actualSentenceTransitionSet.addingTransition.generateCode(previousWordText + " " + actualWord.text, previousWordText, anim_id, style, actualWord.accentutation);
		*/
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
	vector <string> textOfWords = helperFunctions::splitStringByDelimiters(text, { " " });
	for (it = textOfWords.begin(); it != textOfWords.end(); ++it) {
		words.push_back(*it);
	}
}

const string video::generateHTML(
	string element,
	string appearingAnimIdPrefix, string appearingAnimIdPostfix,
	string disappearingAnimIdPrefix, string disappearingAnimIdPostfix,
	unsigned short startFrom) {

	string out;
	double delay = 0;
	unsigned short i = startFrom;

	for (auto const& currentWord : words) {
		out += generateHTMLElem(currentWord.text, "h1", 
			generateAnimationCSS(
				{ 
					animationCSS(   appearingAnimIdPrefix + to_string(i) +    appearingAnimIdPostfix, currentWord.anim.duration, animationCSS::fillMode::backwards, delay),
					animationCSS(disappearingAnimIdPrefix + to_string(i) + disappearingAnimIdPostfix, currentWord.anim.duration, animationCSS::fillMode::forwards,  delay + currentWord.anim.duration)
				}));
		delay += currentWord.anim.duration;
		i++;
	}
	return out;
}

const string video::generateHTMLElem(string content, string element, string style)
{
	return "<" + element + " style='" + style + "'>" + content + "</" + element + ">";
}

const string video::generateAnimationCSS(vector<animationCSS> anims)
{
	string out = "animation: ";
	for (auto anim : anims)
		out += anim.generate() + ",";
	return out.substr(0, out.size() - 1); // Remove extra colon from end
}
