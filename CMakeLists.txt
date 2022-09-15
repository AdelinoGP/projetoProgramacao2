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

project(TrabalhoTemperatura
		VERSION 1.0.0
		DESCRIPTION "Projeto de Monitoramento de temperatura para a matéria de Programação 2"
		LANGUAGES CXX)
		
add_executable(TrabalhoTemperatura src/TrabalhoTemperatura.cpp
									src/DadoSimulador.cpp
									src/Temperatura.cpp)

target_include_directories(TrabalhoTemperatura PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

