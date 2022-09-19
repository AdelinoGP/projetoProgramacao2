#ifndef USERVIEW_H_
#define USERVIEW_H_
class Gerenciador;

class InterfaceDeUsuario
{
private:
	Gerenciador* gerente;
public:
	InterfaceDeUsuario();
	InterfaceDeUsuario(Gerenciador* gerente);
	void exibirIntro();
	void exibirMenu();
	void exibirMonitoramento();
	void exibirArmazenamento();
	void exibirControle();
	void exibirAnalise();
	void limparTela();
	bool validarEntrada(unsigned int entrada, unsigned int minimo, unsigned int maximo);
};

#endif
