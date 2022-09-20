#include "InterfaceDeUsuario.h"

#include <string>
#include <iostream>
#include <limits>
#include <cstddef>

#include "Gerenciador.h"

using namespace std;

InterfaceDeUsuario::InterfaceDeUsuario()
{
	this->gerente = NULL;
};

InterfaceDeUsuario::InterfaceDeUsuario(Gerenciador *gerente)
{
	this->gerente = gerente;
};

void InterfaceDeUsuario::exibirIntro()
{
	unsigned int opcao = 0;
	cout << " Projeto Monitorador de Temperaturas" << endl
		 << endl
		 << "Bem vindo ao Monitorador de Temperaturas" << endl
		 << "Deseja carregar os dados salvos na ultima vez?" << endl;
	do
	{
		cout << "1 - Sim" << endl
			 << "2 - Nao" << endl;

		cin >> opcao;
	} while (validarOpcao(opcao, 1, 2));

	if (opcao == 1)
		gerente->SelecionarOpcao(0, 1);
};

void InterfaceDeUsuario::exibirMenu()
{
	unsigned int opcao = 0;
	do
	{
		limparTela();
		cout << " Projeto Monitorador de Temperaturas" << endl
			 << endl;
		cout << "Selecione uma das opcoes abaixo:" << endl;
		do
		{
			cout << "1 - Realizar leituras do simulador " << endl
				 << "2 - Salvar e Recuperar Dados" << endl
				 << "3 - Configurar limites de temperatura" << endl
				 << "4 - Analisar dados" << endl
				 << "5 - Encerrar programa" << endl;

			cin >> opcao;
		} while (validarOpcao(opcao, 1, 5));

		switch (opcao)
		{
		case 1:
			cout << "Opcao 1 Escolhida" << endl;
			exibirMonitoramento();
			break;

		case 2:
			cout << "Opcao 2 Escolhida" << endl;
			exibirArmazenamento();
			break;

		case 3:
			cout << "Opcao 3 Escolhida" << endl;
			exibirControle();
			break;

		case 4:
			cout << "Opcao 4 Escolhida" << endl;
			exibirAnalise();
			break;

		case 5:
			cout << "Opcao 5 Escolhida, o programa sera encerrado!" << endl;
			break;
		}

	} while (opcao != 5);
};

void InterfaceDeUsuario::exibirMonitoramento()
{
	unsigned int opcao;
	cout << "Monitoramento de Dados" << endl
		 << endl;
	cout << "Selecione uma das opcoes abaixo:" << endl;
	do
	{
		cout << "1 - Alterar numero de leituras " << endl
			 << "2 - Alterar intervalo(em ms) entre leituras" << endl
			 << "3 - Realizar nova Leitura" << endl
			 << "4 - Limpar dados da ultima leitura" << endl
			 << "5 - Encerrar subMenu" << endl
			 << endl;

		cout << "Resultados da ultima leitura:" << endl;
		gerente->SelecionarOpcao(0, 8);

		cin >> opcao;
	} while (validarOpcao(opcao, 1, 5));

	switch (opcao)
	{
	case 1:
		cout << "Opcao 1 Escolhida" << endl;
		gerente->SelecionarOpcao(1, 1);
		break;

	case 2:
		cout << "Opcao 2 Escolhida" << endl;
		gerente->SelecionarOpcao(1, 2);
		break;

	case 3:
		cout << "Opcao 3 Escolhida" << endl;
		gerente->SelecionarOpcao(1, 3);
		break;

	case 4:
		cout << "Opcao 4 Escolhida" << endl;
		gerente->SelecionarOpcao(1, 4);
		break;

	case 5:
		cout << "Opcao 5 Escolhida, o subMenu sera encerrado!" << endl;
		break;
	}
};

void InterfaceDeUsuario::exibirArmazenamento()
{
	unsigned int opcao;
	cout << "Armazenamento de Dados" << endl
		 << endl;
	cout << "Selecione uma das opcoes abaixo:" << endl;
	do
	{
		cout << "1 - Salvar leitura atual como .csv" << endl
			 << "2 - Carregar dados salvos em .csv" << endl
			 << "3 - Encerrar subMenu" << endl
			 << endl;

		cout << "Resultados da ultima leitura:" << endl;
		gerente->SelecionarOpcao(0, 8);

		cin >> opcao;
	} while (validarOpcao(opcao, 1, 3));

	switch (opcao)
	{
	case 1:
		cout << "Opcao 1 Escolhida" << endl;
		gerente->SelecionarOpcao(2, 1);
		break;

	case 2:
		cout << "Opcao 2 Escolhida" << endl;
		gerente->SelecionarOpcao(2, 2);
		break;

	case 3:
		cout << "Opcao 3 Escolhida, o subMenu sera encerrado!" << endl;
		break;
	}
};

void InterfaceDeUsuario::exibirControle()
{
	unsigned int opcao;
	cout << "Controle de Temperatura" << endl
		 << endl;
	cout << "Selecione uma das opcoes abaixo:" << endl;
	do
	{
		cout << "1 - Alterar o limiar de temperatura minimo" << endl
			 << "2 - Alterar o limiar de temperatura maximo" << endl
			 << "3 - Encerrar subMenu" << endl
			 << endl;

		cout << "Limiares atuais:" << endl;
		gerente->SelecionarOpcao(0, 4);

		cin >> opcao;
	} while (validarOpcao(opcao, 1, 3));

	switch (opcao)
	{
	case 1:
		cout << "Opcao 1 Escolhida" << endl;
		gerente->SelecionarOpcao(3, 1);
		break;

	case 2:
		cout << "Opcao 2 Escolhida" << endl;
		gerente->SelecionarOpcao(3, 2);
		break;

	case 3:
		cout << "Opcao 3 Escolhida, o subMenu sera encerrado!" << endl;
		break;
	}
};

void InterfaceDeUsuario::exibirAnalise()
{
	unsigned int opcao;
	cout << "Analise estatistica da leitura atual" << endl
		 << endl;
	cout << "Selecione uma das opcoes abaixo:" << endl;
	do
	{
		cout << "1 - Encerrar Submenu" << endl
			 << endl;

		cout << "Analise Estatistica:" << endl;
		gerente->SelecionarOpcao(4, 1);

		cin >> opcao;
	} while (opcao != 1);

	switch (opcao)
	{
	case 1:
		cout << "Opcao 1 Escolhida, o subMenu sera encerrado!" << endl;
		break;
	}
};

void InterfaceDeUsuario::limparTela()
{
	system("cls"); // Limpa o console
};

bool InterfaceDeUsuario::validarOpcao(unsigned int entrada, unsigned int minimo, unsigned int maximo)
{
	limparTela();
	bool isInvalid = !(entrada >= minimo && entrada <= maximo); // Se for false, entrada valida
	if (isInvalid)
		cout << "Escolha Invalida, selecione uma das opcoes validas abaixo:" << endl;
	return isInvalid;
};

void InterfaceDeUsuario::validarEntrada(int& val, int minimo, int maximo)
{
	bool entradaInvalida = true;
	while (entradaInvalida) {
		if (cin >> val && val >= minimo && val <= maximo)
			entradaInvalida = false;
		else {
			cout << "Por favor entre um numero inteiro valido, no intervalo de " << minimo << " ate " << maximo << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
};

void InterfaceDeUsuario::validarEntrada(int& val)
{
	bool entradaInvalida = true;
	while (entradaInvalida) {
		if (cin >> val)
			entradaInvalida = false;
		else {
			cout << "Por favor entre um numero inteiro valido" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
};

void InterfaceDeUsuario::validarEntrada(unsigned int& val, unsigned int minimo, unsigned int maximo)
{
	bool entradaInvalida = true;
	while (entradaInvalida) {
		if (cin >> val && val >= minimo && val <= maximo)
			entradaInvalida = false;
		else {
			cout << "Por favor entre um numero inteiro positivo valido, no intervalo de " << minimo << " ate " << maximo << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
};

void InterfaceDeUsuario::validarEntrada(unsigned int& val)
{
	bool entradaInvalida = true;
	while (entradaInvalida) {
		if (cin >> val)
			entradaInvalida = false;
		else {
			cout << "Por favor entre um numero inteiro positivo valido" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
};

void InterfaceDeUsuario::validarEntrada(char& val)
{
	bool entradaInvalida = true;
	while (entradaInvalida) {
		if (cin >> val)
			entradaInvalida = false;
		else {
			cout << "Por favor entre um caracter valido" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
};

void InterfaceDeUsuario::validarEntrada(double& val)
{
	bool entradaInvalida = true;
	while (entradaInvalida) {
		if (cin >> val)
			entradaInvalida = false;
		else {
			cout << "Por favor entre um double valido" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
};
