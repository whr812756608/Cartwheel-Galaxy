"make all"    --- compile and create executive file.
"a.exe INPUTFILENAME   soften distcriterion totalstepnum dt  [number of particle in each galaxy object]"  ---  run the N2_algorithm program

E.g. :
To run with : "midterm_stardist.txt"  (667 particles in disk, 1 in bulge, 1 in canonball)
a.exe ../Input/midterm_stardist.txt  0.25 0.5 400 0.1 667 1 1

To run with : "Final_galaxycomp_80_300_20.txt"(PF model from the reference paper, 80 particles in disk, 300 in halo, 20 in bulge, none in canonball to test the stability of the model)
a.exe ../Input/Final_galaxycomp_80_300_20.txt  0.25 0.5 4000 0.05 80 300 20

To run with : "Final_galaxycomp_20_80_300_20.txt"(PF model from the reference paper, 80 particles in disk, 300 in halo, 20 in bulge, and 20 in canonball)
a.exe ../Input/Final_galaxycomp_20_80_300_20.txt  0.25 0.5 4000 0.05 20 80 300 20


 
"Animation.m"  --- plot and animate in Matlab

Note:
The Treecode file has bug at TreeCodeNode destructor, when the tree is maintained by checking if a particle is moving out of a leaf.
Galaxy_TreeCode.exe is the .exe file compiled from my Windows7-x64, which does not encouter the error.
Compiling on other platform leads to segmentation fault 11.