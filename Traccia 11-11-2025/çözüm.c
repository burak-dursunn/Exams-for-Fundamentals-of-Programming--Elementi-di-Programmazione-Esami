#include <stdio.h>
#define NMAX 100

struct Mystruct {
    int id;
    int n;
    int word_len[NMAX];
} typedef infostruct;

int main() {
    int i, j;
    int counter, line = 0;
    int length; 
    struct Mystruct line_info[NMAX];
    char myString[NMAX];

    FILE *f = fopen("input 1.txt", "r");

    if (f == NULL) {
        printf("Not able to open the file");
    }

    while(fgets(myString, NMAX, f)) {

        i = 0;
        counter = 0;
        length = 0;

        line_info[line].id = line + 1;

        while(myString[i] != '\0') {
            //!word length
            if(myString[i] != ' ' && myString[i] != '\n') {
                length++; // 2
            }
            //!words
            if(myString[i] != ' ' && myString[i] != '\n'  && 
                (myString[i+1] == ' ' || myString[i+1] == '\n' || myString[i+1] == '\0')) {
                line_info[line].word_len[counter] = length;
                counter++; // 1
                length = 0;
            }

            i++;
        }

        line_info[line].n = counter;
        line++;
    }

    fclose(f);

    for(i=0; i<line; i++) {
        printf("Satir: %d\n", line_info[i].id);
        printf("Kelime sayisi: %d\n", line_info[i].n);
        int j;
        for(j = 0; j<line_info[i].n; j++) {
            printf("%d ",line_info[i].word_len[j]);
        }
        printf("\n");
    }


}