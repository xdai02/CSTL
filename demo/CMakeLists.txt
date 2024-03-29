cmake_minimum_required(VERSION 3.10)
project(DEMO C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Set compilation flags
add_compile_options(-O2 -pedantic)
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall)
endif()

# Set up directories
set(INC_DIR "${CMAKE_SOURCE_DIR}/../include")
set(SRC_DIR "${CMAKE_SOURCE_DIR}/../src")
set(BIN_DIR "${CMAKE_SOURCE_DIR}/bin")

# Create bin directory
file(MAKE_DIRECTORY ${BIN_DIR})

# Set output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

# Build the CSTL library
file(GLOB_RECURSE CSTL_SOURCES "${SRC_DIR}/*.c")
add_library(cstl OBJECT ${CSTL_SOURCES})
target_include_directories(cstl PUBLIC ${INC_DIR})

# Get all .c files in the 'demo' directory
file(GLOB_RECURSE DEMO_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

# Build the demo executables
foreach(demo_src ${DEMO_SOURCES})
    # Get the filename without extension
    get_filename_component(demo_name ${demo_src} NAME_WE)
    
    # Create an executable for each .c file in the 'demo' directory
    add_executable(${demo_name} ${demo_src} $<TARGET_OBJECTS:cstl>)
    target_include_directories(${demo_name} PRIVATE ${INC_DIR})
endforeach()

# Clean up CMake generated files
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_BINARY_DIR}/CMakeFiles"
    COMMAND ${CMAKE_COMMAND} -E remove "${CMAKE_BINARY_DIR}/CMakeCache.txt"
    COMMAND ${CMAKE_COMMAND} -E remove "${CMAKE_BINARY_DIR}/cmake_install.cmake"
    COMMAND ${CMAKE_COMMAND} -E remove "${CMAKE_BINARY_DIR}/Makefile"
    COMMAND ${CMAKE_COMMAND} -E remove "${CMAKE_BINARY_DIR}/CMakeCCompilerId"
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_BINARY_DIR}/bin"
    COMMENT "Cleaning up CMake generated files"
)
