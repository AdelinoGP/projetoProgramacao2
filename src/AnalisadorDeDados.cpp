#include "AnalisadorDeDados.h"

#include "DadoSimulador.h"
#include "ListaEncadeada.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

AnalisadorDeDados::AnalisadorDeDados()
{
	listarTemperaturas = ListarTemperaturas(&listaTemperatura);
};

AnalisadorDeDados::AnalisadorDeDados(int limMaximo, int limMinimo)
{
	this->limMaximo = limMaximo;
	this->limMinimo = limMinimo;
};

void AnalisadorDeDados::AnalisarLista(ListaEncadeada<DadoSimulador>* lista)
{
	listaTemperatura.limpa();
	lista->paraCada(listarTemperaturas);
	listaTemperatura.sort();

	tempMaxima = listaTemperatura.ultimo();
	tempMinima = listaTemperatura.primeiro();

	media = listaTemperatura.acharMedia();
	mediana = listaTemperatura.acharMediana(true);

	vezesAcimaMaximo = 0;
	vezesAcimaMinimo = 0;
	listaTemperatura.paraCada([this](double* valor) {
		if (*valor > limMaximo) vezesAcimaMaximo++;
	});
	listaTemperatura.paraCada([this](double* valor) {
		if (*valor < limMinimo) vezesAcimaMinimo++;
	});
}

ostream& operator<<(ostream& os, const AnalisadorDeDados& analisador){
	os << "Temperatura Maxima: " << analisador.tempMaxima << " Temperatura Minima: " << analisador.tempMinima << endl
		<< "Media: " << analisador.media << " Mediana: " << analisador.mediana << endl;
	if (analisador.limMaximo != 0)
		os << "Vezes Acima do Limite Maximo: " << analisador.vezesAcimaMaximo << "Vezes Acima do Limite Minimo: " << analisador.vezesAcimaMinimo << endl;
	return os;
};


