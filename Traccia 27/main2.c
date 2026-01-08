#include <string.h>

#define N_MAX 512

int main()
{
	char s[N_MAX], *parola;
	FILE *fp=fopen("input.txt","r");
	if(fp!=NULL)
	{
		while(fgets(s,N_MAX,fp)!=NULL)
		{
			//linea file letta
			parola=strtok(s, " ");
			int n=0;
			while(parola!=NULL)
			{
				if(converti(parola)>=0)
				 n =n *10 +converti(parola);
				
				parola=strtok(NULL, " ");
				}
			
			
			
			
			
			
			}
		
		
		
		
		
		}
	
	
	
	
	}




int converti(char s[]
{
	if(!strcmp(s,"uno")) return 1;
	else if(!strcmp(s,"due")) return 2;
	else if(!strcmp(s,"tre")) return 3;
	else if(!strcmp(s,"quattro")) return 4;
	else if(!strcmp(s,"cinque")) return 5;
	else if(!strcmp(s,"sei")) return 6;
	else if(!strcmp(s,"sette")) return 7;
	else if(!strcmp(s,"otto")) return 8;
	else if(!strcmp(s,"nove")) return 9;
	else if(!strcmp(s,"zero")) return 0;
	else return -1;
	
	
	
	
	
	}
