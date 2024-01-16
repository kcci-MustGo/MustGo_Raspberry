cmake_minimum_required(VERSION 3.7.0)
project(MustGo_raspi LANGUAGES C)

# set C compiler
#set(CMAKE_C_COMPILER /Applications/Xcode.app/Contents/Developer/usr/bin/gcc)
set(CMAKE_C_COMPILER gcc)
# set the output folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)
# set the src folder
set(src ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(uuid)
find_package(CURL REQUIRED)
find_package(Threads REQUIRED)

# specify src files and execution file
add_executable(MustGo_raspi ${src}/main.c ${src}/currentPosStreaming.c ${src}/videoStreaming.c ${src}/aboutRequest.c)

target_compile_options(MustGo_raspi PRIVATE -g -Wall)


target_include_directories(MustGo_raspi PRIVATE ${CMAKE_SOURCE_DIR}/hdr ${CURL_INCLUDE_DIRS} ${Threads_INCLUDE_DIRS})
target_link_libraries(MustGo_raspi PRIVATE ${CURL_LIBRARIES} ${Threads_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include (CPack)
