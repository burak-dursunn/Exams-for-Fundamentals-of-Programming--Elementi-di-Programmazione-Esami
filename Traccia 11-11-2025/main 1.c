#include <stdio.h>
#include <string.h>

#define N_MAX 100
struct Mystruct
	{
		int id;
		int n;
		int word_len[N_MAX];				
	};

void read_lines(char lines[N_MAX][N_MAX], int *n);


int main()
{

	
}


void read_lines(char lines[N_MAX][N_MAX], int *n){
	
	FILE* fp_in;
	int i=0;
    //Apertura del file di input
    fp_in = fopen("input.txt", "r");
    if(fp_in!=NULL)
    {
        while(fgets(lines[i], N_MAX, fp_in) != NULL) i++;       
        //Chiusura del file di input
        fclose(fp_in);
	    *n=i;
	   }
    else
        printf("Errore apertura file");
 }
 
