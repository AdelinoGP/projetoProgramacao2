#include <cstdlib>
#include <iostream>
#include <iomanip>

template <class T>
class RespostaLeitura
{
public:
  bool sucesso;
public:
  T valor;
  RespostaLeitura<T> SetupValores(bool sucesso,T valor)
  {
    this->sucesso = sucesso;
    this->valor = valor;
    return this;
  }
};

template <class T>
class ListaBasica
{ // Classe de Armazenamento
protected:
  unsigned short tamanho;    // Tamanho ocupado da lista
  unsigned short tamanhoMax; // Tamanho ocupado da lista
  T vetor[];                 // Vetor com os dados a serem armazenados
public:
  ListaBasica(int tamanho)
  {
    vetor = calloc(sizeof(T), tamanho);
    assert(vetor);
  }
  ~ListaBasica()
  {
    free(vetor);
    vetor = NULL;
  }
  int comprimento()
  { // necessário por tam ser privado
    return tamanho;
  }
};

template <class T>
class Lista : public ListaBasica<T>
{ // Definição da Classe que herda da classe ListaBasica

using ListaBasica<T>::ListaBasica;

public:
  T primeiro()
  {
    return vetor[0];
  }

  T ultimo()
  {
    return vetor[tamanho - 1]; // tam-1 por todo vetor começar em 0
  }

  bool localiza(T val)
  {
    for (unsigned short i = 0; i < tamanho; i++)
      if (val == vetor[i])
        return true;
    return false;
  }

  int pos(T val)
  {
    for (unsigned short i = 0; i < tamanho; i++)
      if (val == vetor[i])
        return i;
    return -1; // posição impossível p/ sinalizar não encontrado
  }

  bool insere(T val, unsigned short pos)
  {
    if ((pos >= 0) && (pos <= tamanho) && (tamanho < tamanhoMax))
    {
      for (unsigned short i = tamanho; i > pos; i--) // avança todos elementos
        vetor[i] = vetor[i - 1];
      vetor[pos] = val; // grava o valor na posição
      tam++;            // aumenta o tamanho do vetor
      return true;
    }
    return false;
  }

  bool insereI(T val)
  {
    return insere(val, 0); // Chamada ao m�todo insere
  }

  bool insereF(T val)
  {
    return insere(val, tamanho);
  }

  bool delP(unsigned short pos)
  {
    if ((pos >= 0) && (pos < tamanho))
    {
      for (unsigned short i = pos; i < (tamanho - 1); i++)
        vetor[i] = vetor[i + 1];
      tamanho--; // diminui o tamanho do vetor
      return true;
    }
    return false;
  }
  bool delV(T val)
  {
    return delP(pos(val));
  }

  RespostaLeitura<T> ler(unsigned short pos)
  {
    RespostaLeitura resposta;
    if ((pos >= 0) && (pos < tamanho))
    {
      return resposta->SetupValores(true, vetor[pos]);
    }
      return resposta->SetupValores(false, null);
  }
};
