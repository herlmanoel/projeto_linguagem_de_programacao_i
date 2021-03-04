#ifndef UTIL_H
#define UTIL_H

#include "vector"
#include "Playlist.h"

/** Arquivo responsável por conter os cabeçalhos das funções do arquivo util.cpp
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
**/

Playlist *qualPlaylist(vector<Playlist *> playlists);
void imprimirTodasPlaylists(vector<Playlist *> playlists);
void removerPlaylist(vector<Playlist *> *playlists);
string lerTituloMusica();
string lerNomeArtista();

#endif