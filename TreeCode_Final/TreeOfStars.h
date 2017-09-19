#pragma once

#include "stdafx.h"
#include <math.h>
#include <fstream>
#include <vector>

#include "TreeCodeNode.h"
#include "TreeOfStars.h"
#include "param.h"

class TreeOfStars {
private:

     void deletenodechildren(TreeCodeNode* &todelete);
     void deletenodeself(TreeCodeNode*  todelete);

public:
     TreeCodeNode* root;

     // default constructor, initial an empty tree
     TreeOfStars(double xo, double yo, double zo, double dx, double dy, double dz);

     // default destructor
     ~TreeOfStars();

     //insert the star at (x,y,z) with mass m. return its leaf ptr
     TreeCodeNode* insertnode(double x, double y, double z, double m, TreeCodeNode* & start);

     // remove the node content, in case the star is moving out from the zone
     bool removenode(double x, double y, double z, TreeCodeNode* & removenode);

     // calculate the acceleration of an object at (x,y,z) and m, influnced by the mass inside the "fromthenode" (including its children). 
     // distcriterion: if Dim_of_Node/Dist_between_obj_and_node < distcriterion, the node could be recognized as a "distant" node so that its force may be calculated by CM and TM.
     std::vector<double> getAfromnode(double x, double y, double z, double distcriterion, double soften, TreeCodeNode* fromthenode);

     std::vector<double> updatem(TreeCodeNode*& node);  // update the total mass and center mass coordiantes in this node
};
