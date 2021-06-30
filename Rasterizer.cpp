#include "Rasterizer.h"
#include <cmath>
#include <float.h>
#include <iostream>
#include <limits>

/* Rasterização */
void Rasterizer::rasterize(std::vector<Vector4d> v, std::vector<Face> f) {

    std::vector<Vector4d> vtrans = changeCoord(v);

    for (unsigned i = 0; i < f.size(); i++) {

        /* Desenha as linhas de um triângulo através do algoritmo de Bresenham */
        
        Vector4d vi, vf;
        vi = vtrans[f[i].getV1()];
        vf = vtrans[f[i].getV2()];

        bresenham(vi, vf);

        vi = vtrans[f[i].getV1()];
        vf = vtrans[f[i].getV3()];

        bresenham(vi, vf);

        vi = vtrans[f[i].getV2()];
        vf = vtrans[f[i].getV3()];

        bresenham(vi, vf);
    }

}

/* Algoritmo de bresenham para desenhar uma linha */
void Rasterizer::bresenham(Vector4d ci, Vector4d cf) {
    int xi = ci.x(), xf =  cf.x(),  yi =  ci.y(), yf = cf.y();
    double zi = ci.z(), zf = cf.z();


    int dx = xf - xi;
    int dy = yf - yi;
    double dz = zf - zi;

    int d = 2 * dy - dx;
    int incE = 2 * dy;
    int incNE = 2 * (dy - dx);
    double w = dz/dx;

    int x = xi;
    int y = yi;
    double z = zi;

    drawPixel(x, y, zi, 255, 0, 0);

    while(x < xf) {
        if(d <= 0) {
            d += incE;
            x++;  
        }  
        else { 
            d += incNE;
            x++;
            y++;
        }

        z += w;
        drawPixel(x, y, z, 255, 0, 0);
    }   
}

/* Inicializa a imagem e o zbuffer */
Rasterizer::Rasterizer(const int h, const int w, const double t, const double r) {

    this->h = h;
    this->w = w;
    this->t = t;
    this->r = r;

    /* Inicia o vetor de imagem */
    image.resize(w * h * 4);
    zbuffer.resize(w * h);

    for(int y = 0; y < h; y++)
        for(int x = 0; x < w; x++) {
            
            image[4 * w * y + 4 * x + 0] = 0;
            image[4 * w * y + 4 * x + 1] = 0;
            image[4 * w * y + 4 * x + 2] = 0;
            image[4 * w * y + 4 * x + 3] = 0;

            zbuffer[w * y + x] = -DBL_MAX;
        }
}

/* Muda as coordenadas para serem compatíveis com a resolução da imagem de saída */
vector<Vector4d> Rasterizer::changeCoord(vector<Vector4d> v) {
    double xmin = DBL_MAX;
    double ymin = DBL_MAX;
    double xmax = -DBL_MAX;
    double ymax = -DBL_MAX;

    for (unsigned i = 0; i < v.size(); i++) {
        if (v[i].x() < xmin)
            xmin = v[i].x();
        if(v[i].y() < ymin)
            ymin = v[i].y();
        if(v[i].x() > xmax)
            xmax = v[i].x();
        if(v[i].y() > ymax)
            ymax = v[i].y();
    }

    xmin = -this->r;
    xmax = this->r;
    ymin = -this->t;
    ymax = this->t;

    vector<Vector4d> final;
    for (unsigned i = 0; i < v.size(); i++) {
        double oldx = v[i].x();
        double oldy = v[i].y();
        double newxmax = w - 1;
        double newymax = h - 1;
        
        double newx = ( ( (oldx - xmin) * newxmax ) / (xmax - xmin) );
        double newy = ( ( (oldy - ymin) * newymax ) / (ymax - ymin) );

        final.push_back(Vector4d( newx, newy, v[i].z(), v[i].w() ) );
    }

    return final;

}

/* Desenha o pixel de acordo com a cor fornecida */
void Rasterizer::drawPixel(int x, int y, double z, int r, int g, int b) {

    if (x < w && y < h && x >= 0 && y >= 0) {

        if (zbuffer[w * y + x] == -DBL_MAX) {
            image[4 * w * y + 4 * x + 0] = r;
            image[4 * w * y + 4 * x + 1] = g;
            image[4 * w * y + 4 * x + 2] = b;
            // image[4 * w * y + 4 * x + 0] = 255 * !(x & y);
            // image[4 * w * y + 4 * x + 1] = x ^ y;
            // image[4 * w * y + 4 * x + 2] = x | y;
            image[4 * w * y + 4 * x + 3] = 255;
            zbuffer[w * y + x] = z;
        }
        else if(z > zbuffer[w * y + x]) {
            image[4 * w * y + 4 * x + 0] = r;
            image[4 * w * y + 4 * x + 1] = g;
            image[4 * w * y + 4 * x + 2] = b;
            // image[4 * w * y + 4 * x + 0] = 255 * !(x & y);
            // image[4 * w * y + 4 * x + 1] = x ^ y;
            // image[4 * w * y + 4 * x + 2] = x | y;
            image[4 * w * y + 4 * x + 3] = 255;
            zbuffer[w * y + x] = z;
        }
    }
    
}