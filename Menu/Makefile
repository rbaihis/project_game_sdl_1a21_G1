menu:mainbyme.o option.o jouer.o SousMenu.o
	gcc mainbyme.o option.o jouer.o SousMenu.o -o menu -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g
mainbyme.o:mainbyme.c
	gcc -c mainbyme.c   -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g
option.o:option.c
	gcc -c option.c   -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g
jouer.o:jouer.c
	gcc -c jouer.c   -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g
SousMenu.o:SousMenu.c
	gcc -c SousMenu.c   -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g	
	
clean:
	rm -fr menu mainbyme.o option.o jouer.o SousMenu.o
execute:
	./menu
