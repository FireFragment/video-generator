#pragma once
#include <string>
#include <vector> 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "style.h"
#include "helperFunctions.h"
#include "transitionSet.h"
#include "word.h"
#include "animations/animationCSS.h"
using namespace std;

class video
{
public:
	/// <param name="text">represents text of new video.</param>
	video(string text);
	/// <returns>HTML code with result video containing CSS and JS. </returns>
	string const generate();
	vector <word> words;
	style style;

	const string generateHTML(
		beatGroup& beats,
		string element = "h1", 
		string appearingAnimIdPrefix    = "a", string appearingAnimIdPostfix    = "",
		string disappearingAnimIdPrefix = "d", string disappearingAnimIdPostfix = "",
		short startFrom = 1);
	const string generateKeyframes(short startFrom = 1);

	/// <param name="content">Body of the element</param>
	/// <param name="element">Type of the element</param>
	/// <param name="id">ID of the element (empty by default)</param>
	/// <param name="style">CSS of the element (empty by default)</param>
	/// <returns>HTML element</returns>
	static const string generateHTMLElem(string content, string element, string style = "");

	/// <returns>CSS <c>animation</c> property.</returns>
	static const string generateAnimationCSS(vector<animationCSS> anims);

	void assignBeatsToWords(beatGroup* beats);
private:
	/// <returns>Count of transitions in video.</returns>
	unsigned short int getNeededTransitionsCount();
};