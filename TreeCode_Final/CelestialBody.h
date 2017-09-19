#pragma once

#include <math.h>
#include <fstream>
#include <vector>
#include "TreeCodeNode.h"
#include "TreeOfStars.h"
#include "param.h"

using namespace std;

class CelestialBody
{
private:


public:
     CelestialBody();
	CelestialBody(int SIZE);
	~CelestialBody();

	// PUBLIC CALCULATED VARIABLES
     int celestialbodynum;

     double *mpt; // mass of each body, all bodies in the class have same mass ; [in self_celestialObject]
     double m; // same as *m, but in value format, not pointer;

	//double *r; //radial position
	double *x; //x-Position
	double *y; //y-Position
	double *z; //z-Position

	//double *V; //Total Velocity 
	double *vx; //Velocity in x Component
	double *vy; //Velocity in y Component
	double *vz; //Velocity in z Component

	double *ax; //Acceleration in x Component
	double *ay; //Acceleration in y Component
	double *az; //Acceleration in z Component

     vector<TreeCodeNode*> treepos; // a vector saving the postion of the leaf in the tree corresponding to the star

	// PUBLIC FUNCTIONS
     void UpdateV(double t);

	void WriteStateToFileM1(ofstream &File);

     void UpdateR(double t, TreeOfStars*& tree);
};
