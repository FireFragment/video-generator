#include "animationCSS.h"

const map<animationCSS::easing::easingPreset, animationCSS::easing> animationCSS::easing::presets = {
	pair<animationCSS::easing::easingPreset, animationCSS::easing>(easeOut, animationCSS::easing(range<double>(0.22, 1),range<double>(0.36, 1))),
	pair<animationCSS::easing::easingPreset, animationCSS::easing>(easeIn,  animationCSS::easing(range<double>(0.64, 0),range<double>(0.78, 0)))
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
