#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <Windows.h>
#include "helperFunctions.h"
#include "../BeatDetector/Detector/BeatDetector.h"
#include "animations/animation.h"
#include "helperFunctions.h"
#include "video.h"
using namespace std;

int main()
{
	video video("One Two Three Four Five Six Seven Eight Nine Ten Eleven Twelve Thirteen Fourteen Fifteen Sixteen Seventeen Eighteen Nineteen Twenty Twenty-One Twenty-Two Twenty-Three Twenty-Four Twenty-Five Twenty-Six Twenty-Seven Twenty-Eight Twenty-Nine Thirty Thirty-One Thirty-Two Thirty-Three Thirty-Four Thirty-Five Thirty-Six Thirty-Seven Thirty-Eight Thirty-Nine Forty Forty-One Forty-Two Forty-Three Forty-Four Forty-Five Forty-Six Forty-Seven Forty-Eight Forty-Nine Fifty Fifty-One Fifty-Two Fifty-Three Fifty-Four Fifty-Five Fifty-Six Fifty-Seven Fifty-Eight Fifty-Nine Sixty Sixty-One Sixty-Two Sixty-Three Sixty-Four Sixty-Five Sixty-Six Sixty-Seven Sixty-Eight Sixty-Nine Seventy Seventy-One Seventy-Two Seventy-Three Seventy-Four Seventy-Five Seventy-Six Seventy-Seven Seventy-Eight Seventy-Nine Eighty Eighty-One Eighty-Two Eighty-Three Eighty-Four Eighty-Five Eighty-Six Eighty-Seven Eighty-Eight Eighty-Nine Ninety Ninety-One Ninety-Two Ninety-Three Ninety-Four Ninety-Five Ninety-Six Ninety-Seven Ninety-Eight Ninety-Nine One-Hundred");
	cout << "DEVELOPMENT VERSION, DO NOT USE!\n\nIt's recommended to use rhytmical musics.\nEnter the path of music: ";
	getline(cin, video.style.musicURL);
	// Create and open a text file
	ofstream OutFile("generated.html");
	OutFile << video.generate();

	// Close the file
	OutFile.close();
	system("generated.html");
}
