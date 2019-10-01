#ifndef MIRROR_H // avoid repeated expansion
#define MIRROR_H

#include "./map.h"

class Mirror : public Map{
    private:

	public:
		Mirror();
		void countNeighbors();   //count # of neighbors (adjacent cells) each tile has
		void resetNeighbors();   //reset # of neighbors for all cells to 0
		void generation();       //determines the next generation of cells based on rules
		void play(int);          //plays Conway's Game of Life (mirrored) and combines above functions
};
#endif
