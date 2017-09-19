#pragma once

#include "stdafx.h"
#include "param.h"

class TreeCodeNode {
private:

public:
     double tm; // total mass
     double cmx; // coordinates of center of mass
     double cmy;
     double cmz;

     double ox, oy, oz, dx, dy, dz; // node regeion, oxyz is center, dxyz is length;


                                    
     int numofchild;  // mark the status of the node: -1:empty   0:leafnode  other:internalnode with this number of children

     int numofallleaf; // the total leaves below this node, including leaves in children's children, childrenX3, etc.

     TreeCodeNode** whichstaristhisnode; // A pointer noticing which star the leaf corresponds to


     TreeCodeNode* parent;
     int childidx; // the child index of its parent
                   // pointer to children_XYZ,  1 = minus, 2 = plus in xyz coordinates
                   // eg, child_212 means the subregion with child_cx > thisnode_cx, child_cy < thisnode_cy, child_cz > thisnode_cz 
     TreeCodeNode* child_111; // idx 1
     TreeCodeNode* child_112; // idx 2
     TreeCodeNode* child_121; // idx 3
     TreeCodeNode* child_122; // idx 4
     TreeCodeNode* child_211; // idx 5
     TreeCodeNode* child_212; // idx 6
     TreeCodeNode* child_221; // idx 7
     TreeCodeNode* child_222; // idx 8

     // constructor, create new node at (ox,oy,oz) with length(dx,dy,dz), may specify its parent
     TreeCodeNode(double ox, double oy, double oz, double dx, double dy, double dz);
     TreeCodeNode(double ox, double oy, double oz, double dx, double dy, double dz, TreeCodeNode* & parent, int idx);

     // destructor
     ~TreeCodeNode();
};