#include "classic.h"
#include "doughnut.h"
#include "mirror.h"

int main(int argc, char **argv) {
	//Declare various types
	srand((unsigned int)time(NULL));	//random seed generator
	int generation = 0;					//generation #
	int response;						//either generate map from file or generate map randomly


	//Declare 3 types of maps.  Using if statements to differentiate between them
	Classic classic;
	Doughnut doughnut;
	Mirror mirror;

	//Ask whether to use classic, doughnut, or mirrored mode
	int mode;
	cout << "Choose either to use classic (1), doughnut (2), or mirrored (3) modes: "<< endl;
	cin >> mode;
	while (mode < 1 && mode > 3) {
		cout << "Choose either to use classic (1), doughnut (2), or mirrored (3) modes: " << endl;
		cin >> mode;
	}

	//Ask user if they want to generate the map with a file or with randomization
	cout << "Would you like to provide a map (1) or randomly generate a map (2)? " << endl;
	cin >> response;
	while (response != 1 && response != 2) {
		cout << "Would you like to provide a map (1) or randomly generate a map (2)? " << endl;
		cin >> response;
	}

	//Check which response was answered
	if (response == 1) {
		//Ask for file name and error handle if necessary
		ifstream input;
		string file;
		cout << "Enter file name: "<< endl;
		cin >> file;
		input.open(file);
		while (input.fail()) {
			cout << "Enter a valid file name: " << endl;
			cin >> file;
			input.open(file);
		}

		int length;
		int width;
		input >> length >> width;
		//Choose between the three modes via if statement: this initializes the map that is read from the provided file
		if (mode == 1)
			classic.initializeMapFile(length, width, input);
		else if (mode == 2)
			doughnut.initializeMapFile(length, width, input);
		else
			mirror.initializeMapFile(length, width, input);

		//close file, we dont need it anymore
		input.close();
	}
	else {
		int length;
		int width;
		double density;

		//Have user enter length and width (< 0)
		//Error handling is implemented
		cout << "Please enter the length: " << endl;
		cin >> length;
		while (length <= 0) {
			cout << "Please enter the length: " << endl;
			cin >> length;
		}

		cout << "Please enter the width: " << endl;
		cin >> width;
		while (width <= 0) {
			cout << "Please enter the width: " << endl;
			cin >> width;
		}

		//Have user enter population density that is in (0, 1]
		cout << "Please enter the population density (0 < x <= 1): " << endl;
		cin >> density;
		while (density <= 0 && density > 1) {
			cout << "Please enter the population density (0 < x <= 1): " << endl;
			cin >> density;
		}

		//population density = # of people / area --> # of people = population density * area (round to nearest integer via round() in math.h)
		int numPopulation = round(round(density) * length * width);

		//Choose between the three modes via if statement: this randomly initializes the map
		if (mode == 1)
			classic.initializeMapRandom(length, width, numPopulation);
		else if (mode == 2)
			doughnut.initializeMapRandom(length, width, numPopulation);
		else
			mirror.initializeMapRandom(length, width, numPopulation);
	}

	//Choose between the three modes via if statement: this plays the game until number of cells is 0
	if (mode == 1)
		classic.play(generation);
	else if (mode == 2)
		doughnut.play(generation);
	else
		mirror.play(generation);


	return 0;
}
