#ifndef MUSICA_H
#define MUSICA_H

#include <iostream>

using namespace std;

/** Classe responsável por guardar a Música e um endereço para a proxima.
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
    // Construtor
    Musica();

    /** Constructor
        * @param nome - string - nome do artista
        * @param titulo - string - titulo da musica
        */
    Musica(string nome, string titulo);

    /** Método para acessar o nome do artista
        * @return nome - string
        */
    string getNome();

    /** Método para acessar o titulo da Música
        * @return titulo - string
        */
    string getTitulo();

    /** Método para adicionar a proxima Música
        * @param musica - Musica*
        */
    void setProxima(Musica *musica);
    void setNome(string n);
    void setTitulo(string t);

    /** Método para acessar a proxima Música
        * @return proxima - Musica*
        */
    Musica *getProxima();

    void imprimir();

    /** Método destructor
        * Liberar o espaço da musica 
        */
    ~Musica();
};

#endif