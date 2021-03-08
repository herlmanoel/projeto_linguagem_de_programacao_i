#include <iostream>
#include <vector>
#include "Musica.h"
#include "Lista.h"
#include "Playlist.h"
#include "util.h"

using namespace std;

/** Método responsável exemplificar as operações pedidas no projeto.
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
* @param mensagem - String - Mensagem de boas vindas
* @param opcoes - String - Opções que o usuário possue
* @param linha - String - Frizar as opções
* @param operacao - int - Operação a ser realizada
* @param playlists - Vector<Playlist *> - Vetor de Playlists
**/

int main()
{
    // g++ main.cpp util.cpp Lista.cpp Playlist.cpp Musica.cpp  -Wall -o prog && prog
    Lista list01;
    list01.inserirNoInicio("Flor de Tangerina", "Alceu Valenca");
    list01.inserirNoInicio("Girassol", "Alceu Valenca");
    list01.inserirNoInicio("La Belle de Jour", "Alceu Valenca");
    list01.inserirNoInicio("Valeu", "Dorgival Dantas");

    Lista list02;
    list02.inserirNoInicio("Desta", "Dorgival Dantas");
    list02.inserirNoInicio("Primeiro Passo", "Dorgival Dantas");
    list02.inserirNoInicio("Tarde Demais", "Dorgival Dantas");

    // A. Adicionar elementos
    list01.inserirNoInicio(list02);
    list01.imprimir();

    Lista list03;
    list03.inserirNoInicio("Desta", "Dorgival Dantas");
    list03.inserirNoInicio("Primeiro Passo", "Dorgival Dantas");

    // B. Remover elementos
    list01.remover(list03);
    list01.imprimir();

    // C. Construtor cópia
    Lista list04 = list02;
    list04.imprimir();

    // Usando sobrecarga de operadores
    // A. Operador “+”
    Lista soma(list01 + list02);
    soma.imprimir();

    // B. Operador de extração “>>”
    Musica *musica_teste = new Musica();
    list01 >> musica_teste;
    cout << musica_teste->getNome() << " " << musica_teste->getTitulo() << endl;

    // C. Operador de inserção “<<”
    Musica *m = new Musica("Ate mais ver", "Dorgival Dantas");
    list01 << m;
    list01.imprimir();

    // Classe Playlist
    Playlist playlist01("Forro 01");
    playlist01.adicionarMusicaPlaylist("Flor de Tangerina", "Alceu Valenca");
    playlist01.adicionarMusicaPlaylist("Girassol", "Alceu Valenca");
    playlist01.adicionarMusicaPlaylist("La Belle de Jour", "Alceu Valenca");
    playlist01.adicionarMusicaPlaylist("Valeu", "Dorgival Dantas");

    Playlist playlist02("Forro 02");
    // A. Adicionar músicas
    playlist02.adicionarMusicaPlaylist(playlist01);
    playlist02.imprimirTodasMusicas(playlist02.getLista()->getPrimeira());

    Playlist playlist03("Forro 03");
    playlist03.adicionarMusicaPlaylist("La Belle de Jour", "Alceu Valenca");
    playlist03.adicionarMusicaPlaylist("Valeu", "Dorgival Dantas");

    // B. Remover músicas
    playlist02.removerMusica(playlist03);

    // C. Construtor cópia
    Playlist playlist04 = playlist01;
    playlist04.imprimirTodasMusicas(playlist04.getLista()->getPrimeira());

    // A. Operador “+”
    Playlist soma_pl(playlist04 + playlist03);
    soma_pl.imprimirTodasMusicas(soma_pl.getLista()->getPrimeira());

    // B. Operador “+”
    Musica musica01("Conselho Amigo", "Dorgival Dantas");
    Playlist soma_m_p(playlist01 + musica01);

    Playlist playlist05;
    playlist05.adicionarMusicaPlaylist("Flor de Tangerina", "Alceu Valenca");
    playlist05.adicionarMusicaPlaylist("Girassol", "Alceu Valenca");
    playlist05.adicionarMusicaPlaylist("La Belle de Jour", "Alceu Valenca");
    playlist05.adicionarMusicaPlaylist("Valeu", "Dorgival Dantas");

    Playlist playlist06;
    playlist06.adicionarMusicaPlaylist("La Belle de Jour", "Alceu Valenca");
    playlist06.adicionarMusicaPlaylist("Valeu", "Dorgival Dantas");

    // C. Operador “-”
    Playlist sub_pl1(playlist05 - playlist06);
    sub_pl1.imprimirTodasMusicas(sub_pl1.getLista()->getPrimeira());

    // D. Operador “-”
    Musica musica02("Valeu", "Dorgival Dantas");
    Playlist sub_pl2(playlist05 - musica02);
    sub_pl2.imprimirTodasMusicas(sub_pl2.getLista()->getPrimeira());

    Musica musica03;
    // E. Operador de extração “>>”
    playlist06 >> musica03;
    cout << musica03.getNome() << " " << musica03.getTitulo() << endl;

    Musica musica04("Pra Voce Voltar Pra Mim", "Dorgival Dantas");
    // F. Operador de inserção “<<”
    playlist06 << musica04;
    playlist06.imprimirTodasMusicas(playlist06.getLista()->getPrimeira());

    return 0;
}