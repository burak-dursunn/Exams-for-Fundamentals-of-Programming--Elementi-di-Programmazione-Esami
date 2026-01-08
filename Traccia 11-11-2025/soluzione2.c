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
void ordina(struct Mystruct v[], int n);

int main()
{
	char lines[N_MAX][N_MAX];
	char *parola;
	int n;
	struct Mystruct v[N_MAX];
	FILE *fp;
	
	read_lines(lines,&n);
	for(int i=0;i<n;i++)
	  printf("%s\n", lines[i]);
	  
	  
	for(int i=0;i<n;i++)
	{
		v[i].id=i;
		int n_parole=0;
		
		if(lines[i][strlen(lines[i])-1]=='\n') lines[i][strlen(lines[i])-1]='\0';
		
		// separazione in stringhe
		parola=strtok(lines[i]," ");
		while(parola!=NULL)
		{
			v[i].word_len[n_parole]=strlen(parola);
			n_parole++;
			parola=strtok(NULL," ");
			}
		v[i].n=n_parole;
		
		
		}
		
    ordina(v, n);
	for(int i=0;i<n;i++)
	{
		printf("{%d, %d, [",v[i].id, v[i].n);
		for(int j=0;j<v[i].n;j++)
		  printf("%d ",v[i].word_len[j]);
		printf("]}\n"); 
		
		}	
		
		
		
	fp=fopen("output.bin","w");
	if(fp!=NULL)
	{
		fwrite(v,sizeof(struct Mystruct),n,fp);
		fclose(fp);
		
		}	
	
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
void ordina(struct Mystruct v[], int n)
{
	for(int i=0;i<n-1;i++)
	  for(int j=0;j<n-1-i;j++)
	   if(v[j].n> v[j+1].n)
	   {
		   struct Mystruct temp=v[j];
		   v[j]=v[j+1];
		   v[j+1]=temp;
		   
		   }
	
	
	
	
	
	}
