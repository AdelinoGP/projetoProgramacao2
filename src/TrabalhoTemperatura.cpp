#include <iostream>
#include <chrono>
#include <windows.h>

#include "listaEstatica.h"
#include "Temperatura.h"
using namespace std;

int main()
{
	ListaBasica<int> l(40000);
	Temperatura t;	// Cria um objeto t da classe Temperatura
	t.inicializa(); // Inicializa a simulação
	for (int i = 0; i < 10; ++i)
	{
		cout << t.lerTemp() << endl;						// L� a temperatura
		this_thread::sleep_for(chrono::milliseconds(1000)); // Aguarda
	}
	return EXIT_SUCCESS;
}
