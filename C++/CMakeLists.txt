cmake_minimum_required(VERSION 3.10)
project(interview CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB LEETCODE_SOURCES "leetcode/*.cpp")
file(GLOB DATA_STRUCTURE_SOURCES "data_structures/*.cpp")

list(APPEND ALL_SOURCES ${LEETCODE_SOURCES} ${DATA_STRUCTURE_SOURCES})

include_directories(leetcode data_structures)


foreach(SOURCE_FILE ${ALL_SOURCES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE})
    message(STATUS "Created executable '${EXECUTABLE_NAME}'")
endforeach()