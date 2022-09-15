#include <iostream>
#include <chrono>
#include <windows.h>

#include "ListaEncadeada.h"
#include "DadoSimulador.h"
#include "Temperatura.h"
using namespace std;

int main()
{
	Temperatura t;	// Cria um objeto t da classe Temperatura
	ListaEncadeada<DadoSimulador> listaDeDados;
	t.inicializa(); // Inicializa a simulação
	bool resistorOn = false;
	bool coolerOn = false;
	for (int i = 0; i < 10; ++i)
	{
		double temp =  t.lerTemp();	
		DadoSimulador dado(temp, resistorOn, coolerOn);
		listaDeDados.insereI(dado);
		this_thread::sleep_for(chrono::milliseconds(1000)); // Aguarda
	}
	listaDeDados.imprime();
	return EXIT_SUCCESS;
}
