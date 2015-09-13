#ifndef COMP_HUFF_H_INCLUDED
#define COMP_HUFF_H_INCLUDED
#include"Arbre_Huffman.h"
#include<string.h>



int Taille_Bit_Comp(struct Tableau_Noeud );
int Convertir_Binaire_char(char *);
char * Extraire_Souschaine(char*,int );
char* Compression_Code_Texte(char[120], struct Tableau_Noeud);
void Compression_Huffman_Texte(char [120],int,char *);
void Taux_Compression(struct Tableau_Noeud );
#endif // COMP_HUFF_H_INCLUDED
