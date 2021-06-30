#include "Mesh.h"

void Mesh::pushV(double x, double y, double z) {
    Vector3d vec3(x, y, z);
    v.push_back(vec3);
}

void Mesh::pushF(int v1, int v2, int v3) {
    Face vec3(v1, v2, v3);
    f.push_back(vec3);
}