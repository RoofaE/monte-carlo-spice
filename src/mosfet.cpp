#include "mosfet.h"

// TODO: I WILL IMPLEMENT THIS LATER, JUST CREATING THE FILE FOR NOW
MOSFET::MOSFET(Type type, double width, double length, double vto, double kp)
    : type(type), W(width), L(length), VTO(vto), KP(kp) {}

double MOSFET::calculateCurrent(double vgs, double vds, double vbs) const {
    return 0.0;
}

double MOSFET::dId_dVgs(double vgs, double vds, double vbs) const {
    return 0.0;
}

double MOSFET::dId_dVds(double vgs, double vds, double vbs) const {
    return 0.0;
}

bool MOSFET::isInSaturation(double vgs, double vds) const {
    return vds >= (vgs - VTO);
}