#include <stdio.h>

void selection_sort(int *dizi, int n);

int main() {
    int i;

    int dizi[10] = {10,9,8,724,6,5,4,3,2,1};
    selection_sort(dizi, 10);
    for(i=0; i<10; i++) {
        printf("%d ", dizi[i]);
    }


}

void selection_sort(int *dizi, int n) {
    int i, j, temp;
    for(i = 0; i<(n-1); i++) {
        for(j = i+1; j<n; j++) {
            if(dizi[i] < dizi[j]) {
                temp = dizi[i];
                dizi[i] = dizi[j];
                dizi[j] = temp;
            }
        }
    }
}

