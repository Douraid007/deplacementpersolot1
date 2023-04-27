#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"


void initialiser_imageBACK(image *imge)
{
    imge->url = "back.png";
    imge->img = IMG_Load(imge->url);
    if (imge->img == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }
    imge->pos_img_ecran.x = 0;
    imge->pos_img_ecran.y = 0;
    imge->pos_img_affiche.x = 0;
    imge->pos_img_affiche.y = 0;
    imge->pos_img_affiche.h = SCREEN_H;
    imge->pos_img_affiche.w = SCREEN_W;
}
void initialiser_image(image *image, char path[],int x,int y)
{
   
    (*image).url=path;
    (*image).img=IMG_Load((*image).url);
    if((*image).img==NULL)
    {
        printf("Unable to load background image %s \n",SDL_GetError());
        
    }
    (*image).pos_img_ecran.x=x;
    (*image).pos_img_ecran.y=y;
    (*image).pos_img_affiche.x=0;
    (*image).pos_img_affiche.y=0;
    (*image).pos_img_affiche.h=SCREEN_H;
    (*image).pos_img_affiche.w=SCREEN_W;
}
void afficher_imageBMP(SDL_Surface *screen, image imge)
{
    SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}

void liberer_image(image imge)
{
    SDL_FreeSurface(imge.img);
}

void initPerso(Personne *p)
{
    p->position.x = 0;
    p->position.y = SCREEN_H - 350;
    p->current_image = 0;
    p->direction = 1;
    p->move = 0;
    p->images[0] = IMG_Load("./image/jou.png");
    p->images[1] = IMG_Load("./image/jou1.png");
    p->images[2] = IMG_Load("./image/jou2.png");
    p->images[3] = IMG_Load("./image/jou3.png");
    p->images[4] = IMG_Load("./image/jou4.png");
    p->images[5] = IMG_Load("./image/jou5.png");
    p->images[6] = IMG_Load("./image/jou6.png");
    p->images[7] = IMG_Load("./image/jou7.png");
    p->images[8] = IMG_Load("./image/jour.png");
    p->images[9] = IMG_Load("./image/jour1.png");
    p->images[10] = IMG_Load("./image/jour2.png");
    p->images[11] = IMG_Load("./image/jour3.png");
    p->images[12] = IMG_Load("./image/jour4.png");
    p->images[13] = IMG_Load("./image/jour5.png");
    p->images[14] = IMG_Load("./image/jour6.png");
    p->images[15] = IMG_Load("./image/jour7.png");
}
void afficherPerso(Personne p, SDL_Surface * screen)
{
    SDL_BlitSurface(p.images[p.current_image], NULL, screen, &(p.position));
}

void deplacerPerso(Personne *p)
{
    if(p->move == 1)
    {
       
        p->position.x += p->direction * 2;
        if(p->position.x > SCREEN_W-60 || p->position.x < 0)
        {
            p->direction = 0;
            p->move = 0;
        }
    }

}
void saut(Personne* p,int *jump,int* jump_speed){
    if (*jump) {
        p->position.y -= *jump_speed;
        (*jump_speed)--; 
    }

        if (p->position.y >= SCREEN_H - 350) { 
            *jump = 0; 
            p->position.y = SCREEN_H -350;
        }
    
}
void animerPerso(Personne* p,int left)
{
    static int counter = 0;
    const int animation_speed = 8;  
    static int change = 0;
    counter++;
    if (counter >= animation_speed)
    {
        if(p->move == 0)
        {
            if(left)
            {
                p->current_image = 8 + change;
                change= (change + 1) % 2;
            }
            else
            {
                p->current_image = 0 + change;
                change= (change + 1) % 2;
            }
        }
        else
        {
            if(left)
            {
                p->current_image++;
                if(p->current_image < 9 || p->current_image > 15)
                {
                    p->current_image = 8;
                }
            }
            else
            {
                p->current_image--;
                if(p->current_image < 1 || p->current_image > 7)
                {
                    p->current_image = 7;
                }
               
            }
        }
        
        counter = 0;
    }
}
void initialiser_texte(texte *txte, char police[],int taille,int r,int g,int b, int x, int y)
{
    TTF_Init(); 
    (*txte).police = TTF_OpenFont(police,taille);
    (*txte).color_txt.r=r;
    (*txte).color_txt.g=g;
    (*txte).color_txt.b=b;
    (*txte).pos_txt.x=x;
    (*txte).pos_txt.y=y;
}
void afficher_texte(SDL_Surface *screen, texte txte, char message[])
{

    txte.txt=TTF_RenderText_Blended(txte.police,message,txte.color_txt);
    SDL_BlitSurface(txte.txt,NULL,screen,&txte.pos_txt);
}
void afficher_texte4(SDL_Surface *screen,int maxi, texte txte4)
{
    char ch[20];
    sprintf(ch,"%d",maxi);
    txte4.txt = TTF_RenderText_Blended(txte4.police,ch,txte4.color_txt);
    SDL_BlitSurface(txte4.txt, NULL, screen, &txte4.pos_txt);
    
}
void liberer_texte(texte txte)
{
    TTF_CloseFont(txte.police);
    TTF_Quit();
}
void initPerso1(Personne1 *pg)
{
    pg->position.x = 1000;
    pg->position.y = SCREEN_H - 343;
    pg->current_image = 0;
    pg->direction = 1;
    pg->move = 0;
    pg->images[0] = IMG_Load("./image1/pers1.png");
    pg->images[1] = IMG_Load("./image1/pers2.png");
    pg->images[2] = IMG_Load("./image1/pers3.png");
    pg->images[3] = IMG_Load("./image1/pers4.png");
    pg->images[4] = IMG_Load("./image1/pers5.png");
    pg->images[5] = IMG_Load("./image1/pers5.png");
    pg->images[6] = IMG_Load("./image1/pers6.png");
    pg->images[7] = IMG_Load("./image1/pers7.png");
    pg->images[8] = IMG_Load("./image1/per.png");
    pg->images[9] = IMG_Load("./image1/per1.png");
    pg->images[10] = IMG_Load("./image1/per2.png");
    pg->images[11] = IMG_Load("./image1/per3.png");
    pg->images[12] = IMG_Load("./image1/per4.png");
    pg->images[13] = IMG_Load("./image1/per5.png");
    pg->images[14] = IMG_Load("./image1/per6.png");
    pg->images[15] = IMG_Load("./image1/per7.png");
}
void afficherPerso1(Personne1 pg, SDL_Surface * screen)
{
    SDL_BlitSurface(pg.images[pg.current_image], NULL, screen, &(pg.position));
}

void deplacerPerso1(Personne1 *pg)
{
    if(pg->move == 1)
    {
       
        pg->position.x += pg->direction * 2;
        if(pg->position.x > SCREEN_W-60 || pg->position.x < 0)
        {
            pg->direction = 0;
            pg->move = 0;
        }
    }

}
void saut1(Personne1* pg,int *jump1,int* jump_speed1){
    if (*jump1) {
        pg->position.y -= *jump_speed1;
        (*jump_speed1)--; 
}
        if (pg->position.y >= SCREEN_H - 343) { 
            *jump1 = 0; 
            pg->position.y=SCREEN_H - 343;

        }

}
void animerPerso1(Personne1* pg,int left1)
{
    static int counter = 0;
    const int animation_speed = 10;  
    static int change = 0;
    counter++;
    if (counter >= animation_speed)
    {
        if(pg->move == 0)
        {
            if(left1)
            {
                pg->current_image = 8 + change;
                change= (change + 1) % 2;
            }
            else
            {
                pg->current_image = 0 + change;
                change= (change + 1) % 2;
            }
        }
        else
        {
            if(left1)
            {
                pg->current_image++;
                if(pg->current_image < 9 || pg->current_image > 15)
                {
                    pg->current_image = 8;
                }
            }
            else
            {
                pg->current_image--;
                if(pg->current_image < 1 || pg->current_image > 7)
                {
                    pg->current_image = 7;
                }
               
            }
        }
        
        counter = 0;
    }
}



