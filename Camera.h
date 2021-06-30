#include "Eigen/Dense"
#include <cmath>

#ifndef CAMERA_H_
#define CAMERA_H_

using namespace Eigen;

class Camera {
    private:
        Vector3d pos;
        Vector3d target;
        double aspectRatio;
        double fov;
        double far;
        double near;
        int upDirection;
        
        Vector3d cameraDirection;
        Vector3d cameraUp;
        Vector3d cameraRight;
        Matrix4d cameraLookAt;
        Matrix4d cameraPerspective;
        Matrix4d cameraFinal;
    
    public:
        Camera(Vector3d pos, Vector3d target, double aspectRatio, double fov, double far, double near, Vector3d upCoord);
        void setPos(Vector3d pos);
        void setTarget(Vector3d target);
        void setCameraUp(Vector3d cameraUp);
        void setCameraRight(Vector3d cameraRight);
        Matrix4d getCameraLookAt();
        Matrix4d getCameraFinal();
};

#endif