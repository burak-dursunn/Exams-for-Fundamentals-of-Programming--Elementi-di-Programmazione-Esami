#include <stdio.h>
#include <string.h>

#define N 50
 struct Mystruct
{
    int len;;
    float values[N];
    int originRow;
    int originCol;
};

void ordina(struct Mystruct v[], int r);

float somma(float v[], int n)
{
	float s=0;
	for(int i=0;i<n;i++) s =s +v[i];
	return s;
	}


int main()
{
	int n;
	float m[N][N];
	struct Mystruct v[N];
	int r=0;
	
	FILE *fp=fopen("input.txt", "r");
	
	memset(v,0,sizeof(struct Mystruct)*N);
	
	
	if(fp!=NULL)
	{
		fscanf(fp,"%d",&n);
		for(int i=0;i<n;i++)
		  for(int j=0;j<n;j++)
		    fscanf(fp, "%f", &m[i][j]);
	 
	    fclose(fp); 	
		}
    
   for(int i=0;i<n;i++)
   {
		  for(int j=0;j<n;j++) 
		     printf("%.2f\t",m[i][j]);
		  
		  printf("\n");
        
   }
   
   for(int j=0;j<n;j++)
   {
	   v[j].len = n-1;
	   v[j].originCol=j;
	   v[j].originRow=0;
	   for(int i=0;i<n-j;i++)
	    v[j].values[i]=m[i][i+j];
	}
	
	for(int i=1;i<n;i++)
	{
		v[i+n-1].len=n-i;
		v[i+n-1].originCol=0;
		v[i+n-1].originRow=i;
		for(int j=0;j<n-i;j++)
		  v[i+n-1].values[j]=m[j+i][j];	
		
		}
	   
	 r= 2*n-1;
	 
	ordina(v,r);
   for(int i=0;i<r;i++)
   {
     printf("{%d, %d, %d, [ ",v[i].len, v[i].originRow, v[i].originCol);
     for(int j=0;j<v[i].len;j++)
       printf("%.2f ",v[i].values[j]);
     printf("]}\n");
  }
   
   
   fp = fopen("output.bin", "w");
   if(fp!=NULL)
   {
	   fwrite(v,sizeof(struct Mystruct),r, fp);
	   fclose(fp);
	   
	   }
    
}

void ordina(struct Mystruct v[], int r)
{
	for(int i=0;i<r-1;i++)
	  for(int j=0;j<r-1-i;j++)
	    if(somma(v[j].values,v[j].len)> somma(v[j+1].values, v[j+1].len))
	    {
			struct Mystruct temp;
			temp=v[j];
			v[j]=v[j+1];
			v[j+1]=temp;
			
			}
	
	
	
	
	}
