#include <stdio.h>

#define DIM 5

void concatenateInArray(int arr1[], int arr2[], int arrConcat[]);
void print_Array(int a[], int dimArr);

int main()
{
    int arr1[] = {11, 6, 1, 3, 10};
    int arr2[] = {3, 5, 5, 13, 9};
    int arrConcat[2*DIM];
    
    concatenateInArray(arr1, arr2, arrConcat);
    
    print_Array(arrConcat, 2*DIM);

    return 0;
}

void concatenateInArray(int arr1[], int arr2[], int arrConcat[])
{
    int doubleDim = 2*DIM;
    
    for(int i = 0; i < 2*DIM; i++)
    {
        if(i < doubleDim/2)
        {
            arrConcat[i] = arr1[i];
        }else{
            arrConcat[i] = arr2[i - DIM];
        }
    }
}

void print_Array(int a[], int dimArr)
{
    for(int i = 0; i < dimArr; i++)
    {
        printf("%d ", a[i]);
    }
}
