#ifndef ARMAZENAMENTO_H_
#define ARMAZENAMENTO_H_

#define FILE_NAME "logSimulador.csv"

#include <fstream>
#include "DadoSimulador.h"
#include "ListaEncadeada.h"

using namespace std;


class SalvarLogDeDado {
private:
	fstream* arquivoDeLog;
public:
	SalvarLogDeDado() : arquivoDeLog() {};
	SalvarLogDeDado(fstream* val) : arquivoDeLog(val) {};
	void operator()(DadoSimulador* dado) {
		*arquivoDeLog << dado->paraCSV() << "\n";
	};
};

class ArmazenamentoDeArquivos
{
	private:
		fstream arquivoDeLog;
		SalvarLogDeDado salvarLogDeDado;
	public:
		ArmazenamentoDeArquivos();
		ListaEncadeada<DadoSimulador> PegarListaDoLog();
		void SalvarListaEmLog(ListaEncadeada<DadoSimulador>* lista);


};


#endif
