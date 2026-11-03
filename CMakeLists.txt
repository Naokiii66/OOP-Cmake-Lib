cmake_minimum_required(VERSION 3.10)
project(AtmProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/utf-8)
endif()

add_subdirectory(lib)

add_executable(atm_app src/main.cpp)

target_link_libraries(atm_app PRIVATE atm_lib)
