#include <stdio.h>

#define DIM 12

void sort_ascendingOrder(float floats_array[]);
float linearSearch(float floats_array[]);

int main()
{
     
    float floats_array[] = {100, 9, 1, 5, 8, 2, 68, 1, 67, 6, 1, 10};
    sort_ascendingOrder(floats_array);
    float second_maximum = linearSearch(floats_array);
    printf("The second maximum of the array is: %f", second_maximum);
    return 0;
}

void sort_ascendingOrder(float floats_array[])
{
    for(int i = 0; i < DIM - 1; i++)
    {
        for(int j = i + 1; j < DIM ; j++)
        {
            if(floats_array[i] > floats_array[j])
            {
                float temporal = floats_array[i];
                floats_array[i] = floats_array[j];
                floats_array[j] = temporal;
            }
        }
    }
}

float linearSearch(float floats_array[])
{
    float second_maximum;
    int i = DIM - 1 ;
    while(floats_array[i] == floats_array[i - 1])
    {
        i--;
    }
    second_maximum = floats_array[i-1];
    return second_maximum;
}
