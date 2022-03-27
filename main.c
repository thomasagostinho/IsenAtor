
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"


#define LMAX 256
#define ficsauv "FILE.SAV"



int main(void){

    //variable pour la recherche
    char nom[20];
    char moteur[20];
    char statut[5];
    int promo;

    //fin var recherche
    int choix;
    annuaire *R=NULL, *N=NULL, *P=NULL;

    //fichier
    FILE *Fic;
    Fic=fopen(ficsauv,"rb");


    do{
        printf("\n(0) Quitter\n");
        printf("(1) Enregitrer annuaire\n");
        printf("(2) Chercher un ancien eleve\n");
        printf("(3) Afficher les anciens élèves par ordre alphabétique \n");
        printf("(4) Afficher les elesves d'une promotion \n");
        printf("(5) Afficher les elesves d'un statut\n");
        printf("(6) Suppression d'un élève \n");
        printf("(7) Caractéristique de l'arbre Binaire \n");

        scanf("%d",&choix);

        switch(choix){
            case 0:

                Fic=fopen(ficsauv,"wb");
                sauvegarde(R,Fic);
                return 0;
                break;

            case 1:
                N = CreerEleve ();
                R = AjouterEleve (R,N);
                break;



            case 2:


                printf(" \n Saisir le nom de la personne rechercher: ");
                scanf("%s", nom);

                printf(" \n Saisir le prénom de la personne rechercher: ");
                scanf("%s", moteur);

                P=rechercheEleve(R, nom, moteur);


                break;

            case 3:
                printf("bonjour\n");
                afficheArbres(R);


                break;

            case 4:
                printf("Quelle promotion doit être affichée? ");
                scanf("%d", &promo);
                recherchePromo(R, promo);

                break;

            case 5:

                printf("quel statut est concerné ? ");
                scanf("%s", statut);
                rechercheStatut(R, statut);

                break;


            default:
                printf("erreur de saisie\n");
        }


    } while(choix!= 0);
    return 0;
}
