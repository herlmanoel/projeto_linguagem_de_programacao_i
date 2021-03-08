imd0030: main.o util.o
	g++ -o imd0030 -Wall -ansi -pedantic main.o util.o

main.o: main.cpp Lista.h
	g++ -c main.cpp

util.o: util.cpp util.h
	g++ -c util.cpp

Musica.o: Musica.cpp Musica.h
	g++ -c Musica.cpp

Lista.o: Lista.cpp Lista.h
	g++ -c Lista.cpp

Lista.o: Playlist.cpp Playlist.h
	g++ -c Playlist.cpp

clean: 
	rm -rf *.o imd0030
