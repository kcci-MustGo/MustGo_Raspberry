cmake_minimum_required(VERSION 3.7.0)
project(MustGo_raspi LANGUAGES C)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)
set(src ${CMAKE_SOURCE_DIR}/src)

find_package(CURL REQUIRED)
find_package(Boost REQUIRED)
add_executable(MustGo_raspi ${src}/main.c ${src}/urrentPosStreaming.c ${src}/videoStreaming.c)

target_compile_options(MustGo_raspi PRIVATE -g -Wall)

target_include_directories(MustGo_raspi PRIVATE ${CMAKE_SOURCE_DIR}/hdr ${CURL_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
target_link_libraries(MustGo_raspi PRIVATE ${CURL_LIBRARIES} ${Boost_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include (CPack)
