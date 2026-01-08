/*
Data una stringa contare il numero di caratteri diversi.
Esempio: mamma --> n=2
*/
#include <stdio.h>
#include <string.h>
#define  NMAX 512

int diversi(char *s);

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
   int i=0, cont=0; 
   while(s[i]!='\0')
   {
	   // se s[i] non lo trovo a partire da i+1 vado avanti
	   // altrimenti incremento cont
	   if(strchr(s+i+1,s[i])==NULL) 
	     cont++;
	   
	   
	   i++;
	   
	}
	return cont;
}
