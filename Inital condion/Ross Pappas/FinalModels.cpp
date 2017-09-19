// Final Initialization: Disc, Bulge, Halo, and Companion Galaxy 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{

    //Define Constants
    int diskStars, bulgeStars, companionStars, haloStars; // Units: N
    int count, i, j, k;
    int r0 = 1; // Units: [Tm]
    double b = 5.0; 
    double M, mDisk, mBulge, mCompanion, mHalo; // Units: [M_Solar]
    double G; // Units: [Tm/(M_Solar * years^2)]
    double X1, X2, X3, X4, X5, X6, X7, X8, X9;
    double r, x, y, z, v, vx, vy, vz, kappa, phi, vdisp, rdisp, hdisp, Q, theta, bdisp;
    double Pi = atan(1) * 4;
    Q = 1.3;
    G = 6.678 * 1/pow(10,11.0) * 1/(pow(pow(10,12),3)) * (1.989 * pow(10,30)) * pow(3600,2) * pow(24,2) * pow(365,2); /*  G [m^3/(kg * s^2)] * [(Tm^3)/(m^3)] * [kg/M_Solar] * [(s^2)/(h^2)] * [(h^2)/(day^2)] * [(day^2)/(years^2)] */ 
    count = 0;
    M = pow(10,11); // M/M_Solar
    
    
    //Define files
    fstream diskData;
    fstream bulgeData;
    fstream haloData;
    fstream companionData;
    fstream allData;
    
    cout << G << endl;
    
    cout << Pi << endl;
    
    
    cout << "Please, enter the amount of disc, bulge, companion, and halo stars you'd like to calculate: " << endl;
    cin >> diskStars >> bulgeStars >> companionStars >> haloStars;
    
    mDisk = (M/((double)diskStars));
    mHalo = ((3 * M)/((double)(haloStars)));
    mCompanion = (2.0/3 * M)/((double)companionStars);
    mBulge = ((1.0/3 * M)/((double)(bulgeStars)));
    
    cout << "Thank you." << endl;
    
    // Populate the Disk
    
    // Initialize Time
    unsigned int seed = time(NULL);
    srand(seed);
    
    
    // Open the Disk File
    diskData.open("diskData.txt", ios::out);
    allData.open("allData.txt", ios::out);
    
    do
    {
        // Initialize Random Values
        X1 = (((double)rand())/(RAND_MAX)); 
        X2 = ((((double)rand()))/(RAND_MAX))*100; 
        X3 = ((((double)rand()))/(RAND_MAX)); 
        X4 = ((((double)rand()))/(RAND_MAX)); 
        
        rdisp = 1/((double)(r0)) * exp(- 1/(pow(r0,2) * 2));
        if(X1 < rdisp)
        {
            if(X2 * exp(- pow(X2,2)/2) < X1)
            {
                if(X2 * r0 < 4 && X2 * r0 > 2.3)
                {
                    r = X2 * r0;
                    z = (1 - 2 * X3) * r;
                    y = sqrt(pow(r,2) - pow(z,2)) * sin(2 * Pi * X4);
                    x = sqrt(pow(r,2) - pow(z,2)) * cos(2 * Pi * X4);
                    phi = (double)acos(x/r);
                    rdisp = ((double)(r)/(double)(r0) * exp(- pow(r,2)/(((double)pow(r0,2)) * 2)));
                    if(r < 0.0003)
                    {
                        kappa = 1/r;
                    }
                    else
                    {
                        kappa = sqrt(G * mDisk/((double)r))/(2 * Pi * r);
                    }
                    vdisp = 1.3 * 3.36 * G * rdisp * 1/((double)(kappa));
                    vx = vdisp * cos(phi);
                    vy = vdisp * sin(phi);
                    vz = 0;
                    z = 0;
                    count++;
                    diskData << r << " " << x << " " << y << " " << z << " " << vdisp << " " << vx << " " << vy << " " << vz << " " << mDisk << " " <<  endl;
                    allData << r << " " << x << " " << y << " " << z << " " << vdisp << " " << vx << " " << vy << " " << vz << " " << mDisk << " " <<  endl;
                }
            }
        }
    }while(count != diskStars);
    
    diskData.close();
    count = 0;
    haloData.open("haloData.txt", ios::out);
    
    //Halo Generation
    do
    {
        // Initialize Random Values
        X1 = (((double)rand())/(RAND_MAX)); 
        X2 = ((((double)rand()))/(RAND_MAX))*100; 
        X3 = ((((double)rand()))/(RAND_MAX)); 
        X4 = ((((double)rand()))/(RAND_MAX));
        
        hdisp = 3 * mHalo * (1 - 0.035) / (4 * Pi * pow(b,3)) * (1/pow(1 + 1/(pow(b,2)),5.0/2));
        
        if(X1 < hdisp)
        {
            hdisp = 3 * mHalo * (1 - 0.035) / (4 * Pi * pow(b,3)) * (1/pow(1 + pow(X2,2)/(pow(b,2)),5.0/2));
            if(hdisp < X1)
            {
                r = X2;
                z = (1 - 2 * X3) * r;
                x = (sqrt(pow(r,2) - pow(z,2))) * cos(2 * Pi * X4);
                y = (sqrt(pow(r,2) - pow(z,2))) * sin(2 * Pi * X4);
                phi = acos(x/r);
                haloData << r << " " << x << " " << y << " " << z << " " << vdisp << " " << vx << " " << vy << " " << vz << " " << mHalo << " " <<  endl;
                allData << r << " " << x << " " << y << " " << z << " " << vdisp << " " << vx << " " << vy << " " << vz << " " << mDisk << " " <<  endl;
                count++;
            }
        }
    }while(count != haloStars);
    
    haloData.close();
    count = 0;
    // Open the Companion File
    companionData.open("companionData.txt", ios::out);
    
    do
    {
        // Initialize Random Values
        X1 = (((double)rand())/(RAND_MAX)); 
        X2 = ((((double)rand()))/(RAND_MAX)); 
        X3 = ((((double)rand()))/(RAND_MAX));    
 
            r = 1/(sqrt(1/pow(X1, 2.0/3) - 1));
            z = (1 - 2 * X2) * r;
            y = sqrt(pow(r,2) - pow(z,2)) * sin(2 * Pi * X3);
            x = sqrt(pow(r,2) - pow(z,2)) * cos(2 * Pi * X3);
            z = z + 2000;
            phi = (double)acos(x/r);
            theta = (double)acos(z/r);
            rdisp = ((double)(r)/(double)(r0) * exp(- pow(r,2)/(((double)pow(r0,2)) * 2)));
            if(r < 0.0003)
            {
                kappa = 1/r;
            }
            else
            {
                kappa = sqrt(G * mCompanion/((double)r)/(2 * Pi * r));
            }
            vdisp = 1.3 * 3.36 * G * rdisp * 1/((double)(kappa));
            vx = vdisp * cos(phi) * sin(theta);
            vy = vdisp * sin(phi) * sin(theta);
            vz = - 0.13;
            count++;
            companionData << r << " " << x << " " << y << " " << z << " " << vdisp << " " << vx << " " << vy << " " << vz << " " << mCompanion << " " <<  endl;
            allData << r << " " << x << " " << y << " " << z << " " << vdisp << " " << vx << " " << vy << " " << vz << " " << mDisk << " " <<  endl;

    }while(count != companionStars);

    companionData.close();
    
    //make bulge
    
    bulgeData.open("bulgeData.txt",ios::out);
    count = 0;
    
    do
    {
        // Initialize Random Values
        X1 = (((double)rand()))/(RAND_MAX); 
        X2 = ((((double)rand())))/(RAND_MAX)*1000; 
        X3 = ((((double)rand())))/(RAND_MAX); 
        X4 = ((((double)rand())))/(RAND_MAX);
        
        b = 0.375;
        
        bdisp = (((3 * mBulge * bulgeStars)/((double)(4 * Pi * pow(b,3)))) * (1/((double)(pow((1 + 1/(pow(b,2))), 5.0/2)))));
        
        if(X1 < bdisp)
        {
            bdisp = (((3 * mBulge * bulgeStars)/(4 * Pi * pow(b,3))) * (1/(pow(1 + ((pow(X2,2))/(pow(b,2))), 5.0/2))));
            if(bdisp < X1 )
            {
                r = X2;
                z = (1 - 2 * X3) * r;
                x = (sqrt(pow(r,2) - pow(z,2))) * cos(2 * Pi * X4);
                y = (sqrt(pow(r,2) - pow(z,2))) * sin(2 * Pi * X4);
                phi = acos(x/r);
                if(r < 0.0003)
                {
                    kappa = 1/r;
                }
                else
                {
                    kappa = sqrt(G * mBulge * bulgeStars/((double)r))/(2 * Pi * r);
                }
                vdisp = 1.3 * 3.36 * G * bdisp * 1/((double)(kappa));
                theta = (double)acos(z/r);
                vx = vdisp * cos(phi) * sin(theta);
                vy = vdisp * sin(phi) * sin(theta);
                vz = vdisp * cos(theta);
                bulgeData << r << " " << x << " " << y << " " << z << " " << vdisp << " " << vx << " " << vy << " " << vz << " " << mBulge << " " <<  endl;
                count++;
                allData << r << " " << x << " " << y << " " << z << " " << vdisp << " " << vx << " " << vy << " " << vz << " " << mBulge * bulgeStars << " " <<  endl;
            }
        }
        
    }while(count != bulgeStars);
    
    bulgeData.close();
    allData.close();
    
    return 0;
}

    