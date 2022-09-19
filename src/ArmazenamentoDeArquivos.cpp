#include "ArmazenamentoDeArquivos.h"
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "DadoSimulador.h"
#include "ListaEncadeada.h"
#include "Utils.h"

ArmazenamentoDeArquivos::ArmazenamentoDeArquivos()
{
	salvarLogDeDado = SalvarLogDeDado(&arquivoDeLog);
}

ListaEncadeada<DadoSimulador> ArmazenamentoDeArquivos::PegarListaDoLog()
{
	arquivoDeLog.open(FILE_NAME, ios::in);
	ListaEncadeada<DadoSimulador> listaDeDados;
	if (arquivoDeLog.is_open())
	{
		string stringDataTempo;
		string stringTemperatura;
		string stringResistor;
		string stringCooler;

		while (getline(arquivoDeLog, stringDataTempo, SEPARADOR)) {
			getline(arquivoDeLog, stringTemperatura, SEPARADOR);
			getline(arquivoDeLog, stringResistor, SEPARADOR);
			getline(arquivoDeLog, stringCooler, '\n');
			time_t dataTempo = StringParaTempo(stringDataTempo);
			double temperatura = stod(stringTemperatura);
			bool resistor = stoi(stringResistor);
			bool cooler = stoi(stringCooler);
			DadoSimulador* dadoAtual = new DadoSimulador(temperatura, resistor, cooler, dataTempo);
			listaDeDados.insereF(*dadoAtual);
		}
	}
	arquivoDeLog.close();
	return listaDeDados;
}


void ArmazenamentoDeArquivos::SalvarListaEmLog(ListaEncadeada<DadoSimulador>* lista)
{
	arquivoDeLog.open(FILE_NAME, ios::out | ios::trunc);
	if (arquivoDeLog.is_open())
	{
		lista->paraCada(salvarLogDeDado);
	}
	arquivoDeLog.close();
}



