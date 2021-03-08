#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Musica.h"

using namespace std;
using std::cin;
using std::cout;
using std::endl;

/** Classe responsável por gerir as Músicas
* Assinatura dos métodos utilizados no arquivo .cpp 
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
* @param primeira - Musica* - primeira Música da lista
* @param ultima - Musica* - ultima Música da lista
**/

class Lista
{
private:
    Musica *primeira;
    Musica *ultima;

public:
    Lista();
    Lista(string nome, string titulo);
    ~Lista();
    Lista(const Lista &l);
    Musica *getPrimeira();
    void setPrimeira(Musica *m);
    Musica *getUltima();
    void inserirNoInicio(string nome, string titulo);
    void inserirNoInicio(Lista &listaDeMusica);
    void inserirNoFinal(string nome, string titulo);
    void imprimir();
    Musica *buscarPeloNomeTitulo(string nome, string titulo);
    void remover(string nome, string titulo);
    void remover(Lista &listaDeMusica);
    void removerUltima();
    Lista operator+(Lista &lista);
    void operator>>(Musica *m);
    void operator<<(Musica *m);
};

#endif