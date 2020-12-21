#include "transition.h"
#include "style.h"
using namespace std;

transition::transitionItem::transitionItem(transitionItemType typeArg) {type = typeArg;}
transition::transitionItem::transitionItem(string string) { text = string; }

transition::transitionItem::transitionItem(unsigned short int limit, string ifBigger, string ifSmaller)
{
	accentuationCondition_limit = limit;
	accentuationCondition_ifBigger = ifBigger;
	accentuationCondition_ifSmaller = ifSmaller;
	type = transitionItem_accentuationCondition;
}

transition transition::pickTransitionFromListByIndex(vector<transition> transitions, int index)
{
	int i = 0;
	vector <transition> ::iterator it;
	for (it = transitions.begin(); i != index; ++it) i++;

	return *it;
}

transition transition::emptyTransition(transitionType type_)
{
	transition returnValue = transition(type_);
	returnValue.CSScode.clear();
	return returnValue;
}

string transition::transitionItem::generate(string actualWord, string previousWord, int animId, unsigned short int accentutation)
{
	string returnValue;
	switch (type) {
		case transitionItem_actualWord: {returnValue = actualWord; break;}
		case transitionItem_previousWord: {returnValue = previousWord; break;}
		case transitionItem_animId: {returnValue = to_string(animId); break;}
		case transitionItem_string: {returnValue = text; break; }
		case transitionItem_accentuationCondition: {if (accentuationCondition_limit < accentutation) return accentuationCondition_ifBigger; else return accentuationCondition_ifSmaller; }
	};
	return returnValue;
};

string transition::generateCode(string actualWord, string previousWord, unsigned int animId, style styleOfVid, unsigned short int accentuation) {
	string returnValue;
	for (vector <transitionItem> ::iterator it = CSScode.begin(); it != CSScode.end(); ++it) 
		returnValue += (*it).generate(actualWord, previousWord, animId, accentuation);
	return returnValue;
}
transition::transition(transitionType type_) {
	type = type_;
	CSScode = { transitionItem("@keyframes a"), transitionItem(transitionItem::transitionItem_animId), transitionItem("{from{content:\""), transitionItem(transition::transitionItem::transitionItem_previousWord), transitionItem("\";}to{content:\""), transitionItem(transitionItem::transitionItem_actualWord), transitionItem("\";}}") };
}

transition::transition(vector<transitionItem> CSScodeArg) {
	CSScode = CSScodeArg;
}

transition operator+(const transition& t1, const transition::transitionItem& i2)
{
	vector<transition::transitionItem> codeToReturn = t1.CSScode;
	codeToReturn.push_back(i2);

	return transition(transition(codeToReturn));
}

transition operator+(const transition& t1, const transition::transitionItem::transitionItemType& i2)
{
	vector<transition::transitionItem> codeToReturn = t1.CSScode;
	codeToReturn.push_back(transition::transitionItem(i2));

	return transition(transition(codeToReturn));
}

transition operator+(const transition& t1, const string& i2)
{
	vector<transition::transitionItem> codeToReturn = t1.CSScode;
	codeToReturn.push_back(transition::transitionItem(i2));

	return transition(transition(codeToReturn));
}
