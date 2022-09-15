#ifndef ELEMENTO_H_
#define ELEMENTO_H_

#include <stddef.h>
#include "DadoSimulador.h"

using namespace std;

template <typename T>
class Elemento
{
public:
  T valor;           // Pode ser implementado qualquer tipo de dados aqui.
  Elemento<T> *prox; // Ponteiro para proximo elemento
  Elemento<T>(T v) {  // Construtor recebe obrigatoriamente um valor do tipo T
	  valor = v;
	  prox = nullptr;
  };  
};

#endif // ELEMENTO_H_
