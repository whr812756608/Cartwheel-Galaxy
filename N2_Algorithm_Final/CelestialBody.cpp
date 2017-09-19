#include "stdafx.h"
#include <math.h>
#include <vector>
#include "CelestialBody.h"
#include <fstream>

CelestialBody::CelestialBody()
{
     //default constructor
     celestialbodynum = 1;
	 r = new double[celestialbodynum];
     x = new double[celestialbodynum];
     y = new double[celestialbodynum];
     z = new double[celestialbodynum];

	 V = new double[celestialbodynum];
     vx = new double[celestialbodynum];
     vy = new double[celestialbodynum];
     vz = new double[celestialbodynum];

     ax = new double[celestialbodynum];
     ay = new double[celestialbodynum];
     az = new double[celestialbodynum];


     for (int i = 0; i < celestialbodynum; i++) {
		  r[i] = 0;
          x[i] = 0;
          y[i] = 0;
          z[i] = 0;

		  V[i] = 0;
          vx[i] = 0;
          vy[i] = 0;
          vz[i] = 0;

          ax[i] = 0;
          ay[i] = 0;
          az[i] = 0;

     }

     m = 1.0;
     mpt = &m;

}

CelestialBody::CelestialBody(int SIZE)
{
     //constructor with variable array size
     celestialbodynum = SIZE;

	 r = new double[celestialbodynum];
     x = new double[celestialbodynum];
     y = new double[celestialbodynum];
     z = new double[celestialbodynum];

	 V = new double[celestialbodynum];
     vx = new double[celestialbodynum];
     vy = new double[celestialbodynum];
     vz = new double[celestialbodynum];

     ax = new double[celestialbodynum];
     ay = new double[celestialbodynum];
     az = new double[celestialbodynum];

	 mpt = new double[celestialbodynum];

     for (int i = 0; i < celestialbodynum; i++) {
		  r[i] = 0;
          x[i] = 0;
          y[i] = 0;
          z[i] = 0;

		  V[i] = 0;
          vx[i] = 0;
          vy[i] = 0;
          vz[i] = 0;

          ax[i] = 0;
          ay[i] = 0;
          az[i] = 0;

		  mpt[i] = 0;

     }

   //  m = 1.0;
  //   mpt = &m;
}


CelestialBody::~CelestialBody()
{
	 delete[] r;
     delete[] x;
     delete[] y;
     delete[] z;

	 delete[] V;
     delete[] vx;
     delete[] vy;
     delete[] vz;

     delete[] ax;
     delete[] ay;
     delete[] az;

     delete[] mpt;
}


void CelestialBody::Acceleration(vector<CelestialBody*> externalcelestialbody, double soften) {
     //void CelestialBody<SIZE>::Acceleration(int externalarraysize, double * m_externalbody[], double * x_externalbody[], double * y_externalbody[], double * z_externalbody[]) {
	//loop through each item in celestialObject
	for (int i = 0; i < celestialbodynum; i++) {
		double acc_x = 0;
		double acc_y = 0;
		double acc_z = 0;

		//self_celestialObject
		for (int j = 0; j < celestialbodynum; j++) {
               if (j != i) {
                    double dx = x[j] - x[i];
                    double dy = y[j] - y[i];
                    double dz = z[j] - z[i];

                    double dr3 = pow(sqrt((dx*dx) + (dy*dy) + (dz*dz) + soften*soften), 3.);

                    double AccelCoeffient = (G * (mpt[j])) / dr3;

                    acc_x += AccelCoeffient * dx;
                    acc_y += AccelCoeffient * dy;
                    acc_z += AccelCoeffient * dz;
               };
          };

		// External_celestialObject
          // loop all external celestial bodies
		for (int l = 0; l < externalcelestialbody.size(); l++) {

               // loop through all items in one external celestial body
               for (int j = 0; j < externalcelestialbody[l]->celestialbodynum; j++ ) {
                    double dx = externalcelestialbody[l]->x[j] - x[i];
                    double dy = externalcelestialbody[l]->y[j] - y[i];
                    double dz = externalcelestialbody[l]->z[j] - z[i];

                    double dr3 = pow(sqrt((dx*dx) + (dy*dy) + (dz*dz) + soften*soften), 3.);
                    double AccelCoeffient = (G * (externalcelestialbody[l]->mpt[j]) ) / dr3;

                    acc_x += AccelCoeffient * dx;
                    acc_y += AccelCoeffient * dy;
                    acc_z += AccelCoeffient * dz;
               };

          };
		
		ax[i] = acc_x;
		ay[i] = acc_y;
		az[i] = acc_z;

     };
	
};

void CelestialBody::UpdateV(double t) {
     for (int i = 0; i < celestialbodynum; i++) {
          vx[i] += ax[i] * t;
          vy[i] += ay[i] * t;
          vz[i] += az[i] * t;
     };
};


void CelestialBody::UpdateR(double t) {
     for (int i = 0; i < celestialbodynum; i++) {
          x[i] += vx[i] * t;
          y[i] += vy[i] * t;
          z[i] += vz[i] * t;
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
