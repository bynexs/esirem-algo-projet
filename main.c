#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/
#include <stdlib.h>

enum enum_color {CARREAU, PIQUE, COEUR, TREFLE};
enum enum_joueur {CARTE=0,HIT=0,ARRETER=1,STAND=1,DOUBLE=2,ABANDONNER=3,SURREND=3};

struct Carte{
    int valeur;
    enum enum_color type;
};

typedef struct joueur{
    struct listeCartes* cartes;
    int montant;
};

typedef struct listeCartes{
    struct Carte carte;
    struct listeCartes* cartenext;
}listeCartes;

// Fonction pour créer un nouveau nœud
struct listeCartes* createNode(int valeur, int type) {
    struct listeCartes* newNode = (struct listeCartes*)malloc(sizeof(struct listeCartes));
    struct Carte carte;
    carte.type = type;
    carte.valeur = valeur;

    newNode->carte = carte;
    newNode->cartenext = NULL;
};

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

void affichage_main(struct listeCartes* premierecarte, int multiply){ 
    int i=2;

	struct listeCartes *nouvellecarte;
    nouvellecarte=premierecarte->cartenext;
    
    printf("Voici la carte 1 :\n");
    switch (premierecarte->carte.type)
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
                printf("Valeur : %d \n", premierecarte->carte.valeur);
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
    if(multiply == 1){
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
    //shuffleList(head);
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

struct Carte tirageCartes(struct listeCartes** deskhead){
    struct listeCartes* courant = *deskhead;
    struct listeCartes* temps = *deskhead;
    while (courant->cartenext != NULL)
    {
        temps = courant;
        courant = courant->cartenext;
    }
    temps->cartenext = NULL;
    struct Carte carte = courant->carte;
    free(courant);
    return carte;
}

int count(struct listeCartes* premierecarte){
    int valeurmain = 0;
    valeurmain += premierecarte->carte.valeur;
    struct listeCartes* nouvellecarte;
    nouvellecarte = premierecarte->cartenext;
    while (nouvellecarte != NULL){
        if (nouvellecarte->carte.valeur > 9){;
            valeurmain += 10;
        }
        else{
            valeurmain+= nouvellecarte->carte.valeur;
        };
        nouvellecarte = nouvellecarte->cartenext;
    }
    return valeurmain;
}

int traitement_saisie(char str[]){

    if(strcmp("CARTE", str) || strcmp("HIT", str)){
        return 0;
    }
    else if(strcmp("ARRETER", str) || strcmp("STAND", str)){
        return 1;
    }
    else if(strcmp("DOUBLE", str)){
        return 2;
    }
    else if(strcmp("ABANDONNER", str) || strcmp("SURRENDER", str)){
        return 3;
    }
    else{
        return 10; //Pour indiquer que l'utilisateur a rentré une mauvaise saisie
    }

}

int main(){
    int credit=100;
    int mise=10;
    int montant;
    
    struct joueur banque;
    struct joueur player;

    struct listeCartes* mainjoueurlistcarte = NULL;
    struct listeCartes* mainbanquelistcarte = NULL;
    struct listeCartes* head = CreationDeck();
    shuffleList(&head);
    
    struct Carte temps;
    for(int i=0;i<4;i++){
        if((i%2) == 0){
            struct Carte carte = tirageCartes(&head);
            append(&mainjoueurlistcarte, carte.valeur, carte.type);
        }else{
            struct Carte carte = tirageCartes(&head);
            append(&mainbanquelistcarte, carte.valeur, carte.type);
        }
    }

    affichage_main(mainjoueurlistcarte, 1);
    affichage_main(mainbanquelistcarte, 0);

    int compteurMainJoueur = count(mainjoueurlistcarte);
    int compteurMainBanque = count(mainbanquelistcarte);
    char str[20];
    printf("Que veux tu faire ?\n");
    scanf("%s", &str);
    int choix = traitement_saisie(str);
    while(compteurMainJoueur < 21 && choix != 1 && choix != 3){
        printf("%d", choix);
        if(choix == 0){
            struct Carte carte = tirageCartes(&head);
            append(&mainjoueurlistcarte, carte.valeur, carte.type);
            affichage_main(mainjoueurlistcarte, 1);
        }
        if(compteurMainBanque < 17){
            struct Carte carte = tirageCartes(&head);
            append(&mainbanquelistcarte, carte.valeur, carte.type);
        }
        compteurMainJoueur = count(mainjoueurlistcarte);
        compteurMainBanque = count(mainbanquelistcarte);
        if(compteurMainJoueur < 21 && choix != 1 && choix != 3){
            printf("Que veux tu faire ?");
            char repioche[20];
            scanf("%s", &repioche);
        }
    }

    affichage_main(mainjoueurlistcarte, 1);
    affichage_main(mainbanquelistcarte, 1);
    
    if(compteurMainJoueur > compteurMainBanque){
        printf("joueur a gagné");
    }else if(compteurMainJoueur < compteurMainBanque){
        printf("Banque a gagné");
    }
}