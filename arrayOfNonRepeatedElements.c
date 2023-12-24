#include <stdio.h>

void array_NonRepeated(int arr[], int size_Arr);
int getNumberOfNonRepeated(int arr[], int size_Arr);
void fill_Array(int arr[], int arrRepeated[], int size_Arr);
void sortArray(int arr[], int size_Arr);
void print_Array(int arr[], int size_Arr);

int main()
{
    int arr[] = {24, 11, 11, 3, 2, 3, 1, 1, 9, 7 ,10, 10, 11, 3, 2, 8};
    int dim_Arr = sizeof(arr)/sizeof(arr[0]);
    array_NonRepeated(arr, dim_Arr);

    return 0;
}

void array_NonRepeated(int arr[], int size_Arr)
{
    int numRepeated = getNumberOfNonRepeated(arr, size_Arr);
    int arrayRepeated[numRepeated];
    fill_Array(arr, arrayRepeated, size_Arr);
    printf("Original array: ");
    print_Array(arr, size_Arr);
    printf("\nOnly non repeated: ");
    print_Array(arrayRepeated, numRepeated);
}

int getNumberOfNonRepeated(int arr[], int size_Arr)
{
    int k = 0;
    int i = 0;
    
    sortArray(arr, size_Arr);
    
    for(i = 0; i < size_Arr - 1; i++)
    {
        if(arr[i] != arr[i+1])
        {
            k++;            
        }
    }
    
    if(arr[i] != arr[i+1]){
        k++;
    }
    
    return k;
}

void fill_Array(int arr[], int arrRepeated[], int size_Arr)
{
    int k = 0;
    int i;
    
    for(i = 0; i < size_Arr - 1; i++)
    {
        if(arr[i] != arr[i+1])
        {
            arrRepeated[k] = arr[i];
            k++;
        }
    }
    
    if(arr[i] != arr[i+1]){
        arrRepeated[k] = arr[i];
    }
}

void sortArray(int arr[], int size_Arr)
{
    for(int i = 0; i < size_Arr - 1; i++)
    {
        for(int j = i + 1; j < size_Arr; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void print_Array(int arr[], int size_Arr)
{
    for(int i = 0; i < size_Arr; i++)
    {
        printf("%d ", arr[i]);
    }
}
