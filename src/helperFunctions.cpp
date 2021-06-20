#include "helperFunctions.h"
using namespace std;

vector<string> helperFunctions::splitStringByDelimiter(string toSplit, string delimiter) {
	toSplit = toSplit + delimiter;
	vector<string> returnValue;
	size_t pos = 0;
	std::string token;
	while ((pos = toSplit.find(delimiter)) != string::npos) {
		token = toSplit.substr(0, pos);
		if(token != "") {
			returnValue.push_back(token);
		}
		toSplit.erase(0, pos + delimiter.length());
	}
	return returnValue;
}
vector<string> helperFunctions::splitStringByDelimiters(string toSplit, vector<string> delimiters)
{
	string regex_string = "[^";

	vector<string> returnValue;
	vector <string> ::iterator it;
	for (it = delimiters.begin(); it != delimiters.end(); ++it) {
		regex_string += *it;
	}
	regex_string += "]+";
	regex words_regex(regex_string);
	auto words_begin = sregex_iterator(toSplit.begin(), toSplit.end(), words_regex);
	auto words_end = sregex_iterator();

	for (sregex_iterator i = words_begin; i != words_end; ++i)
		returnValue.push_back((*i).str());
	return returnValue;
}

beatGroup helperFunctions::getBeats(string url, float sensitivity, unsigned short int count, bool echoProgress)
{
	BeatDetector::Instance()->loadSystem();
	BeatDetector::Instance()->LoadSong(1024, _strdup(url.c_str()));
	BeatDetector::Instance()->sensitivity = sensitivity;
	BeatDetector::Instance()->setStarted(true);
	bool firstBeat = true;

	beat localLastBeatOccured = beat();
	beatGroup beats;
	while (beats.size() <= count) {

		BeatDetector::Instance()->update();
		Sleep(10);
		int lastB = BeatDetector::Instance()->getLastBeat().time;
		
		if (localLastBeatOccured.time != BeatDetector::Instance()->getLastBeat().time)
		{
			if (firstBeat)
				firstBeat = false; 
			else {

				// Beat detected: info about is accesible by BeatDetector::Instance()->getLastBeat();

				BeatDetector::Instance()->updateTime();
				localLastBeatOccured = BeatDetector::Instance()->getLastBeat();

				beats.push_back(localLastBeatOccured);
				if (echoProgress)
					cout << "Analyzing music: " << beats.size() - 1 << "/" << count << endl;
			}
		}
	}
	BeatDetector::Instance()->setStarted(false);


	return beats;
}

string helperFunctions::doubleToString(double num)
{
	if (fmod(num, 1) == 0) {
		return to_string((int)num);
	}
	return to_string(num).erase(to_string(num).find_last_not_of('0') + 1, string::npos);
}

double helperFunctions::doubleRandBetween(range<double> _range)
{
	return *_range.min + static_cast<double> (rand()) / (static_cast<double> (RAND_MAX / (*_range.max - *_range.min)));
}

double helperFunctions::addNoise(double n, double amount)
{
	return helperFunctions::doubleRandBetween(range<double>(n - amount, n + amount));
}

double helperFunctions::randomSign(double n)
{
	return rand()%2 ? n : 0-n;
}
