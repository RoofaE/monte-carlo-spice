cmake_minimum_required(VERSION 3.15)
project(MonteCarloSPICE VERSION 1.0 LANGUAGES CXX)

# C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Eigen3
find_package(Eigen3 CONFIG REQUIRED)

# Find OpenMP (for parallelization)
find_package(OpenMP)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/main.cpp
    src/parser.cpp
    src/circuit.cpp
    src/mosfet.cpp
    src/solver.cpp
    src/monte_carlo.cpp
    src/statistics.cpp
)

# Create executable
add_executable(mc_spice ${SOURCES})

# Link libraries
target_link_libraries(mc_spice PRIVATE Eigen3::Eigen)

# Link OpenMP if available
if(OpenMP_CXX_FOUND)
    target_link_libraries(mc_spice PRIVATE OpenMP::OpenMP_CXX)
endif()

# Output directory
set_target_properties(mc_spice PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)