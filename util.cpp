#include "util.h"

/** Arquivo responsável por empacotar funções úteis ao main
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
**/

/** Função para buscar uma Playlist no vetor de Playlists
* @param playlists - vector<Playlist *>
* @return playlist - Playlist *
*/
Playlist *qualPlaylist(vector<Playlist *> playlists)
{
    string nomePlaylist;
    cout << "Qual playlist?" << endl;
    cin.ignore(1000, '\n');
    cin >> nomePlaylist;
    int tamanho = playlists.size();
    for (int i = 0; i < tamanho; i++)
    {
        if (nomePlaylist.compare(playlists[i]->getNome()) == 0)
        {
            return playlists[i];
        }
    }
    return NULL;
}

/** Função para imprimir as Playlists do vetor
* @param playlists - vector<Playlist *>
*/
void imprimirTodasPlaylists(vector<Playlist *> playlists)
{
    int tamanho = playlists.size();
    if (tamanho > 0)
    {
        for (int i = 0; i < tamanho; i++)
        {
            cout << i << ": " << playlists[i]->getNome() << endl;
        }
    }
    else
    {
        cout << "Voce nao criou nenhuma playlist" << endl;
    }
}

/** Função para ler do usuário o titulo da Musica
* @return tituloDaMusica - string
*/
string lerTituloMusica()
{
    string tituloDaMusica;
    cout << "Qual o titulo da musica?" << endl;
    cin.ignore(1000, '\n');
    cin >> tituloDaMusica;
    return tituloDaMusica;
}

/** Função para ler do usuário o nome do artista
* @return nomeDoArtista - string
*/
string lerNomeArtista()
{
    string nomeDoArtista;
    cout << "Qual o nome do artista?" << endl;
    cin.ignore(1000, '\n');
    cin >> nomeDoArtista;
    return nomeDoArtista;
}

/** Função para remover uma Playlist do vetor
* @param playlists - vector<Playlist *>
*/
void removerPlaylist(vector<Playlist *> *playlists)
{
    string nomePlaylist;
    int i;
    cout << "Qual playlist?" << endl;
    cin.ignore(1000, '\n');
    cin >> nomePlaylist;
    int tamanho = playlists[0].size();
    for (i = 0; i < tamanho; i++)
    {
        if (nomePlaylist.compare(playlists[0][i]->getNome()) == 0)
        {
            playlists[0].erase(playlists[0].begin() + i);
            break;
        }
    }
}