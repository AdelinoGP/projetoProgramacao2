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
	bool validarOpcao(unsigned int& entrada, unsigned int minimo, unsigned int maximo);
	void validarEntrada(int& val, int minimo, int maximo);
	void validarEntrada(int& val);
	void validarEntrada(unsigned int& val, unsigned int minimo, unsigned int maximo);
	void validarEntrada(unsigned int& val);
	void validarEntrada(char& val);
	void validarEntrada(double& val);
};

#endif
