#include "CSSprop.h"

const vector<doubleCSSprop> doubleCSSprop::props = {
	doubleCSSprop(
		"margin-left", 0.3, "0",
		new range<double>(100, 100),
		{ range<double>(-60, -50), range<double>(60, 50) },
		new range<double>(-3, 3),
		"", "vw"),
	doubleCSSprop(
		"opacity", 1, "1",
		new range<double>(0, 1),
		{ range<double>(0, 0.5) }),
	doubleCSSprop(
		"transform", 2, "1",
		new range<double>(10, 0),
		{ range<double>(0, 0.3) },
		new range<double>(0.7, 1.3),
		"scale(", ")")

};

const float CSSprop::animateStrengthRandomness = 0.2;

const string CSSprop::generate(const string val)
{
	return name + ":" + valPrefix + val + valPostfix + ";";
}

const string CSSprop::generateAnimated(string name, CSSpropAnimationData anim)
{
	return "@keyframes " + name + "{from{" + generate(*anim.animation.min) + "}to{" + generate(*anim.animation.max) + "}}";
}

/// <summary>
///   Automatically animate the property.
/// </summary>
/// <param name="type">Type of animation to generate</param>
/// <param name="strength">Strength of animation to generate, used only if <paramref name="type"/> is set to <c>accenting</c></param>
void doubleCSSprop::animate(const animationType type, float strength)
{
	if (badVisibility.size() == 0 && type != animationType::accenting)
		throw logic_error("Requested appearing or disappearing animation, but badVisibility is empty!");

	switch (type) {
	case animationType::appearing: {
		animation = new CSSpropAnimationData(range<string>(
			helperFunctions::doubleToString(
				*badVisibility[rand() % badVisibility.size()].min
			), 
			inital));
		return;
	}
	case animationType::disappearing: {
		animation = new CSSpropAnimationData(
			range<string>(
				inital,
				helperFunctions::doubleToString(
					*badVisibility[rand() % badVisibility.size()].min)));
		return;
	}
	case animationType::accenting: {
		if (decorative == NULL)
			throw logic_error("Requested accenting animation, but decorative is NULL. Set decorative before requesting accenting animation, or, if property isn't decorative, don't try to animate it.");

		try {
			animation = new CSSpropAnimationData(range<string>(
				// START
				inital,

				// END
				helperFunctions::doubleToString(
					// Randomize a little bit
					helperFunctions::doubleRandBetween(
						range<double>::around(
							// Main part
							range<double>(
								*decorative->max,
								stoi(inital)).avg(strength),
							CSSprop::animateStrengthRandomness)))));


		}
		catch (invalid_argument except) {
			throw (logic_error("Inital is not valid double!"));
		}
	}
	}
}

string doubleCSSprop::generate(const double val)
{
	return CSSprop::generate(helperFunctions::doubleToString(val));
}
