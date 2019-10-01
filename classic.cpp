#include "classic.h"

Classic::Classic(){

}
// 2d array
Grid** Classic::getCurrentMap(){
    return map;
}

void Classic::countNeighbors(){
	for(int i = 0; i < length; i++){
		for(int j = 0; j < width; j++){
			//check for top left corner
			if(i == 0 && j == 0){
				if(map[i][j + 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i + 1][j + 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i + 1][j].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
			}

			//check for top right corner
			else if(i == 0 && j == width - 1){
				if(map[i][j - 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i + 1][j - 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i + 1][j].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
			}

			//check for bottom left corner
			else if(i == length - 1 && j == 0){
				if(map[i][j + 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i - 1][j + 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i - 1][j].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
			}

			//check for bottom right corner
			else if(i == length - 1 && j == width - 1){
				if(map[i][j - 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i - 1][j - 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i - 1][j].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
			}

			//check top edge
			else if(i == 0){
				if(map[i][j - 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i][j + 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i + 1][j - 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i + 1][j].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i + 1][j + 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
			}

			//check bottom edge
			else if(i == length - 1){
				if(map[i][j - 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i][j + 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i - 1][j - 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i - 1][j].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i - 1][j + 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
			}

			//check left edge
			else if(j == 0){
				if(map[i - 1][j].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i - 1][j + 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i][j + 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i + 1][j + 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i + 1][j].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
			}

			//check right edge
			else if(j == width - 1){
				if(map[i - 1][j].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i - 1][j - 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i][j - 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i + 1][j - 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i + 1][j].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
			}

			//check everywhere else
			else{
				if(map[i][j + 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i + 1][j + 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i + 1][j].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i + 1][j - 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i][j - 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i - 1][j - 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i - 1][j].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
				if(map[i - 1][j + 1].getTile() == 'X')
					map[i][j].setNumNeighbors(map[i][j].getNumNeighbors() + 1);
			}
		}
	}
}

void Classic::resetNeighbors(){
	//After 1 generation, reset the # of neighbors to 0 to recompute for next generation
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++)
			map[i][j].setNumNeighbors(0);
	}

}

void Classic::generation(){
	//less than 2 adjacent neighbors and at least 4 adjacent neighbors means cell is dead
	//2 adjacent neighbors means cell remains dead or alive, depending on its current state
	//3 adjacent neighbors means cell remains alive or, if previously dead, comes to life
	for(int i = 0; i < length; i++){
		for(int j = 0; j < width; j++){
			if(map[i][j].getNumNeighbors() <= 1 || map[i][j].getNumNeighbors() >= 4)
				map[i][j].setTile('-');
			if(map[i][j].getNumNeighbors() == 3)
				map[i][j].setTile('X');
		}
	}
}

void Classic::play(int gen){

	//Begin by showing initial state
	cout << "\nGeneration " << gen << endl;
	printMap();
	gen++;

	//create a copy of the Classic class
	Classic copy;
	copy.setLength(length);
	copy.setWidth(width);
	copy.createMap();

	//Game loop: continue looping while at least 1 cell is alive
	while(numCells()){  //numCells() call returns true if it's not 0
		cout << "\nGeneration " << gen << endl;
		countNeighbors();   //count the # of neighbors in each block

		//Before generating the new map state, make a copy of current map state
		for(int i = 0; i < length; i++){
			for(int j = 0; j < width; j++){
				copy.map[i][j].setTile(map[i][j].getTile());
				copy.map[i][j].setNumNeighbors(map[i][j].getNumNeighbors());
			}
		}

		generation();       //generate the new map based on # of neighbors
		printMap();         //output the new map state afterwards

		//Ask the user if they want to pause for a moment
		char pause;
		cout << "Would you like to pause? (Press Y for yes) "<< endl;
		cin >> pause;
		if (pause == 'Y' || pause == 'y')
			system("pause");

		cout << "Would you like to store this map on a file? (Press Y for yes) "<<endl;
		cin >> pause;
		if (pause == 'Y' || pause == 'y') {
			string file;
			cout << "Enter file name: "<<endl;
			cin >> file;
			ofstream output(file);

			//output the dimensions and then the map itself
			output << length << endl << width << endl;
			for (int i = 0; i < length; i++) {
				for (int j = 0; j < width; j++)
					output << map[i][j].getTile();
				output << endl;
			}

			//close file afterwards
			output.close();
		}

		resetNeighbors();
		gen++;

		//Compare new map state with current map state
		//If the states are the same, then we don't need to run the program anymore
		bool allMatch = true;
		for(int i = 0; i < length; i++){
			for(int j = 0; j < width; j++){
				if(map[i][j].getTile() != copy.map[i][j].getTile()){
					allMatch = false;
					i = length;
					j = width;
				}
			}
		}

		if(allMatch)
			return;

	}
}
