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
	ListaEncadeada<int> listaDeDados;
	t.inicializa(); // Inicializa a simulação
	for (int i = 0; i < 10; ++i)
	{
		cout << t.lerTemp() << endl;						// Le a temperatura
		this_thread::sleep_for(chrono::milliseconds(1000)); // Aguarda
	}
	return EXIT_SUCCESS;
}
