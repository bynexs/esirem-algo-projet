#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/
enum enum_color {CARREAU, PIQUE, COEUR, TREFLE};

struct Carte{

    int valeur; 
    enum enum_color type;

};

typedef struct listeCartes{
    struct Carte carte[];
};


enum enum_color {CARTE=0,HIT=0,ARRETER=1,STAND=1,DOUBLE=2,ABANDONNER=3,SURREND=3};
