#include "Elemento.h"
// Construtor, Caso um valor nao seja atribuído sera utilizado zero
template<typename T>
Elemento<T>::Elemento(T v) {
  valor = v;
  prox = nullptr;
}
