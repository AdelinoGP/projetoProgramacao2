cmake_minimum_required(VERSION 3.10)

project(TrabalhoTemperatura)

include_directories(TrabalhoTemperatura PUBLIC "src")
add_library(SimuladorTermico "src/temperatura.cpp")

add_executable(TrabalhoTemperatura "src/TrabalhoTemperatura.cpp")
target_link_libraries(TrabalhoTemperatura PUBLIC SimuladorTermico)
