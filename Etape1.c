#include "Tab_Ascci.h"

//Lecture du fichier texte initial
 void Lecture_Fichier_Initial(char nom_fich[120], struct Tableau_Noeud *Tableau_Asci)
{
          FILE* fich;
          char  Caractere;

         fich=fopen(nom_fich,"rb");
         if (fich==NULL)

	              perror("imp");
          else
                  {
					  while ((Caractere=fgetc(fich))!= EOF)
                          {

                                   //printf("%c", Caractere);
                                  Calcul_Occurence_Caractere(Caractere,Tableau_Asci);
                                 //printf("nbre %d\n",Adr_Tableau_Asci.Taille_Occupe);
                           }
	              }
	      fclose(fich);

}

// Calcul Nombre d'occurence associe à chaque caractère du fichier à compresser et on le met dans un tableau de structure (Tableau_Asci)

void Calcul_Occurence_Caractere(char Caractere,struct Tableau_Noeud *Tableau_Asci)
{
	int Test,i;
    struct Noeud *tmp;
    Test=Recherche_Caractere_TASCI(Caractere,*Tableau_Asci);

   if (Test!=-1)
     Tableau_Asci->Data[Test].occurence++;
     else
        {
            if (Tableau_Asci->Taille_Occupe==0)
              {
                Tableau_Asci->Data=(struct Noeud*)malloc(sizeof(struct Noeud));
				Tableau_Asci->Data[0].lettre=Caractere;
	        	Tableau_Asci->Data[0].occurence=1;
	        	Tableau_Asci->Taille_Occupe++;

              }
              else
              {
                  Tableau_Asci->Taille_Occupe++;
	              tmp=Tableau_Asci->Data;
                  Tableau_Asci->Data=(struct Noeud*)malloc((Tableau_Asci->Taille_Occupe)*sizeof(struct Noeud));
		          for(i=0;i<(Tableau_Asci->Taille_Occupe-1);i++)
		             {
		                 Tableau_Asci->Data[i].lettre=tmp[i].lettre;
                         Tableau_Asci->Data[i].occurence=tmp[i].occurence;
		             }
		          free(tmp);
		          Tableau_Asci->Data[Tableau_Asci->Taille_Occupe-1].lettre=Caractere;
		          Tableau_Asci->Data[Tableau_Asci->Taille_Occupe-1].occurence=1;
               }
           }
}
// Test si le Caractere existe déjà dans le tableau (Tableau_Asci) si ce le cas on renvoie sa position dans le tableau
int Recherche_Caractere_TASCI(char Caractere, struct Tableau_Noeud Tableau_Asci)
{
	int i;
    int aux;
    aux=-1;
	for(i=0;i<(Tableau_Asci.Taille_Occupe);i++)

	 if(Tableau_Asci.Data[i].lettre==Caractere)
	 {
		aux=i;
 		break;
	 }

 	return aux;
  }
void TriCroissant_Tableau_Occurence(struct Tableau_Noeud Tableau_Asci)
{

  int i,j,idmin;
  struct Noeud tmp ;

	for(i=0;i<Tableau_Asci.Taille_Occupe-1;i++)
	{
		idmin=i;
		for( j=i+1;j<(Tableau_Asci.Taille_Occupe);j++)
			{
			    if (Tableau_Asci.Data[j].occurence < Tableau_Asci.Data[idmin].occurence) idmin=j;
			    if (Tableau_Asci.Data[j].occurence == Tableau_Asci.Data[idmin].occurence)
                {
                    if(Tableau_Asci.Data[j].lettre < Tableau_Asci.Data[idmin].lettre) idmin=j;
                }
			}

		tmp=Tableau_Asci.Data[idmin];
		Tableau_Asci.Data[idmin]=Tableau_Asci.Data[i];
		Tableau_Asci.Data[i]=tmp;
	}
}

void Affiche_Tableau_Occurence(struct Tableau_Noeud Tableau_Asci )
{
 int i;
  // printf("prem: %c",Tableau_Asci.Data[0].lettre);
	for(i=0;i<Tableau_Asci.Taille_Occupe;i++)

		{
			printf(" lettre=%c",Tableau_Asci.Data[i].lettre);
			printf(" occurence=%d \n ",Tableau_Asci.Data[i].occurence);

		}
}
void Sauvgarde_Tableau_frequence(struct Tableau_Noeud Tableau_Asci)
{
      FILE* fichier_data;int i;
          char  Caractere;

         fichier_data=fopen("data.txt","w");
         if (fichier_data!=NULL)
          {
              for(i=0;i<Tableau_Asci.Taille_Occupe;i++)
              fwrite(&Tableau_Asci.Data[i],sizeof(Tableau_Asci.Data[i]),1,fichier_data);
          }
          fclose(fichier_data);
}
