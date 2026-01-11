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
        i = j = 0;
        words = chars = 0;
        // index = strcspn(temp,".!?");
        while(start[i] != '\0') {
            while((start[j] != ' ' || start[j] != '\n' || start[j] != '\0' ||
                start[j] != '.' || start[j] != '!' || start[j] != '?')){
                    chars++;
                    j++;
                }
            if(start[i] != ' ' && (start[i+1] == ' ' || start[i+1] == '\n' || start[i+1] == '\0' ||
                start[i+1] == '.' || start[i+1] == '!' || start[i+1] == '?')) {
                    words++;
                }
            if((start[i+1] == '.' || start[i+1] == '!' || start[i+1] == '?')) {
                sum_chars += chars;
                sum_words += words;
                struct1[id-1].id = id;
                struct1[id-1].chars = chars;
                struct1[id-1].words = words;
                struct1[id-1].meanc = sum_chars/id+1;
                struct1[id-1].meanw = sum_words/id+1;

                id++;
            }

            
            i++;
        }
    }
}