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
	video video("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Et ultrices neque ornare aenean. Ante in nibh mauris cursus mattis molestie. Ultrices tincidunt arcu non sodales neque sodales ut etiam. Purus gravida quis blandit turpis cursus in. Pellentesque sit amet porttitor eget dolor morbi non arcu risus. Cras fermentum odio eu feugiat pretium nibh ipsum consequat. A cras semper auctor neque vitae tempus quam pellentesque nec. Ornare suspendisse sed nisi lacus sed viverra tellus in. Diam in arcu cursus euismod quis.");
	cout << "DEVELOPMENT VERSION, DO NOT USE!\n\nIt's recommended to use rhytmical musics.\nEnter the path of music: ";
	getline(cin, video.style.musicURL);
	// Create and open a text file
	ofstream OutFile("generated.html");
	OutFile << video.generate();

	// Close the file
	OutFile.close();
	system("generated.html");
}
