cmake_minimum_required(VERSION 3.10)

include(FetchContent)

FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v3.0.0
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

project(TrabalhoTemperatura)

include_directories(TrabalhoTemperatura PUBLIC "src")
add_library(Temperatura "src/Temperatura.cpp")
add_library(Elemento "src/Elemento.cpp")
add_library(ListaEncadeada "src/ListaEncadeada.cpp")
add_library(DadoSimulador "src/DadoSimulador.cpp")

add_executable(TrabalhoTemperatura "src/TrabalhoTemperatura.cpp")
target_link_libraries(TrabalhoTemperatura PUBLIC Elemento)
target_link_libraries(TrabalhoTemperatura PUBLIC ListaEncadeada)
target_link_libraries(TrabalhoTemperatura PUBLIC DadoSimulador)
target_link_libraries(TrabalhoTemperatura PUBLIC Temperatura)

