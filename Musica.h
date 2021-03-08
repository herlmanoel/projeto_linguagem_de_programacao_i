#ifndef MUSICA_H
#define MUSICA_H

#include <iostream>

using namespace std;

/** Classe responsável por guardar a Música e um endereço para a proxima.
* Assinatura dos métodos utilizados no arquivo .cpp  
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
* @param nome - string - nome do artista
* @param titulo - string - titulo da musica
* @param proxima - Musica* - endereço da proxima Música
**/

class Musica
{
private:
    string nome;
    string titulo;
    Musica *proxima;

public:
    Musica();
    Musica(string nome, string titulo);
    string getNome();
    string getTitulo();
    void setProxima(Musica *musica);
    void setNome(string n);
    void setTitulo(string t);
    Musica *getProxima();
    void imprimir();
    ~Musica();
};

#endif