# CMakeList.txt : CMake project for GOAP, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("GOAP")
project ("UtilAI")

# Add source to this project's executable.
#add_executable (GOAP "main.cpp" "headers/World.h" "headers/Action Planning/Action.h" "headers/Action Planning/Planner.h" "headers/Action Planning/Precondition.h" "headers/Resource.h" "src/Action Planning/Planner.cpp" "headers/Utils.h" "src/Utils.cpp" )

add_executable( GOAP "headers/Action.h" src/Action.cpp main.cpp headers/States/PlayerState.h src/States/PlayerState.cpp headers/States/WorldState.h headers/Enums/Preconditions.h headers/Enums/Resources.h headers/Enums/Rules.h headers/Utils.h src/Utils.cpp)
#UtilityAI
add_executable( UtilAI "UtilityAI/main.cpp" "UtilityAI/headers/states/WorldState.h" "UtilityAI/src/states/WorldState.cpp" "UtilityAI/src/Action.cpp" "UtilityAI/headers/Action.h" "UtilityAI/headers/states/AgentState.h" "UtilityAI/src/states/AgentState.cpp" "UtilityAI/src/states/WorldState.cpp" "UtilityAI/headers/actions/ProduceWood.h" "UtilityAI/headers/actions/AllActions.h" "UtilityAI/headers/Utils.h" "UtilityAI/headers/actions/ActionMakeVillager.h" "UtilityAI/src/actions/ActionMakeVillager.cpp" "UtilityAI/headers/actions/ActionMakeLumberjack.h" "UtilityAI/src/actions/ActionMakeLumberjack.cpp" "UtilityAI/headers/actions/AllActions.h")