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

//function for printing the elements in a vector 
void showvector(vector <string> g)
{
	vector <string> ::iterator it;
	for (it = g.begin(); it != g.end(); ++it)
		cout << '\n' << *it;
	cout << '\n';
}

int main()
{
	vector<doubleCSSprop> props = {
		doubleCSSprop(
			"margin-left", 0.3, "0",
			new range<double>(100, 100),
			{ range<double>(-150, -90), range<double>(150, 90) },
			new range<double>(-3, 3),
			"", "vw"),
		doubleCSSprop(
			"opacity", 1, "1",
			new range<double>(0, 1),
			{ range<double>(0, 0.5) }),
		doubleCSSprop(
			"transform", 2, "1",
			new range<double>(10, 0),
			{ range<double>(0, 0.3) },
			new range<double>(0.7, 1.3),
			"scale(", ")")

	};
	for (unsigned short i = 1; i < 100; i++) {
		animation anim(props, animationType::appearing, 2000);
		cout << anim.generate("a" + to_string(i));
	}

	for (unsigned short i = 1; i < 100; i++) {
		animation anim(props, animationType::disappearing, 2000);
		cout << anim.generate("d" + to_string(i));
	}

	cout << endl << endl << endl;
	video video("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Et ultrices neque ornare aenean. Ante in nibh mauris cursus mattis molestie. Ultrices tincidunt arcu non sodales neque sodales ut etiam. Purus gravida quis blandit turpis cursus in. Pellentesque sit amet porttitor eget dolor morbi non arcu risus. Cras fermentum odio eu feugiat pretium nibh ipsum consequat. A cras semper auctor neque vitae tempus quam pellentesque nec. Ornare suspendisse sed nisi lacus sed viverra tellus in. Diam in arcu cursus euismod quis.");
	cout << "DEVELOPMENT VERSION, DO NOT USE!\n\nIt's recommended to use rhytmical musics.\nEnter the path of music: ";
	getline(cin, video.style.musicURL);
	// Create and open a text file
	ofstream OutFile("generated.html");
	OutFile << video.generate();

	// Close the file
	OutFile.close();
	//system("generated.html");
}
