#include <stdio.h>
#include <string.h>


#define NMAX 100
	struct Mystruct{
	int lunghezza_riga;
	float elementi_doppione[NMAX];
	int indice_di_riga;

};

typedef struct Mystruct RigaMat;
int confronta(float *v1, float *v2, int n);
int cerca(RigaMat v[], int n, float *riga, int c);
void elimina_riga(float m[][NMAX], int x, int r, int c);

int main()
{
    int r,c;
    float m[NMAX][NMAX];
    FILE *fp;
    
    RigaMat v[NMAX];
    int n=0;
    
    fp=fopen("input.txt", "r");
    if(fp!=NULL)
    {
		fscanf(fp,"%d %d", &r, &c);
		for(int i=0;i<r;i++)
		  for(int j=0;j<c;j++)
		  {fscanf(fp,"%f", &m[i][j]);}
		fclose(fp);  	
		}

     for(int i=0;i<r;i++)
     {
		  for(int j=0;j<c;j++)
		   printf("%.2f\t",m[i][j]);
		 printf("\n");
	  }
	
	 memset(v,0,sizeof(RigaMat)*NMAX);
	 
	 for(int i=0;i<r-1;i++)
	 {
		 int j=i+1;
		 while(j<r && confronta(m[i], m[j],c)==0)
		    j++;
		 if(j<r)
		 {//trovato un doppione
			 if(cerca(v,n,m[i],c)==0)
			 {
				 v[n].indice_di_riga=i;
				 v[n].lunghezza_riga=c;
				 for(int k=0;k<c;k++)
				   v[n].elementi_doppione[k]=m[i][k];
				 n++;
				 
				 }//end if 
			 
			 
			 }//end if j<r
		 }//end for i
		 
	 for(int i=0;i<n;i++)
	 {
		 printf("{%d, %d, [ ",v[i].indice_di_riga, v[i].lunghezza_riga);
		  for(int j=0;j<v[i].lunghezza_riga;j++)
		    printf("%0.2f ", v[i].elementi_doppione[j]);
		  printf("]}\n");
		 
		 }
	 
	 
	 
	 fp=fopen("output.bin", "w");
	 if(fp!=NULL)
	   {
		   fwrite(v,sizeof(RigaMat), n,fp);
		   fclose(fp);
		   }
	
	for(int i=0;i<r;i++)
	{
		//cerco la riga doppione
		int j=i+1;
		while(j<r && confronta(m[i], m[j],c)==0)
		    j++;
		if(j<r)
		 {//trovato un doppione
		  //elimino riga j
		    elimina_riga(m, j,r,c);
		    r=r-1;
		    i=i-1;
		  }
	  }
	
	
	for(int i=0;i<r;i++)
     {
		  for(int j=0;j<c;j++)
		   printf("%.2f\t",m[i][j]);
		 printf("\n");
	  }
	
	
	}



int confronta(float *v1, float *v2, int n){
	
	int i=0;
	while(i<n && v1[i]==v2[i]) i++;
	if(i<n) return 0; //array diversi
	else return 1;
	
	
	
	}
int cerca(RigaMat v[], int n, float *riga, int c){
	
	int i=0;
	while(i<n && confronta(riga, v[i].elementi_doppione,c)==0)
	  i++;
	  
	if(i<n) return 1; //trovato doppione
	else return 0;
	
	
	}

void elimina_riga(float m[][NMAX], int x, int r, int c)
 {
	 for(int i=x;i<r-1;i++)
	 
		 for(int j=0;j<c;j++)
		   m[i][j]=m[i+1][j];
 
	 }
