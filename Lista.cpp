#include <iostream>
#include "Musica.h"
#include "Lista.h"

using namespace std;
using std::cin;
using std::cout;
using std::endl;

Lista::Lista()
{
    primeira = NULL;
    ultima = NULL;
}

/** Constructor. Adiciona a primeira Música
        * @param nome - string - nome do artista
        * @param titulo - string - titulo da musica
        */
Lista::Lista(string nome, string titulo)
{
    Musica *musica = new Musica(nome, titulo);
    primeira = musica;
    ultima = primeira;
    delete musica;
}

/** Constructor cópia. Cria uma cópia exata do objeto
        * @param nome - string - nome do artista
        * @param titulo - string - titulo da musica
        */
Lista::Lista(const Lista &l)
{
    Lista *nova_lista = new Lista();
    Musica *m = l.primeira;
    while (m != NULL)
    {
        nova_lista->inserirNoInicio(m->getNome(), m->getTitulo());
        m = m->getProxima();
    }
    this->primeira = nova_lista->primeira;
    this->ultima = nova_lista->getUltima();
}

/** Método para acessar a primeira Música
* @return primeira - Musica*
*/
Musica *Lista::getPrimeira()
{
    return primeira;
}

Musica *Lista::getUltima()
{
    Musica *musica = primeira;
    while (musica != NULL)
    {
        if (musica->getProxima() == NULL)
        {
            return musica;
            break;
        }
        musica = musica->getProxima();
    }
    return NULL;
}

void Lista::setPrimeira(Musica *m)
{
    primeira = m;
}

/** Método para adicionar musica no inicio da lista
* @param nome - string - nome do artista
* @param titulo - string - titulo da musica
*/
void Lista::inserirNoInicio(string nome, string titulo)
{
    Musica *musica = new Musica(nome, titulo);
    if (primeira == NULL)
    {
        primeira = musica;
        ultima = musica;
    }
    else
    {
        musica->setProxima(primeira);
        primeira = musica;
    }
}

// -------------------------------------------------------------------
void Lista::inserirNoInicio(Lista &listaDeMusica)
{
    listaDeMusica.getUltima()->setProxima(primeira);
    primeira = listaDeMusica.getPrimeira();
}

/** Método para adicionar musica no final da lista
* @param nome - string - nome do artista
* @param titulo - string - titulo da musica
*/
void Lista::inserirNoFinal(string nome, string titulo)
{
    Musica *musica = new Musica(nome, titulo);
    if (primeira == NULL)
    {
        primeira = musica;
        ultima = musica;
    }
    else
    {
        ultima->setProxima(musica);
        ultima = musica;
    }
}

// Método para imprimir todas as Músicas da lista
void Lista::imprimir()
{
    Musica *musica = primeira;

    if (primeira == NULL)
    {
        cout << "Lista sem musica. :(" << endl;
    }
    else
    {
        int cont = 1;
        while (musica != NULL)
        {

            cout << cont++ << "- " << musica->getNome() << " " << musica->getTitulo() << endl;
            musica = musica->getProxima();
        }
        cout << endl;
    }
    delete musica;
}

/** Método para buscar musica na lista pelo nome e titulo 
* @param nome - string - nome do artista
* @param titulo - string - titulo da musica
* @return  musica - Musica*
*/
Musica *Lista::buscarPeloNomeTitulo(string nome, string titulo)
{
    Musica *musica = primeira;

    if (primeira == NULL)
    {
        cout << "Lista vazia. :(" << endl;
    }
    else
    {
        while (musica != NULL)
        {
            if (musica->getNome().compare(nome) == 0 && musica->getTitulo().compare(nome))
            {
                return musica;
                break;
            }
            musica = musica->getProxima();
        }
    }
    delete musica;
    return NULL;
}

/** Método para remover musica na lista
* @param nome - string - nome do artista
* @param titulo - string - titulo da musica
*/
void Lista::remover(string nome, string titulo)
{
    Musica *anterior = new Musica();
    Musica *musica = new Musica();
    Musica *posterior = new Musica();

    if (primeira->getNome().compare(nome) == 0 && primeira->getTitulo().compare(titulo) == 0)
    {
        primeira = primeira->getProxima();
    }
    else if (primeira->getProxima()->getNome().compare(nome) == 0 && primeira->getProxima()->getTitulo().compare(titulo) == 0)
    {
        primeira->setProxima(primeira->getProxima()->getProxima());
    }
    else
    {
        // cout << "AA" << endl;
        musica = primeira->getProxima()->getProxima();
        anterior = musica;
        while (musica != NULL)
        {
            // cout << musica->getNome() << endl;
            if (musica->getNome().compare(nome) == 0 && musica->getTitulo().compare(nome))
            {
                posterior = musica->getProxima();
                anterior->setProxima(posterior);
                break;
            }
            anterior = musica;
            musica = musica->getProxima();
        }
    }
}

/** Método sobrecarregado para remover uma lista de Músicas
* @param Lista - lista de músicas
*/
void Lista::remover(Lista &listaDeMusica)
{
    Musica *musica_excluir = listaDeMusica.getPrimeira();

    while (musica_excluir != NULL)
    {
        Musica *musica = primeira;
        Musica *anterior = musica;
        while (musica != NULL)
        {
            // cout << musica_excluir->getNome() << endl;
            if (musica->getNome().compare(musica_excluir->getNome()) == 0 && musica->getTitulo().compare(musica_excluir->getTitulo()) == 0)
            {
                if (musica->getNome().compare(anterior->getNome()) == 0 && musica->getTitulo().compare(anterior->getTitulo()) == 0)
                {
                    primeira = primeira->getProxima();
                    break;
                }
                else
                {
                    anterior->setProxima(musica->getProxima());
                    break;
                }
            }
            anterior = musica;
            musica = musica->getProxima();
        }
        musica_excluir = musica_excluir->getProxima();
    }
}

/** Método sobrecarregando operador "+" add lista a outra lista
* @param Lista - lista de músicas
*/
Lista Lista::operator+(Lista &lista)
{
    // parcialmente feita
    Lista nova_lista;
    Musica *m = primeira;
    while (m != NULL)
    {
        nova_lista.inserirNoInicio(m->getNome(), m->getTitulo());
        m = m->getProxima();
    }

    Musica *m_1 = lista.getPrimeira();
    Lista nova_lista1;
    while (m_1 != NULL)
    {
        nova_lista1.inserirNoInicio(m_1->getNome(), m_1->getTitulo());
        m_1 = m_1->getProxima();
    }

    nova_lista.getUltima()->setProxima(nova_lista1.getPrimeira());
    return nova_lista;
}

/** Método para remover última música da lista
*/
void Lista::removerUltima()
{
    Musica *musica = primeira;
    Musica *anterior = musica;
    while (musica != NULL)
    {
        if (musica->getProxima() == NULL)
        {
            anterior->setProxima(NULL);
        }
        anterior = musica;
        musica = musica->getProxima();
    }
}

/** Método sobrecarregando operador ">>" add o último elemento da lista a uma música e remove da lista 
* @param Musica* m - música
*/
void Lista::operator>>(Musica *m)
{
    if (primeira != NULL)
    {
        m->setNome(getUltima()->getNome());
        m->setTitulo(getUltima()->getTitulo());
        Lista::removerUltima();
    }
}

/** Método sobrecarregando operador "<<" insere a música na última posição da lista 
* @param Musica* m - música
*/
void Lista::operator<<(Musica *m)
{
    if (primeira != NULL)
    {
        getUltima()->setProxima(m);
    }
}

/** Método destructor
* Liberar o espaço da lista 
*/
Lista::~Lista()
{
    delete primeira;
    delete ultima;
}