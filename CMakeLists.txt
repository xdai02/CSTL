cmake_minimum_required(VERSION 3.10)
project(COOP C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Set compilation flags
add_compile_options(-O2 -pedantic -UNDEBUG)
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall)
endif()

# Set up directories
set(INC_DIR "${CMAKE_SOURCE_DIR}/include")
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/test")
set(BIN_DIR "${CMAKE_SOURCE_DIR}/bin")

# Create bin directory
file(MAKE_DIRECTORY ${BIN_DIR})

# Set output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

# Build the coop library
file(GLOB_RECURSE COOP_SOURCES "${SRC_DIR}/*.c")
add_library(coop OBJECT ${COOP_SOURCES})
target_include_directories(coop PUBLIC ${INC_DIR})

# Build the static and shared library
add_library(coop_static STATIC $<TARGET_OBJECTS:coop>)
add_library(coop_shared SHARED $<TARGET_OBJECTS:coop>)

set_target_properties(
    coop_static PROPERTIES
    OUTPUT_NAME coop
    LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIR}
)
set_target_properties(
    coop_shared PROPERTIES
    OUTPUT_NAME coop
    LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR}
)

# Build the test executable
file(GLOB_RECURSE TEST_SOURCES "${TEST_DIR}/*.c")
add_executable(test_coop ${TEST_SOURCES})
target_link_libraries(test_coop PRIVATE coop)
target_include_directories(test_coop PRIVATE ${INC_DIR} ${TEST_DIR})

# Clean up CMake generated files
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_BINARY_DIR}/CMakeFiles"
    COMMAND ${CMAKE_COMMAND} -E remove "${CMAKE_BINARY_DIR}/CMakeCache.txt"
    COMMAND ${CMAKE_COMMAND} -E remove "${CMAKE_BINARY_DIR}/cmake_install.cmake"
    COMMAND ${CMAKE_COMMAND} -E remove "${CMAKE_BINARY_DIR}/cMakeCComppilerId"
    COMMAND ${CMAKE_COMMAND} -E remove "${CMAKE_BINARY_DIR}/Makefile"
    COMMAND ${CMAKE_COMMAND} -E remove "${CMAKE_BINARY_DIR}/libcoop.a"
    COMMAND ${CMAKE_COMMAND} -E remove "${CMAKE_BINARY_DIR}/libcoop.so"
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_BINARY_DIR}/build"
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_BINARY_DIR}/bin"
    COMMENT "Cleaning up CMake generated files"
)
