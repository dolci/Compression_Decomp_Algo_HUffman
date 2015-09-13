#ifndef DECOMPRESSION_H_INCLUDED
#define DECOMPRESSION_H_INCLUDED
#include"Comp_Huff.h"



void Lecture_fichier(struct Tableau_Noeud *);
char * Convertir_char_Binaire(int );
char* Convertir_En_Binaire(char [120]);
void Decompresion_Fichier(struct Noeud_Arbre *,char[120],struct Tableau_Noeud );

#endif // DECOMPRESSION_H_INCLUDED
