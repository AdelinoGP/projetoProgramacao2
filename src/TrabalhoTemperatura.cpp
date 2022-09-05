#include <iostream>
#include <chrono>
#include<windows.h>

#include "listaEstatica.h"
#include "Temperatura.h"
using namespace std;

int main() {
	Temperatura t; //Cria um objeto t da classe Temperatura
	t.inicializa(); // Inicializa a simula��o
	cout << t.enviarComando(RES_ON) << endl; // Aciona o resistor
	for (int i = 0; i < 10; ++i) {
		cout << t.lerTemp() << endl; // L� a temperatura
		this_thread::sleep_for(chrono::milliseconds(1000)); // Aguarda
	}
	return EXIT_SUCCESS;
}
