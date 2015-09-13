#include <stdio.h>
#include"Etape4.c"
 int main()
{


	struct Tableau_Noeud Tableau_Asci;
    char nom_fichier[120];
    char nom_fichie[120];
    Tableau_Asci.Taille_Occupe=0;
    struct TabNoeud_Arbre Tab_Arbre;
    struct Noeud_Arbre *Arbre;
    int *tab,i; char *chaine,*chai;
    struct Tableau_Noeud Tableau_freq;
     i=0;
     int c;
      chaine=(char *)malloc(sizeof(char));
    strcpy(nom_fichier,"file.txt");

    Lecture_Fichier_Initial(nom_fichier,&Tableau_Asci);

    TriCroissant_Tableau_Occurence(Tableau_Asci);

    Sauvgarde_Tableau_frequence(Tableau_Asci);

   /*Affiche_Tableau_Occurence(Tableau_Asci);

    Creation_File_Attente(&Tab_Arbre,Tableau_Asci,&tab);


    Creation_Arbre_Huffman(&Tab_Arbre,&Arbre,tab);

    Parcours_Arbre(Arbre,i);
    Dictionnaire_Huffman(Arbre,chaine,&Tableau_Asci,i);
   Compression_Huffman_Texte(nom_fichier,Taille_Bit_Comp(Tableau_Asci),Compression_Code_Texte(nom_fichier,Tableau_Asci));
   // Compression_Code_Texte(nom_fichier,Tableau_Asci);
    Taux_Compression( Tableau_Asci);*/
    Lecture_fichier(&Tableau_freq);

    Creation_File_Attente(&Tab_Arbre,Tableau_freq,&tab);

    Creation_Arbre_Huffman(&Tab_Arbre,&Arbre,tab);
    Parcours_Arbre(Arbre,i);
    Dictionnaire_Huffman(Arbre,chaine,&Tableau_freq,i);

    Decompresion_Fichier(Arbre,nom_fichier,Tableau_freq);

//    Convertir_En_Binaire(nom_fichier,chai);*/
    getchar();

}

