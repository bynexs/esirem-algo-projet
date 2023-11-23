
#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/
#include <stdlib.h>

enum enum_color {CARREAU, PIQUE, COEUR, TREFLE};
enum enum_joueur {CARTE=0,HIT=0,ARRETER=1,STAND=1,DOUBLE=2,ABANDONNER=3,SURREND=3};

struct Carte{
    int valeur;
    enum enum_color type;
};

typedef struct listeCartes{
    struct Carte carte;
    struct listeCartes* cartenext;
};

typedef struct joueur{
    struct listeCartes;
    int montant;

};

// Fonction pour créer un nouveau nœud
struct listeCartes* createNode(int valeur, int type) {
    struct listeCartes* newNode = (struct listeCartes*)malloc(sizeof(struct listeCartes));
    struct Carte carte;
    carte.type = type;
    carte.valeur = valeur;

    newNode->carte = carte;
    newNode->cartenext = NULL;

    return newNode;
}

void append(struct listeCartes** head, int valeur, int type) {
    struct listeCartes* newNode = createNode(valeur, type);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct listeCartes* current = *head;
        while (current->cartenext != NULL) {
            current = current->cartenext;

        }
        current->cartenext = newNode;
    }
}



void afficherList(struct listeCartes* tete){
    struct listeCartes* courant = tete;
    while (courant != NULL)
    {
        printf("Valeur %d, Type: %d\n", courant->carte.valeur, courant->carte.type);
        courant = courant->cartenext;
    }
    
}



struct listeCartes* findNode(struct listeCartes* head, int index) {
    struct listeCartes* current = head;
    for (int i = 0; i < index && current != NULL; i++) {
        current = current->cartenext;
    }
    return current;
}

void shuffleList(struct listeCartes** head) {
    if (*head == NULL || (*head)->cartenext == NULL) {
        return; // Rien à mélanger.
    }

    int count = 0;
    struct listeCartes* current = *head;
    while (current != NULL) {
        count++;
        current = current->cartenext;
    }
    
    for (int i = count - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        struct listeCartes* noeudI = findNode(*head, i);
        struct listeCartes* noeudJ = findNode(*head, j);

        struct Carte temp = noeudI->carte;
        noeudI->carte = noeudJ->carte;
        noeudJ->carte = temp;
    }
}


void affichage_main(struct listeCartes *premierecarte){ 
    int i=2;

	struct listeCartes *nouvellecarte;
    nouvellecarte=premierecarte->cartenext;
    
    printf("Voici la carte 1 :\n");
    switch (  premierecarte->carte.type )
        {

            case 0:
                printf("Couleur : CARREAU | ") ;
                break;
            case 1:
                printf("Couleur : PIQUE | ") ;
                break;
            case 2:
                printf("Couleur : COEUR | ") ;
                break;
            case 3:
                printf("Couleur : TREFLE | ") ;
                break;
                
            }

            if(premierecarte->carte.valeur<=10){
                printf("Valeur : %d \n",premierecarte->carte.valeur);
            }
            else{
                
                if(premierecarte->carte.valeur==11){
                    printf("Valeur : VALET\n");
                }
                else if(premierecarte->carte.valeur==12){
                    printf("Valeur : DAME\n");
                }
                else if(premierecarte->carte.valeur==13){
                    printf("Valeur : ROI\n");
                }
            }  



    while( nouvellecarte!= NULL){

        printf("Voici la carte %d :\n",i);

        switch ( nouvellecarte->carte.type )
        {

            case 0:
                printf("Couleur : CARREAU | ") ;
                break;
            case 1:
                printf("Couleur : PIQUE | ") ;
                break;
            case 2:
                printf("Couleur : COEUR | ") ;
                break;
            case 3:
                printf("Couleur : TREFLE | ") ;
                break;
                
        }
        if(nouvellecarte->carte.valeur<=10){
            printf("Valeur : %d \n",nouvellecarte->carte.valeur);
        }
        else{
            
            if(nouvellecarte->carte.valeur==11){
                printf("Valeur : VALET\n");
            }
            else if(nouvellecarte->carte.valeur==12){
                printf("Valeur : DAME\n");
            }
            else if(nouvellecarte->carte.valeur==13){
                printf("Valeur : ROI\n");
            }
        }  
            
        i+=1;
        nouvellecarte=nouvellecarte->cartenext;
    }

}

struct listeCartes* CreationDeck(){
    struct listeCartes* myList = NULL;
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= 13; j++){
            append(&myList, j, i);
        }
    }
    return myList;
}

int Init(){
    struct listeCartes mainbanque;
    struct joueur player;
    struct listeCartes* head=CreationDeck();
    shuffleList(head);
}

int valeurmain=0 ;
int count(struct listeCartes* premierecarte){
    valeurmain += premierecarte->carte.valeur;
    struct listeCartes* nouvellecarte;
    nouvellecarte = premierecarte->cartenext;
    while (nouvellecarte != NULL ){
        if (nouvellecarte->carte.valeur > 9){;
            valeurmain += 10;
        }
        else{
            valeurmain+= nouvellecarte->carte.valeur;
        };
        nouvellecarte = premierecarte->cartenext;
    }
    return valeurmain;

}
