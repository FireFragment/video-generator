#pragma once
#include <string>
#include "../helperFunctions.h"

using namespace std;

/// <summary>
/// CSS <c>animation</c> property.
/// </summary>
class animationCSS {
public:
	enum class fillMode {
		none,
		forwards,
		backwards,
		both
	};

	string name;
	double duration;
	double delay = 0;
	fillMode mode;

	animationCSS() {};
	animationCSS(string name, double duration, fillMode mode, double delay = 0) : name(name), duration(duration), mode(mode), delay(delay) {};

	/// <returns>Name of fill mode</returns>
	const string generateFillMode();

	/// <returns>Value of <c>animation</c> CSS property (<example>eg. <c>the-bestest-animation 0 ease 0 1 normal none running</c></example>)</returns>
	const string generate();
};