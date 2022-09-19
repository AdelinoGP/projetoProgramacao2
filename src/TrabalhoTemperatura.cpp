#include <iostream>
#include <windows.h>

#include "ArmazenamentoDeArquivos.h"
#include "ListaEncadeada.h"
#include "DadoSimulador.h"
#include "Temperatura.h"
#include "AnalisadorDeDados.h"

using namespace std;

int main()
{
	Temperatura t;	// Cria um objeto t da classe Temperatura
	t.inicializa(); // Inicializa a simulação

	ArmazenamentoDeArquivos armazenamento;
	AnalisadorDeDados analisador;

	ListaEncadeada<DadoSimulador> listaDeDados /*= armazenamento.PegarListaDoLog()*/;

	double tempMax = 26;
	double tempMin = 24;

	bool controlarTemperatura = true;
	bool resistorOn = false;
	bool coolerOn = false;
	for (int i = 0; i < 10; ++i)
	{
		double temp =  t.lerTemp();

		if (controlarTemperatura && temp > tempMax) {
			coolerOn = true;
			resistorOn = false;
			if (t.enviarComando(2) != 205)
				cout << "Falha ao acionar ventoinha" << endl;
			t.enviarComando(5);
		}

		if (controlarTemperatura && temp < tempMin) {
			coolerOn = false;
			resistorOn = true;
			//Todo: Transformar em função com recursão
			if (t.enviarComando(4) != 205)
				cout << "Falha ao acionar resistor" << endl;
			t.enviarComando(3);
		}

		DadoSimulador dado(temp, resistorOn, coolerOn);
		listaDeDados.insereF(dado);
		Sleep(1);
	}
	analisador.AnalisarLista(&listaDeDados);
	cout << analisador;
	listaDeDados.imprime();
	armazenamento.SalvarListaEmLog(&listaDeDados);
	return EXIT_SUCCESS;
}
