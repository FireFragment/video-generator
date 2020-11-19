#include "transition.h"
#include "style.h"
using namespace std;

transitionItem::transitionItem(transitionItemType typeArg) {type = typeArg;}
transitionItem::transitionItem(string string) { text = string; }

transitionItem::transitionItem(unsigned short int limit, string ifBigger, string ifSmaller)
{
	accentuationCondition_limit = limit;
	accentuationCondition_ifBigger = ifBigger;
	accentuationCondition_ifSmaller = ifSmaller;
	type = transitionItem_accentuationCondition;
}

transition transition::pickTransitionFromListByIndex(list<transition> transitions, int index)
{
	int i = 0;
	list <transition> ::iterator it;
	for (it = transitions.begin(); i != index; ++it) i++;

	return *it;
}

string transitionItem::generate(string actualWord, string previousWord, string previousWords, int animId, unsigned short int accentutation)
{
	string returnValue;
	switch (type) {
		case transitionItem_actualWord: {returnValue = actualWord; break;}
		case transitionItem_previousWord: {returnValue = previousWord; break;}
		case transitionItem_previousWords: {returnValue = previousWords; break;}
		case transitionItem_animId: {returnValue = to_string(animId); break;}
		case transitionItem_string: {returnValue = text; break; }
		case transitionItem_accentuationCondition: {if (accentuationCondition_limit < accentutation) return accentuationCondition_ifBigger; else return accentuationCondition_ifSmaller; }
	};
	return returnValue;
};

string transition::generateCode(string actualWord, string previousWord, string previousWords, unsigned int animId, style styleOfVid, unsigned short int accentuation) {
	string returnValue;
	for (list <transitionItem> ::iterator it = CSScode.begin(); it != CSScode.end(); ++it) 
		returnValue += (*it).generate(actualWord, previousWord, previousWords, animId, accentuation);
	return returnValue;
}
transition::transition() {
	CSScode = { transitionItem("@keyframes anim"), transitionItem(transitionItem_animId), transitionItem("{from{content:\""), transitionItem(transitionItem_previousWord), transitionItem("\";}to{content:\""), transitionItem(transitionItem_actualWord), transitionItem("\";}}") };
}

transition::transition(list<transitionItem> CSScodeArg) {
	CSScode = CSScodeArg;
}
