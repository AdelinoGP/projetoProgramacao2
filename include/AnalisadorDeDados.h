#ifndef ANALISADOR_H_
#define ANALISADOR_H_

#include "DadoSimulador.h"
#include "ListaEncadeada.h"
#include <iostream>

class ListarTemperaturas
{
public:
	ListaEncadeada<double> *lista;
	ListarTemperaturas() : lista(){};
	ListarTemperaturas(ListaEncadeada<double> *val) : lista(val){};
	void operator()(DadoSimulador *dado)
	{
		double temp = dado->getTemperatura();
		lista->insereF(temp);
	};
};

class AnalisadorDeDados
{
private:
	ListarTemperaturas listarTemperaturas;
	ListaEncadeada<double> listaTemperatura;

public:
	double tempMaxima = 0;
	double tempMinima = 0;
	double media = 0;
	double mediana = 0;
	double limMaximo = 0;
	double limMinimo = 0;
	int vezesAcimaMaximo = 0;
	int vezesAcimaMinimo = 0;

	AnalisadorDeDados();
	AnalisadorDeDados(int limMaximo, int limMinimo);
	void AnalisarLista(ListaEncadeada<DadoSimulador> *lista);
	friend ostream &operator<<(ostream &os, const AnalisadorDeDados &analisador);
};

#endif
