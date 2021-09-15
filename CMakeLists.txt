# CMakeList.txt : CMake project for GOAP, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("GOAP")

# Add source to this project's executable.
#add_executable (GOAP "main.cpp" "headers/World.h" "headers/Action Planning/Action.h" "headers/Action Planning/Planner.h" "headers/Action Planning/Precondition.h" "headers/Resource.h" "src/Action Planning/Planner.cpp" "headers/Utils.h" "src/Utils.cpp" )
add_executable( GOAP "src/MinifiedGOAPTest.cpp" )
