#ifndef TAB_ASCCI_H_INCLUDED
#define TAB_ASCCI_H_INCLUDED
#include<stdlib.h>
#include <tchar.h>
#include<string.h>
struct Noeud
{
  char lettre;
  int  occurence;
  char *code;
  int taille_code;
};

struct Tableau_Noeud
{
	int Taille_Occupe;
	struct Noeud  *Data;
};
void Lecture_Fichier_Initial(char n[120], struct Tableau_Noeud *);
void Calcul_Occurence_Caractere(char,struct Tableau_Noeud *);
int Recherche_Caractere_TASCI(char,struct Tableau_Noeud);
void TriCroissant_Tableau_Occurence(struct Tableau_Noeud);
void Affiche_Tableau_Occurence(struct Tableau_Noeud);
void Sauvgarde_Tableau_frequence(struct Tableau_Noeud );

#endif // TAB_ASCCI_H_INCLUDED
