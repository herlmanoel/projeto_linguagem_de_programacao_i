#include <iostream>
#include <vector>
#include "Musica.h"
#include "Lista.h"
#include "Playlist.h"
#include "util.h"

using namespace std;

/** Método responsável por gerir as Playlists.
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
    string mensagem = "\nBem vindo ao seu gerenciador de Playlists!\n";
    string opcoes = "\nOperacoes \n1: Criar playlist \n2: Adicionar musica \n3: Remover musica \n4: Retornar proxima musica\n5: Imprimir todas as musicas \n6: Remover Playlist\n7: Listar Playlists \n0: Para sair.\n\n";
    string linha = "-----------------------------";
    int operacao;
    vector<Playlist *> playlists;

    cout << mensagem << endl;
    // ---------------------------------------------------
    Playlist *nova_playlist1 = new Playlist("aa");
    playlists.push_back(nova_playlist1);

    Playlist *nova_playlist2 = new Playlist("bb");
    playlists.push_back(nova_playlist2);

    Playlist *nova_playlist3 = new Playlist("cc");
    playlists.push_back(nova_playlist3);

    playlists[0]->adicionarMusicaPlaylist("ni", "ja");
    playlists[1]->adicionarMusicaPlaylist("ni", "ja");
    playlists[2]->adicionarMusicaPlaylist("ni", "ja");

    playlists[0]->adicionarMusicaPlaylist("nem eu seiaaaaaa", "jjjjja");
    playlists[1]->adicionarMusicaPlaylist("nem eu seibbbbbbb", "kkkkkja");
    playlists[2]->adicionarMusicaPlaylist("nem eu seiccccccccc", "ooooooooja");

    playlists[0]->imprimirTodasMusicas(playlists[0]->getLista()->getPrimeira());

    // ------------------------------------------------------------- Parte 2
    // g++ main.cpp util.cpp Lista.cpp  -Wall -o prog && prog
    Lista l;
    Lista* l1= new Lista();
    l1->inserirNoInicio("4", "4"); l1->inserirNoInicio("3", "3"); l1->inserirNoInicio("2", "2");
    l.inserirNoInicio("8", "8"); l.inserirNoInicio("7", "7"); l.inserirNoInicio("6", "6"); 

    // teste add lista a lista
    l1->inserirNoInicio(l);
    l1->imprimir();

    // Lista *musicas_para_remover = new Lista();
    // musicas_para_remover->inserirNoInicio("1", "1");
    // musicas_para_remover->inserirNoInicio("3", "3");
    // musicas_para_remover->inserirNoInicio("8", "8");

    // l->remover(musicas_para_remover);
    // l->imprimir();

    // Lista paraCopiar;
    // paraCopiar.inserirNoInicio("A", "A");
    // paraCopiar.inserirNoInicio("A", "A");
    // paraCopiar.inserirNoInicio("A", "A");
    // Lista copiada = paraCopiar;
    // copiada.imprimir();
    
    // Operador “+”
    // Lista ll1;
    // ll1.inserirNoInicio("A", "A");
    // ll1.inserirNoInicio("A", "A");
    // ll1.inserirNoInicio("A", "A");
    // Lista ll2;
    // ll2.inserirNoInicio("B", "B");
    // ll2.inserirNoInicio("B", "B");
    // ll2.inserirNoInicio("B", "B");
    // Lista ll3;
    // ll3.inserirNoInicio("C", "C");
    // ll3.inserirNoInicio("C", "C");


    // Lista soma(ll1 + ll2);
    // soma.imprimir();

    // ll1.imprimir();
    // ll2.imprimir();

    // Musica* musica_teste = new Musica();
    // ll2 >> musica_teste;

    // ll2.imprimir();
    // musica_teste->imprimir();

    // ll3 << musica_teste;
    // ll3.imprimir();

    // g++ main.cpp util.cpp Lista.cpp -Wall -o prog && prog
    // ------------------------------------------------
    // do
    // {
    //     cout << opcoes << endl;
    //     cin >> operacao;

    //     switch (operacao)
    //     {
    //     case 1:
    //     {
    //         cout << endl
    //              << linha << endl;
    //         cout << "Criar Playlist" << endl;
    //         cout << linha << endl;
    //         string nomePlaylist;
    //         cout << "Digite o nome da Playlist: " << endl;
    //         cin >> nomePlaylist;
    //         Playlist *nova_playlist = new Playlist(nomePlaylist);
    //         playlists.push_back(nova_playlist);
    //         break;
    //     }
    //     case 2:
    //     {
    //         Playlist *playlist = qualPlaylist(playlists);
    //         cout << endl
    //              << linha << endl;
    //         cout << "Adicionando musica" << endl;
    //         cout << linha << endl;

    //         string tituloDaMusica = lerTituloMusica();
    //         string nomeDoArtista = lerNomeArtista();

    //         playlist->adicionarMusicaPlaylist(tituloDaMusica, nomeDoArtista);

    //         break;
    //     }
    //     case 3:
    //     {
    //         cout << endl
    //              << linha << endl;
    //         cout << "Remover musica." << endl;
    //         cout << "Lembrando que a musica sera removida de todas as playlists." << endl;
    //         cout << linha << endl;

    //         string tituloDaMusica = lerTituloMusica();
    //         string nomeDoArtista = lerNomeArtista();

    //         int tam = (int)playlists.size();
    //         for (int i = 0; i < tam; i++)
    //         {
    //             playlists[i]->removerMusica(tituloDaMusica, nomeDoArtista);
    //         }
    //         break;
    //     }
    //     case 4:
    //     {
    //         cout << endl
    //              << linha << endl;
    //         cout << "Proxima musica" << endl;
    //         cout << linha << endl;
    //         Playlist *playlist = qualPlaylist(playlists);
    //         Musica *musica = playlist->getProximaMusica(playlist->getLista()->getPrimeira());
    //         cout << musica->getNome() << " - " << musica->getTitulo() << endl;
    //         break;
    //     }
    //     case 5:
    //     {
    //         cout << endl
    //              << linha << endl;
    //         cout << "Imprimir todas as musica" << endl;
    //         cout << linha << endl;
    //         cout << "\nPlaylists salvas: " << endl;
    //         imprimirTodasPlaylists(playlists);
    //         cout << linha << endl;
    //         cout << "Imprimindo todas as musicas" << endl;
    //         Playlist *imprimir_playlist = qualPlaylist(playlists);
    //         imprimir_playlist->imprimirTodasMusicas(imprimir_playlist->getLista()->getPrimeira());
    //         break;
    //     }
    //     case 6:
    //     {
    //         cout << endl
    //              << linha << endl;
    //         cout << "Remover playlist" << endl;
    //         cout << linha << endl;
    //         imprimirTodasPlaylists(playlists);
    //         vector<Playlist *> *ref_playlists = &playlists;
    //         removerPlaylist(ref_playlists);
    //     }
    //     case 7:
    //     {
    //         cout << endl
    //              << linha << endl;
    //         cout << "Todas as playlists" << endl;
    //         cout << linha << endl;
    //         imprimirTodasPlaylists(playlists);
    //     }
    //     }
    // } while (operacao != 0);

    return 0;
}