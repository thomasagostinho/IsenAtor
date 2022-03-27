//
// Created by thomas on 27/03/2022.
//

#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LMAX 256
#define ficsauv "FILE.SAV"



annuaire* CreerEleve (void) {
    annuaire* A = (annuaire *)malloc(sizeof(annuaire));
    if( A == NULL) {
        printf ("\n Erreur d'allocation");
        return NULL;
    }
    printf("\nEntrer le prénom :");
    scanf("%s", A->moteur);
    printf("\nEntrer le nom :");
    scanf("%s", A->nom);
    printf("\nEntrer la date de naissance AAMMJJ :");
    scanf("%d", &(A->naissance));
    printf("\nEntrer la promo :");
    scanf("%d", &(A->promo));
    printf("\nEntrer le statut (ACT, RET, DEC) :");
    scanf("%s", A->statut);

    A-> gauche = NULL;
    A-> droite = NULL;
    return A;

}

annuaire* AjouterEleve ( annuaire *R, annuaire* N)
{
    if (N==NULL)
    {
        printf("Problème sur la création de l'élève, ajout annulé.\n");
        return R;
    }
    if(R==NULL)
        return N;
    if (strcmp(R->nom, N->nom)==0)
    {
        if (strcmp(R->moteur, N->moteur) == 0)
        {
            printf("\nL'élève existe déja");
            free(N);
            N = NULL;
            return R;
        }
        if (strcmp(R->moteur, N->moteur) > 0)
        {
            R->gauche = AjouterEleve(R->gauche, N); // on relance récursivement l'ajout dans la branche gauche
            return R;
        }
        if (strcmp(R->moteur, N->moteur) < 0)
        {
            R->droite = AjouterEleve(R->droite, N); // on relance récursivement l'ajout dans la branche droite
            return R;
        }
    }
    if (strcmp(R->nom, N->nom)>0)
    {
        R->gauche = AjouterEleve(R->gauche, N); // on relance récursivement l'ajout dans la branche gauche
        return R;
    }
    if (strcmp(R->nom, N->nom)<0)
    {
        R->droite = AjouterEleve(R->droite, N); // on relance récursivement l'ajout dans la branche droite
        return R;
    }
    return R;
}


void afficheArbres(annuaire *R){
    if(R==NULL)
        return;
    afficheArbres(R->gauche);

    // affichage in odre
    printf("Nom : %10s -",R->nom);
    printf("Prenom : %10s -",R->moteur);
    printf("Date : %6d -",R->naissance);
    printf("Promo : %4d -",R->promo);
    printf("Statut : %4s \n",R->statut);

    afficheArbres(R->droite);
}

void afficheStruct(annuaire * R)
{
    printf("Nom : %10s -",R->nom);
    printf("Prenom : %10s -",R->moteur);
    printf("Date : %6d -",R->naissance);
    printf("Promo : %4d -",R->promo);
    printf("Statut : %4s \n",R->statut);

}





annuaire* rechercheEleve(annuaire * R, char nom[20], char prenom[20])
{


    if (strcmp (nom, R->nom)==0)
    {
        if(strcmp(prenom, R->moteur) == 0)
            afficheStruct(R);
        return R;

        if(strcmp(prenom, R->moteur) > 0)
        {
            R->gauche=rechercheEleve(R->gauche, nom, prenom);

        }
        if(strcmp(prenom, R->moteur) < 0)
        {
            R->droite=rechercheEleve(R->droite, nom, prenom);

        }
    }
    if (strcmp (nom, R->nom)>0)
    {
        R->gauche=rechercheEleve(R->droite, nom, prenom);

    }
    if (strcmp (nom, R->nom)<0)
    {
        R->droite=rechercheEleve(R->droite, nom, prenom);
    }





}

void recherchePromo(annuaire *R, int promo)
{
    if (R==NULL)
    {
        return;
    }
    if (promo == R->promo){

        afficheStruct(R);

    }

    recherchePromo(R->gauche, promo);
    recherchePromo(R->droite, promo);



}

void rechercheStatut(annuaire *R, char statut[5])
{
    if(R==NULL)
    {
        return;
    }
    if (strcmp(statut, R->statut)==0)
        afficheStruct(R);


    rechercheStatut(R->gauche, statut);
    rechercheStatut(R->droite, statut);


}

void sauvegarde(annuaire *F,FILE Fic[1000])
{
    if ( Fic == NULL)
    {
        printf("sauvegarde impossible\n");
        return;
    }
    fwrite(F,sizeof(F),1,Fic);
    if( F->droite !=0)
    {
        printf("droite\n");
        sauvegarde(F->droite,Fic);
    }
    if( F->gauche !=0)
    {
        printf("gauche\n");
        sauvegarde(F->gauche,Fic);

    }
    return;
}


