all:
	g++ -Lsrc/lib -Isrc/include -o game src/cpp/*cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image