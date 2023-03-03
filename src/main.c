#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"

#include "SDL2/SDL.h"

#include "util.h"



int main(int ac, char** av){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window*	 window;
	SDL_Surface* screen;	
	window = SDL_CreateWindow("Binplot",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				1600, 900, SDL_WINDOW_SHOWN);
	screen = SDL_GetWindowSurface(window);
	
	SDL_Surface* fontSurface = SDL_LoadBMP("font.bmp");
	fontSurface = SDL_ConvertSurfaceFormat(fontSurface, SDL_PIXELFORMAT_ABGR8888, 0);
	
	char** 		paths;
	uint8_t**	files;
	int64_t*	sizes;
	int			filect;
	if(ac > 1){
		paths = alloca(sizeof(char    *) * (ac-1));
		files = alloca(sizeof(uint8_t *) * (ac-1));
		sizes = alloca(sizeof(uint64_t*) * (ac-1));
		
		for(int i = 1; i < ac; i++){
			paths[i-1] = av[i];
			char* text;
			loadFile(av[i], &text, &sizes[i-1]);
			files[i-1] = (uint8_t*)text;
		}
		filect = ac-1;
	}
	

	int cont = 1;
	while(cont){
		SDL_Event e;
		while(SDL_PollEvent(&e)){
			switch(e.type){
				case SDL_QUIT : cont = 0; break;
				case SDL_MOUSEMOTION : {
					
				}break;
				
				case SDL_MOUSEBUTTONDOWN : {
					
				}break;
				
				case SDL_MOUSEBUTTONUP   : {
					
				}break;
				
				case SDL_MOUSEWHEEL : {
					
				}break;
			}
		}
		
		SDL_UpdateWindowSurface(window);
		SDL_Delay(16);
	}
	SDL_Quit();
}
