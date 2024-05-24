cmake_minimum_required(VERSION 3.16)

project(nuttx_conan)

list(APPEND CMAKE_FIND_ROOT_PATH ${CMAKE_BINARY_DIR})

include(build/nuttx/scripts/toolchain.cmake)

find_package(Eigen3)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cc
)

add_executable(nuttx_conan ${SOURCES})
target_link_libraries(nuttx_conan Eigen3::Eigen)
