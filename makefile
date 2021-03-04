imd0030: main.o util.o
	g++ -o imd0030 -Wall -ansi -pedantic main.o util.o

main.o: main.cpp Musica.h Lista.h Playlist.h
	g++ -c main.cpp

util.o: util.cpp util.h
	g++ -c util.cpp

clean: 
	rm -rf *.o imd0030
