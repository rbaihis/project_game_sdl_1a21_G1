game:mainfinal.o init.o background.o perso.o ennemi.o enigme.o
	gcc mainfinal.o init.o background.o perso.o ennemi.o enigme.o -o play -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lm -g
mainfinal.o:mainfinal.c
	gcc -c mainfinal.c  -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lm -g
init.o:init.c
	gcc -c init.c  -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lm -g
background.o:background.c
	gcc -c background.c  -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lm -g
perso.o:perso.c
	gcc -c perso.c  -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lm -g
ennemi.o:ennemi.c
	gcc -c ennemi.c  -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lm -g
enigme.o:enigme.c
	gcc -c enigme.c  -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf -lm -g
clean:
	rm -fr game mainfinal.o init.o background.o perso.o ennemi.o enigme.o
execute:
	./test
