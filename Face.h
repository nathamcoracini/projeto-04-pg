#ifndef FACE_H
#define FACE_H

class Face {
    private:
        unsigned v1, v2, v3;
    public:
        Face(unsigned v1, unsigned v2, unsigned v3);
        unsigned getV1();
        unsigned getV2();
        unsigned getV3();
};

#endif