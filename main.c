#include <stdio.h> 


enum enum_color {CARREAU, PIQUE, COEUR, TREFLE};

enum enum_joueur {CARTE=0,HIT=0,ARRETER=1,STAND=1,DOUBLE=2,ABANDONNER=3,SURREND=3};

struct Carte{
    int valeur;
    enum enum_color type;
};

typedef struct listeCartes{

    struct Carte carte[52];
};

int CreationDeck(){
    struct listeCartes listecarte;
    int compt  = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= 13; j++){
            struct Carte carte;
            carte.valeur = j;
            carte.type = i;
            listecarte.carte[compt] = carte;
            compt ++;
        }
    }
}
    struct Carte carte[];
};

int Init(){
  
    struct listeCartes mainbanque;
    struct joueur player;
    CreationDeck();
}


typedef struct joueur{
    struct listeCartes;
    int montant;
    
};