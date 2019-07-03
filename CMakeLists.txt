cmake_minimum_required(VERSION 3.9.1)
project(camera)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
add_executable(cam cam.cpp)
target_link_libraries(cam opencv2/imgproc.hpp)
target_link_libraries(cam opencv2/highgui.hpp)
