#pragma once

// Shichman-Hodges MOSFET model
class MOSFET {
public:
    enum Type { NMOS, PMOS };
    
    MOSFET(Type type, double width, double length, double vto, double kp);
    
    // Calculate drain current given terminal voltages
    double calculateCurrent(double vgs, double vds, double vbs = 0.0) const;
    
    // Calculate transconductances (derivatives for Newton-Raphson)
    double dId_dVgs(double vgs, double vds, double vbs = 0.0) const;
    double dId_dVds(double vgs, double vds, double vbs = 0.0) const;

private:
    Type type;
    double W;      // Width
    double L;      // Length
    double VTO;    // Threshold voltage
    double KP;     // Transconductance parameter
    
    bool isInSaturation(double vgs, double vds) const;
};