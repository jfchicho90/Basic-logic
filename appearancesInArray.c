#include <stdio.h>

#define DIM 10

void appearances(int a[]);

int main() {
    
    int arr[] = {0, 1, 2, 2, 2, 3, 5, 5, 10, 12};
    appearances(arr);
    
    return 0;
}

void appearances(int a[]){
    int i = 0;
    while(i != DIM){
        int counter = 1;
        int j = i + 1;
        while(a[i] == a[j]){
            counter++;
            j++;
        }
        printf("Number %d ocurred %d times\n", a[i], counter);
        i = j;
    }
}
