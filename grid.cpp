#include "grid.h"

//constructor
Grid::Grid(){
    tile = '-';
    numNeighbors = 0;
}

//overloaded constructor
Grid::Grid(char t){
    tile = t;
}

char Grid::getTile(){
    return tile;
}

int Grid::getNumNeighbors(){
    return numNeighbors;
}

void Grid::setTile(char t){
    tile = t;
}

void Grid::setNumNeighbors(int n){
    numNeighbors = n;
}
