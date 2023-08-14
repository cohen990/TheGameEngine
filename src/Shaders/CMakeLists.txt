cmake_minimum_required(VERSION "3.22.1")

set(SOURCE_FILES TGEshader.cpp TGEshader.hpp TGEbuiltInShaders.cpp TGEbuiltInShaders.hpp TGEloadShaders.cpp TGEloadShaders.hpp)

add_library(Shaders ${SOURCE_FILES})

target_link_libraries(Shaders PUBLIC IO)
