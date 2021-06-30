#ifndef MESH_H
#define MESH_H

#include "Face.h"
#include "Eigen/Dense"

#include <vector>

using std::vector;
using namespace Eigen;

class Mesh {
    public:
        void pushV(double x, double y, double z);
        void pushF(int v1, int v2, int v3);
        vector<Vector3d> v;
        vector<Face> f;
};

#endif