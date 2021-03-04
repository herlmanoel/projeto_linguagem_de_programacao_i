#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include "Lista.h"
#include "Musica.h"

using namespace std;

/** Classe responsável por gerir a listas ligada.
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
* @param nome - String - nome da playlist
* @param lista - Lista* - lista ligada de Musica 
**/

class Playlist
{
private:
    string nome;
    Lista *lista;

public:
    // Construtor
    Playlist()
    {
        nome = "";
        Lista *lista = new Lista();
        this->lista = lista;
    }

    /** Método constructor passando como parametro o nome da Playlist
     * @param nome - string - nome da playlist
     */
    Playlist(string nome)
    {
        this->nome = nome;
        Lista *lista = new Lista();
        this->lista = lista;
    }

    /** Método para setar nome
    * @param nome - string - nome da playlist
    */
    void setNome(string nome)
    {
        this->nome = nome;
    }

    /** Método para acessar o nome
    * @return nome - string - nome da playlist
    */
    string getNome()
    {
        return nome;
    }

    /** Método para acessar a lista
    * @return lista - Lista* - lista de musicas
    */
    Lista *getLista()
    {
        return lista;
    }

    /** Método para setar lista
    * @param lista - Lista* - lista de musicas
    */
    void setNome(Lista *lista)
    {
        this->lista = lista;
    }

    /** Método para adicionar musica na lista
    * @param nome - string - nome do artista
    * @param titulo - string - titulo da musica
    */
    void adicionarMusicaPlaylist(string nome, string titulo)
    {
        lista->inserirNoInicio(nome, titulo);
    }

    /** Método para remover musica na lista
    * @param nome - string - nome do artista
    * @param titulo - string - titulo da musica
    */
    void removerMusica(string nome, string titulo)
    {
        lista->remover(nome, titulo);
    }

    /** Método para pegar a proxima musica na lista
    * @param musica - Musica* - instancia da musica
    */
    Musica *getProximaMusica(Musica *musica)
    {
        return musica->getProxima();
    }

    /** Método recursivo para imprimir todas as musicas
    * @param musica - Musica* - instancia da primeira musica da lista
    */
    void imprimirTodasMusicas(Musica *musica)
    {
        if (musica == NULL)
        {
            cout << endl;
            return;
        }

        cout << endl
             << musica->getNome() << endl;
        cout << musica->getTitulo() << endl;
        cout << "-----------------------------";

        return imprimirTodasMusicas(musica->getProxima());
    }

    /** Método destructor
    * Liberar o espaço da lista 
    */
    ~Playlist()
    {
        delete lista;
    }
};

#endif