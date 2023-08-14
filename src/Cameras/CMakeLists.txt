cmake_minimum_required(VERSION "3.22.1")

set(SOURCE_FILES TGEcamera.cpp TGEcamera.hpp TGEperspectiveCamera.cpp TGEperspectiveCamera.hpp)

add_library(Cameras ${SOURCE_FILES})