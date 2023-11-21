#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/
enum enum_color {CARREAU, PIQUE, COEUR, TREFLE};

struct Carte{

    int valeur; 
    enum enum_color type;

};

typedef struct listeCartes{
    Carte carte[];
};


