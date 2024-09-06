#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char titre[30];
    char auteur[25];
    int prix;
    int quantite;
} Book;

Book L[100];
int dim = 0;
int ID = 0;
int i, j;

void ajouter_livre() {

    printf("Entrer le titre : ");
    scanf(" %29[^\n]", L[dim].titre);
    printf("Auteur : ");
    scanf(" %24[^\n]", L[dim].auteur);
    L[dim].id = ID+1;
    printf("Prix : ");
    scanf("%d", &L[dim].prix);
    printf("Entrer la quantit� : ");
    scanf("%d", &L[dim].quantite);

    dim++;
    ID++;
}

void modifier_livre() {
    int id, nv_quant;
    int exist = 0;

    printf("Entrer l'ID du livre � modifier : ");
    scanf("%d", &id);
    printf("Entrer la nouvelle quantit� : ");
    scanf("%d", &nv_quant);

    for (i = 0; i < dim; i++) {
        if (L[i].id == ID) {
            L[i].quantite = nv_quant;
            exist = 1;
            printf("Quantit� mise � jour avec succ�s.\n");
            break;
        }
    }

    if (!exist) {
        printf("Livre avec ID %d non trouv�.\n", id);
    }
}

void chercher_livre() {
    char recherche[30];
    printf("Entrez le titre du livre � rechercher : ");
    scanf(" %29[^\n]", recherche);
    int exist = 0;
    for (i = 0; i < dim; i++) {
        if (strcmp(L[i].titre, recherche) == 0) {
            printf("Livre trouv� :\n");
            printf("Titre : %s \n Auteur : %s \n Prix : %d Dh \n Quantit� : %d\n", L[i].titre, L[i].auteur, L[i].prix, L[i].quantite);
            exist++;
            break;
        }
    }
    if (!exist) {
        printf("Livre non trouv�.\n");
    }
}

void afficher_livres() {
    if (dim == 0) {
        printf("Aucun livre � afficher.\n");
        return;
    }

    for (i = 0; i < dim; i++) {
            printf("\n\n");
        printf("ID: %d\nTitre: %s\nAuteur: %s\nPrix: %d\nQuantit�: %d\n\n",
            L[i].id, L[i].titre, L[i].auteur, L[i].prix, L[i].quantite);
    }
}

void supprimer_livre() {
    int id, exist = 0;

    printf("Entrer l'ID du livre � supprimer : ");
    scanf("%d", &id);

    for (i = 0; i < dim; i++) {
        if (L[i].id == id) {
            for (j = i; j < dim - 1; j++) {
                L[j] = L[j + 1];
            }
            dim--;
            exist = 1;
            printf("Livre supprim� avec succ�s.\n");
            break;
        }
    }

    if (!exist) {
    printf("Livre avec ID %d introuvable.\n", id);
    }
}

void afficher_nbr_livre() {
    int crono=0;
    for (i = 0; i < dim; i++) {
    crono=crono+L[i].quantite;
}
printf("le nombre totale des livre en stock est: %d ",crono);
}

void menu() {
    printf("Bonjour, vous pouvez choisir :\n");
    printf("1: Ajouter un livre\n");
    printf("2: Afficher tous les livres disponibles\n");
    printf("3: Changer la quantit� pour un livre\n");
    printf("4: Supprimer un livre\n");
    printf("5: Afficher le nombre total des livres\n");
    printf("6:chercher un seul livre:\n");
    printf("7: Quitter\n");
    printf("Saisir un nombre entre 1 et 7 : ");
}

int main() {
    int num;
    do {
        printf("\n\n");
        menu();
        scanf("%d", &num);

        switch (num) {
            case 1:
                ajouter_livre();
                break;
            case 2:
                afficher_livres();
                break;
            case 3:
                modifier_livre();
                break;
            case 4:
                supprimer_livre();
                break;
            case 5:
                afficher_nbr_livre();
                break;
                case 6:
                 chercher_livre() ;
                break;

            case 7:
                printf("Vous avez quitt�. Au revoir et � la prochaine fois\n");
                return 0;
                break;
        }
    } while (num != 7);

    return 0;
}
