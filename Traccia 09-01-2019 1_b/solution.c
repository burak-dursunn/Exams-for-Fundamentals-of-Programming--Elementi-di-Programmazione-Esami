#include <stdio.h>
#include <stdbool.h>
#define NMAX 100
struct Mystruct {
    int length;
    float row_elements[NMAX];
    int row_index;
} typedef recurring;

int main() {
    float matrix[NMAX][NMAX];
    recurring duplicates[NMAX];
    int row, column;
    
    //! Okuma
    FILE *fr = fopen("input.txt", "r");
    if(fr == NULL) {
        printf("Could not be opened");
    }
    fscanf(fr, "%d %d", &row, &column);
    int i,j;
    for(i = 0;i<row; i++) {
        for(j = 0; j<column; j++) {
            fscanf(fr, "%f", &matrix[i][j]);
        }
    }
    fclose(fr);

    //! Aynı satırları tespit etme
    int counter = 0;
    bool is_duplicate[NMAX] = {false};
    for(i = 0; i<row; i++) {
        for(int k = i+1; k<row; k++) {
            if(is_duplicate[k]) continue;

            bool match = true;
            for(j = 0; j<column; j++) {
                if(matrix[i][j] != matrix[k][j]) {
                    match = false;
                    break;
                }
            }

            if(match) {
                duplicates[counter].length = column;
                for(int j = 0; j<column; j++) {
                    duplicates[counter].row_elements[j] = matrix[k][j];
                }
                duplicates[counter].row_index = k;
                counter++;

                is_duplicate[k] = true;
            }
            
        }
    }

    //! Silme
    float new_matrix[NMAX][NMAX];
    int new_rows = 0;
    for(i = 0; i<row; i++) {
        if(!(is_duplicate[i])) {
            for(j = 0; j<column; j++){
                new_matrix[new_rows][j] = matrix[i][j];
            }
            new_rows++;
        }
    }

    //! Binary Yazma
    FILE *fw = fopen("output.bin", "wb");
    if(fw == NULL) {
        printf("File was not be opened");
    }

    fwrite(duplicates, sizeof(recurring), counter, fw);
    fclose(fw);
    printf("Islem tamamlandi. %d kopya satir bulundu.\n", counter);

    //! Ekrana yazdırma
    for(i = 0; i<new_rows; i++) {
        for(j = 0; j<column; j++){
            printf("%.1f ", new_matrix[i][j]);
        }
        printf("\n");
    }


    return 0;
}
