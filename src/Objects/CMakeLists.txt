cmake_minimum_required(VERSION "3.22.1")

set(SOURCE_FILES TGEmesh.cpp TGEmesh.hpp TGEgameObject.cpp TGEgameObject.hpp TGEroot.cpp TGEroot.hpp)

add_library(Objects ${SOURCE_FILES})