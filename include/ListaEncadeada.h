#ifndef LISTAENCADEADA_H_
#define LISTAENCADEADA_H_

#include <cstdlib>
#include <iostream>
#include "Elemento.h"

using namespace std;

template <typename T>
class ListaEncadeada
{ // Definição da Classe
protected:
    int tam;             // Tamanho da lista
    Elemento<T> *cabeca; // A "cabeça" é um ponteiro para o primeiro elemento da lista.
public:
    ListaEncadeada()
    {
        cabeca = NULL; // Lista vazia
        tam = 0;
    }; // Construtor padrão

    void insereF(T x) // Adiciona um elemento ao final da lista
    {                                           
        Elemento<T> *novo = new Elemento<T>(x); // Aloca espaço de memoria
        tam++;
        if (!cabeca) // Lista vazia
            cabeca = novo;
        else
        { // Lista ja tem elementos
            Elemento<T> *onde = cabeca;
            while (onde->prox) // Enquanto nao for o ultimo elemento
                onde = onde->prox;
            onde->prox = novo;
        };
    }

    void insereI(T x)// Método para adicionar um elemento novo no inicio.
    {                                        
        Elemento<T> *novo = new Elemento<T>(x); // Aloca espaço de memoria
        tam++;
        novo->prox = cabeca;
        cabeca = novo;
    }; 

    void insere(T x, int pos)// Método para inserir em uma posição qualquer
    {
        if (pos == 0)
            insereI(x);
        else if (pos == tam)
            insereF(x);
        else if ((pos < tam) && (pos > 0))
        {
            Elemento<T> *novo = new Elemento<T>(x); // Aloca espaço de memoria
            tam++;
            Elemento<T> *onde = cabeca;
            for (int i = 0; i < (pos - 1); ++i) // Avança ate a posição de inserção
                onde = onde->prox;
            novo->prox = onde->prox;
            onde->prox = novo;
        }
    }; 

    void imprime()
    { // Metodo para imprimir, na saida padrao, todos os elementos na tela;

        if (cabeca == NULL) // Volta se a lista for nula
            return;
        Elemento<T> *temp = cabeca;
        do
        {
            cout << temp->valor << endl;
            temp = temp->prox;
        } while (temp); // e uma atribuição e uma comparação
    };

    bool localiza(T val)// Método de busca de um elemento na lista
    { 
        for (Elemento<T> *onde = cabeca; onde; onde = onde->prox)
            if (onde->valor == val)
                return true;
        return false;
    }; 

    bool delU() // Apaga o último elemento de uma lista
    {
        if (tam > 0)
        {
            tam--;
            Elemento<T> *onde = cabeca;
            while (onde->prox->prox) // Enquanto nao for o penúltimo elemento
                onde = onde->prox;
            delete onde->prox; // libera a area de memoria do ponteiro
            onde->prox = NULL; // define o penúltimo elemento como prox NULL.
            return true;
        }
        return false;
    };

    bool delP() // Apaga o primeiro elemento de uma lista
    {
        if (tam > 0)
        {
            tam--;
            Elemento<T> *lixo = cabeca;
            cabeca = cabeca->prox;
            delete lixo; // libera a area de memoria do ponteiro
            return true;
        }
        return false;
    };

    void limpa() // Apaga toda a lista
    {
        while (delP());
    };

    bool delV(T y) // Apaga o elemento de valor y
    {
        if ((tam > 0) && (localiza(y)))
        {
            Elemento<T> *onde = cabeca;
            if (onde->valor == y)
                return delP();
            tam--;
            while (onde->prox->valor != y) // ve o valor do no seguinte
                onde = onde->prox;         // Avança
            Elemento<T> *lixo = onde->prox;
            onde->prox = onde->prox->prox;
            delete lixo;
            return true;
            this->imprime();
        }
        return false;
    };


    T pos(int pos) // Retorna a posição do elemento p;
    {
        if ((pos < tam) && (pos >= 0))
        {                                 // Verifica se a pos e valida
            Elemento<T> *onde = cabeca;   // Ponteiro auxiliar
            for (int i = 0; i < pos; i++) // Avança ate a posição que se queira
                onde = onde->prox;        // Avança 1 posição
            return onde->valor;           // Retorna o valor
        }
        return T();
    };

    T ultimo() // Retorna o ultimo elemento ;
    {
        if (cabeca != NULL)
        {                                 
            Elemento<T>* onde = cabeca;   
            while (onde->prox != NULL)    // Avança ate a ultima posição
                onde = onde->prox;        // Avança 1 posição
            return onde->valor;           // Retorna o valor
        }
        return T();
    };

    T primeiro() // Retorna o primeiro elemento;
    {
        if (cabeca != NULL)
            return cabeca->valor;
        return T();
    };

    T acharMediana(bool isSorted) // Acha a Mediana de uma Lista, se isSorted for falso, faz sort;
    {
        if (!isSorted)
            this->sort();

        T mediana = T();

        if (tam % 2 == 0)// se for Impar
            mediana = (this->pos((tam - 1) / 2) + this->pos(tam / 2)) / 2.0;
        else             // se for par
            mediana = this->pos(tam / 2);

        return mediana;
    };

    T acharMedia() // Acha a Mediana de uma Lista, se isSorted for falso, faz sort;
    {

        T media = T();

        Elemento<T>* onde = cabeca;
        do {
            media += onde->valor;
            onde = onde->prox;
        } while (onde != NULL);

        media /= tam;
        return media;
    };
    
    int comprimento()
    {
        return tam;
    };

   
    void sort() { //Faz sorting na lista, usando bubble sort e os metodos de comparação de T

        int swapped;
        Elemento<T> *ptr1;
        Elemento<T> *lptr = NULL;

        if (cabeca == NULL) // Volta se a lista for nula
            return;

        do
        {
            swapped = 0;
            ptr1 = cabeca;

            while (ptr1->prox != lptr)
            {
                if (ptr1->valor > ptr1->prox->valor)
                {
                    troca(ptr1, ptr1->prox);
                    swapped = 1;
                }
                ptr1 = ptr1->prox;
            }
            lptr = ptr1;
        } while (swapped);
    }

    void troca(Elemento<T>* a, Elemento<T>* b) //Troca dois elementos de posição
    {
        T temp = a->valor;
        a->valor = b->valor;
        b->valor = temp;
    }
   
    template<typename Operation> void //Executa o functor op, que aceita um valor T e retorna void, em cada membro da lista
        paraCada(Operation op) {
        if (cabeca == NULL) // Volta se a lista for nula
            return;
        Elemento<T>* onde = cabeca;
        do {
            op(&(onde->valor));
            onde = onde->prox;
        } while (onde != NULL);
    };

    //Executa o functor op, que aceita um valor T e retorna void, em cada membro da lista, se este passa pelo predicado que aceita T e retorna bool
    template<typename Pred, typename Operation> void
        paraCadaSe(Pred predicate, Operation op) {
        if (cabeca == NULL) // Volta se a lista for nula
            return;
        Elemento<T>* onde = cabeca;
        do {
            if (predicate(*onde)) op(*onde);
            onde = onde->prox;
        } while (onde != NULL)
    };

};

#endif // LISTAENCADEADA_H_
