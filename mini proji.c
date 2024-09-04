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
int i,j;
void ajouter_livre() {
    if (dim >= 100) {
        printf("le stock est plein, impossible d'ajouter un nouveau livre.\n");
    }
    printf("Entrer le titre : ");
    scanf(" %29[^\n]", L[dim].titre); 
    printf("Auteur : ");
    scanf(" %24[^\n]", L[dim].auteur);  
    L[dim].id = ID + 1;
    printf("Prix : ");
    scanf("%d", &L[dim].prix);
    printf("Entrer la quantité : ");
    scanf("%d", &L[dim].quantite);

    dim++;
    ID++;
}

void modifier_livre(){
    int id, nv_quant;
    int exist = 0;

    printf("Entrer l'ID du livre à modifier : ");
    scanf("%d", &id);
    printf("Entrer la nouvelle quantité : ");
    scanf("%d", &nv_quant);

    for (i = 0; i < dim; i++) {
    if (L[i].id == id) {
         L[i].quantite = nv_quant;
          exist= 1;
        printf("Quantité mise à jour avec succès.\n");
           break;
       }
    }

    if (!exist) {
        printf("Livre avec id %d non trouvé.\n", id);
    }
}

void afficher_livres() {
    if (dim == 0) {
        printf("Aucun livre à afficher.\n");
        return;
    }

    for (i = 0; i < dim; i++) {
        printf("ID: %d\nTitre: %s\nAuteur: %s\nPrix: %d\nQuantité: %d\n\n",
            L[i].id, L[i].titre, L[i].auteur, L[i].prix, L[i].quantite);
    }
}

void supprimer_livre() {
    int id, exist = 0;

    printf("Entrer l'ID du livre à supprimer : ");
    scanf("%d", &id);

    for (i = 0; i < dim; i++) {
       if (L[i].id == id) {
    for ( j = i; j < dim - 1; j++) {
        L[j] = L[j + 1];
         }
     dim--;
       exist = 1;
	   printf("Livre supprimé avec succès.\n");
            break;
    }
    }

    if (!exist) {
        printf("Livre avec ID %d introuvable .\n", id);
    }
}

void afficher_nbr_livre() {
    printf("Nombre total de livres : %d\n", dim);
}
void menu(){
    printf("Bonjour, vous pouvez choisir :\n");
    printf("1: Ajouter un livre\n");
     printf("2: Afficher tous les livres disponibles\n");
    printf("3: Changer la quantité pour un livre\n");
    printf("4: Supprimer un livre\n");
    printf("5: Afficher le nombre total des livres\n");
    printf("6: Quitter\n");
    printf("Saisir un nombre entre 1 et 6 : ");
    }
	
int main() {
	int num;
	do{
    menu();
    scanf("%d",&num);
    }while(num!=6);
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
    printf("vous avez quite Au revoir a la prochaine fois.\n");
    return 0;
   break;
    }
	return 0;
}
