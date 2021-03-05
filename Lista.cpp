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
Lista::Lista(const Lista& l) {
    cout << "Constructor copia!" << endl;
    this->primeira = l.primeira;
    ultima = l.ultima;
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
void Lista::inserirNoInicio(Lista *listaDeMusica)
{
    listaDeMusica->getUltima()->setProxima(primeira);
    primeira = listaDeMusica->getPrimeira();
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
    Musica *temporaria = new Musica();

    if (primeira->getNome().compare(nome) == 0 && primeira->getTitulo().compare(titulo) == 0)
    {
        cout << "1. ENTROU" << endl;
        primeira = primeira->getProxima();
    }
    else if (primeira->getProxima()->getNome().compare(nome) == 0 && primeira->getProxima()->getTitulo().compare(titulo) == 0)
    {
        cout << "2. ENTROU" << endl;
        temporaria = primeira->getProxima();
        primeira->setProxima(primeira->getProxima()->getProxima());
        delete temporaria;
    }
    else
    {
        cout << "3. ENTROU" << endl;
        musica = primeira->getProxima()->getProxima();
        anterior = musica;
        while (musica != NULL)
        {
            cout << musica->getNome() << endl;
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

void Lista::remover(Lista *listaDeMusica)
{
    Musica *musica_excluir = listaDeMusica->getPrimeira();
    
    while (musica_excluir != NULL) {
        Musica *musica = primeira;
        Musica *anterior = musica;
        while (musica != NULL) {
            cout << musica_excluir->getNome() << endl;
            if (musica->getNome().compare(musica_excluir->getNome()) == 0 
                && musica->getTitulo().compare(musica_excluir->getTitulo()) == 0) {
                if(musica->getNome().compare(anterior->getNome()) == 0 
                && musica->getTitulo().compare(anterior->getTitulo()) == 0) {
                    primeira = primeira->getProxima();
                    cout << "AQUI!" << endl;
                    break;
                } else {
                    // cout << "AQUI!" << endl;
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

/** Método destructor
* Liberar o espaço da lista 
*/
Lista::~Lista()
{
    delete primeira;
    delete ultima;
}