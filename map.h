// class's been called twice
#ifndef MAP_H
#define MAP_H

#include "grid.h"

class Map{
    protected:
        Grid **map;
        int length, width;

    public:
        //Constructors and the Big 3
        Map();
        virtual ~Map();
		Map(const Map &);
		Map &operator=(const Map &);

        //Accessors
        int getLength();
        int getWidth();

        //Mutators
        void setLength(int);
        void setWidth(int);

        //Maps
        void initializeMapFile(int, int, ifstream &);  //initialize from given map on file
        void initializeMapRandom(int, int, int);      //initialize map randomly (3rd argument is # of cells to potentially add)
        void printMap();
		int numCells();   //number of cells still alive
		void createMap();

};
#endif
