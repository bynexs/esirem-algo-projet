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


typedef struct joueur{
    struct listeCartes listeCartes;
    int montant;
    
};

void affichage_main(struct main main[]){
    int i=0; 
    
    for(i=0;i<sizeof(main)+1;i++){
        printf("Voici la carte %d :\n", i+1);
        printf("Valeur : %d | Couleur : %d\n", main.valeur[i], main.type[i]);
    }
}