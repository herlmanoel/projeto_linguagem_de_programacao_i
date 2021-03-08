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
    Playlist();
    Playlist(string nome);
    Playlist(const Playlist& p);
    ~Playlist();
    string getNome();
    Lista *getLista();
    void setNome(string nome);
    void setLista(Lista *lista);
    void adicionarMusicaPlaylist(string nome, string titulo);
    void adicionarMusicaPlaylist(Playlist &p);
    void removerMusica(string nome, string titulo);
    void removerMusica(Playlist &p);
    Musica *getProximaMusica(Musica *musica);
    void imprimirTodasMusicas(Musica *musica);
    Playlist operator+(Playlist &p);
    Playlist operator+(Musica &m);
    Playlist operator-(Playlist &p);
    Playlist operator-(Musica &m);
    void operator>>(Musica &m);
    void operator<<(Musica &m);
};

#endif