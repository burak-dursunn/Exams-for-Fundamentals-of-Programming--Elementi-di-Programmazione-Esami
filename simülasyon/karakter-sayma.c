#include <stdio.h>
#define nmax 512

int karakter_sayaci(char kelime[]);


int main() {
    char kelime[nmax];
    printf("Kelimeyi giriniz: ");
    scanf("%s", &kelime[0]);

    printf("kelime: %s\n", kelime);
    printf("Kac farkli karakter var: %d\n", karakter_sayaci(kelime));

}

int karakter_sayaci(char kelime[]) {
    int i = 0;
    int j;
    int sayac = 0;
    char temp[128];
    temp[0] = '\0';

    while(kelime[i] != '\0') {
        j = 0;
        while(temp[j] != kelime[i] && temp[j] != '\0') {
            j++;
        }
        if(temp[j] != kelime[i]) {
            temp[j] = kelime[i];
            temp[j+1] = '\0';
            sayac++;
        }

        i++;
    }

    printf("temp: %s\n", temp);

    return sayac;
}