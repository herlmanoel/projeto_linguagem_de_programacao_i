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

/** Método construtor cópia
* @param Playlist &p - referencia para a Playlist
*/
Playlist::Playlist(const Playlist &p)
{
    this->nome = p.nome;
    Lista *nova_lista = p.lista;
    this->lista = nova_lista;
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
Lista *Playlist::getLista()
{
    return lista;
}

/** Método para setar lista
* @param lista - Lista* - lista de musicas
*/
void Playlist::setLista(Lista *lista)
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

/** Método sobrecarregado para unir duas Playlists
* @param Playlist &p- referencia para a Playlist
*/
void Playlist::adicionarMusicaPlaylist(Playlist &p)
{
    lista->inserirNoInicio(*(p.getLista()));
}

/** Método para remover musica na lista
* @param nome - string - nome do artista
* @param titulo - string - titulo da musica
*/
void Playlist::removerMusica(string nome, string titulo)
{
    lista->remover(nome, titulo);
}

/** Método sobrecarregado para remover uma Playlist de outra Playlist
* @param Playlist &p- referencia para a Playlist
*/
void Playlist::removerMusica(Playlist &p)
{
    lista->remover(*(p.getLista()));
}

/** Método para pegar a proxima musica na lista
* @param musica - Musica* - instancia da musica
*/
Musica *Playlist::getProximaMusica(Musica *musica)
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

    cout << musica->getNome() << " | " << musica->getTitulo() << endl;
    cout << "-----------------------------" << endl;

    return Playlist::imprimirTodasMusicas(musica->getProxima());
}

/** Método destructor
    * Liberar o espaço da lista 
    */
Playlist::~Playlist()
{
    delete lista;
}

/** Método sobrecarregando o operador "+" unindo duas Playlists
* @param Playlist &p- referencia para a Playlist
*/
Playlist Playlist::operator+(Playlist &p)
{
    Playlist nova_playlist;
    Lista *nova_lista = nova_playlist.getLista();

    Musica *m_p = lista->getPrimeira();
    while (m_p != NULL)
    {
        nova_lista->inserirNoInicio(m_p->getNome(), m_p->getTitulo());
        m_p = m_p->getProxima();
    }
    Musica *musica = p.getLista()->getPrimeira();
    while (musica != NULL)
    {
        if (!nova_lista->buscarPeloNomeTitulo(musica->getNome(), musica->getTitulo()))
        {
            nova_lista->inserirNoInicio(musica->getNome(), musica->getTitulo());
        }
        musica = musica->getProxima();
    }
    return nova_playlist;
}

/** Método sobrecarregando o operador "+" add uma música ao final da playlist
* @param Musica &m - referencia para a Música
*/
Playlist Playlist::operator+(Musica &m)
{
    Playlist nova_playlist;
    Lista *nova_lista = nova_playlist.getLista();

    Musica *m_p = lista->getPrimeira();
    while (m_p != NULL)
    {
        nova_lista->inserirNoInicio(m_p->getNome(), m_p->getTitulo());
        m_p = m_p->getProxima();
    }
    nova_lista->getUltima()->setProxima(&m);
    return nova_playlist;
}

/** Método sobrecarregando o operador "-" removendo uma Playlist de outra Playlist
* @param Playlist &p- referencia para a Playlist
*/
Playlist Playlist::operator-(Playlist &p)
{
    Playlist nova_playlist;
    Lista *nova_lista = nova_playlist.getLista();
    Musica *m_p = lista->getPrimeira();
    while (m_p != NULL)
    {
        nova_lista->inserirNoInicio(m_p->getNome(), m_p->getTitulo());
        m_p = m_p->getProxima();
    }

    nova_lista->remover(*(p.getLista()));

    return nova_playlist;
}

/** Método sobrecarregando o operador "-" removendo uma música de uma Playlist
* @param Musica &m - referencia da Música
*/
Playlist Playlist::operator-(Musica &m)
{
    Playlist nova_playlist;
    Lista *nova_lista = nova_playlist.getLista();

    Musica *m_p = lista->getPrimeira();
    while (m_p != NULL)
    {
        nova_lista->inserirNoInicio(m_p->getNome(), m_p->getTitulo());
        m_p = m_p->getProxima();
    }
    nova_lista->remover(m.getNome(), m.getTitulo());

    return nova_playlist;
}

/** Método sobrecarregando o operador ">>" add a última música da Playlist na referencia de musica e removendo
* @param Musica &m - referencia da Música
*/
void Playlist::operator>>(Musica &m)
{
    if (lista->getPrimeira() != NULL)
    {
        m.setNome(lista->getUltima()->getNome());
        m.setTitulo(lista->getUltima()->getTitulo());
        lista->removerUltima();
    }
}

/** Método sobrecarregando o operador "<<" add uma música ao final da Playlist
* @param Musica &m - referencia da Música
*/
void Playlist::operator<<(Musica &m)
{
    if (lista->getPrimeira() != NULL)
    {
        lista->getUltima()->setProxima(&m);
    }
}
