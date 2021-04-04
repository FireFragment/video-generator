#pragma once
#include <list>
#include "transition.h"
class transitionSet
{
	public:	
	transition normalTransition = transition();
	transition addingTransition = transition(transition_adding);
	transitionSet(transition normal = transition(), transition adding = transition(transition_adding)) {
	normalTransition = normal;
	addingTransition = adding;
	};
};;