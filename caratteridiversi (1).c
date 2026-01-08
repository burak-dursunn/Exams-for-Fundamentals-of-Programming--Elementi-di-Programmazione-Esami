/*
Data una stringa contare il numero di caratteri diversi.
Esempio: mamma --> n=2
*/
#include <stdio.h>
#define  NMAX 512

int diversi(char *s);
int cerca(char *s, char x);

int main()
{
	char stringa[NMAX];
	
	printf("Inserisci la stringa:\n");
	fgets(stringa, NMAX, stdin);
	printf("%s",stringa);
	printf("caratteri diversi=%d\n",diversi(stringa));
	
	}
	
int diversi(char *s)
{
	int cont=0;
	char temp[128];
	int i=0;
	temp[0]='\0'; //stringa vuota
	while(s[i]!='\0')
	{
		//controllare se il caratter iesimo e' gia' stato incontrato
		//ovvero se e' gia' stato inserito nell'array
		if(cerca(temp,s[i])<0)
		{  
			temp[cont]=s[i];
			temp[cont+1]='\0';
			cont++;
		}
		i++;
	}

	 printf("temp=%s\n",temp);
	 return cont;
	}

int cerca(char *s, char x){
	
	int i=0;
	while(s[i]!='\0' && s[i]!=x) i++;
	if(s[i]==x) return i;
	
	return -1;
	
	
	
	}
