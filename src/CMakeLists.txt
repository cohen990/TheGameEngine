set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(SOURCE_FILES TGEengine.cpp TGEengine.hpp TGEgame.cpp TGEgame.hpp TGEwindowManager.cpp TGEwindowManager.hpp)

add_subdirectory(IO)
add_subdirectory(Objects)
add_subdirectory(Shaders)
add_library(TGE ${SOURCE_FILES})

target_link_libraries(TGE PUBLIC IO)
target_link_libraries(TGE PUBLIC Objects)
target_link_libraries(TGE PUBLIC Shaders)

target_include_directories(TGE PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/MathFunctions"
)

