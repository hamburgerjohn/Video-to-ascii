cmake_minimum_required(VERSION 3.4)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -O3")

project(Video-to-ascii)

add_executable(
    test
    ../src/test.cpp
)
set_target_properties(test PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../${CMAKE_BINARY_DIRECTORY}/tests")

target_link_libraries(test PRIVATE 
-lopencv_core
-lopencv_imgproc
-lopencv_highgui
-lopencv_ml
-lopencv_video
-lopencv_features2d
-lopencv_calib3d
-lopencv_objdetect
-lopencv_flann
-lopencv_imgcodecs
-lopencv_dnn
-lopencv_gapi
-lopencv_photo
-lopencv_videoio
-lopencv_stitching
)