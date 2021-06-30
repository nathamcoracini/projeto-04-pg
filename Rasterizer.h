#include "Eigen/Dense"
#include "Camera.h"
#include "Mesh.h"
#include "Face.h"

#ifndef RASTERIZER_H_
#define RASTERIZER_H_

class Rasterizer {
    private:
        void bresenham(Vector4d ci, Vector4d cf);
        int h;
        int w;
        double t;
        double r;
        vector<Vector4d> changeCoord(vector<Vector4d> v);
        std::vector<double> zbuffer;
       
    public:
        void rasterize(std::vector<Vector4d> v, std::vector<Face> f);
        Rasterizer(const int h, const int w, const double t, const double r);
        std::vector<unsigned char> image;
        void drawPixel(int x, int y, double z, int r, int g, int b);
};

#endif