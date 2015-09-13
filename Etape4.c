/***************************************************************************/
/***************************  DECOMPRESSION  ******************************/
/*************************************************************************/
#include"Decompression.h"
#include"Etape3.c"

void Lecture_fichier(struct Tableau_Noeud *Tableau_freq)
{
      FILE* fichier_data;
      struct Noeud Bloc;
      int i,nbre;
        i=0;
         fichier_data=fopen("data.txt","r");
         if (fichier_data!=NULL)
          {
            fseek(fichier_data,0,2);
            nbre=ftell(fichier_data)/sizeof(Bloc);
            Tableau_freq->Taille_Occupe=nbre;
            Tableau_freq->Data=(struct Noeud *)malloc(nbre*sizeof(struct Noeud));
            rewind(fichier_data);
           do
           {
               fread(&Bloc,sizeof(Bloc),1,fichier_data);
               Tableau_freq->Data[i].lettre=Bloc.lettre;
               Tableau_freq->Data[i].occurence=Bloc.occurence;
               Tableau_freq->Data[i].code=Bloc.code;
               // printf(" %d %c \n",Tableau_freq->Data[i].occurence,Tableau_freq->Data[i].lettre);
                i++;
           }
           while(i<nbre);
          }
          fclose(fichier_data);
}

char * Convertir_char_Binaire(int x)
{
    int tab[8]={128,64,32,16,8,4,2,1};
    char *res;
    int i;

    res=(char*)calloc('0',8);
    for(i=0;i<8;i++)
    {
        if(x/tab[i]==0)
         res[i]='0';
         else
         {
           res[i]='1';
            x=x%tab[i];
         }
    }
    res[8]='\0';
    return res;

}
char* Convertir_En_Binaire(char nomfichier[120])
{
     FILE* fichier_data;
    unsigned char carc;
    char * Suite_binaire;
    int i,nbre;
        i=0;

         strcat(nomfichier,".dat");
         fichier_data=fopen(nomfichier,"r");
         if (fichier_data!=NULL)
           {
             fseek(fichier_data,0,2);
             nbre=ftell(fichier_data);

           //printf("\n nbre= %d \n",nbre);
             Suite_binaire=(char*)calloc('0',nbre*8);
             rewind(fichier_data);
             do
                {
                       carc=fgetc(fichier_data);
                  strcat(Suite_binaire,Convertir_char_Binaire(carc));
                  i++;
                } while( (carc!= EOF )&& i< nbre);
                }
  // Suite_binaire[strlen(Suite_binaire)]='\0';

    return Suite_binaire;
}
void Decompresion_Fichier(struct Noeud_Arbre * Racine,char nomfichier[120],struct Tableau_Noeud T)
{
    FILE * fichier1;
    char Caractere;char * Suite_binaire;
    struct Noeud_Arbre * tmp;
    int i;
    i=0;
   // strcpy(nom_fichier,"huff.dat");
    tmp=Racine;
    fichier1=fopen("Comprehuff.txt","w");
    Suite_binaire=Convertir_En_Binaire(nomfichier);
    Suite_binaire[strlen(Suite_binaire)]='\0';

   // printf(" taille %d %d \n",Taille_Bit_Comp(T),strlen(Suite_binaire));
    if(fichier1!=NULL)
    {


         while (i<Taille_Bit_Comp(T))
        {

               if(Suite_binaire[i]=='0')
                       tmp=tmp->Gauche;
                      else if(Suite_binaire[i]=='1')
                       tmp=tmp->Droite;
                if(tmp->Droite==NULL & tmp->Gauche==NULL)
                   {
                       fputc(tmp->Branche.lettre,fichier1);
                      // printf(" %c ",tmp->Branche.lettre);
                       tmp=Racine;
                   }

              i++;

            }


        }

      fclose(fichier1) ;
}
