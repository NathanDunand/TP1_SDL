#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL_ttf.h>

#include "fonctions_SDL.h"


int main()
{
    /*SDL_Window* fenetre;//déclaration de la fenêtre
    SDL_Event evenements;//événements liés à la fenêtre
    bool terminer=false;
    if(SDL_Init(SDL_INIT_VIDEO)<0)//initiation de la sdl
    {
        printf("Erreur d'initialisation de la SDL: %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    //Créer la fenêtre
    fenetre=SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);
    if(fenetre==NULL)//si erreur
    {
        printf("Erreur à la création d'une fenetre : %s", SDL_GetError());
        SDL_Quit;
        return EXIT_FAILURE;
    }
    //boucle principale
    while(!terminer)
    {
        while(SDL_PollEvent(&evenements))
        {
            switch(evenements.type)
            {
                case SDL_QUIT:
                    terminer=true;
                    break;
                case SDL_KEYDOWN:
                switch(evenements.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        terminer=true;
                        break;
                }
            }
        }
        //Quitter SDL
        SDL_DestroyWindow(fenetre);
        SDL_Quit();
        return 0;
    }   */

    /*SDL_Window* fenetre;//déclaration de la fenêtre
    //Créer la fenêtre
    fenetre=SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);

    if(fenetre==NULL)//si erreur
    {
        printf("Erreur à la création d'une fenetre : %s", SDL_GetError());
        SDL_Quit;
        return EXIT_FAILURE;
    }
    bool terminer=false;

    if(SDL_Init(SDL_INIT_VIDEO)<0)//initiation de la sdl
    {
        printf("Erreur d'initialisation de la SDL: %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    //mettre en place un contexte de rendu de l'écran
    SDL_Renderer* ecran;
    ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);

    //charger img
    SDL_Texture* fond=charger_image("fond.bmp", ecran);

    //boucle principale
    while(!terminer)
    {
        SDL_RenderClear(ecran);
        SDL_RenderCopy(ecran, fond, NULL, NULL);

        SDL_RenderPresent(ecran);
    }

    //libération de l'écran (renderer)
    SDL_DestroyRenderer(ecran);*/







/*CODE QUI FONCTIONNE
    //I nitialisation simple 
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }

    {
        //Création de la fenêtre 
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  640,
                                                                  480,
                                                                  SDL_WINDOW_SHOWN);

        if( pWindow )
        {
            SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voie la fenêtre

            SDL_DestroyWindow(pWindow);
        }
        else
        {
            fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        }
    }

    SDL_Quit();

    return 0;
*/

/*
    //OPEN CLASSROOM + TP
    SDL_Window* fenetre;
    bool terminer=false;

    if(SDL_Init(SDL_INIT_VIDEO)==-1)//demarrage de la sdl
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    

    
    //ouvre une fenêtre
    fenetre=SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600,800,SDL_WINDOW_RESIZABLE);

    

    SDL_Quit();//arrêt de la sdl
    return 0;
*/

    //TP EXO 4
        SDL_Window* fenetre;  
        // Déclaration de la fenêtre
        SDL_Event evenements; 
        // Événements liés à la fenêtre
        bool terminer = false;
        if(SDL_Init(SDL_INIT_VIDEO) < 0) 
        // Initialisation de la SDL
        {
            printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
            SDL_Quit();
            return EXIT_FAILURE;
        }// Créer la fenêtre
        fenetre = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);

        if(fenetre == NULL) // En cas d’erreur
        {
            printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
            SDL_Quit();
            return EXIT_FAILURE;
        }

        // Mettre en place un contexte de rendu de l’écran
        SDL_Renderer* ecran;
        ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
        /*// Charger l’image*/
        SDL_Texture* fond = charger_image( "fond.bmp", ecran );

        //Charger img avec transparence
        Uint32 r=255, g=255, b=255;
        SDL_Texture* objTransparent=charger_image_transparente("obj.bmp",ecran,r,g,b);


        //Paramétrer l'image transparente
        SDL_Rect SrcR;

        int w;
        int h;
        SDL_QueryTexture(objTransparent, NULL, NULL, &w, &h);
        SrcR.x = 0;
        SrcR.y = 0;
        SrcR.w = w; 
        // Largeur de l’objet en pixels (à récupérer)
        SrcR.h = h; 
        // Hauteur de l’objet en pixels (à récupérer)

        SDL_Rect DestR;
        DestR.x = 350;//position d'affichage
        DestR.y = 350;// ""
        DestR.w = w/3;
        DestR.h = h/2;

        //Charger sprite
        Uint32 rSprite=0, gSprite=255, bSprite=255;
        SDL_Texture* sprite=charger_image_transparente("sprites.bmp",ecran,rSprite,gSprite,bSprite);

        //Paramétrer le sprite
        SDL_Rect SrcR_sprite[6];

        int tailleW=0;
        int tailleH=0;

        SDL_QueryTexture(sprite, NULL, NULL, &tailleW, &tailleH);
        //on récupère les infos de sprite

        tailleW=tailleW/3;
        tailleH=tailleH/2;


        int x=0;
        int y=0;
        for(int i=0;i<6;i++)
        {
            if(i==3)
            {
                y=tailleH;
                x=0;
            }
            SrcR_sprite[i].x=x;
            SrcR_sprite[i].y=y;

            SrcR_sprite[i].h=tailleH;
            SrcR_sprite[i].w=tailleW;
            x=tailleW;
        }

        
        SDL_Rect DestR_sprite[6];
        for(int i=0;i<6;i++)
        {
            DestR_sprite[i].x = i > 2 ? 60*(i+1)+100 : 60*(i+1);
            DestR_sprite[i].y =  i > 2 ? 60 : 120;
            DestR_sprite[i].w = tailleW; //Largeur du sprite
            DestR_sprite[i].h = tailleH; //Hauteur du sprite
        }

        //Charger texte
        TTF_Init();
        TTF_Font *font=TTF_OpenFont("./arial.ttf",28);
        SDL_Color color={0,0,0,0};
        char msg[]="TP sur Makefile et SDL";
        SDL_Texture* texte=charger_texte(msg,ecran,font, color);
        SDL_Rect text_position;//position du texte
        text_position.x=10;
        text_position.y=100;

        int wText=0;
        int hText=0;
        SDL_QueryTexture(texte, NULL, NULL, &wText, &hText);
        text_position.w=wText;//Largeur du tecte en pixels
        text_position.h=hText;//Hauteur du texte en pixels

        // Boucle principale
        while(!terminer)
        {
            //RenderCopy permet d'afficher
            SDL_RenderClear(ecran);
            SDL_RenderCopy(ecran, fond, NULL, NULL);
            SDL_RenderCopy(ecran, objTransparent, &SrcR, &DestR);
            //&SrcR adresse vers le fichier source, &DestR adresse vers la destination affichage ?
            //Appliquer la surface du texte sur l'écran
            SDL_RenderCopy(ecran, texte, NULL, &text_position);

            for(int i=0;i<6;i++)
            {
                SDL_RenderCopy(ecran, sprite, &SrcR_sprite[i], &DestR_sprite[i]);
            }

            while( SDL_PollEvent( &evenements ) )
                switch(evenements.type)
                {
                    case SDL_QUIT:terminer = true;
                    break;
                    case SDL_KEYDOWN:
                        switch(evenements.key.keysym.sym)
                        {
                            case SDLK_ESCAPE:
                            case SDLK_q:
                            terminer = true;
                            break;
                        }
                }
            SDL_RenderPresent(ecran);
        }

        //Libération de l'écran
        SDL_DestroyRenderer(ecran);
        // Quitter SDL
        SDL_DestroyWindow(fenetre);
        SDL_Quit();
        return 0;
}

