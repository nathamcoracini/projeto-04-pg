#include "Translate.h"

Matrix4d translate(Vector3d v) {
    Matrix4d m;
    m << 1, 0, 0, v.x(),
         0, 1, 0, v.y(),
         0, 0, 1, v.z(),
         0, 0, 0, 1;

    return m;
}


