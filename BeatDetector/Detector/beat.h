#pragma once
#include "TimeStamp.h"
#include <iostream>
class beat
{
public:
	/// <summary>
	/// Time from song begin in miliseconds
	/// </summary>
	float time;
	float strength = 1;
	float threshold;
	/// <summary>
	/// Creates new beat at time.
	/// </summary>
	beat(TimeStamp timeArg) { 
		time = timeArg.getMilliseconds() / float(100) + timeArg.getSeconds() + timeArg.getMinutes() * 60; 
	};
	beat() {};
};

