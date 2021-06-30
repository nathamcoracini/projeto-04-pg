#include "Rotate.h"
#include <cmath>

Matrix4d rotateX(double angle) {
    Matrix4d m;
    m << 1, 0, 0, 0,
         1, cos(angle), -sin(angle), 0,
         0, sin(angle),  cos(angle), 0,
         0,          0,           0, 1;

    return m;
}
Matrix4d rotateY(double angle) {
    Matrix4d m;
    m << cos(angle), 0, sin(angle), 0,
                  0, 1,          0, 0,
        -sin(angle), 0, cos(angle), 0,
         0,          0,          0, 1;

    return m;
}
Matrix4d rotateZ(double angle) {
    Matrix4d m;
    m << cos(angle), -sin(angle), 0, 0,
         sin(angle), cos(angle) , 0, 0,
         0,          0,           1, 0,
         0,          0,           0, 1;

    return m;
}