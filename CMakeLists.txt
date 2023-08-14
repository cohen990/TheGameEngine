cmake_minimum_required(VERSION "3.22.1")

project(TGESample)

set(SOURCE_FILES tester-app/mygame.cpp)

add_subdirectory(src)

add_executable(sample-game ${SOURCE_FILES})

target_link_libraries(sample-game PUBLIC TGE)
target_link_libraries(sample-game PUBLIC GLEW)
target_link_libraries(sample-game PUBLIC glfw)
target_link_libraries(sample-game PUBLIC GL)

#target_include_directories(
#        "${PROJECT_BINARY_DIR}"
#        "${PROJECT_BINARY_DIR}/src"
#)