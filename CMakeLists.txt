cmake_minimum_required(VERSION 3.27.7)
project(calculator_task CXX)

# Print variables for debugging
include(CMakePrintHelpers)
cmake_print_variables(PROJECT_SOURCE_DIR)
cmake_print_variables(CMAKE_SOURCE_DIR)

# Global C++ Standard for this library
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

###########
## Build ##
###########

# Create the static library target
add_library(calculator STATIC
    ${PROJECT_SOURCE_DIR}/src/calculator.cpp
    ${PROJECT_SOURCE_DIR}/src/operation.cpp
    ${PROJECT_SOURCE_DIR}/src/string_to_number.cpp
)

# Include directories for the library
target_include_directories(calculator
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
    # Include other directories if necessary
)

# Create an executable target for the main application
add_executable(CalculatorApp ${PROJECT_SOURCE_DIR}/src/main.cpp)

# Link the calculator library with the CalculatorApp executable
target_link_libraries(CalculatorApp
    PRIVATE
        calculator
)

#############
## Install ##
#############

# Install header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include
    FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
)

#############
## Testing ##
#############

# Include CTest for enabling testing
include(CTest)

# Testing logic goes here, if applicable
# Add test executable, link libraries, and discover tests

