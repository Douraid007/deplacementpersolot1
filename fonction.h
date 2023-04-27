#ifndef FONCTION_H
#define FONCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 800
#define SCREEN_W 1200

typedef struct {
    char *url;
    SDL_Rect pos_img_affiche;
    SDL_Rect pos_img_ecran;
    SDL_Surface *img;
}image;
typedef struct {
    SDL_Rect position;
    SDL_Surface *images[16];
    int current_image;
    int direction;
    int move;
    int jump;
    int jump_speed;
} Personne;
typedef struct {
    SDL_Rect position;
    SDL_Surface *images[16];
    int current_image;
    int direction;
    int move;
    int jump1;
    int jump_speed1;
}Personne1;
typedef struct {
    SDL_Surface *txt;
    SDL_Rect pos_txt;
    SDL_Colour color_txt;
    TTF_Font *police;
}texte;
void initialiser_image(image *image, char path[],int x,int y);
void initialiser_imageBACK (image *imge);
void afficher_imageBMP(SDL_Surface *screen, image imge);
void afficher_image(SDL_Surface *screen,image imge);
void liberer_image (image imge);
void initPerso(Personne *p);
void afficherPerso(Personne p, SDL_Surface * screen);
void deplacerPerso (Personne *p);
void saut(Personne* p,int *jump,int* jump_speed);
void animerPerso(Personne* p,int left);
void initialiser_texte(texte *txte, char police[],int taille,int r,int g,int b, int x, int y);
void afficher_texte(SDL_Surface *screen, texte txte, char message[]);
void afficher_texte4(SDL_Surface *screen,int maxi, texte txte4);
void liberer_texte (texte txte);
void initPerso1(Personne1 *pg);
void afficherPerso1(Personne1 pg, SDL_Surface * screen);
void deplacerPerso1(Personne1 *pg);
void saut1(Personne1* pg,int *jump1,int* jump_speed1);
void animerPerso1(Personne1* pg,int left1);
#endif
