#includes"Etape2.c"
int Taille_Bit_Comp
void Compression_Huffman(char nom_fich_Source[120], struct Tableau_Noeud Tableau_Asci)
{
     FILE* fich_source;
     char  Caractere;
     int i,Nbre;

         fich_source=fopen(nom_fich,"rb");
         if (fich==NULL)

	              perror("impossible d'ouvrir le fichier");
          else
                  {
					  while ((Caractere=fgetc(fich))!= EOF)
                          {
                             for(i=0;i<Tableau_Asci.Taille_Occupe;i++)
                             {
                                 if(Caractere==Tableau_Asci.Data[i].lettre)
                                 {

                                 }
                             }


                           }
	              }
	      fclose(fich);


}
