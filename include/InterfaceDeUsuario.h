#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "Gerenciador.h"

class InterfaceDeUsuario {
private:
	int menuAtual = 0;
	int subMenuAtual = 0;
	Gerenciador* gerente;
public:
	InterfaceDeUsuario(Gerenciador * gerente);
	bool exibirMenu();
	void exibirMonitoramento();
	void exibirArmazenamento();
	void exibirControle();
	void exibirAnalise();
	void limparTela();
	bool validarEntrada(unsigned int entrada, unsigned int minimo , unsigned int maximo);
};

#endif
