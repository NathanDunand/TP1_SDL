/*
//Créer un contexte de rendu de l'image
SDL_Renderer* SDL_CreateRenderer(SDL_Window* window, int index, Uint32 flags);

//Charger une image
SDL_Surface* SDL_LoadBMP(const char* file);

//convertir la surface de l'image au format texture avant de l'appliquer
SDL_Texture* SDL_CreateTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface);

//copier une pertie de la texture dans le renderer
int SDL_RenderCopy(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect);

//Récupérer les attributs d'une texture
int SDL_QueryTexture(SDL_Texture* texture, Uint32* format, int* access, int* w, int* h);

//Libérer une surface
void SDL_FreeSurface(SDL_Surface* surface);

//Libérer une texture
void SDL_DestroyTexture(SDL_Texture* texture);
*/

SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer* renderer);
SDL_Texture* charger_image_transparente(const char* nomfichier,SDL_Renderer* renderer,Uint8 r, Uint8 g, Uint8 b);
SDL_Texture* charger_texte(const char* message, SDL_Renderer* renderer, TTF_Font *font, SDL_Color color);