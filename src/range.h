#pragma once
#include <stdexcept>

using namespace std;

template<class T = void>
class range {
public:
	T* max = NULL;
	T* min = NULL;

	range() {}

	/// <summary>
	/// Creates new range around <paramref name="average"/> and min and max are <paramref name="distance"/> far from <paramref name="average"/>.
	/// </summary>
	/// <param name="average">Average of <c>min</c> and <c>max</c></param>
	/// <param name="distance"></param>
	/// <returns></returns>
	static range around(T average, T distance) {
		return range(average - distance, average + distance);
	};

	/// <remarks>
	/// <c>max</c> of returned range is always bigger then <c>min</c>.
	/// </remarks>
	/// <param name="direction">If true, top half will be returned, bottom half otherwise.</param>
	/// <returns>Half of the range</returns>
	range half(bool direction) {
		return direction ? range(avg(), *max) : range(*min, avg());
	}
	
	/// <param name="bias">How much move the resulting average.  
	/// eg. bias 1 causes this function to return max, 
	/// with bias -1, this function returns min, 
	/// 0 (default) keeps average same.</param>
	/// <returns>Average between <see cref="min"/> and <see cref="max"/></returns>
	const T avg(double bias = 0) {
		if (max == NULL || min == NULL) {
			throw logic_error("Min or max property of range is NULL, but both of them are needed when calculating their average.");
		}
		return (*min + *max) / 2 + (*max - *min) / 2 * bias;
	}

	void swap() {
		T* newMax = min;
		min = max;
		max = newMax;
	}

	const range<double> aroundAvg(unsigned short distance) {
		return range<double>(avg() - distance, avg() + distance);
	}

	static const int test = 1;

	explicit range(T _min, T _max) {
		min = new T(_min);
		max = new T(_max);
	}

	range(const range& o) {
		if (o.min != NULL) min = new T(*o.min);
		if (o.max != NULL) max = new T(*o.max);
	}

	range& operator=(const range& o) {
		if (&o != this) {
			min = new T(*o.min);
			max = new T(*o.max);
		}
		return *this;
	}
	~range() {
		delete min;
		delete max;
	}
};