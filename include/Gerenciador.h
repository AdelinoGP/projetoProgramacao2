#ifndef GERENCIADOR_H_
#define GERENCIADOR_H_

#include "InterfaceDeUsuario.h"
#include "ArmazenamentoDeArquivos.h"
#include "ListaEncadeada.h"
#include "DadoSimulador.h"
#include "Temperatura.h"
#include "AnalisadorDeDados.h"



class Gerenciador
{
private:
	Temperatura t; // Interface com o simulador

	ArmazenamentoDeArquivos armazenamento; // Classe de armazenamento de dados
	AnalisadorDeDados analisador;		   // Classe de Analise de Dados
	InterfaceDeUsuario uInterface;

	ListaEncadeada<DadoSimulador> listaDeDados; //  Lista de dados da leitura atual

	double limiarMax = 99; // Limiar maximo
	double limiarMin = 0;  // Limiar minimo

	unsigned int leituras = 10;
	unsigned int intervalo = 200;

	bool resistorOn = false; // Estado do Resistor e Cooler, default falso
	bool coolerOn = false;

	void RealizarLeitura(unsigned int quantidade, unsigned int intervalo);
	void ImprimirDados();
	void LimparDados();
	void AnalisarDados();
	void CarregarDadosArmazenados();
	void SalvarDados();
	void MudarLimiarMax(double limiarNovo);
	void MudarLimiarMin(double limiarNovo);
	void ExecutarComando(unsigned int comando, unsigned int tentativas);

public:
	Gerenciador() :uInterface(this) {};
	void Inicializa();
	void LoopPrincipal();
	void SelecionarOpcao(unsigned int menu, unsigned int subMenu);
};

#endif
