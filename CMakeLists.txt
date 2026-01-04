cmake_minimum_required(VERSION 3.16)

project(digital-images-processing-course LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

# hello
add_executable(hello
  hello/main.cpp
)
target_link_libraries(hello PRIVATE ${OpenCV_LIBS})
set_target_properties(hello PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/hello")


# pixels
add_executable(pixels
  pixels/main.cpp
)
target_link_libraries(pixels PRIVATE ${OpenCV_LIBS})
set_target_properties(pixels PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/pixels")

# labeling
add_executable(labeling
  labeling/main.cpp
)
target_link_libraries(labeling PRIVATE ${OpenCV_LIBS})
set_target_properties(labeling PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/labeling")

install(TARGETS hello labeling pixels)