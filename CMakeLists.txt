cmake_minimum_required(VERSION 3.10)
project(lvgl)

set(CMAKE_C_STANDARD 99)#C99 # lvgl officially support C99 and above
set(CMAKE_CXX_STANDARD 17)#C17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(lvgl)
target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR})

add_executable(main main.cpp mouse_cursor_icon.c)

include(${CMAKE_CURRENT_LIST_DIR}/lvgl/tests/FindLibDRM.cmake)
include_directories(${Libdrm_INCLUDE_DIRS})
target_include_directories(lvgl PUBLIC ${Libdrm_INCLUDE_DIRS})

find_package(SDL2)
find_package(SDL2_image)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

target_link_libraries(main lvgl lvgl::examples lvgl::demos lvgl::thorvg ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${Libdrm_LIBRARIES} m pthread)
add_custom_target (run COMMAND ${EXECUTABLE_OUTPUT_PATH}/main DEPENDS main)

# 添加custom/*.c 和 general/*.c，递归添加
file(GLOB_RECURSE CUSTOM_SOURCES custom/*.c)
file(GLOB_RECURSE GENERAL_SOURCES generated/*.c)
target_sources(main PRIVATE ${CUSTOM_SOURCES} ${GENERAL_SOURCES})

target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/custom)
target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/generated)