#include "Face.h"

Face::Face(unsigned v1, unsigned v2, unsigned v3) {
    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
}

unsigned Face::getV1() {
    return v1;
}
unsigned Face::getV2() {
    return v2;
}
unsigned Face::getV3() {
    return v3;
}