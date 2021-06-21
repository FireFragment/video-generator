#pragma once
#include <string>
#include <map>
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

	class easing : public range<range<double>> {
	public:
		string generate() {
			return "cubic-bezier(" + 
				helperFunctions::doubleToString(*min->min) + "," +
				helperFunctions::doubleToString(*min->max) + "," +
				helperFunctions::doubleToString(*max->min) + "," +
				helperFunctions::doubleToString(*max->max) + ")";
		}

		enum class type {
			in, out
		};

		enum inEasingPreset {
			easeIn
		};

		enum outEasingPreset {
			easeOut
		};

		easing(type _type) {
			if (_type == type::in) {
				map<inEasingPreset, easing>::const_iterator item = inPresets.begin();
				advance(item, rand() % inPresets.size());
				*this = item->second;
			} else {
				map<outEasingPreset, easing>::const_iterator item = outPresets.begin();
				advance(item, rand() % outPresets.size());
				*this = item->second;
			}
		};

		easing(inEasingPreset preset) {
			*this = inPresets.at(preset);
		};

		easing(outEasingPreset preset) {
			*this = outPresets.at(preset);
		};

		static const map<inEasingPreset, easing> inPresets;
		static const map<outEasingPreset, easing> outPresets;

		easing(range<double> _min = range<double>(0.5, 0.5), range<double> _max = range<double>(0.5, 0.5)): range<range<double>>(_min, _max) {}
	};

	// Cubic bezier
	easing _easing;

	animationCSS() {};
	animationCSS(string name, double duration, fillMode mode, easing _easing, double delay = 0) : name(name), duration(duration), mode(mode), _easing(_easing), delay(delay) {};

	/// <returns>Name of fill mode</returns>
	const string generateFillMode();

	/// <returns>Value of <c>animation</c> CSS property (<example>eg. <c>the-bestest-animation 0 ease 0 1 normal none running</c></example>)</returns>
	const string generate();
};