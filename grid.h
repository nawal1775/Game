#ifndef GRID_H // avoid repeated expansion
#define GRID_H
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Grid{
    private:
        char tile;
        int numNeighbors;

    public:
        //Two constructors
        Grid(); //default constructor (if no file was given)
        Grid(char); //nondefault constructor (if a file was given)

        //Accessors
        char getTile();
        int getNumNeighbors();

        //Mutators
        void setTile(char);
        void setNumNeighbors(int);

};
#endif
