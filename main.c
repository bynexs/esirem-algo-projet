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


int Init(){
  
    struct listeCartes mainbanque;
    struct joueur player;
    CreationDeck();
}


void affichage_main(struct main main[]){
    int i=0; 
    
    for(i=0;i<sizeof(main)+1;i++){
        printf("Voici la carte %d :\n", i+1);
        printf("Valeur : %d | Couleur : %d\n", main.valeur[i], main.type[i]);
    }
}

int traitement_saisie(char str[]){

    if(str=="CARTE" || str=="HIT"){
        return 0;
    }
    else if(str=="ARRETER" || str=="STAND"){
        return 1;
    }
    else if(str=="DOUBLE"){
        return 2;
    }
    else if(str=="ABANDONNER" || str=="SURREND"){
        return 3;
    }
    else{
        return 10; //Pour indiquer que l'utilisateur a rentré une mauvaise saisie
    }

}
