#ifndef __LISTAESTATICA_H__
#define __LISTAESTATICA_H__
template <class T>
class RespostaLeitura
{
public:
  bool sucesso;

public:
  T valor;
  RespostaLeitura();
};

template <class T>
class ListaBasica
{ // Classe de Armazenamento
protected:
  unsigned short tam; // Tamanho ocupado da lista
  T *vetor;           // Vetor com os dados a serem armazenados
public:
  ListaBasica(int tamanho);
  ~ListaBasica();
  int comprimento();
};

template <class T>
class Lista : public ListaBasica<T>
{ // Definição da Classe que herda da classe ListaBasica

public:
  T primeiro();

  T ultimo();

  bool localiza(T val);

  int pos(T val);

  bool insere(T val, unsigned short pos);

  bool insereI(T val);

  bool insereF(T val);

  bool delP(unsigned short pos);

  bool delV(T val);

  T ler(unsigned short pos);
};

#endif // __LISTAESTATICA_H__