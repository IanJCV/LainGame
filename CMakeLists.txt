# CMakeList.txt : CMake project for LainGame, include source and define
# project specific logic here.

cmake_minimum_required (VERSION 3.8)

project (Lain LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED YES)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(FLAGS -O3 -Wall -Wextra -Wpedantic)

set(CFLAGS ${FLAGS})
set(CXXFLAGS ${FLAGS})

add_definitions(Lain
  -DTESTING
  -DVERSION=\"0.0.0\"
)

# Add source to this project's executable.
add_executable(Lain
  ${CMAKE_SOURCE_DIR}/src/main.cpp
  ${CMAKE_SOURCE_DIR}/src/game.cpp
)

target_link_libraries(Lain
  -lpthread
  -lglfw
  -lopenal
)

target_include_directories(Lain PRIVATE
  ${CMAKE_SOURCE_DIR}/src
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/dependencies
)

# TODO: Add tests and install targets if needed

