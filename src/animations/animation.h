#pragma once
#include <vector>
#include <string>
#include "CSSprop.h"

using namespace std;

class animation : public vector<CSSprop*>
{
public:

	animationType type = animationType::accenting;

	/// <summary>
	///	Creates new animation using SOME of provided <see cref="CSSprop"/>s.
	/// </summary>
	/// <param name="aviableProps">Avialable props to use (but not all of them will be likely used). Will be reanimated (so they has to be doubleCSSprop). If you want to animate some props manually, do it after creating object.</param>
	/// <param name="type">Type of animation to be generated.</param>
	animation(vector<doubleCSSprop> aviableProps = doubleCSSprop::props, animationType _type = animationType::accenting, double requestedStrength = 3);

	/// <returns>Calculated strength of the animation.</returns>
	const double getStrength() {
		double result = 0;
		for (iterator it = begin(); it != end(); ++it)
			result += (*it)->calcAnimStrength();
		return result;
	}

	/// <param name="name">Name of animation to generate</param>
	/// <returns>@keyframes CSS notation</returns>
	const string generate(string name);

	/// <summary>
	/// Add new property. Prefer instead of push_back.
	/// </summary>
	/// <param name="toAdd">Property to add.</param>
	void add(CSSprop *toAdd);

	/// <summary>
	/// Duration in seconds
	/// </summary>
	double duration = 0.5;
};