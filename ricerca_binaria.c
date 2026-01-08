
#include <stdio.h>
void ricerca_binaria ( int a[], int n, int x, int *flag, int *i );

int main()
{
	int v[10]= {1,3,5,7,10,11,12,13,19,23};
	int x=19, flag=0, i;
	
	ricerca_binaria(v,10,x,&flag, &i);
	
	if(flag) 
	  printf("Elemento %d trovato in posizione %d\n",x,i);
	else
	  printf("Elemento %d non trovato\n",x);
	  
	}

void ricerca_binaria ( int a[], int n, int x, int *flag, int *i ) {
	int primo=0, ultimo=n-1;
	int medio;
	*flag=0;
	while ( (primo<=ultimo) && ! *flag ) {
		medio = (primo + ultimo) / 2;
		if ( x == a[medio] )
			*flag = 1;
		else if ( x < a[medio] )
				ultimo = medio - 1;
			else /* x > a[medio] */
				primo = medio + 1;
	}
	if ( flag ) *i = medio;
}
