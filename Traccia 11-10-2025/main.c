#include <stdio.h>
#include <string.h>

#define N_MAX 100
struct Mystruct
	{
		int col;
		int sum;
		int n;
		int row[N_MAX];				
	};

// legge la matrice da file e restituendo anche numero di righe e colonne
void read_mat(int m[N_MAX][N_MAX], int *r, int*c);


int main()
{
	
	
}



void read_mat(int mat[N_MAX][N_MAX], int *r, int*c){
	
	FILE* fp_in;
    //Apertura del file di input
    fp_in = fopen("input.txt", "r");
    if(fp_in != NULL)
    {
        //Lettura dei dati (dimensioni e elementi) della matrice dal file di input
        fscanf(fp_in, "%d", r);
        fscanf(fp_in, "%d", c);
        for(int i=0; i<*r; i++)
        {
            for(int j=0; j<*c; j++)
                fscanf(fp_in, "%d", &mat[i][j]);
        }
        //Chiusura del file di input
        fclose(fp_in);
	
	
	   }
    else
        printf("Errore apertura file");
 }
