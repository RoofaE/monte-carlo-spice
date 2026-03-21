* CMOS Inverter Test Circuit
* Simple 2-transistor inverter

* Power supply
VDD vdd 0 DC 1.8V

* Input voltage
VIN in 0 DC 0.9V

* NMOS transistor (pulldown)
M1 out in 0 0 NMOS W=2u L=180n

* PMOS transistor (pullup)
M2 out in vdd vdd PMOS W=4u L=180n

* MOSFET models
.model NMOS NMOS (VTO=0.4 KP=200u)
.model PMOS PMOS (VTO=-0.4 KP=100u)

.end