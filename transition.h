#pragma once
#include <vector>
#include <string>

using namespace std;
class style;

/// <summary>
/// Types of transition items. See also <seealso cref="transitionItem"/> and <seealso cref="transition"/>
/// </summary>
typedef enum transitionItemType
{
	transitionItem_string,
	transitionItem_actualWord,
	transitionItem_previousWord,
	transitionItem_animId,
	transitionItem_accentuationCondition
};

typedef enum transitionType
{
	/// <summary>
	/// Classic transition which replaces text actually shown on screen with new text.
	/// </summary>
	transition_normal,
	/// <summary>
	/// Transition which adds new word to screen, but keeps original text. Used when beats are close to each other.
	/// </summary>
	transition_adding,
	/// <summary>
	/// Accents text on screen, doesn't change text.
	/// </summary>
	transition_accenting
};

/// <summary>
/// Transition item is part of transition CSS code, eg. text of word, that disappears with transition (previousWord) or appears (actualWord) or concrete string. See also <seealso cref="transition"/>
/// </summary>
class transitionItem {
public:
	transitionItemType type = transitionItem_string;
	///<summary>Used only when type is transitionItem_string </summary>
	string text;


	/// <summary>Used only when type is transitionItem_accentutationCondition </summary>
	int accentuationCondition_limit = 0;
	/// <summary>Used only when type is transitionItem_accentutationCondition 
	///		<para>Returned by generate(), when accentutation is bigger or equal to limit</para>
	/// </summary>
	string accentuationCondition_ifBigger;
	/// <summary>Used only when type is transitionItem_accentutationCondition 
	///		<para>Returned by generate(), when accentutation is smaller than limit</para>
	/// </summary>
	string accentuationCondition_ifSmaller;


	transitionItem(transitionItemType typeArg);
	transitionItem(string string);
	/// <summary>
	/// Creates transition item with type accentutationCondition
	/// </summary>
	/// <param name="limit"></param>
	/// <param name="ifBigger">: returned by generate(), when accentutation is bigger or equal to limit</param>
	/// <param name="ifSmaller">: returned by generate(), when accentutation is smaller than limit</param>
	transitionItem(unsigned short int limit, string ifBigger, string ifSmaller = "");
	string generate(string actualWord, string previousWord, int animId, unsigned short int accentutation = 0);


};

class transition
{
public:
	transition(transitionType type_ = transition_normal);
	transition(vector<transitionItem> CSScodeArg);
	vector<transitionItem> CSScode;
	/// <summary>
	/// Generates @keyframes CSS code.
	/// </summary>
	/// <param name="actualWord"> defines word, that appear with transition.</param>
	/// <param name="previousWord"> defines word, that disappear with transition.</param>
	/// <param name="animId"> is unique id of animation. Also defines animation name, eg. <c>anim0</c> if is animId 0.</param>
	/// <param name="accentutation"> defines importance of <c>actualWord</c> in range 0-3</param>
	/// <returns>@keyframes CSS code, eg. <example><code>"@keyframes anim23{from{content:"Hello"}to{content:"guys"}}"</code></example></returns>
	string generateCode(string actualWord, string previousWord, unsigned int animId, style astyleOfVid, unsigned short int accentuation = 0);
	/// <summary>
	/// Defines, if transition highlights the text.
	/// </summary>
	bool importatnt = false;
	unsigned accentuation : 5;
	static transition pickTransitionFromListByIndex(vector<transition> transitions, int index);
	friend transition operator+(const transition& i1, const string& i2);
	friend transition operator+(const transition& t1, const transitionItem& i2);
	friend transition operator+(const transition& t1, const transitionItemType& i2);

	/// <returns>Empty transition(transition that satisfies: this.CSScode.size = 0)</returns>
	static transition emptyTransition(transitionType type_ = transition_normal);
	transitionType type = transition_normal;
};