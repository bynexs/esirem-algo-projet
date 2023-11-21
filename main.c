#include <stdio.h> 


enum enum_color {CARREAU, PIQUE, COEUR, TREFLE};

struct Carte{

    int valeur; 
    enum enum_color type;

};

typedef struct listeCartes{
    Carte carte[];
};

typedef struct joueur{
    struct listeCartes;
    int = montant;
    
};