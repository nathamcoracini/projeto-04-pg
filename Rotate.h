#include "Eigen/Dense"

#ifndef ROTATE_H_
#define ROTATE_H_

using namespace Eigen;

Matrix4d rotateX(double angle);
Matrix4d rotateY(double angle);
Matrix4d rotateZ(double angle);

#endif