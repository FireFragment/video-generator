#include "animation.h"

animation::animation(vector<doubleCSSprop> aviableProps, animationType type, double requestedStrength) : type(type)
{
	doubleCSSprop* appearingProp = NULL;

	// At least one appearing/disappearing CSS property is needed when type is not accenting.
	if (type != animationType::accenting) {
		vector<doubleCSSprop> appearingProps;

		copy_if(aviableProps.begin(), aviableProps.end(), back_inserter(appearingProps), [](doubleCSSprop prop) {
			return prop.badVisibility.size() != 0;
		});

		if (appearingProps.size() == 0) {
			throw new logic_error("Requested appearing/disappearing CSS property, but in aviableProps isn't any property with badVisibility.");
		};

		unsigned short appearingPropIndex = rand() % appearingProps.size();
		appearingProp = new doubleCSSprop(appearingProps[appearingPropIndex]);

		appearingProp->animate(type);
		add(appearingProp);
	}

	// Props, where decorative isn't NULL (and also exclude appearingProp to avoid its overriding).
	vector<doubleCSSprop> accentingProps;
	copy_if(aviableProps.begin(), aviableProps.end(), back_inserter(accentingProps), [appearingProp](doubleCSSprop prop) {
		return prop.decorative != NULL 
			&& (appearingProp != NULL ? (prop.name != appearingProp->name) : true); // Do not repeat appearingProp.
	});

	// Add properties until the requestedStrength is reached.
	while (getStrength() < requestedStrength && accentingProps.size() != 0) {
		unsigned short toAddIndex = rand() % accentingProps.size();
		doubleCSSprop toAdd = doubleCSSprop(accentingProps[toAddIndex]);
		vector<doubleCSSprop>::iterator myBegin = accentingProps.begin();
		accentingProps.erase(accentingProps.begin() + toAddIndex);
		toAdd.animate(animationType::accenting);

		if (type == animationType::appearing) {
			toAdd.animation->animation.swap();
		}

		add(new doubleCSSprop(toAdd));
	}
}

const string animation::generate(string name)
{
	string out = "@keyframes " + name + "{from{";
	for (auto& i : *this) {
		out += i->generate(*i->animation->animation.min) + "";
	}

	if (type == animationType::appearing) {
		out += "opacity:0;}1%{opacity:1;";
	}

	if (type == animationType::disappearing) {
		out += "}99%{opacity:1;";
	}

	out += "}to{";
	for (auto& i : *this) {
		out += i->generate(*i->animation->animation.max) + "";
	}

	if (type == animationType::disappearing) {
		out += "opacity:0;";
	}

	out += "}}";
	return out;
}

void animation::add(CSSprop *toAdd)
{
	push_back(toAdd);
}
