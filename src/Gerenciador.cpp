#include "Gerenciador.h"

#include "ArmazenamentoDeArquivos.h"
#include "ListaEncadeada.h"
#include "DadoSimulador.h"
#include "Temperatura.h"
#include "AnalisadorDeDados.h"
#include "InterfaceDeUsuario.h"

#include <iostream>
#include <windows.h>

void Gerenciador::Inicializa()
{
	t.inicializa();
	uInterface.exibirIntro();
}

void Gerenciador::LoopPrincipal()
{
	uInterface.exibirMenu();
}

void Gerenciador::RealizarLeitura(unsigned int quantidade, unsigned int intervalo)
{
	cout << "Realizando leituras por favor aguarde..." << endl;
	for (unsigned int i = 0; i < quantidade; ++i)
	{
		double temp = t.lerTemp();

		if (temp > limiarMax)
		{
			resistorOn = false;
			coolerOn = true;

			ExecutarComando(RES_OFF, 2); // Desliga Resistor
			ExecutarComando(VENT_ON, 2); // Aciona cooler
		}

		if (temp < limiarMin)
		{
			resistorOn = true;
			coolerOn = false;

			ExecutarComando(RES_ON, 2);	  // Aciona resistor
			ExecutarComando(VENT_OFF, 2); // Desliga cooler
		}

		DadoSimulador dado(temp, resistorOn, coolerOn);
		listaDeDados.insereF(dado);
		Sleep(intervalo);
	}
}

void Gerenciador::ImprimirDados()
{
	listaDeDados.imprime();
}

void Gerenciador::LimparDados()
{
	listaDeDados.limpa();
}

void Gerenciador::AnalisarDados()
{
	analisador.AnalisarLista(&listaDeDados);
	cout << analisador;
}

void Gerenciador::CarregarDadosArmazenados()
{
	listaDeDados.limpa();
	listaDeDados = armazenamento.PegarListaDoLog();
}

void Gerenciador::SalvarDados()
{
	armazenamento.SalvarListaEmLog(&listaDeDados);
}

void Gerenciador::MudarLimiarMax(double limiarNovo)
{
	limiarMax = limiarNovo;
}

void Gerenciador::MudarLimiarMin(double limiarNovo)
{
	limiarMin = limiarNovo;
}

void Gerenciador::ExecutarComando(unsigned int comando, unsigned int tentativas)
{
	if (tentativas == 0)
		cout << "Tentou executar o comando " << comando << " sem sucesso" << endl;
	else if (t.enviarComando(comando) != 200 + comando)
	{
		cout << "Falha ao executar comando " << comando << ", tentando novamente" << endl;
		ExecutarComando(comando, tentativas - 1);
	}
}

void Gerenciador::SelecionarOpcao(unsigned int menu, unsigned int subMenu)
{
	switch (menu)
	{
	case 0: // Menu Inicial e metodos comuns
		switch (subMenu)
		{
		case 1: // Carrega dados armazenados em .csv
			CarregarDadosArmazenados();
			break;
		case 4: // Imprime Limites
			cout << "Limiar Superior: " << limiarMax << " Limiar Inferior: " << limiarMin << endl;
			break;
		case 8: // Imprime Dados
			ImprimirDados();
			break;
		}
		break;
	case 1: // Monitoramento
		switch (subMenu)
		{
		case 1: // Alterar numero de leituras
			cout << "Digite a quantidade de leituras" << endl;
			uInterface.validarEntrada(leituras);
			break;
		case 2: // Alterar intervalo(em ms) entre leituras
			cout << "Digite o valor do novo intervalo" << endl;
			uInterface.validarEntrada(intervalo);
			break;

		case 3: // Realizar nova Leitura
			RealizarLeitura(leituras, intervalo);
			break;

		case 4: // Limpar dados da ultima leitura
			listaDeDados.limpa();
			break;
		}
		break;

	case 2: // Armazenamento
		switch (subMenu)
		{
		case 1: // Salvar leitura atual como .csv
			SalvarDados();
			break;
		case 2: // Carregar dados salvos em .csv
			CarregarDadosArmazenados();
			break;
		}
		break;
	case 3: // Controle
		switch (subMenu)
		{
		case 1: //  Alterar o limiar de temperatura minimo
			cout << "Digite o valor do novo limiar minimo" << endl;
			uInterface.validarEntrada(limiarMin);
			break;
		case 2: //  Alterar o limiar de temperatura maximo
			cout << "Digite o valor do novo limiar maximo" << endl;
			uInterface.validarEntrada(limiarMax);
			break;
		}
		break;
	case 4:	// Estatistica
		if (subMenu == 1) //  Imprime a analise de dado
			AnalisarDados();
		break;
	}
}
