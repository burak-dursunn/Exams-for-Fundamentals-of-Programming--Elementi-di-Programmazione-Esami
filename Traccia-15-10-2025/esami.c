#include <stdio.h>
#define N_MAX 100

struct Mystruct {
    int idstr;
    char c;
    int removals;
} typedef infocuk;

void sort_struct(infocuk characters[], int n);
void print_struct(infocuk characters[], int n);
void write_struct(infocuk characters[], int n);

int main() {
    char temp[N_MAX];
    struct Mystruct characters[N_MAX];
    int n = 0;
    FILE *f = fopen("input.txt", "r");
    if(f == NULL) {
        printf("The document could not be opened");
    }
    int line = 0;
    while(fgets(temp, N_MAX, f)) {
        int i = 0;
        int counter = 1;
        while(temp[i] != '\0' && temp[i] != '\n') {
            if(temp[i] == temp[i+1]) {
                counter++;
            } 
            else {
                if((temp[i] == ' ' && counter > 1 ) || (counter > 2)) {
                    characters[n].idstr = line;
                    characters[n].c = temp[i];

                    if(temp[i] == ' ') {
                        characters[n].removals = counter - 1;
                    } else {
                        characters[n].removals = counter - 2;
                    }
                    
                    n++;
                    counter = 1;
                }
                counter = 1;
            }

            i++;
        }
        line++;
    }

    sort_struct(characters, n);
    print_struct(characters, n);
    write_struct(characters, n);


    return 0;
}

void write_struct(infocuk characters[], int n) {
    FILE *f = fopen("output.bin", "wb");
    if(f == NULL) {
        printf("File couldn't be opened");
    }
    fwrite(characters, sizeof(infocuk), n, f);
    fclose(f);
}

void print_struct(infocuk characters[], int n) {
    int i,j;
    for(i = 0; i<n; i++) {
            printf("{%d,%c,%d}\n", characters[i].idstr, characters[i].c, characters[i].removals);
    }
}

void sort_struct(infocuk characters[], int n) {
    infocuk temp;
    int i,j;
    for(i = 0; i<n; i++) {
        for(j = i+1; j<n; j++) {
            if((characters[i].idstr > characters[j].idstr) 
            || ((characters[i].idstr == characters[j].idstr) 
            && (characters[i].removals < characters[j].removals))) {
                temp = characters[i];
                characters[i] = characters[j];
                characters[j] = temp;

            }
        }
    }
}
