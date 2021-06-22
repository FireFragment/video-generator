#pragma once
#include <string>
#include <exception>
#include "../range.h"
#include "../helperFunctions.h"

using namespace std;

/// <summary>
/// Used for <see cref="animation"/>s or animated <see cref="CSSprop"/>s
/// </summary>
enum class animationType
{
	/// <summary>
	/// Causes object to which is property applied to appear.
	/// </summary>
	appearing,

	/// <summary>
	/// Causes object to which is property applied to disappear.
	/// </summary>
	disappearing,

	/// <summary>
	/// Accents already visible object to which is property applied, doesn't change visibility.
	/// </summary>
	accenting
};

class CSSpropAnimationData {
public:
	/// <summary>
	/// Set <c>min</c> to value at animation start and <c>max</c> to animation end.
	/// </summary>
	range<string> animation = range<string>("a", "b");
	animationType type;

	CSSpropAnimationData(range<string> animation = range<string>("0", "1"), animationType type = animationType::accenting) :animation(animation), type(type) {}
};

class CSSprop
{
public:
	/// <summary>
	/// Name of property, eg. <c>opacity</c> or <c>margin-top</c>.
	/// </summary>
	string name;

	const string generate(const string val);
	/// <returns>eg. <example><c>opacity:</c></example></returns>
	const string generateBegin();
	const string generateValue(const string val);

	/// <summary>
	/// Generate @keyframes CSS notation.
	/// </summary>
	/// <param name="name">Name of animation to generate</param>
	/// <param name="anim">Animation to generate</param>
	/// <returns>@keyframes CSS notation</returns>
	const string generateAnimated(string name, CSSpropAnimationData anim);
	/// <summary>
	/// Generate @keyframes CSS notation.
	/// </summary>
	/// <param name="name">Name of animation to generate</param>
	/// <returns>@keyframes CSS notation</returns>
	const string generateAnimated(string name) { return generateAnimated(name, *animation); }

	CSSprop(string _name, string _inital = "0", string _valPrefix = "", string _valPostfix = "") {
		name = _name;
		inital = _inital;
		valPrefix = _valPrefix;
		valPostfix = _valPostfix;
	}

	CSSprop() {}

	/// <summary>
	///		Value is prefixed with this.
	/// </summary>
	string valPrefix;

	/// <summary>
	///		Value is postfixed with this. It's userful for adding units (eg. <c>vw</c> for left)
	/// </summary>
	string valPostfix;

	/// <summary>
	///		Set to <c>NULL</c> if property isn't animated. See also <seealso cref="CSSpropAnimationData"/>
	/// </summary>
	CSSpropAnimationData* animation = NULL;

	/// <summary>
	///   Inital value of property
	/// </summary>
	string inital = "0";

	static const float animateStrengthRandomness;

	CSSprop(const CSSprop& original) {
		if (original.animation != NULL)
			animation = new CSSpropAnimationData(*original.animation);
		name = original.name;
		inital = original.inital;
		valPrefix = original.valPrefix;
		valPostfix = original.valPostfix;
	}

	~CSSprop() {
		delete animation;
	}

	CSSprop& operator=(const CSSprop& original) {
		if (original.animation != NULL) 
			*animation = *(original.animation);
		name = original.name;
		inital = original.inital;
		valPrefix = original.valPrefix;
		valPostfix = original.valPostfix;
		return *this;
	}

	virtual const double calcAnimStrength() { return 0; };
};

class doubleCSSprop : public CSSprop
{
public:
	static const vector<doubleCSSprop> props;

	/// <summary>
	///     Maximum and minimum values of property. Set to <c>NULL</c> if it's unlimited.
	/// </summary>
	/// <remarks>
	///		If value of the property is technically unlimited, but too high and low values doesn't make sense
	///		(eg. rotation, values above 360� works, but it's better to replace it with lower value), don't
	///		leave the pointer NULL and set it to the highest and lowest values, which makes sense. 
	/// </remarks>
	range<double>* boundaries = NULL;

	/// <summary>
	///		Set it to ranges, where object has a bad visibility.
	///		<para>
	///			Set min to value, which causes target object completely invisible. 
	///			Set max value to value, that causes same readability as opcity 0.5.
	///		</para>
	/// </summary>
	vector<range<double>> badVisibility;

	/// <summary>
	///	  Set this pointer to NULL, if this property isn't decorative. Most of CSS properties are decorative,
	///   but eg. opacity isn't, because we don't want blinking in our videos.
	/// </summary>
	/// <remarks>
	///   If porperty is decorative, set min and max to values, where object, to which is property applied is
	///   accented like it was scaled up to 2 times it's original size. 
	/// </remarks>
	range<double>* decorative = NULL;

	string generate(const double val);

	doubleCSSprop(string _name,
		double _strength,
		string _inital = 0,
		range<double>* _boundaries = NULL,
		vector<range<double>> _badVisibility = {},
		range<double>* _decorative = NULL,
		string _valPrefix = "",
		string _valPostfix = "") {

		name = _name;
		strength = _strength;
		inital = _inital;
		valPrefix = _valPrefix;
		valPostfix = _valPostfix;
		boundaries = _boundaries;
		badVisibility = _badVisibility;
		decorative = _decorative;
	}

	void animate(const animationType type, float strength = 0.5);

	/// <summary>
	///		How strong the property is per one unit. <example>eg. Opacity has 1.</example>
	/// </summary>
	double strength;
	/// <returns>How strong is property with given value.</returns>
	double calcStrength(double val) {
		double toReturn = val * strength;
		return val * strength;
	}

	const double calcAnimStrength() {
		if (animation == NULL)
			throw logic_error("Animation was NULL when tried to calculate it's strength.");
		return calcStrength(abs(animation->animation.min - animation->animation.max));
	}

	using CSSprop::CSSprop;

	doubleCSSprop(const doubleCSSprop& original) : CSSprop(original)
	{
		if (original.boundaries != NULL)
			boundaries = new range<double>(*original.boundaries);
		if (original.decorative != NULL)
			decorative = new range<double>(*original.decorative);
		badVisibility = original.badVisibility;
		strength = original.strength;
	}

	~doubleCSSprop() {
		delete boundaries;
		delete decorative;
	}

	doubleCSSprop& operator=(const doubleCSSprop& original) {
		if (original.boundaries != NULL)
			boundaries = new range<double>(*original.boundaries);
		if (original.decorative != NULL)
			decorative = new range<double>(*original.decorative);
		badVisibility = original.badVisibility;
		strength = original.strength;
		CSSprop::operator=(original);
		return *this;
	}
};