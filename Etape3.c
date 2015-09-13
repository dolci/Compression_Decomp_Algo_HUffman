#include"Comp_Huff.h"
/***************************************************************************/
/***************************  COMPRESSION  ********************************/
/*************************************************************************/
#include"Etape2.c"
int Taille_Bit_Comp(struct Tableau_Noeud Tableau_Asci)
{
    int i,T,Res;
    Res=0;
    for(i=0;i<Tableau_Asci.Taille_Occupe;i++)
    {
        T=Tableau_Asci.Data[i].occurence*Tableau_Asci.Data[i].taille_code;
        Res+=T;
    }

    return Res;
}

char * Compression_Code_Texte(char nom_fich_Source[120], struct Tableau_Noeud Tableau_Asci)
{
     FILE* fich_source;
     FILE * fichier_dest;
     char  Caractere;
     int i;
     char *Suite_binaire;


         fich_source=fopen(nom_fich_Source,"r");
         Suite_binaire=(char*)calloc('0',Taille_Bit_Comp(Tableau_Asci)*sizeof(char));
         Suite_binaire[Taille_Bit_Comp(Tableau_Asci)]='\0';
         if (fich_source!=NULL)
          {

             while ((Caractere=fgetc(fich_source))!= EOF)
                {

                    for(i=0;i<Tableau_Asci.Taille_Occupe;i++)
                    {
                          if(Caractere==Tableau_Asci.Data[i].lettre)
                          strcat(Suite_binaire,Tableau_Asci.Data[i].code);
                    }

                }
            }

	      fclose(fich_source);
          fclose(fichier_dest);
	     // printf("%s \n",Suite_binaire);
	   return Suite_binaire;
}

int Convertir_Binaire_char(char *C)
{
    int tab[8]={128,64,32,16,8,4,2,1};
    int i,res;
    res=0;
    for(i=0;i<8;i++)
    {

        if((C[i]==49))
        res+=tab[i];
        }
//printf("%d \n",res);
    return res;
}
char * Extraire_Souschaine(char* Suite_binaire,int position)
{
    char *sous_chaine;
    int i;
    sous_chaine=malloc(8*sizeof(char));

    for(i=0;i<8;i++)
       {
           if(position>=strlen(Suite_binaire))
          {
             sous_chaine[i] ='0';
          }
          else
          sous_chaine[i]=Suite_binaire[position++];
       }

    return sous_chaine;
}
void Compression_Huffman_Texte(char Nom_fichier_Initial[120],int Taille,char *Suite_binaire)
{
    FILE *fich_comp;
    int i;
    char fichier_dat[120];
    char *Carac;
    char b;
    i=0;

       strcpy(fichier_dat,Nom_fichier_Initial);
       strcat(fichier_dat,".dat");
       fichier_dat[strlen(fichier_dat)]='\0';
        fich_comp=fopen(fichier_dat,"w");
         if (fich_comp!=NULL)
          {
              while(i<(Taille/8)+1)
              {
                Carac=Extraire_Souschaine(Suite_binaire, i*8);
                b=Convertir_Binaire_char(Carac);
                fwrite(&b,1,1,fich_comp);
                i++;
              }

          }
          fclose(fich_comp);
}

void Taux_Compression(struct Tableau_Noeud Tableau_Asci)
{
    int i,taux;
    taux=0;
    for(i=0;i<Tableau_Asci.Taille_Occupe;i++)
        taux+=Tableau_Asci.Data[i].occurence;
    printf("  Taille fichier initial %d octet\n",taux);
    printf("  Taille fichier apres compression %d",(Taille_Bit_Comp(Tableau_Asci)/8)+1);
    printf("\n\n");
}
