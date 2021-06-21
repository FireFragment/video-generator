#include "animationCSS.h"

const map<animationCSS::easing::inEasingPreset, animationCSS::easing> animationCSS::easing::inPresets = {
	pair<animationCSS::easing::inEasingPreset, animationCSS::easing>(easeIn, animationCSS::easing(range<double>(0.64, 0),range<double>(0.78, 0))),
	pair<animationCSS::easing::inEasingPreset, animationCSS::easing>(bounceIn, animationCSS::easing(range<double>(0.36, 0),range<double>(0.66, -0.56)))
};

const map<animationCSS::easing::outEasingPreset, animationCSS::easing> animationCSS::easing::outPresets = {
	pair<animationCSS::easing::outEasingPreset, animationCSS::easing>(easeOut, animationCSS::easing(range<double>(0.22, 1),range<double>(0.36, 1))),
	pair<animationCSS::easing::outEasingPreset, animationCSS::easing>(bounceOut, animationCSS::easing(range<double>(0.34, 1.56),range<double>(0.64, 1)))
};

const string animationCSS::generateFillMode()
{
	switch (mode) {
	case fillMode::none:      { return "none";      }
	case fillMode::forwards:  { return "forwards";  }
	case fillMode::backwards: { return "backwards"; }
	case fillMode::both:      { return "both";      }
	}
}

const string animationCSS::generate()
{
	return name
		+ " " + helperFunctions::doubleToString(duration) + "s " + _easing.generate() + " " + helperFunctions::doubleToString(delay) + "s 1 normal " + generateFillMode();
}
