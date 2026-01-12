#include <stdio.h>
#define N_MAX 100

struct Mystruct
{
    int id;
    int chars;
    int words;
    float meanc;
    float meanw;
} typedef info;

void sort_struct(info struct1[], int id);
void write_struct(info struct1[], int id);
void print_struct(info struct1[], int id);


int main() {
    char temp[N_MAX];
    info struct1[N_MAX];

    FILE *f = fopen("input.txt", "r");
    if(f == NULL) {
        printf("File Couldn't opened");
    }
    
    int i = 0;
    int j = 0;
    char *start;
    // int index;
    int id = 0;
    int chars;
    int words;
    float meanc;
    float meanw;
    float sum_chars = 0; float sum_words = 0;
    while(fgets(temp, N_MAX, f)) {
        start = temp;
        chars = words = 0;
        meanc = meanw = 0;
        i = 0;
        // index = strcspn(temp,".!?");
        while(start[i] != '\0') {
            if((start[i] != ' ' || start[i] != '\n' || start[i] != '\0' ||
                start[i] != '.' || start[i] != '!'  || start[i] != '?')){
                    chars++;
                }

            if(start[i] != ' ' && start[j] != '\n' 
                && start[i] != '.'  && start[i] != '!' && start[i] != '?'
                && (start[i+1] == ' ' || start[i+1] == '\n' || start[i+1] == '\0' ||
                start[i+1] == '.' || start[i+1] == '!' || start[i+1] == '?')) {
                    words++;
                }

           if((start[i+1] == '.' || start[i+1] == '!' || start[i+1] == '?')) {
                sum_chars += chars;
                sum_words += words;
                struct1[id].id = id;
                struct1[id].chars = chars;
                struct1[id].words = words;
                struct1[id].meanc = (float)sum_chars/id+1;
                struct1[id].meanw = (float)sum_words/id+1;

                words = chars = 0;
                id++;
            } 

            
            i++;
        }
    }
    fclose(f);

    sort_struct(struct1, id);
    write_struct(struct1, id);
    print_struct(struct1, id);
}

void print_struct(info struct1[], int id) {
    int i;
    for(i = 0; i<id; i++) {
            printf("Sentence: %d\n", struct1[i].id);
            printf("Character: %d\n", struct1[i].chars);
            printf("Words: %d\n", struct1[i].words);
            printf("Mean Character: %d\n", struct1[i].meanc);
            printf("Mean Words: %d\n", struct1[i].meanw);
            printf("-------------------------------\n");
    }
}

void sort_struct(info struct1[], int id) {
    info temp_struct;
    int i,j;
    for(i = 0; i<id; i++) {
        for(j = i+1; j<id; j++) {
            if(struct1[i].chars<struct1[j].chars) {
                temp_struct = struct1[i];
                struct1[i] = struct1[j];
                struct1[j] = temp_struct;
            }
        }
    }
}

void write_struct(info struct1[], int id) {
    FILE *f = fopen("output.bin", "wb");
    if(f == NULL) {
        printf("The file could not be opened");
    }

    fwrite(struct1, sizeof(info), id, f);
    fclose(f);
}