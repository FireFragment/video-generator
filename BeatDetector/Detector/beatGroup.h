#pragma once
#include <vector>
#include "beat.h"

using namespace std;

class beatGroup :public vector<beat>
{
public:
	static float getTimeDifference(iterator a, iterator b) {
		return abs(a->time - b->time);
	}

	/// <summary>
	/// How many beats around arguments of getRelativeTimeDifference affects return value.
	/// <para>See also <seealso cref="getRelativeTimeAfterBeat" /></para>
	/// </summary>
	static unsigned short relativeTimeAffectDistance;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="beat"></param>
	/// <returns>Time difference between beat arg and next beat divided by average time differences around beat. <seealso cref="getAverageTimeDifferencesAroundBeat" /></returns>
	float getRelativeTimeAfterBeat(iterator beat) {
		return getTimeDifference(beat, beat + 1) / getAverageTimeDifferencesAroundBeat(beat);
	}

	/// <param name="beat"></param>
	/// <param name="range">- how far beats from beat arg affects return value. Optional - default value is relativeTimeAffectDistance</param>
	/// <returns>Average time difference between beats around beat arg.</returns>
	float getAverageTimeDifferencesAroundBeat(iterator beat, float range = relativeTimeAffectDistance) {

		// Process beats after beat arg.
		float timesSum = 0;
		unsigned short i = 0;
		for (iterator it = beat; it < end() - 1 && i != beatGroup::relativeTimeAffectDistance; it++, i++)
			timesSum += getTimeDifference(it, it + 1);
		
		unsigned short beatsCount = i;

		// Process beats before beat arg.
		i = 0;
		for (iterator it = beat; it > begin() + 1 && i != beatGroup::relativeTimeAffectDistance; it--, i++)
			timesSum += getTimeDifference(it, it + 1);
		
		beatsCount += i;

		return timesSum / beatsCount;
	}
};