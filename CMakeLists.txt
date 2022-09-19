cmake_minimum_required(VERSION 3.10)


project(TrabalhoTemperatura
		VERSION 1.0.0
		DESCRIPTION "Projeto de Monitoramento de temperatura para a materia de Programacao 2"
		LANGUAGES CXX)
		
add_executable(TrabalhoTemperatura  "src/TrabalhoTemperatura.cpp"
									"src/Gerenciador.cpp"
									"src/DadoSimulador.cpp"
									"src/Temperatura.cpp"
									"src/ArmazenamentoDeArquivos.cpp"
									"src/Utils.cpp"
									"src/AnalisadorDeDados.cpp"
									"src/InterfaceDeUsuario.cpp")

target_include_directories(TrabalhoTemperatura PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

