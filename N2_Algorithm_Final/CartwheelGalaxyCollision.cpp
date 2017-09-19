// CartwheelGalaxyCollision.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include "CelestialBody.h"

using namespace std;

const char* FILEPRE = "Output";
string READINDIST = "stardist10.txt";
double LOWESTDISTANCE = 0.3333;


//void LeapFrogStep(int _nstep, double dt, vector<CelestialBody*> bodylist, ofstream &File);
void LeapFrogStep(int _nstep, double dt, vector<CelestialBody*> bodylist);
void geta(vector<CelestialBody*> bodylist);

void ReadInInitialConditions(vector<CelestialBody*> bodylist);


int main(int argc, char* argv[])
{

     int nstep;
     double dt;
     vector<int> numofbodies;

     if (argc <= 5) {
          cout << "Invalid number of arguments.\n"
               << "Usage: ./THISPROGRAM Inputfile SoftenFactor TotalStepNum dt [particle num in each celetial body]\n";
          return -1;
     }
     else {
          READINDIST = argv[1];
          LOWESTDISTANCE = atof( argv[2] );
          nstep = atoi(argv[3]);
          dt = atof(argv[4]);
          for (int i = 5; i < argc; i++) {
               int temp = atoi(argv[i]);
               numofbodies.push_back(temp);
          }
     }


	std::cout << "Hello Galaxy Collision" << "\n";

     cout << "Number of particles in each celetial body is: ";
     for (int i = 0; i < numofbodies.size(); i++) {
          cout << " "<< numofbodies[i] ;
     };
     cout << endl;

	// Create a list containing all galaxies.
	vector<CelestialBody*> all;
     for (int i = 0;i < numofbodies.size();i++) {
          CelestialBody* tmp = new CelestialBody(numofbodies[i]);
          all.push_back(tmp);
     }

	ReadInInitialConditions(all);
	LeapFrogStep(nstep, dt, all);

	//outputFile.close();

	std::cout << "Bye Galaxy Collision" << "\n";

	//system("PAUSE");
    return 0;
}


//void LeapFrogStep(int _nstep, double dt, vector<CelestialBody*> bodylist, ofstream &OutFile) {
void LeapFrogStep(int _nstep, double dt, vector<CelestialBody*> bodylist) {

     //LEAPFROG Start from here:
	 int frame = 0;
	 char filename[20];
	 sprintf(filename,"%s_%04d.txt", FILEPRE, frame);
	 string file_s = filename;
	 ofstream OutFile;
	 OutFile.open(file_s);

     //cout << "Leapfrog : step " <<frame<< endl;
     geta(bodylist);

     for (int i = 0; i < bodylist.size();i++) {
          bodylist[i]->WriteStateToFileM1(OutFile);
     }
	 OutFile << "\n";
	 OutFile.close();
	 //WriteStateToFileM2(bodylist, frame);

     for (int n = 0; n < _nstep; n++) {
          frame++;
           //cout << "Leapfrog : step " << frame << endl;
		 // First, calculate v at t+0.5dt;
           for (int i = 0; i < bodylist.size();i++) {
                bodylist[i]->UpdateV(0.5*dt);
           }

		 // Caluclate r at t+dt by v_0.5 * dt 
           for (int i = 0; i < bodylist.size();i++) {
                bodylist[i]->UpdateR(1.0*dt);
           }

		 //update acceleration
		 geta(bodylist);
		 
         //update v at t+dt;
           for (int i = 0; i < bodylist.size();i++) {
                bodylist[i]->UpdateV(0.5*dt);
           }

		 //WriteStateToFileM2(bodylist, frame);
           if (frame % 10 == 0) {
                char filename2[20];
                sprintf(filename2, "%s_%04d.txt", FILEPRE, frame);
                file_s = filename2;
                OutFile.open(file_s);
                for (int i = 0; i < bodylist.size();i++) {
                     bodylist[i]->WriteStateToFileM1(OutFile);
                }
           }
		 //OutFile << "\n";

		 OutFile.close();
	 };

	 



}


void geta(vector<CelestialBody*> bodylist) {
     vector<CelestialBody*> external;

     // for each item in body list
     for (int i = 0; i < bodylist.size(); i++) {
          external.clear();
          external.assign(bodylist.begin(), bodylist.end());

          // remove this item from external
          external.erase(external.begin() + i);

          // calculate this item's acceleration, treating all other items as external forces.
          (bodylist[i])->Acceleration(external, LOWESTDISTANCE);
     };
};

void ReadInInitialConditions(vector<CelestialBody*> bodylist) {
	std::ifstream infile(READINDIST);

	if (!infile.is_open()) {
		std::cout << "Error in opening file! \n";
		exit(1);
	}


	// For all stars  
     for (int j = 0; j < bodylist.size(); j++) {
	     for (int l = 0; l < bodylist[j]->celestialbodynum; l++) {
		     // Read in row
               infile >> bodylist[j]->mpt[l];

		     //infile >> bodylist[j]->r[l];
		     infile >> bodylist[j]->x[l];
		     infile >> bodylist[j]->y[l];
		     infile >> bodylist[j]->z[l];
		     //infile >> bodylist[j]->V[l];
		     infile >> bodylist[j]->vx[l];
		     infile >> bodylist[j]->vy[l];
		     infile >> bodylist[j]->vz[l];
		     
               bodylist[j]->mpt[l] = (bodylist[j]->mpt[l]) ;
          }
	}


/*
	// Check all Stars
	for (int i = 0; i < numOfStars; i++) {
		std::cout << "Stars" << "\n";
		std::cout << " numOfStars: " << numOfStars << "\n";
		std::cout << "i: " << i << "\n";
		std::cout << "r: " << bodylist[0]->r[i] << "\n";
		std::cout << "x: " << bodylist[0]->x[i] << "\n";
		std::cout << "y: " << bodylist[0]->y[i] << "\n";
		std::cout << "z: " << bodylist[0]->z[i] << "\n";
		std::cout << "V: " << bodylist[0]->V[i] << "\n";
		std::cout << "vx: " << bodylist[0]->vx[i] << "\n";
		std::cout << "vy: " << bodylist[0]->vy[i] << "\n";
		std::cout << "vz: " << bodylist[0]->vz[i] << "\n";
		std::cout << "mpt: " << bodylist[0]->mpt[i] << "\n";
	}

	// Check Bulge and Compact Galaxy
	for (int i = 1; i < bodylist.size(); i++) {
		std::cout << "Bulge or Compact Galaxy" << "\n";
		std::cout << "bodylist.size(): " << bodylist.size() << "\n";
		std::cout << "i: " << i << "\n";
		std::cout << "*bodylist[i]->r: " << *bodylist[i]->r << "\n";
		std::cout << "*bodylist[i]->x: " << *bodylist[i]->x << "\n";
		std::cout << "*bodylist[i]->y: " << *bodylist[i]->y << "\n";
		std::cout << "*bodylist[i]->z: " << *bodylist[i]->z << "\n";
		std::cout << "*bodylist[i]->V: " << *bodylist[i]->V << "\n";
		std::cout << "*bodylist[i]->vx: " << *bodylist[i]->vx << "\n";
		std::cout << "*bodylist[i]->vy: " << *bodylist[i]->vy << "\n";
		std::cout << "*bodylist[i]->vz: " << *bodylist[i]->vz << "\n";
		std::cout << "*bodylist[i]->mpt: " << *bodylist[i]->mpt << "\n";
	}
	*/
}









