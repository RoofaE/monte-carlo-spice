* Simple Diode Circuit
* VIN -- R1 -- Anode-Diode-Cathode -- GND

VIN 1 0 DC 5.0V
R1 1 2 1000
D1 2 0 DIODE

.model DIODE D (IS=1e-14)

.end