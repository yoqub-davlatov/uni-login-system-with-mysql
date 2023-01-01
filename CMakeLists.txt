cmake_minimum_required(VERSION 3.25)

project(myProject)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp)

target_link_libraries(${PROJECT_NAME} mysql)
