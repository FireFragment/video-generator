#pragma once
#include <vector>
#include "beat.h"

using namespace std;

class beatGroup :public vector<beat>
{
public:
	static float getTimeDifference(iterator a, iterator b);

	/// <summary>
	/// How many beats around arguments of getRelativeTimeDifference affects return value.
	/// See also <seealso cref="getRelativeTimeAfterBeat" />
	/// </summary>
	static const unsigned short relativeTimeAffectDistance;

	/// <param name="beat"></param>
	/// <returns>Time difference between beat arg and next beat divided by average time differences around beat. <seealso cref="getAverageTimeDifferencesAroundBeat" /></returns>
	float getRelativeTimeAfterBeat(iterator beat) {
		return getTimeDifference(beat, beat + 1) / getAverageTimeDifferencesAroundBeat(beat);
	}

	/// <param name="beat"></param>
	/// <param name="range">- how far beats from beat arg affects return value. Optional - default value is relativeTimeAffectDistance</param>
	/// <returns>Average time difference between beats around beat arg.</returns>
	float getAverageTimeDifferencesAroundBeat(iterator beat, float range = relativeTimeAffectDistance);
	
	//static void assignToWords(vector<word>* words);
};