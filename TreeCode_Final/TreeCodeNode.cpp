
#include "stdafx.h"
#include "TreeCodeNode.h"
#include "param.h"
#include <iostream>

#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

TreeCodeNode::TreeCodeNode(double iox, double ioy, double ioz, double idx, double idy, double idz) {

     cmx = 0;
     cmy = 0;
     cmz = 0;
     tm = 0;

     ox = iox;
     oy = ioy;
     oz = ioz;
     dx = idx;
     dy = idy;
     dz = idz;


     numofchild = -1;  // -1 : empty   ;  0 : leaf ; other: number of children
     whichstaristhisnode = nullptr;
     numofallleaf = 0;

     child_111 = nullptr;
     child_112 = nullptr;
     child_112 = nullptr;
     child_112 = nullptr;
     child_112 = nullptr;
     child_112 = nullptr;
     child_112 = nullptr;
     child_112 = nullptr;

     parent = nullptr;
     childidx = 0;
}

TreeCodeNode::TreeCodeNode(double iox, double ioy, double ioz, double idx, double idy, double idz, TreeCodeNode* & iparent, int n) {

     //cmx = icx;
     //cmy = icy;
     //cmz = icz;
     //tm = im;

     cmx = 0;
     cmy = 0;
     cmz = 0;
     tm = 0;

     //x1 = ix1;
     //x2 = ix2;
     //y1 = iy1;
     //y2 = iy2;
     //z1 = iz1;
     //z2 = iz2;
     ox = iox;
     oy = ioy;
     oz = ioz;
     dx = idx;
     dy = idy;
     dz = idz;


     //ifleaf = true;
     //ifoccupied = false;
     numofchild = -1;
     numofallleaf = 0;

     whichstaristhisnode = nullptr;


     child_111 = nullptr;
     child_112 = nullptr;
     child_112 = nullptr;
     child_112 = nullptr;
     child_112 = nullptr;
     child_112 = nullptr;
     child_112 = nullptr;
     child_112 = nullptr;

     parent = iparent;
     childidx = n;
}

TreeCodeNode::~TreeCodeNode() {

     // This destructor causes SEGMENTATION FAULT on MAC and LINUX
     if (child_111) {
          delete child_111;
     }
     if (child_112) {
          delete child_112;
     }
     if (child_121) {
          delete child_121;
     }
     if (child_122) {
          delete child_122;
     }
     if (child_211) {
          delete child_211;
     }
     if (child_212) {
          delete child_212;
     }
     if (child_221) {
          delete child_221;
     }
     if (child_222) {
          delete child_222;
     }

     //delete the child ptr in parent node
     child_111 = nullptr;
     child_112 = nullptr;
     child_121 = nullptr;
     child_122 = nullptr;
     child_211 = nullptr;
     child_212 = nullptr;
     child_221 = nullptr;
     child_222 = nullptr;

     if (whichstaristhisnode) {
          if ((*whichstaristhisnode) == this) {
               (*whichstaristhisnode) = nullptr;
          }
     };
}
