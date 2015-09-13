#include"Arbre_Huffman.h"
#include "Etape1.c"

void Creation_File_Attente(struct TabNoeud_Arbre *T, struct Tableau_Noeud Tableau_Asci,int **Tab)
{
    int i; int *tmp;


   tmp=(int*)malloc((Tableau_Asci.Taille_Occupe+1)*sizeof(int));
    T->Taille=Tableau_Asci.Taille_Occupe;
    T->Taille_T=(Tableau_Asci.Taille_Occupe*2)-1;

    tmp[0]=T->Taille;
    for(i=0;i<Tableau_Asci.Taille_Occupe;i++)
      {
          T->File_A[i] =(struct Noeud_Arbre*)malloc(sizeof(struct Noeud_Arbre));
          T->File_A[i]->Branche.lettre=Tableau_Asci.Data[i].lettre;
          T->File_A[i]->Branche.occurence=Tableau_Asci.Data[i].occurence;
          tmp[i+1]=Tableau_Asci.Data[i].occurence;
          T->File_A[i]->Poids=-1;
          T->File_A[i]->Droite=T->File_A[i]->Gauche=NULL;
      }

     *Tab=tmp;

}


void Miseajour_File_Attente(struct TabNoeud_Arbre *T,struct Noeud_Arbre *Nouveau_Noeud)
{
    struct Noeud_Arbre *Tmp;
    int i,j,trouve;
    j=trouve=0;
    T->Taille++;

     T->File_A[ T->Taille-1] =(struct Noeud_Arbre*)malloc(sizeof(struct Noeud_Arbre));

         if( T->File_A[ T->Taille-1]==NULL)
            printf("Erreeur llocation\n");
         else
         {
                 T->File_A[ T->Taille-1]->Branche.lettre=Nouveau_Noeud->Branche.lettre;
                 T->File_A[ T->Taille-1]->Branche.occurence=Nouveau_Noeud->Branche.occurence;
                 T->File_A[ T->Taille-1]->Droite=Nouveau_Noeud->Droite;
                 T->File_A[ T->Taille-1]->Gauche=Nouveau_Noeud->Gauche;
                 T->File_A[ T->Taille-1]->Poids=Nouveau_Noeud->Poids;
         }

      for(i=0;i<T->Taille-1;i++)
      {
          if(T->File_A[i]->Branche.occurence>=T->File_A[T->Taille-1]->Branche.occurence)
          {
            Tmp=T->File_A[i];
            T->File_A[i]=T->File_A[T->Taille-1];
            T->File_A[T->Taille-1]=Tmp;
          }

      }

}
void Miseajour_Tableau(struct TabNoeud_Arbre *T_N,int **Tab)
{
    int i;
    int *Tmp,*T;
    T=*Tab;

    Tmp=(int*)malloc((T_N->Taille+1)*sizeof(int));
    Tmp[0]=T_N->Taille;

    for(i=1;i<=Tmp[0];i++)
      {
          if(T[i]==0)
             Tmp[i]=0;
          else
          Tmp[i]=T_N->File_A[i-1]->Branche.occurence;
      }
    *Tab=Tmp;


}
void Min_Fil_Attente(int**Tab,int*T_Min)
{

    int i;
    int *T;
    i=1; T=*Tab;

    while(i<=T[0]&&T[i]==0&&T[i+1]==0) i=i+2;

    T_Min[0]=i-1;
    T_Min[1]=i;
    T[i]=T[i+1]=0;
    *Tab=T;
}
void Creation_Arbre_Huffman(struct TabNoeud_Arbre *Tab_Arbre, struct Noeud_Arbre **Arbre,int*Tab)
{
    int *Min,i;
    struct Noeud_Arbre *Nouveau_Noeud;
    *Arbre=NULL;
     Min=(int*)malloc(2*sizeof(int));
   do
   {


        Min_Fil_Attente(&Tab,Min);
        // printf("min %d %d \n",Min[0],Min[1]);
        Nouveau_Noeud=(struct Noeud_Arbre *)malloc(sizeof(struct Noeud_Arbre));
        Nouveau_Noeud->Gauche=Tab_Arbre->File_A[Min[0]];
        Nouveau_Noeud->Droite=Tab_Arbre->File_A[Min[1]];

        Nouveau_Noeud->Branche.occurence=Tab_Arbre->File_A[Min[0]]->Branche.occurence+Tab_Arbre->File_A[Min[1]]->Branche.occurence;
        Nouveau_Noeud->Poids=-1;
        Miseajour_File_Attente(Tab_Arbre,Nouveau_Noeud);
        Miseajour_Tableau(Tab_Arbre,&Tab);

   } while(Tab[0]!=Tab_Arbre->Taille_T);
*Arbre=Nouveau_Noeud;


}


void Parcours_Arbre(struct Noeud_Arbre *A,int Hauteur)
{

   if(A->Droite==NULL && A->Gauche==NULL)
     {
         printf("Carcatere=%c ,Occurence=%d   \n",A->Branche.lettre,A->Branche.occurence);
          A->Poids=Hauteur;
     }

   else
   {

           Parcours_Arbre(A->Droite,Hauteur+1);
           Parcours_Arbre(A->Gauche,Hauteur+1);
   }
}

void Dictionnaire_Huffman(struct Noeud_Arbre* Racine, char *chaine,struct Tableau_Noeud *Tableau_Asci,int Hauteur)
{
   int  i;
if (Racine->Droite == NULL && Racine->Gauche==NULL)
    {

        for(i=0;i<Tableau_Asci->Taille_Occupe;i++)
        {
            if(Racine->Branche.lettre==Tableau_Asci->Data[i].lettre)
            {
                Tableau_Asci->Data[i].code=(char *) malloc((Racine->Poids)*sizeof(char));
                chaine[Racine->Poids]='\0';
                strcpy(Tableau_Asci->Data[i].code,chaine);
                Tableau_Asci->Data[i].taille_code=Racine->Poids;

               break;
            }

        }

    }

  else
    {

      if(Racine->Droite!= NULL)
      {
          chaine[Hauteur]='1';
          Dictionnaire_Huffman(Racine->Droite,chaine,Tableau_Asci,Hauteur + 1);
      }
       if(Racine->Gauche!=NULL)
      {chaine[Hauteur]='0';
      Dictionnaire_Huffman(Racine->Gauche,chaine,Tableau_Asci,Hauteur + 1);}
      chaine=(char *) realloc(chaine,(Hauteur+1) * sizeof(char));
    }
}


