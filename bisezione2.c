#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float poly(float coeff[], int n, float x)
{
	float temp =1;
	float val=0;
	for(int i= 0;i<n;i++)
	 {
		 val = val+coeff[i]*temp;
		 temp = temp*x;
		 }
	return val;
	
	}
	
#define NMAX 10;
#define MAXSTEPS 40
#define RESOLUTION 0.001
int main(void) {
	int steps=0;
	float low=2, high=200;
	float z,fl,fh,fz;
	int n=3;
	float coeff[]= {54.5,-55.5,1};
  
	


	printf("l'equazione e': ");
	for(int i=n-1;i>0;i--)
	  printf("(%.2f)*X^%d +",coeff[i],i);
	printf("(%.2f)\n", coeff[0]);
	
	
	printf("L'intervallo e'  [%.2f , %.2f] \n",low, high);
	fflush(stdout);
	
	fl=poly(coeff,n,low);
	fh=poly(coeff,n,high);
	do {
		z=(low+high)/2;
		fz=poly(coeff,n,z);;

		printf("z: %.2f, fz: %.2f , flow: %.2f, fhigh: %.2f\n",z,fz,fl,fh); fflush(stdout);

		if((fz*fl)<0) {
			high=z;
			fh=fz;
		} else {
			low=z;
			fl=fz;
		}
		steps++;
	} while((fabs(fz)>RESOLUTION)&&(steps<MAXSTEPS));

	if(steps<MAXSTEPS) 
	  printf("Zero: %f, Result: %f in %d passi\n",z,fz, steps);
	else
	   printf("L'algoritmo non converge in %d passi\n",steps);
	return EXIT_SUCCESS;
}
