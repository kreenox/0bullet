

#include "vid/vid.h"



int main(int argc, char *argv[])
{
	int cont; //verifie si on continue
	SDL_Window *mainwin;
	SDL_Event ev;

	mainwin = initVid();
	cont = 1;

	while(cont)
	{
		SDL_PollEvent(&ev);
		switch(ev.type)
		{
			case SDL_QUIT:
				cont = 0;
				break;
			default:
				break;
		}
	}

	freeVid(mainwin);
}
