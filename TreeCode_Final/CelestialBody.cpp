#include "stdafx.h"
#include <math.h>
#include <vector>
#include "CelestialBody.h"
#include "TreeCodeNode.h"
#include "TreeOfStars.h"
#include "param.h"
#include <fstream>
#include <iostream>


CelestialBody::CelestialBody()
{
     //default constructor
     celestialbodynum = 1;
	 //r = new double[celestialbodynum];
     x = new double[celestialbodynum];
     y = new double[celestialbodynum];
     z = new double[celestialbodynum];

	 //V = new double[celestialbodynum];
     vx = new double[celestialbodynum];
     vy = new double[celestialbodynum];
     vz = new double[celestialbodynum];

     ax = new double[celestialbodynum];
     ay = new double[celestialbodynum];
     az = new double[celestialbodynum];


     for (int i = 0; i < celestialbodynum; i++) {
		  //r[i] = 0;
          x[i] = 0;
          y[i] = 0;
          z[i] = 0;

		  //V[i] = 0;
          vx[i] = 0;
          vy[i] = 0;
          vz[i] = 0;

          ax[i] = 0;
          ay[i] = 0;
          az[i] = 0;

     }

     m = 1.0;
     mpt = &m;

     treepos.resize(celestialbodynum, nullptr);

}

CelestialBody::CelestialBody(int SIZE)
{
     //constructor with variable array size
     celestialbodynum = SIZE;

	 //r = new double[celestialbodynum];
     x = new double[celestialbodynum];
     y = new double[celestialbodynum];
     z = new double[celestialbodynum];

	 //V = new double[celestialbodynum];
     vx = new double[celestialbodynum];
     vy = new double[celestialbodynum];
     vz = new double[celestialbodynum];

     ax = new double[celestialbodynum];
     ay = new double[celestialbodynum];
     az = new double[celestialbodynum];

	 mpt = new double[celestialbodynum];

     for (int i = 0; i < celestialbodynum; i++) {
		  //r[i] = 0;
          x[i] = 0;
          y[i] = 0;
          z[i] = 0;

		  //V[i] = 0;
          vx[i] = 0;
          vy[i] = 0;
          vz[i] = 0;

          ax[i] = 0;
          ay[i] = 0;
          az[i] = 0;

		  mpt[i] = 0;

     }
     treepos.resize(celestialbodynum, nullptr);
   //  m = 1.0;
  //   mpt = &m;
}

CelestialBody::~CelestialBody()
{
	//delete[] r;
     delete[] x;
     delete[] y;
     delete[] z;

	//delete[] V;
     delete[] vx;
     delete[] vy;
     delete[] vz;

     delete[] ax;
     delete[] ay;
     delete[] az;

     delete[] mpt;

     treepos.erase(treepos.begin(), treepos.end());
}

void CelestialBody::UpdateV(double t) {
     for (int i = 0; i < celestialbodynum; i++) {
          vx[i] += ax[i] * t;
          vy[i] += ay[i] * t;
          vz[i] += az[i] * t;
     };
};

void CelestialBody::UpdateR(double t, TreeOfStars*& tree) {
     for (int i = 0; i < celestialbodynum; i++) {
          x[i] += vx[i] * t;
          y[i] += vy[i] * t;
          z[i] += vz[i] * t;

          bool ifremoved = tree->removenode(x[i], y[i], z[i], treepos[i]);
          if (ifremoved) {
               auto pos = tree->insertnode(x[i], y[i], z[i], mpt[i], tree->root);
               if (pos) {
                    treepos[i] = pos;
                    treepos[i]->whichstaristhisnode = &(treepos[i]);
               }
          };
     };
};


void CelestialBody::WriteStateToFileM1(ofstream &File) {

	for (int i = 0; i < celestialbodynum; i++) {
		File << x[i] << " ";
		File << y[i] << " ";
		File << z[i] << " \n";
	}
	return;
}


