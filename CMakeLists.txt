project(objectR)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable( ${PROJECT_NAME} src/main.cpp)

set( CMAKE_BUILD_TYPE Release )
set( CMAKE_CXX_FLAGS "-std=c++11 -Wall -O2 -march=native" )
set( objectR_SOURCE_FILES 
	${PROJECT_SOURCE_DIR}/src/DetectBlueCircle.cpp
	${PROJECT_SOURCE_DIR}/src/DetectMarker.cpp
	${PROJECT_SOURCE_DIR}/src/setting.cpp)
set ( apriltags_SOURCE_DIR
	${PROJECT_SOURCE_DIR}/../apriltags)

#aux_source_directory(. dir_srcs) #aux_source_directory(<dir> <variable>)

find_package( OpenCV REQUIRED )
find_package( OpenCV 2 REQUIRED )

include_directories( ${OPENCV_INCLUDE_DIR} 
	${PROJECT_SOURCE_DIR}/include 
	${apriltags_SOURCE_DIR}
	"/usr/include/eigen3")

#封装头文件
add_library(libobjectR ${objectR_SOURCE_FILES})

#添加需要的库的路径
link_directories( ${apriltags_SOURCE_DIR}/build/lib )

target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} libobjectR apriltags )





