#include <stdio.h>
#include <stdlib.h>
#define dim 100

void readMatrix(float mat[][dim],int row,int col);
//float medianum(float mat[][dim],int fix_row,int col);
void aggiungiMediaRighe(float mat[][dim], int righe, int *colonne);
void sortRow(float mat[][dim],int fix_row,int col);
void sortMat(float mat[][dim],int fix_col,int row,int col);
void swap(float* a,float* b);

int main(int argv, char *argc[])
{
         FILE *fpin,*fpout;
         int r,c;
         int fix_col;
         float mat[dim][dim];
         float media[dim];
         
         //Apro il file input.txt
         fpin=fopen("input.txt","r");
         if(fpin!=NULL)
           {
           fscanf(fpin,"%d",&r); 
           fscanf(fpin,"%d\n\n",&c);
           
           for(int i=0;i<r;i++)
              for(int j=0;j<c;j++)
              {
              if(j==(c-1))
                fscanf(fpin,"%f\n",&mat[i][j]);
              else
                fscanf(fpin,"%f ",&mat[i][j]);
              }
           fclose(fpin);
           }
         else
           printf("Errore di apertura di input.txt.\n");
         
         readMatrix(mat,r,c);
        
 
             /*  for(int i=0;i<r;i++)
            media[i]=medianum(mat,i,c);
         
         for(int i=0;i<r;i++)
            printf("\nMedia della riga %d-esima e': %6.2f\n\n",i,media[i]);
  
         //Aggiungo una colonna alla matrice con valore la corrispettiva media
         c=c+1; 
         //Ciclo che stampa la nuova matrice ed inserisce la media all'ultima colonna
         for(int i=0;i<r;i++)
            {
            for(int j=0;j<c;j++)
               { 
               if(j==(c-1))
                 {
                 mat[i][j]=media[i];
                 printf("%6.2f",mat[i][j]);
                 }
               else
                 printf("%6.2f",mat[i][j]);
               }
            printf("\n");
            }*/  
            
            
        //Calcolo della media delle righe e aggiunge il valore della media nell'ultima colonna          
        aggiungiMediaRighe(mat, r, &c);//  passaggio di parametri 
        
        // stampa la matrice aggiornata
        printf("Matrice con medie aggiunte:\n");
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                printf("%.2f ", mat[i][j]);
            }
            printf("\n");
        }
        printf("nuova matrice");
        
        // Riutilizzo del sottoprogramma per stamapre la matrice aggiornata
        readMatrix(mat,r,c);
    
			
         //Utilizzo il sottoprogramma che ordina ogni riga per valori crescenti
         for(int i=0;i<r;i++)
           { sortRow(mat,i,c);}
         

         printf("\n\nOrdinato per riga:\n");
        
         // Riutilizzo del sottoprogramma per stamapre la matrice aggiornata
         readMatrix(mat,r,c);
         
         //Utilizzo il sottoprogramma che ordina le righe della matrice
         //per valori crescenti dell'ultima colonna
         fix_col=c-1;
         for(int i=0;i<r;i++)
            { sortMat(mat,fix_col,r,c);}
         
         //Stampo la matrice ordinata
         printf("\n\nMatrice ordinata per valori crescenti dell'ultima colonna:\n");
         
         // Riutilizzo del sottoprogramma per stamapre la matrice aggiornata
         readMatrix(mat,r,c);
         
         //Creo il file binario e ci salvo la matrice
         fpout=fopen("output.bin","wb");
         if(fpout!=NULL)
           {
           fwrite(mat,sizeof(float),dim,fpout);
           fclose(fpout);
           printf("\n\nMatrice salvata in output.bin con successo.\n");
           }
         else
           printf("File output.bin non creato correttamente!\n");
}

//Sottoprogramma per lettura delle dimensioni e degli elementi della matrice
void readMatrix(float mat[][dim],int row,int col) {
           
           //Stampo a videoil valore delle righe e delle col
           printf("La matrice ha:\nRighe: %d\ncol: %d\n\n",row,col);
           //Stampo la matrice
           for(int i=0;i<row;i++)
              {
              for(int j=0;j<col;j++)
                 printf("%6.2f",mat[i][j]);
              printf("\n");
              }
}

/*//Funzione per il calcolo della media per ogni riga
float medianum(float mat[][dim],int fix_row,int col) {
              
              float med=0;
              float sum=0;
                for(int i=0;i<col;i++)
                   sum+=mat[fix_row][i];
                med=sum/col;
              
              return med; //ritorna il valore della media della riga da posizionare all'interno del vettore
}*/
//VARIANTE PER IL SOTTOPROGRAMMA CHE CALCOLA E AGGIUNGE LA MEDIA NELL'ULTIMA COLONNA

// Sottoprogramma che calcola la media di ogni riga
//e aggiunge una colonna con il valore di queste medie
void aggiungiMediaRighe(float mat[][dim], int righe, int *colonne) {

    for(int i = 0; i < righe; i++) {
        float somma = 0;

        // somma degli elementi della riga
        for(int j = 0; j < *colonne; j++) {
            somma += mat[i][j];
        }

        float media = somma / (*colonne);

        // la nuova colonna sarà in posizione *colonne
        mat[i][*colonne] = media;
    }

    // aggiorno il numero di colonne
    (*colonne)++;
}

//Sottoprogramma ordina gli elementi di ogni riga per valori crescenti  
void sortRow(float mat[][dim],int fix_row,int col) {
               
  int k=col-1; // k rappresenta l'ultimo indice fino a cui bisogna confrontare
  int scambio=1; //quando scambio vale 1 significa che la matrice deve essere ordinata 
  
  while(k>0 && scambio==1)
  {
    scambio=0;// se scambio =0 significa che è tutto ordinato
    for(int i=0;i<k;i++)
       if((mat[fix_row][i])>(mat[fix_row][i+1]))
       {
        swap(&mat[fix_row][i],&mat[fix_row][i+1]);//swap riceve gli indirizzi delle due celle della matrice da scambiare
        scambio=1;// qui scambio=1 perchè l'ordinamento serve ancora in quanto è stato appena effettuato uno scambio con il sottoprogramma swap
       }
    k--;// decrementa k
  }
}
//sottoprogramma che ordina le righe per valori crescenti dell'ultima colonna
void sortMat(float mat[][dim],int fix_col,int row,int col) {
  
  int k=row-1,scambio=1;
  while(k>0 && scambio==1)
  {
    scambio=0;
    for(int i=0;i<k;i++)
      if((mat[i][fix_col])>(mat[i+1][fix_col]))
      {
        scambio=1;
        for(int j=0;j<col;j++)
           swap(&mat[i][j],&mat[i+1][j]);
      }
  k--;
}
}
//Sottoprogramma di ordinamento 
void swap(float* a,float* b) { //swap riceve due puntatori di tipo float
         
         float tmp;
         
		tmp = *a;   // salvo il valore puntato da a in tmp
		*a  = *b;   // metto in a il valore puntato da b
		*b  = tmp;  // metto in b il valore salvato 
}
