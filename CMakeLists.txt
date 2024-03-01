cmake_minimum_required(VERSION 3.12)
project(SpriteSheet VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
include("cmake/dump_cmake_variables.cmake")

include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_subdirectory("ext/jsoncpp")

add_library(
    SpriteSheet
    SHARED
    include/Constants.hpp
    include/libSpriteSheet.hpp
    include/Sprite.hpp
    include/ImageUtils.hpp
    include/DisplayedSprite.hpp
    include/AnimationFrame.hpp
    include/Animation.hpp
    include/SpriteSheet.hpp
#    include/SpriteSheetManager.hpp

    ext/imgui/imgui.cpp
    ext/imgui/imgui_demo.cpp
    ext/imgui/imgui_draw.cpp
    ext/imgui/imgui_tables.cpp
    ext/imgui/imgui_widgets.cpp
    ext/imgui/backends/imgui_impl_glfw.cpp
    ext/imgui/backends/imgui_impl_opengl3.cpp

    src/Sprite.cpp
    src/SpriteSheet.cpp
    src/Animation.cpp
    src/DisplayedSprite.cpp
#    src/SpriteSheetManager.cpp
)


include_directories(${JSON_INC_PATH})
target_link_libraries(SpriteSheet PUBLIC jsoncpp_static)

target_include_directories(
    SpriteSheet
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/ext/imgui
        ${jsoncpp_SOURCE_DIR}/include
)

# dump_cmake_variables()