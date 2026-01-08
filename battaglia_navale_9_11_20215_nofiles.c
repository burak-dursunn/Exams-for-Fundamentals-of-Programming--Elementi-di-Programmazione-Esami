#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_MAX 5
#define N_NAVI 5

void riempi_random(char m[][N_MAX], int r, int c, int n);
//type=='u' se utente altrimenti =='a' se avversario
void stampa(char m[][N_MAX], int r, int c, char type);

// return 0 se a vuoto, 1 se colpito
int play_user(char m[][N_MAX], int r, int c);
int play_cpu(char m[][N_MAX], int r, int c);


int main()
{
    //nave: N, colpita: X, colpo a vuoto: O, vuoto: '-'
    char user[N_MAX][N_MAX], cpu[N_MAX][N_MAX];
    int user_punt=0, cpu_punt=0;
    FILE *fp;


    srand(time(NULL));

   
      riempi_random(user,N_MAX, N_MAX,N_NAVI);
    riempi_random(cpu,N_MAX, N_MAX, N_NAVI);


    


    do{
        printf("Matrice Utente:\n");
        stampa(user,N_MAX, N_MAX, 'u');
        printf("Matrice CPU:\n");
        stampa(cpu, N_MAX, N_MAX,'a');
        user_punt += play_user(cpu,N_MAX,N_MAX);

        cpu_punt += play_cpu(user,N_MAX, N_MAX);
        printf("user: %d, cpu: %d\n", user_punt,cpu_punt);


 

    }while(user_punt<5 && cpu_punt<5);

    if(user_punt==5)
    printf("User Wins!!!\n");
    else
    printf("CPU Wins!!!\n");






    return 0;
}


void riempi_random(char m[][N_MAX], int r, int c, int n)
{
   for(int i=0;i<r;i++)
     for(int j=0;j<c;j++)
       m[i][j]='-';

   int x,y;
   for(int i=0;i<n;i++)
   {
       do{
        x=rand()%r;
        y=rand()%c;
        }while(m[x][y]=='N');

        m[x][y]='N';

   }


}


void stampa(char m[][N_MAX], int r, int c, char type)

{
    printf("\n\t");
    for(int j=0;j<c;j++)  printf("%d\t",j);

    for(int i=0;i<r;i++)
    {
      printf("\n");
      printf("%d\t",i);
      for(int j=0;j<c;j++)
      {

         if(type=='u')
            printf("%c\t",m[i][j]);
        else
        {
           if(m[i][j]=='N')
             printf("-\t");
           else
             printf("%c\t", m[i][j]);
        }

      }
    }
   printf("\n");

}


int play_user(char m[][N_MAX], int r, int c)
{
   int x, y;
   do{
    printf("inserisci la riga:\n");
    scanf("%d",&x);
    printf("inserisci la colonna:\n");
    scanf("%d",&y);
    }while(x>r || y>c || m[x][y]=='O' || m[x][y]=='X');

    if (m[x][y]=='N')
    {
       m[x][y]='X';
       return 1;
       }
    else {
       m[x][y]='O';
       return 0;
    }

}


int play_cpu(char m[][N_MAX], int r, int c)
{
   int x, y;
   do{
       x=rand()%r;
       y=rand()%c;
   }while(m[x][y]=='O' || m[x][y]=='X');

    if (m[x][y]=='N')
    {
       m[x][y]='X';
       return 1;
       }
    else {
       m[x][y]='O';
       return 0;
    }

}
