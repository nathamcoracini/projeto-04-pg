#include "Scale.h"

Matrix4d scale(Vector3d v) {
    Matrix4d m;
    m << v.x(),    0,        0,        0,
         0,        v.y(),    0,        0,
         0,        0,        v.z(),    0,
         0,        0,        0,        1;

    return m;
}