#include "Camera.h"

Camera::Camera(Vector3d pos, Vector3d target, double aspectRatio, double fov, double far, double near, Vector3d upCoord) {
    this->pos = pos;
    this->target = target;
    this->aspectRatio = aspectRatio;
    this->fov = fov;
    this->far = far;
    this->near = near;
    this->upDirection = upDirection;

    Vector3d tmp = target - pos;
    cameraDirection = tmp.normalized();

    tmp = upCoord;

    tmp = tmp.cross(cameraDirection);
    cameraRight = tmp.normalized();

    tmp = cameraDirection.cross(cameraRight);
    cameraUp = tmp;

    Matrix4d m;
    m << cameraRight.x() ,    cameraRight.y() ,     cameraRight.z(),     0
      , cameraUp.x() ,        cameraUp.y() ,        cameraUp.z(),        0
      , cameraDirection.x() , cameraDirection.y() , cameraDirection.z(), 0
      , 0                   , 0,                    0,                   1;

    Matrix4d n;
    n << 1 ,    0 , 0, -pos.x()
      ,  0 ,    1 , 0, -pos.y()
      ,  0 ,    0 , 1, -pos.z()
      ,  0 ,    0 , 0,        1;

    cameraLookAt = m * n;

    cameraPerspective << 1 / (aspectRatio * tan(fov / 2) ) ,                           0,                              0,                              0
                                                        , 0,            1 / tan(fov / 2),                              0,                              0
                                                        , 0,                           0,   -((far + near)/(far - near)), -((2 * far * near)/(far-near))
                                                        , 0,                           0,                              -1,                             0;

    cameraFinal = cameraPerspective * cameraLookAt;
}

void Camera::setPos(Vector3d pos) {
    this->pos = pos;
}
void Camera::setTarget(Vector3d target) {
    this->target = target;
}
void Camera::setCameraUp(Vector3d cameraUp) {
    this->cameraUp = cameraUp;
}
void Camera::setCameraRight(Vector3d cameraRight) {
    this->cameraRight = cameraRight;
}

Matrix4d Camera::getCameraLookAt() {
    return cameraLookAt;
}

Matrix4d Camera::getCameraFinal() {
    return cameraFinal;
}