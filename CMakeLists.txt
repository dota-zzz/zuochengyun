cmake_minimum_required(VERSION 3.5) # CMake install : https://cmake.org/download/
project(zuo LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
aux_source_directory(./src srcs)



add_executable(${PROJECT_NAME}
    ${srcs} 
 ) 
