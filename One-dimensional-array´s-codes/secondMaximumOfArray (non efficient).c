#include <stdio.h>

#define DIM_ARRAY 6

float obtainSecondMaximum(float arrayFloats[]);
float obtainFirstMaximum(float arrayFloats[]);

int main()
{
    float array_floats[] = {3, 3, 3, 2, 2, 2};
    printf("Second maximum of the array: %f", obtainSecondMaximum(array_floats));

    return 0;
}

float obtainFirstMaximum(float arrayFloats[])
{
    float firstMaximum = arrayFloats[0];
    
    for(int i = 0; i < DIM_ARRAY; i++)
    {
        if(arrayFloats[i] > firstMaximum)
        {
            firstMaximum = arrayFloats[i];
        }
    }
    
    printf("First maximum: %f\n", firstMaximum);
    return firstMaximum;
}

float obtainSecondMaximum(float arrayFloats[])
{
    float secondMaximum = -99;
    float firstElement = arrayFloats[0];
    int firstMax = obtainFirstMaximum(arrayFloats);
    int i = 0;
    int counter = 0;
    
    for(int i = 0; i < DIM_ARRAY; i++)
    {
        if(firstElement == arrayFloats[i])
            counter++;
            
        if(arrayFloats[i] != firstMax && secondMaximum < arrayFloats[i])
        {
            secondMaximum = arrayFloats[i];
        }
        i++;
    }
    
   if(counter == DIM_ARRAY)
   {
       return firstMax;
   }else{
       return secondMaximum;
   }
}
