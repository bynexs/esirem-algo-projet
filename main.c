#include <stdio.h> 


enum enum_color {CARREAU, PIQUE, COEUR, TREFLE};

enum enum_color {CARTE=0,HIT=0,ARRETER=1,STAND=1,DOUBLE=2,ABANDONNER=3,SURREND=3};

struct Carte{

    int valeur; 
    enum enum_color type;

};

typedef struct listeCartes{
    struct Carte carte[];
};


typedef struct joueur{
    struct listeCartes;
    int = montant;
    
};

