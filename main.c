#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/


struct Carte{

    int valeur; 
    enum enum_color type;

};

enum enum_color {CARREAU, PIQUE, COEUR, TREFLE};
