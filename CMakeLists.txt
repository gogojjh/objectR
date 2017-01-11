project(objectR)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable( ${PROJECT_NAME} src/main.cpp)

set( CMAKE_BUILD_TYPE Release )
set( CMAKE_CXX_FLAGS "-std=c++11 -Wall -O2 -march=native" )

#aux_source_directory(. dir_srcs) #aux_source_directory(<dir> <variable>)

find_package( OpenCV REQUIRED )

include_directories( ${OPENCV_INCLUDE_DIR} ${PROJECT_SOURCE_DIR}/include)

target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )





