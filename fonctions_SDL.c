#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL_ttf.h>

#include "fonctions_SDL.h"

SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer* renderer)
{
	return SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP(nomfichier));
}

SDL_Texture* charger_image_transparente(const char* nomfichier,SDL_Renderer* renderer,Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Surface* pointeur=SDL_LoadBMP(nomfichier);
	SDL_SetColorKey(pointeur, SDL_TRUE, SDL_MapRGB(pointeur->format, r,g,b));
	return SDL_CreateTextureFromSurface(renderer,pointeur);
}

SDL_Texture* charger_texte(const char* message, SDL_Renderer* renderer, TTF_Font *font, SDL_Color color)
{
	return SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(font, message, color));
}