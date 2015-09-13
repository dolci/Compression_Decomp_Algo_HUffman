#ifndef ARBRE_HUFFMAN_H_INCLUDED
#define ARBRE_HUFFMAN_H_INCLUDED
#include<stdlib.h>
#include"Tab_Ascci.h"
struct Noeud_Arbre{
     int Poids;
     struct Noeud Branche;
     struct Noeud_Arbre *Droite;
     struct Noeud_Arbre *Gauche;
};

struct TabNoeud_Arbre{
    int Taille;
    int Taille_T;
    struct Noeud_Arbre *File_A[500];

};
void Creation_File_Attente(struct TabNoeud_Arbre*,struct Tableau_Noeud ,int**);
void Miseajour_File_Attente(struct TabNoeud_Arbre*,struct Noeud_Arbre*);
void Creation_Arbre_Huffman(struct TabNoeud_Arbre *,struct Noeud_Arbre **,int*);
void Miseajour_Tableau(struct TabNoeud_Arbre*,int **);
void Min_Fil_Attente(int**,int*);
void Parcours_Arbre(struct Noeud_Arbre*,int);
void Dictionnaire_Huffman(struct Noeud_Arbre*, char *,struct Tableau_Noeud *,int);

#endif // ARBRE_HUFFMAN_H_INCLUDED
