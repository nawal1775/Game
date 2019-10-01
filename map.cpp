#include "map.h"

// constructor
Map::Map(){
    map = 0;
    length = 0;
    width = 0;
}
// default constructor
Map::~Map(){
    for(int i = 0; i < length; i++)
        delete [] map[i];
    if(map != 0)
        delete [] map;
}

Map::Map(const Map &m){
	//initialize non array members first
	length = m.length;
	width = m.width;

	//create 2d array of map
	map = new Grid*[length];
    for(int i = 0; i < length; i++)
        map[i] = new Grid[width];

	//1 by 1, copy over each of map[i]
	for(int i = 0; i < length; i++){
		for(int j = 0; j < width; j++){
			map[i][j].setTile(m.map[i][j].getTile());
			map[i][j].setNumNeighbors(m.map[i][j].getNumNeighbors());
		}
	}

}

Map& Map::operator=(const Map &m){

	cout << "Assignment operator invoked" << endl;

	//Same as copy constructor, but delete existing memory first

	//before creating memory, delete existing memory
	for(int i = 0; i < length; i++)
		delete [] map[i];
	if(map != 0)
		delete [] map;

	//now initialize non array members
	length = m.length;
	width = m.width;

	//create 2d array of map
	map = new Grid*[length];
    for(int i = 0; i < length; i++)
        map[i] = new Grid[width];

	//1 by 1, copy over each of map[i]
	for(int i = 0; i < length; i++){
		for(int j = 0; j < width; j++){
			map[i][j].setTile(m.map[i][j].getTile());
			map[i][j].setNumNeighbors(m.map[i][j].getNumNeighbors());
		}
	}

	return *this;
}

int Map::getLength(){
    return length;
}

int Map::getWidth(){
    return width;
}

void Map::setLength(int l){
    length = l;
}

void Map::setWidth(int w){
    width = w;
}

void Map::initializeMapFile(int l, int w, ifstream &in){
    setLength(l);
    setWidth(w);

    map = new Grid*[length];
    for(int i = 0; i < length; i++)
        map[i] = new Grid[width];

    for(int i = 0; i < length; i++){
        string line;
        in >> line;
        for(int j = 0; j < width; j++)
            map[i][j].setTile(line[j]);
    }
}

void Map::initializeMapRandom(int l, int w, int n){
    setLength(l);
    setWidth(w);

    map = new Grid*[length];
    for(int i = 0; i < length; i++)
        map[i] = new Grid[w];

    for(int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            int random = rand()%2 + 1; //between 1 and 2.  Let 1 be occupied and let 2 be empty
            if(random == 1 && n > 0){
                map[i][j].setTile('X');
                n--;
            }
            else
                map[i][j].setTile('-');
        }
    }
}

void Map::printMap(){
    cout << "Viewing the map" << endl;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < width; j++)
            cout << map[i][j]./*getNumNeighbors()*/getTile() << " ";
        cout << endl;
    }
	cout << endl;
}

int Map::numCells(){
	int count = 0;
	for(int i = 0; i < length; i++){
		for(int j = 0; j < width; j++){
			if(map[i][j].getTile() == 'X')
				count++;
		}
	}
	return count;
}

void Map::createMap(){
	map = new Grid*[length];
    for(int i = 0; i < length; i++)
        map[i] = new Grid[width];
}
