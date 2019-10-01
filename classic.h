#ifndef CLASSIC_H // avoid repeated expansion
#define CLASSIC_H
#include "map.h"

class Classic : public Map{
	private:

	public:
		Classic();
		Grid** getCurrentMap();     //get the current copy of the map
		void countNeighbors();   //count # of neighbors (adjacent cells) each tile has
		void resetNeighbors();   //reset # of neighbors for all cells to 0
		void generation();       //determines the next generation of cells based on rules
		void play(int);          //plays Conway's Game of Life (classic) and combines above functions


};
#endif
