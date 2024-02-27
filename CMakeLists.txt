cmake_minimum_required(VERSION 3.12)

function(dump_cmake_variables)
    get_cmake_property(_variableNames VARIABLES)
    list (SORT _variableNames)
    foreach (_variableName ${_variableNames})
        if (ARGV0)
            unset(MATCHED)
            string(REGEX MATCH ${ARGV0} MATCHED ${_variableName})
            if (NOT MATCHED)
                continue()
            endif()
        endif()
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
endfunction()

project(SpriteSheet VERSION 1.0.0 LANGUAGES CXX)

include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)
FetchContent_Declare(jsoncpp GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp/ GIT_TAG master)
FetchContent_MakeAvailable(jsoncpp)

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

# cmake -DCMAKE_BUILD_TYPE=debug -DBUILD_STATIC_LIBS=ON -DBUILD_SHARED_LIBS=OFF -DARCHIVE_INSTALL_DIR=. -G "Unix Makefiles" ../..
# get_target_property(JSON_INC_PATH jsoncpp_lib INTERFACE_INCLUDE_DIRECTORIES)

include_directories(${JSON_INC_PATH})

# target_link_libraries(${PROJECT_NAME} jsoncpp_lib)

target_include_directories(
    SpriteSheet
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/ext/imgui
        ${jsoncpp_SOURCE_DIR}/include
)

# dump_cmake_variables()