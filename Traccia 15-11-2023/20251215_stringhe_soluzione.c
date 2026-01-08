#include <stdio.h>
#include <string.h>

#define NMAX 200

struct Mystruct {
 int linea;
 int token;
 char str[200];
 int value;
};

int isnumber(char * s){
	int i=0;
	while(s[i]!='\0' && s[i]>='0' &&s[i]<='9')
	  i++;
	
	if(s[i]=='\0' &&i>0) return 1;
	else 
	  return 0;
	
	}


int main()
{
	char line[NMAX];
	FILE *fp;
	int contlinea=0,n=0,contatoken;
	char* token;
	struct Mystruct v[NMAX];
	
	fp=fopen("input.txt", "r");
	if(fp!=NULL)
	{
		while(fgets(line,NMAX,fp)!=NULL)
		{
			contatoken=0;
			printf("%s\n",line);
			if(line[strlen(line)-1]=='\n') line[strlen(line)-1]='\0';
			token=strtok(line," ,");
			while(token!=NULL)
			{
				v[n].linea=contlinea;
				v[n].token=contatoken;
				strcpy(v[n].str,token);
				if(isnumber(token)==0)
				  v[n].value=-1;
				else
				  sscanf(token,"%d", &v[n].value);
				
				
				n++;
				contatoken++;
				token=strtok(NULL," ,");
				}
			
			
			
			contlinea++;
			}//while fgets
		
		
		fclose(fp);
		}
	
	  memset(v,0,sizeof(struct Mystruct)*NMAX);
	  
	  
	  
	  
	  fp=fopen("output.bin", "w");
	  if(fp!=NULL)
	    {
			fwrite(v,sizeof(struct Mystruct), n,fp);
			fclose(fp);
			}
	
	
	}
	
void ordina(struct Mystruct v[], int n)
{
	struct Mystruct temp;
	for(int i=0;i<n-1;i++)
	 for(int j=0;j<n-1-i;j++)
	 if(v[j].value<v[j+1].value || (v[j].value==v[j+1].value  &&  strcmp(v[j+1].str,v[j].str)<0))
	 {
		 temp=v[j];
		 v[j]=v[j+1];
		 v[j+1]=temp;
		 
		 
		 }
	
	
	
	
	}	
	
