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
    Playlist();
    Playlist(string nome);
    void setNome(string nome);
    string getNome();
    Lista *getLista();
    void setNome(Lista *lista);
    void adicionarMusicaPlaylist(string nome, string titulo);
    void removerMusica(string nome, string titulo);
    Musica *getProximaMusica(Musica *musica);
    ~Playlist();
    void imprimirTodasMusicas(Musica *musica);
};

#endif