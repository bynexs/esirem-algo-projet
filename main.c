#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/
enum enum_color {CARREAU, PIQUE, COEUR, TREFLE};

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