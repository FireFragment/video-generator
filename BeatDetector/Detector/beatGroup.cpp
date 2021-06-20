#include "beatGroup.h"

const unsigned short beatGroup::relativeTimeAffectDistance = 10;

/// <param name="beat"></param>
/// <param name="range">- how far beats from beat arg affects return value. Optional - default value is relativeTimeAffectDistance</param>
/// <returns>Average time difference between beats around beat arg.</returns>

float beatGroup::getTimeDifference(iterator a, iterator b) {
	return abs(a->time - b->time);
}

float beatGroup::getAverageTimeDifferencesAroundBeat(iterator beat, float range) {

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
