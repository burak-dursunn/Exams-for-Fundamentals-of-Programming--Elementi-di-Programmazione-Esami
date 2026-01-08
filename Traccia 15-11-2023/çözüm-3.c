#include <stdio.h>
#include <string.h>
#define NMAX 200

struct Mystruct {
    int line;
    int token;
    char str[NMAX];
    int value;
} typedef belge;

int main() {
    belge bilgiler[NMAX];
    
    FILE *fr = fopen("input.txt", "r");
    if(fr == NULL) {
        printf("File could not be opened.");
    }
    
    int i;
    char line[NMAX];
    char *start;
    char *comma;
    int token_id;
    while(fgets(line, NMAX, fr) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        token_id = 0;
        start = line;

        while((comma = strchr(start, ',')) != NULL) {
            *comma = '\0';

            printf("Token %d: [%s]\n", token_id, start);

            token_id++;
            start = comma + 1; 
            //! start bir pointer olduğu için *(comma +1) yapamayız çünkü adres vermemiz lazım
        }

        //? son satırın son virgülünden sonrası için
        printf("Token %d: [%s]\n", token_id, start);
        printf("----------------\n");
    }
    fclose(fr);
} 