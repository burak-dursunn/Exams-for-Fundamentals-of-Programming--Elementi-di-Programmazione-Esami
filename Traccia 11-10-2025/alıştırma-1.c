#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N_MAX 5

struct Mystruct {
    int col;
    float sum;
    int n;
    float row[N_MAX];
} typedef tinystruct;

//* Fonksiyon prototipleri
void print_matrix(float v[][N_MAX], int rows, int cols);
void row_max_min(float v[][N_MAX], int rows, int cols);
int delete_negative_columns(float v[][N_MAX], int rows, int cols);
int read_struct();
void write_struct(struct Mystruct cols[], int columns);


int main()
{
    float v[N_MAX][N_MAX];
    int i, j;
    int x,y;
    int rows = 2;
    int columns = 3;    
    
    for(i = 0; i<rows; i++) {
        for(j = 0; j<columns; j++) {
            printf("enter the first value: ");
            scanf("%f",&v[i][j]);
        }
    }


    printf("Matrix before swaping:\n");
    print_matrix(v, rows, columns);

    row_max_min(v, rows, columns);

    printf("Matrix after swaping and before deleting negative columns:\n");
    print_matrix(v, rows, columns);

    columns = delete_negative_columns(v, rows, columns);
    printf("Matrix after deleting negative columns:\n");
    print_matrix(v, rows, columns);
    printf("New columns value: %d\n\n", columns);

    //! Mystruct 
    tinystruct cols[N_MAX];
    for(x = 0; x<columns; x++) {
        cols[x].col = x;
        cols[x].n = rows;
        cols[x].sum = 0;

        for(y = 0; y<rows; y++) {
            cols[x].sum += v[y][x];
            cols[x].row[y] = v[y][x];
        }
    }

    //! Sıralama - Greater to smaller
    tinystruct temp;
    for(i = 0; i<columns -1; i++) {
        for(j = i+1; j<columns; j++) {
            if(cols[i].sum < cols[j].sum) {
                temp = cols[i];
                cols[i] = cols[j];
                cols[j] = temp;
            }
        }
    }

    write_struct(cols, columns);
    read_struct();

    return 0;
}

void write_struct(struct Mystruct cols[], int columns) {
    FILE *fw = fopen("output.bin","wb");
    for(int i = 0; i<columns; i++) {
        fwrite(&cols[i], sizeof(tinystruct), 1, fw);
    }
    fclose(fw);
}

int read_struct() {
    tinystruct tempinho;
    FILE *fr = fopen("output.bin", "rb");

    if (fr == NULL) {
        printf("Dosya acilamadi!\n");
        return 1;
    }

    while (fread(&tempinho, sizeof(tinystruct), 1, fr) == 1) {

        printf("COLUMN: %d\n", tempinho.col);
        printf("SUM: %.2f\n", tempinho.sum);
        printf("N: %d\n", tempinho.n);

        printf("ROW: ");
        for (int i = 0; i < tempinho.n; i++) {
            printf("%.2f ", tempinho.row[i]);
        }
        printf("\n-----------------\n");
    }

    fclose(fr);
    return 0;
}

void print_matrix(float v[][N_MAX], int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%8.2f ", v[i][j]); // 8 karakter genişliğinde, 2 ondalık basamak
        }
        printf("\n");
    }
}

void row_max_min(float v[][N_MAX], int rows, int cols) {
    int i, j;
    float max, min;
    int index_max = 0, index_min = 0;
    float temp;

    for(i = 0; i<rows; i++) {
        max = min = v[i][0];
        index_max = index_min = 0;
        for(j = 1; j<cols; j++) {
            if (v[i][j]>max) { // en büyük olan ilk elemanı alacak.
                max = v[i][j];
                index_max = j;
            }
            if(v[i][j]<=min) { // en sondaki en küçük elaman istendiği için "<=" kullandım.
                min = v[i][j];
                index_min = j;
            }
        }

        // printf("%.2f - %.2f\n", max,min);
        // printf("%d - %d\n", index_max, index_min);

        
        //? swap
        temp = v[i][index_max];
        v[i][index_max] = v[i][index_min];
        v[i][index_min] = temp;

    }
    
}

int delete_negative_columns(float v[][N_MAX], int rows, int cols) {
    int i, j, k;
    float sum_col = 0;
    for(i = 0; i<cols; i++) {
        
        sum_col = 0;
        for(j = 0; j<rows; j++) {
            sum_col += v[j][i];
        }

        if(sum_col<0) {
            // sütunu sola kaydırma işlemi
            for(k=i; k< cols-1; k++) { // i'den başlattık. silinecek sütundan önceki sütunlara elleşmiyoruz
                for(j=0; j<rows; j++) {
                    v[j][k] = v[j][k+1]; // artık 2. sütun --> 1.sütun oldu.
                }
            }
            cols--; // en sondaki sütun boşa çıktığı için cols değerini 1 düşürüyoruz
            i--; 
            // silme işleminden sonra 2. sütun --> 1. sütun olduğu için i değerimiz 
            // silinen sütunda şuan  ve silinen sütunun yerine bir sonraki i değeri, 
            // yani 2. sütun geldiği  için  otomatik olarak silinen sütundan sonraki sütunu 
            // atlamış oluyoruz istemeyerek.
        } 
    }

    return cols;
}