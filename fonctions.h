#include "stdio.h"
typedef struct annuaire
{
    char nom [32] ;
    char moteur[32];
    int naissance, promo ;
    char statut [32];
    struct annuaire* gauche;
    struct annuaire* droite;

} annuaire ;

typedef struct voiture
{
    char nom [32] ;


} voiture ;




annuaire* CreerEleve (void);
annuaire* AjouterEleve ( annuaire *R, annuaire* N);
void afficheArbres(annuaire *R);
void afficheStruct(annuaire * R);
void ecritureB(char nomFichier[20], annuaire a);
annuaire lectureB( char nomFichier[20]);
annuaire* rechercheEleve(annuaire * R, char nom[20], char prenom[20]);
void recherchePromo(annuaire *R, int promo);
void rechercheStatut(annuaire *R, char statut[5]);
void sauvegarde(annuaire *F,FILE Fic[1000]);