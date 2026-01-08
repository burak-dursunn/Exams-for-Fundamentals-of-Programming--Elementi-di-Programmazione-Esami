//ESECIZIO CON PUNTATORE 
//Calcola la media di ogni riga di una matrice.
//Aggiungere una nuova colonna contenente quelle medie.

#include <stdio.h>
#define dim 100
void aggiungiMediaRighe(float mat[][dim], int righe, int *colonne);
int main() {
    int r = 3, c = 3;
    float m[][dim] = {
        {0, 2.4, 3,4,0},
        {3,0,5,10,2},
        {1,0,2,1,3},
        {8,0,0,0,0},
    };

    aggiungiMediaRighe(m, r, &c);//  passaggio di parametri 
    // stampa la matrice aggiornata
    printf("Matrice con medie aggiunte:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%.2f ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}



// Sottoprogramma che aggiunge una colonna con la media delle righe
void aggiungiMediaRighe(float mat[][dim], int righe, int *colonne) {

    for(int i = 0; i < righe; i++) {
        float somma = 0;

        // somma degli elementi della riga
        for(int j = 0; j < *colonne; j++) {
            somma += mat[i][j];
        }

        float media = somma / (*colonne);

        // la nuova colonna sarà in posizione *colonne
        mat[i][*colonne] = media;
    }

    // aggiorno il numero di colonne
    (*colonne)++;
}
