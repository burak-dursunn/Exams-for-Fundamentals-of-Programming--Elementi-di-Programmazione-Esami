#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N_MAX 100

struct Mystruct {
    char parola[N_MAX];
    int length;
    int pos;
    int string_number;
} typedef structer;

int main() {
    structer mystruct[N_MAX];
    char temp[N_MAX];

    int i, j, y;
    int length = 0;
    int counter = 0;
    int word_counter = 0;

    FILE *fr = fopen("input.txt", "r");
    while(fgets(temp, N_MAX, fr)) {
        i = j = y = 0;

        while(temp[i] != '\0'){
            char palindrome_word[N_MAX];
            while(temp[y] != ' ' && temp[y] != '\0') {
                palindrome_word[length] = temp[y];
                length++;
                y++;
            }

            bool is_palindrome = false;
            for(j = 0; j<length; j++) {
                if(palindrome_word[j] != palindrome_word[length - j]) {
                    is_palindrome = true;
                    break;
                }
            }

            if(!(is_palindrome)) {
                strcpy(mystruct[counter].parola, palindrome_word);
                mystruct[counter].length = length;
                mystruct[counter].pos = length - i;
                mystruct[counter].string_number = word_counter;
                
                counter++;
                word_counter++;
            }

            i = y + 1;
            counter++;
        }
    }

    fclose(fr);

    // struct atamalarını ve ekrana bastırma işlemlerini counter değerini baz alarak yaptım.

}