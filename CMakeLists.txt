# CMakeList.txt : CMake project for LainGame, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("LainGame")

# Add source to this project's executable.
add_executable (LainGame "LainGame.cpp" "LainGame.h" "file_systems/file_packer.h" "file_systems/file_packer.cpp")

# TODO: Add tests and install targets if needed