cmake_minimum_required(VERSION 3.16)

project(exercicios LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

# regioes
add_executable(regions
  regions.cpp
)
target_link_libraries(regions PRIVATE ${OpenCV_LIBS})
set_target_properties(regions PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# trocaregioes
add_executable(trocaregioes
  trocaregioes.cpp
)
target_link_libraries(trocaregioes PRIVATE ${OpenCV_LIBS})
set_target_properties(trocaregioes PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

install(TARGETS regions trocaregioes)