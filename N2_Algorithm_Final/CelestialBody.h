#pragma once

#include <math.h>
#include <fstream>
#include <vector>
#include "param.h"
//double LOWESTDISTANCE ;  

using namespace std;


class CelestialBody
{
private:

	// CONSTANTS
	//double G = 1; // Gravitaional constant 6.67408 * 10^(-11) m^3 kg^-1 s^-2



	// PRIVATE FUNCTIONS
	


public:
     CelestialBody();
	CelestialBody(int SIZE);
	~CelestialBody();

	// PUBLIC CALCULATED VARIABLES
     int celestialbodynum;

     double *mpt; // mass of each body, all bodies in the class have same mass ; [in self_celestialObject]
     double m; // same as *m, but in value format, not pointer;

	double *r; //radial position
	double *x; //x-Position
	double *y; //y-Position
	double *z; //z-Position

	double *V; //Total Velocity 
	double *vx; //Velocity in x Component
	double *vy; //Velocity in y Component
	double *vz; //Velocity in z Component

	double *ax; //Acceleration in x Component
	double *ay; //Acceleration in y Component
	double *az; //Acceleration in z Component


	// PUBLIC FUNCTIONS

     void Acceleration(vector<CelestialBody*> externalbodies, double soften);
     void UpdateV(double t);
     void UpdateR(double t);
	 void WriteStateToFileM1(ofstream &File);
};

