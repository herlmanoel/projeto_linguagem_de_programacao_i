#include <iostream>
#include "Musica.h"
#include "Lista.h"
#include "Playlist.h"

using namespace std;
using std::cin;
using std::cout;
using std::endl;

// Construtor
Playlist::Playlist()
{
    nome = "";
    Lista *lista = new Lista();
    this->lista = lista;
}

/** Método constructor passando como parametro o nome da Playlist
     * @param nome - string - nome da playlist
     */
Playlist::Playlist(string nome)
{
    this->nome = nome;
    Lista *lista = new Lista();
    this->lista = lista;
}

/** Método para setar nome
    * @param nome - string - nome da playlist
    */
void Playlist::setNome(string nome)
{
    this->nome = nome;
}

/** Método para acessar o nome
    * @return nome - string - nome da playlist
    */
string Playlist::getNome()
{
    return nome;
}

/** Método para acessar a lista
    * @return lista - Lista* - lista de musicas
    */
Lista* Playlist::getLista()
{
    return lista;
}

/** Método para setar lista
    * @param lista - Lista* - lista de musicas
    */
void Playlist::setNome(Lista *lista)
{
    this->lista = lista;
}

/** Método para adicionar musica na lista
    * @param nome - string - nome do artista
    * @param titulo - string - titulo da musica
    */
void Playlist::adicionarMusicaPlaylist(string nome, string titulo)
{
    lista->inserirNoInicio(nome, titulo);
}

/** Método para remover musica na lista
    * @param nome - string - nome do artista
    * @param titulo - string - titulo da musica
    */
void Playlist::removerMusica(string nome, string titulo)
{
    lista->remover(nome, titulo);
}

/** Método para pegar a proxima musica na lista
    * @param musica - Musica* - instancia da musica
    */
Musica* Playlist::getProximaMusica(Musica *musica)
{
    return musica->getProxima();
}

/** Método recursivo para imprimir todas as musicas
    * @param musica - Musica* - instancia da primeira musica da lista
    */
void Playlist::imprimirTodasMusicas(Musica *musica)
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

    return Playlist::imprimirTodasMusicas(musica->getProxima());
}

/** Método destructor
    * Liberar o espaço da lista 
    */
Playlist::~Playlist()
{
    delete lista;
}
