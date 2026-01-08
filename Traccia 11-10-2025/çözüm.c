#include <stdio.h>
#define NMAX 100

struct Mystruct {
    int col;
    float sum;
    int n;
    float row[NMAX];
} typedef structcuk;

int delete_rows(int matrix[][NMAX], int r, int c);
void write_struct(structcuk myStruct[], int c);
void read_struct();



int main() {
    //! Dosya okuma
    int r ,c;
    int matrix[NMAX][NMAX];

    FILE *f = fopen("input.txt","r");

    if (f == NULL) {
        printf("File error\n");
        return 1;
    }   
    fscanf(f, "%d %d", &r, &c);
    for(int i= 0; i<r; i++) {
        for(int j = 0; j< c; j++) {
            fscanf(f, "%d", &matrix[i][j]);
        }
    }
    fclose(f);

    //! Satır silme
    c = delete_rows(matrix, r, c);

    //! struct atama
    structcuk myStruct[c];
    int sum = 0;
    int i,j;
    for (i = 0; i < c; i++) {
        myStruct[i].col = i;
        myStruct[i].n = r;
        myStruct[i].sum = 0;

        for (j = 0; j < r; j++) {
            myStruct[i].row[j] = matrix[j][i];
            myStruct[i].sum += matrix[j][i];
        }
    }
    

    //! Sıralama algoritması - Greater to Smaller
    //! Eğer sınavda istenirse Bubble sort algoritması da kullanılabilir.
    //? for(y=0; y<r-i-1;y++) kod satırı ile sağlanabilir.
    int x,y;
    structcuk temp;
    for(x = 0; x<c; x++) {
        for(y = x; y<r; y++) {
            if(myStruct[x].sum < myStruct[y].sum) {
                temp = myStruct[x];
                myStruct[x] = myStruct[y];
                myStruct[y] = temp;
            }
        }
    }

    write_struct(myStruct, c);
    read_struct();

}

void write_struct(structcuk myStruct[], int c) {
    FILE *out = fopen("output.bin", "wb");
    if(out == NULL) {
        printf("Binary File erro\n");
    }

    fwrite(myStruct, sizeof(structcuk), c,out);
    fclose(out);
}

int delete_rows(int matrix[][NMAX], int r, int c) {
    int sum = 0;
    for (int i = 0; i < r; i++) {

        sum = 0;
        for (int j = 0; j < c; j++) {
            sum += matrix[i][j];
        }

        if (sum == 0) {
            // satırı sil
            for (int k = i; k < r - 1; k++) {
                for (int j = 0; j < c; j++) {
                    matrix[k][j] = matrix[k + 1][j];
                }
            }
            r--;
            i--;  // aynı index'i tekrar kontrol et
        }
    }
    return r;
}

void read_struct() {
    structcuk read_struct;
    FILE *read = fopen("output.bin", "rb");
    if(read == NULL) {
        printf("File was not able to open");
    }
    while(fread(&read_struct, sizeof(structcuk), 1, read) == 1) {
        printf("COLUMN: %d\n", read_struct.col);
        printf("SUM: %.2f\n", read_struct.sum);
        printf("N: %d\n", read_struct.n);
        
        printf("ROW Elements:\n");
        for(int i = 0; i< read_struct.n; i++) {
            printf("%.2f\n", read_struct.row[i]);
        }
        printf("-------------------\n");
    }
    fclose(read);
}

//! Kullanılmıyor artık ama kalsın.
int read_input() {
    char myString[NMAX];

    FILE *f = fopen("input.txt", "r");

    if(f == NULL) {
        printf("Could not able to open the file");
        return 1;
    }

    int column;
    int row = 0;
    int max = 0;
    int i;

    while(fgets(myString, NMAX, f)) {
        column = 0;
        i = 0;
        while(myString[i] != '\0' && myString[i] != '\n') {
            if(myString[i] != ' ' && 
                (myString[i+1] == ' ' || myString[i+1] == '\0' || myString[i+1] == '\n')) {
                column++;
            }
            i++;
        }
        if(max < column) {
            max = column;
        }
        row++;
    }

    fclose(f);

    printf("Column : %d - Row: %d\n", max, row);

}