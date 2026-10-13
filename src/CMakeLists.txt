project(MathLibExample)

# Prefer target-based include directories and link libraries.
# Use CMake variables relative to the source tree for portability.

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
add_executable(MathLibExample main.cpp)

add_subdirectory(math_lib)

# Link the executable with the math library
target_link_libraries(MathLibExample PRIVATE math_library)
