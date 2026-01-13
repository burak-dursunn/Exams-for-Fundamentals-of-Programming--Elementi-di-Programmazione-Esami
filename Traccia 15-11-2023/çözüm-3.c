#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NMAX 200

struct Mystruct {
    int line;
    int token;
    char str[NMAX];
    int value;
} typedef belge;

int isNumber(char *s);
void trim(char *s);
void sort(belge belgeler[], int n);
void printStruct(belge bilgiler[], int n);

int main() {
    belge bilgiler[NMAX];
    
    FILE *fr = fopen("input.txt", "r");
    if(fr == NULL) {
        printf("File could not be opened.");
    }
    
    char line[NMAX];
    char *start;
    char *comma;
    int token_id;
    int i = 0;
    int line_no = 0;
    while(fgets(line, NMAX, fr) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        token_id = 0;
        start = line;

        while((comma = strchr(start, ',')) != NULL) {
            *comma = '\0';

            bilgiler[line_no].line = i;
            bilgiler[line_no].token = token_id;
            strcpy(bilgiler[line_no].str, start);
            trim(bilgiler[line_no].str);
            bilgiler[line_no].value = isNumber(start) ? atoi(bilgiler[line_no].str) : -1;

            printf("[%d, %d, [%s], %d]\n", 
                bilgiler[line_no].line, 
                bilgiler[line_no].token,
                bilgiler[line_no].str,
                bilgiler[line_no].value);
            printf("----------------\n");

            token_id++;
            start = comma + 1; 
            //! start bir pointer olduğu için *(comma +1) yapamayız çünkü adres vermemiz lazım
            line_no++;
        }

        //? son satırın son virgülünden sonrası için
        bilgiler[line_no].line = i;
        bilgiler[line_no].token = token_id;
        strcpy(bilgiler[line_no].str, start);
        trim(bilgiler[line_no].str);
        bilgiler[line_no].value = isNumber(bilgiler[line_no].str) ? atoi(bilgiler[line_no].str) : -1;

        printf("[%d, %d, [%s], %d]\n", 
            bilgiler[line_no].line, 
            bilgiler[line_no].token,
            bilgiler[line_no].str,
            bilgiler[line_no].value);
        printf("***********************\n");

        i++;
    }
    fclose(fr);

    sort(bilgiler, line_no);
    printStruct(bilgiler, line_no);
}

void trim(char *s) {
    char *start = s;
    char *end;

    // Baştaki boşlukları atla
    while (*start == ' ')
        start++;

    // String’i sola kaydır
    if (start != s)
        memmove(s, start, strlen(start) + 1);

    // Sondaki boşlukları sil
    end = start + strlen(start) - 1;
    while (end >= start && *end == ' ')
        end--;

    *(end + 1) = '\0';
}

void sort(belge bilgiler[], int n) {
    int i,j;
    belge temp;
    for(i = 0; i<n; i++) {
        for(j = i+1; j<n; j++) {
            if(bilgiler[i].value<bilgiler[j].value || (bilgiler[j].value == bilgiler[i].value && 
                (strcmp(bilgiler[j].str, bilgiler[i].str) > 0))) {
                temp = bilgiler[i];
                bilgiler[i] = bilgiler[j];
                bilgiler[j] = temp;
            }
        }
    }
}

void printStruct(belge bilgiler[], int n) {
    int i,j;
    for(i = 0; i<n; i++) {
        printf("[%d, %d, [%s], %d]\n", 
            bilgiler[i].line, 
            bilgiler[i].token,
            bilgiler[i].str,
            bilgiler[i].value);
    }
}

int isNumber(char *s) {
    int i = 0;

    while (s[i] == ' ')
        i++;

    while((s[i]>='0' && s[i]<='9') && s[i] != '\0') 
        i++;
    
    if(s[i] == '\0' && i>0) {
        return 1;
    }
    else
        return 0;

}