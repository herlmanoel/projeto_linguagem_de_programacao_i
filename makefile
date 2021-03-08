imd0030: main.o util.o Lista.o Musica.o Playlist.o
	g++ -o imd0030 -Wall -ansi -pedantic main.o util.o Musica.o Lista.o Playlist.o

main.o: main.cpp
	g++ -c main.cpp

util.o: util.cpp util.h
	g++ -c util.cpp

Musica.o: Musica.cpp Musica.h
	g++ -c Musica.cpp

Lista.o: Lista.cpp Lista.h
	g++ -c Lista.cpp

Playlist.o: Playlist.cpp Playlist.h
	g++ -c Playlist.cpp

clean: 
	rm -rf *.o imd0030
