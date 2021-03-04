# IMD0030 - 2020.2 - Atividade 1

Atividade desenvolvida por *Herlmanoel Fernandes Barbosa (20190052434)*, apresentada a disciplina de *Linguagem de Programação I* com a orientação do *Prof. Dr. Renan Cipriano Moioli*.
A proposta da atividade foi criar uma aplicação para gerenciamento de playlists, utilizando os conteúdos repassados em aula.
Para compilar e rodar o programa utilizamos o *makefile* que é um arquivo contendo um conjunto de diretivas usadas para automatizar a compilação e gerar um executável.
Desse modo, abaixo temos um exemplo de como compilar, executar e, assim, gerenciar as playlists.
No sistema Linux, para executar o makefile, abra o terminal na pasta do projeto e digite: 
```shell
make
```
Com esse comando será criado o executável imd0030, agora para executa-lo:
```shell
./imd0030
```
Serão apresentado as opções:

```shell
Bem vindo ao seu gerenciador de Playlists!

Operacoes:
1: Criar playlist
2: Adicionar musica
3: Remover musica
4: Retornar proxima musica
5: Imprimir todas as musicas
6: Remover Playlist
7: Listar Playlists
0: Para sair.
```
Digitando "1" no terminal, temos:
```shell
1
-----------------------------
Criar Playlist
-----------------------------
Digite o nome da Playlist: 
Forro
```
Com isso, a playlist Forro foi criada e, para ela, temos as opções citadas acima.
___
Digitando "2" no terminal, escolhemos qual a playlist (buscando pelo nome) para adicionamos a música, respondendo as perguntas:
```shell
2
Qual playlist?
Forro
-----------------------------
Adicionando musica
-----------------------------
Qual o titulo da musica?
Deus Me Proteja
Qual o nome do artista?
Chico Cesar
```
Música com o título Deus Me Proteja e nome do artista Chico Cesar, adicionada a playlist Forro.

___
Digitando "3" no terminal, escolhemos qual a música (buscando pelo título e nome do artista) para excluí-la (a música será excluída de todas as playlists):
```shell
3
-----------------------------
Remover musica.
Lembrando que a musica sera removida de todas as playlists.
-----------------------------
Qual o titulo da musica?
Deus Me Proteja
Qual o nome do artista?
Chico Cesar
```
___
Digitando "5" no terminal, escolhemos qual a playlist para impressão de todas as suas músicas:
```shell
5
-----------------------------
Imprimir todas as musica
-----------------------------

Playlists salvas:
0: Forro
1: Internacionais
-----------------------------
Imprimindo todas as musicas
Qual playlist?
Forro

Deus Me Proteja
Chico Cesar
-----------------------------
```
___
Digitando "6" no terminal, temos a possibilidade de remover alguma playlist:
 ```shell
 6
-----------------------------
Remover playlist
-----------------------------
0: Forro
1: Internacionais
Qual playlist?
Internacionais

-----------------------------
Todas as playlists
-----------------------------
0: Forro
 ```
 ___
 Digitando "7" no terminal, serão impressas todas as playlists:
```shell
7
-----------------------------
Todas as playlists
-----------------------------
0: Forro
```
 ___
 Digitando "0" no terminal, você para a execução do programa
```shell
0
```
---
Por fim, ainda há a possibilidade da exclusão do executável e dos arquivos que foram utilizadas para geração do executável, com o comando:
```shell
make clean
```