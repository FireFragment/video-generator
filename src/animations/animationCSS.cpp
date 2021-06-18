#include "animationCSS.h"

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
	return name + " " + helperFunctions::doubleToString(duration) + "s ease " + helperFunctions::doubleToString(delay) + "s 1 normal " + generateFillMode();
}
