#include "InterfaceDeUsuario.h"

#include <string>
#include <iostream>

using namespace std;

InterfaceDeUsuario::InterfaceDeUsuario(Gerenciador* gerente)
{
	this->gerente = gerente;
}

bool InterfaceDeUsuario::exibirMenu()
{
	unsigned int opcao = 0;
	do
	{
		limparTela();
		cout << " Projeto Monitorador de Temperaturas" << endl << endl;
		cout << "Selecione uma das opcoes abaixo:" << endl;
		do {
			cout << "1 - Realizar leituras do simulador " << endl
				 << "2 - Salvar e Recuperar Dados" << endl
				 << "3 - Configurar limites de temperatura" << endl
				 << "4 - Analisar dados" << endl
				 << "5 - Encerrar programa" << endl;

			cin >> opcao;
		} while (validarEntrada(opcao, 1, 5));

		switch (opcao) {
		case 1:
			cout << "Opção 1 Escolhida" << endl;
			exibirMonitoramento();
			break;

		case 2:
			cout << "Opção 2 Escolhida" << endl;
			exibirArmazenamento();
			break;

		case 3:
			cout << "Opção 3 Escolhida" << endl;
			exibirControle();
			break;

		case 4:
			cout << "Opção 4 Escolhida" << endl;
			exibirAnalise();
			break;

		case 5:
			cout << "Opção 5 Escolhida, o programa sera encerrado!" << endl;
			break;
		}

	} while (opcao != 5);
}

void InterfaceDeUsuario::exibirMonitoramento()
{
	unsigned int opcao;
	cout << "Monitoramento de Dados" << endl << endl;
	cout << "Selecione uma das opcoes abaixo:" << endl;
	do {
		cout << "1 - Alterar numero de leituras " << endl
			<< "2 - Alterar intervalo(em ms) entre leituras" << endl
			<< "3 - Realizar nova Leitura" << endl
			<< "4 - Limpar dados da ultima leitura" << endl
			<< "5 - Encerrar subMenu" << endl << endl;

		cout << "Resultados da ultima leitura:" << endl;
		//Exibir ultima leitura

		cin >> opcao;
	} while (validarEntrada(opcao, 1, 5));


	switch (opcao) {
	case 1:
		cout << "Opção 1 Escolhida" << endl;
		// gerenciador.SelecionarOpcao(1,1);
		break;

	case 2:
		cout << "Opção 2 Escolhida" << endl;
		// gerenciador.SelecionarOpcao(1,1);
		break;

	case 3:
		cout << "Opção 3 Escolhida" << endl;
		// gerenciador.SelecionarOpcao(1,1);
		break;

	case 4:
		cout << "Opção 4 Escolhida" << endl;
		// gerenciador.SelecionarOpcao(1,1);
		break;

	case 5:
		cout << "Opção 5 Escolhida, o subMenu sera encerrado!" << endl;
		break;
	}
}

void InterfaceDeUsuario::exibirArmazenamento()
{
	unsigned int opcao;
	cout << "Armazenamento de Dados" << endl << endl;
	cout << "Selecione uma das opcoes abaixo:" << endl;
	do {
		cout << "1 - Salvar leitura atual como .csv" << endl
			<< "2 - Carregar dados salvos em .csv" << endl
			<< "3 - Encerrar subMenu" << endl << endl;

		cout << "Resultados da ultima leitura:" << endl;
		//Exibir ultima leitura

		cin >> opcao;
	} while (validarEntrada(opcao, 1, 3));


	switch (opcao) {
	case 1:
		cout << "Opção 1 Escolhida" << endl;
		// gerenciador.SelecionarOpcao(2,1);
		break;

	case 2:
		cout << "Opção 2 Escolhida" << endl;
		// gerenciador.SelecionarOpcao(2,2);
		break;

	case 3:
		cout << "Opção 3 Escolhida, o subMenu sera encerrado!" << endl;
		break;
	}
}

void InterfaceDeUsuario::exibirControle()
{
	unsigned int opcao;
	cout << "Controle de Temperatura" << endl << endl;
	cout << "Selecione uma das opcoes abaixo:" << endl;
	do {
		cout << "1 - Alterar o limiar de temperatura minimo" << endl
			<< "2 - Alterar o limiar de temperatura maximo" << endl
			<< "3 - Encerrar subMenu" << endl << endl;

		cout << "Limiares atuais:" << endl;
		//Exibir limiares

		cin >> opcao;
	} while (validarEntrada(opcao, 1, 3));


	switch (opcao) {
	case 1:
		cout << "Opção 1 Escolhida" << endl;
		// gerenciador.SelecionarOpcao(3,1);
		break;

	case 2:
		cout << "Opção 2 Escolhida" << endl;
		// gerenciador.SelecionarOpcao(3,2);
		break;

	case 3:
		cout << "Opção 3 Escolhida, o subMenu sera encerrado!" << endl;
		break;
	}
}

void InterfaceDeUsuario::exibirAnalise()
{
	unsigned int opcao;
	cout << "Analise estatistica da leitura atual" << endl << endl;
	cout << "Selecione uma das opcoes abaixo:" << endl;
	do {
		cout << "1 - Encerrar Submenu" << endl << endl;

		cout << "Analise Estatistica:" << endl;
		//Exibir analise

		cin >> opcao;
	} while (opcao != 1);


	switch (opcao) {
	case 1:

	case 3:
		cout << "Opção 3 Escolhida, o subMenu sera encerrado!" << endl;
		break;
	}
}


void InterfaceDeUsuario::limparTela()
{
	cout << '\033c'; //Limpa o console em sistemas Unix e Windows após versão 10 TH2, alternativa seria usar system("cls");
}

bool InterfaceDeUsuario::validarEntrada(unsigned int entrada, unsigned int minimo, unsigned int maximo)
{
	limparTela();
	bool isValid = (entrada >= minimo && entrada <= maximo);
	if (!isValid)
		cout << "Escolha Invalida, selecione uma das opcoes validas abaixo:" << endl;
	return isValid;
}
