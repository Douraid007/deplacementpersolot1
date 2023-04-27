#include <stdio.h> 
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"

int main (){
    SDL_Surface *screen;
    image IMAGE,IMAGE_BTN;
    SDL_Event event ;
    Personne perso;
    Personne1 perso1;
    texte txte,txte1,txte2;
    int boucle=1;
    int flag=0;
    int left=0,maxi=0,left1,flag1=0;
    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_TIMER)==-1){
        printf("Could not initialisze SDL : %s .\n",SDL_GetError());
        return -1;
    }

    SDL_WM_SetCaption("HelloWorld", "Hello World");
    screen = SDL_SetVideoMode (SCREEN_W,SCREEN_H,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
    initialiser_texte(&txte,"police.ttf",30,255,255,255,20,60);
    initialiser_texte(&txte1,"police.ttf",30,255,255,255,150,60);
    initialiser_texte(&txte2,"police.ttf",40,255,255,255,275,55);
    initialiser_image(&IMAGE_BTN,"live.png",220,55);
    initialiser_imageBACK (&IMAGE);
    initPerso(&perso);
    initPerso1(&perso1);
while (boucle)
{
    
    afficher_imageBMP(screen,IMAGE);
    afficherPerso(perso, screen);
    //animerPerso(&perso,left);
    afficherPerso1(perso1, screen);
    animerPerso(&perso,left);
    animerPerso1(&perso1,left1);
    afficher_texte(screen,txte,"score:");
    afficher_texte(screen,txte2,"3");
    afficher_imageBMP(screen,IMAGE_BTN);
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            boucle=0;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=300 && event.motion.y>=250 && event.motion.x<=423 && event.motion.x>213)){
                boucle=0;
            }
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                left=0;
                perso.direction = 1;
                perso.move = 1;
                maxi=maxi+10;
                break;
            case SDLK_LEFT:
                left=1;
                perso.direction = -1;
                perso.move = 1;
                maxi=maxi+10;
                break;
            case SDLK_UP: 
                    flag = 1; 
                    perso.jump_speed = 22;
                maxi=maxi+20; 
                break;
            case SDLK_LSHIFT:
                if(perso.direction>=0)
                {
               
                    perso.direction = 5;
                    maxi=maxi+50;
                }
                else
                {
                    perso.direction = -5;
                    maxi=maxi+50;

                }
                if(perso1.direction>=0)
                {
               
                    perso1.direction = 5;
                    maxi=maxi+50;
                }
                else
                {
                    perso1.direction = -5;
                    maxi=maxi+50;

                }
            break;

        
            case SDLK_d:
                left1=1;
                perso1.direction = 1;
                perso1.move = 1;
                maxi=maxi+10;
                break;
            case SDLK_q:
                left1=0;
                perso1.direction = -1;
                perso1.move = 1;
                maxi=maxi+10;
                break;
            case SDLK_z: 
                    flag1 = 1; 
                    perso1.jump_speed1= 22;
                maxi=maxi+20; 
                break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                perso.move=0;
                break;
            case SDLK_LEFT:
                perso.move=0;
                break;
            case SDLK_d:
                perso1.move=0;
                break;
            case SDLK_q:
                perso1.move=0;
                break;
            case SDLK_LSHIFT:
                 if(perso.direction>=0)
                {
               
                    perso.direction = 1;
                    maxi=maxi+50;
                }
                else
                {
                    perso.direction = -1;
                    maxi=maxi+50;

                }
                if(perso1.direction>=0)
                {
               
                    perso1.direction = 1;
                    maxi=maxi+50;
                }
                else
                {
                    perso1.direction = -1;
                    maxi=maxi+50;

                }
                break;
            }
            break;
        }
    }    
    
    saut(&perso, &flag, &perso.jump_speed);
    saut1(&perso1, &flag1, &perso1.jump_speed1);
    SDL_Delay(5);
    deplacerPerso(&perso);
    deplacerPerso1(&perso1);
    afficher_texte4(screen,maxi,txte1);
    SDL_Flip(screen);
}
    liberer_texte(txte);
    liberer_image (IMAGE);
    SDL_Quit();
    return 0;
}
    
    
    
    
        
