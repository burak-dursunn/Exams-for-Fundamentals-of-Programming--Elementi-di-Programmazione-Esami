#include <stdio.h>
#define N_MAX 100
struct mystruct {
    int occ;            // Occurrence number found
    int riga;           // Row index where the first element of the vector was found
    int col;            // Column index where the first element of the vector was found
    int len;            // Length of the vector
    int vector[N_MAX]; // The vector itself
};

int main() {
    int temp[N_MAX];
    int row, column;
    FILE *f = fopen("input.txt", "r");
    if(f == NULL) {
        printf("The document could not be opened");
    }

    //! matrix
    int i,j;
    int matrix[N_MAX][N_MAX];
    fscanf(f, "%d %d", &row, &column);
    for(i = 0; i<row; i++) {
        for(j = 0; j<column; j++) {
            fscanf(f, "%d", &matrix[i][j]);
        }
    }
}
