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

# video-tons-cinza
add_executable(video-tons-cinza
  video-tons-cinza.cpp
)
target_link_libraries(video-tons-cinza PRIVATE ${OpenCV_LIBS})
set_target_properties(video-tons-cinza PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# video-negativo
add_executable(video-negativo
  video-negativo.cpp
)
target_link_libraries(video-negativo PRIVATE ${OpenCV_LIBS})
set_target_properties(video-negativo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# filestorage-senoide-horizontal
add_executable(filestorage-senoides
  filestorage-senoides/main.cpp
)
target_link_libraries(filestorage-senoides PRIVATE ${OpenCV_LIBS})
set_target_properties(filestorage-senoides PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/filestorage-senoides)

install(TARGETS regions trocaregioes video-tons-cinza video-negativo filestorage-senoides)