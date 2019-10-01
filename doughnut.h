#ifndef DOUGHNUT_H // avoid repeated expansion
#define DOUGHNUT_H

#include "map.h"

class Doughnut : public Map{
    private:


	public:
		Doughnut();

		void countNeighbors();   //count # of neighbors (adjacent cells) each tile has
		void resetNeighbors();   //reset # of neighbors for all cells to 0
		void generation();       //determines the next generation of cells based on rules
		void play(int);          //plays Conway's Game of Life (Torus) and combines above functions

};
#endif
