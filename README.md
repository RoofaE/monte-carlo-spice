# monte-carlo-spice

# 1. Go to the project

## Navigate to project
cd /c/Users/xyz/Desktop/monte-carlo-spice

## Create build directory
mkdir -p build && cd build

## Configure and build
cmake .. -G "MinGW Makefiles"
cmake --build .

# 2. Run

## From build directory
`./bin/mc_spice.exe ../examples/cmos_inverter.sp`

## Run with custom iterations
`./bin/mc_spice.exe ../examples/cmos_inverter.sp 1000`

# 3. Some available test examples

## Inverter (2 transistors)
`./bin/mc_spice.exe ../examples/cmos_inverter.sp 1000`

## Resistor Divider
`./bin/mc_spice.exe ../examples/resistor_divider.sp 1000`

## NAND Gate
`./bin/mc_spice.exe ../examples/nand_gate.sp 1000`

# 3. Screenshot
<img width="489" height="498" alt="Image" src="https://github.com/user-attachments/assets/a60f906f-fbb9-478a-b9ca-f36ead1715cc" />

# 4. Tech Stack
- C++ with MinGW-w64 (GCC)
- Eigen3 for linear algebra
- CMake build

# 5. Todo
- Expand the project with more test cases & make it more realistic
