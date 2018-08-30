


#include "vid.h"


SDL_Window *initVid()
{
	SDL_Window *res;
	SDL_Renderer *ren;

	if(SDL_Init(SDL_INIT_VIDEO))
	{
		fprintf(stderr, "erreur a l'initialisation de la SDL : %s", SDL_GetError());
		return NULL;
	}
	
	res = SDL_CreateWindow("client", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
	if(res == NULL)
	{
		fprintf(stderr, "creation de la fenetre a echoue : %s\n", SDL_GetError());
		SDL_Quit();
		return NULL;
	}

	ren = SDL_CreateRenderer(res, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	if(ren == NULL)
	{
		fprintf(stderr, "creation du renderer a echoue : %s\n", SDL_GetError());
		SDL_DestroyWindow(res);
		SDL_Quit();
		return NULL;
	}

	return res;

}

//this should be called only once just before you quit the program

void freeVid(SDL_Window *w)
{
	SDL_Renderer *ren;

	ren = SDL_GetRenderer(w);
	
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(w);
	SDL_Quit();
}
