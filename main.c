#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/
#include <stdlib.h>

enum enum_color {CARREAU, PIQUE, COEUR, TREFLE};
int compteur = 0;

struct Carte{
    int valeur;
    enum enum_color type;
};

typedef struct listeCartes{
    struct Carte carte;
    struct listeCartes* cartenext;
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

struct listeCartes* CreationDeck(){
    struct listeCartes* myList = NULL;
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= 13; j++){
            append(&myList, j, i);
        }
    }
    return myList;
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