#include <iostream>
#include "Musica.h"
using namespace std;

/** Classe responsável por guardar a Música e um endereço para a proxima. 
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
* @param nome - string - nome do artista
* @param titulo - string - titulo da musica
* @param proxima - Musica* - endereço da proxima Música
**/

// Construtor
Musica::Musica()
{
    this->nome = "";
    this->titulo = "";
    this->proxima = NULL;
}

/** Constructor
* @param nome - string - nome do artista
* @param titulo - string - titulo da musica
*/
Musica::Musica(string nome, string titulo)
{
    this->nome = nome;
    this->titulo = titulo;
    this->proxima = NULL;
}

/** Método para acessar o nome do artista
* @return nome - string
*/
string Musica::getNome()
{
    return nome;
}

/** Método para acessar o titulo da Música
* @return titulo - string
*/
string Musica::getTitulo()
{
    return titulo;
}

/** Método para adicionar a proxima Música
* @param musica - Musica*
*/
void Musica::setProxima(Musica *musica)
{
    proxima = musica;
}

/** Método para adicionar a proxima Música
* @param string n - nome do artista
*/
void Musica::setNome(string n)
{
    nome = n;
}

/** Método para adicionar a proxima Música
* @param string t - titulo da música
*/
void Musica::setTitulo(string t)
{
    titulo = t;
}

/** Método para acessar a proxima Música
* @return proxima - Musica*
*/
Musica *Musica::getProxima()
{
    return proxima;
}

/** Método para imprimir o nome e o título da música
*/
void Musica::imprimir()
{
    cout << "nome: " << nome << " titulo: " << titulo << endl;
}

/** Método destructor
* Liberar o espaço da musica 
*/
Musica::~Musica()
{
    delete proxima;
}