all:
	clang -O3		-lSDL2		src/*.c		-o binplot

debug:
	clang -O3		-lSDL2		src/*.c		-o binplot
