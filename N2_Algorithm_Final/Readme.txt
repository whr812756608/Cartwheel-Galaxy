"make all"    --- compile and create executive file.
"a.exe INPUTFILENAME   soften  totalstepnum dt  [number of particle in each galaxy object]"  ---  run the N2_algorithm program

E.g. :
To run with : "midterm_stardist"
a.exe ../Input/midterm_stardist.txt  0.25  400 0.1 667 1 1

To run with : "Final_galaxycomp_20_80_300_20.txt"
a.exe ../Input/Final_galaxycomp_20_80_300_20.txt  0.25 0.5 4000 0.05 20 80 300 20

To run with : "Final_galaxycomp_80_300_20.txt"
a.exe ../Input/Final_galaxycomp_80_300_20.txt  0.25 0.5 4000 0.05 80 300 20

"Animation.m"  --- plot and animate in Matlab