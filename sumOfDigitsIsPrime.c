#include <stdio.h>

int sumOfDigits(int n);
int isPrime(int digit);

int main()
{
    int number;
    for(int i = 1; i <= 100; i++)
    {
        number = sumOfDigits(i);
        
        if(isPrime(number))
        {
            printf("%d\n", i);
        }
    }
    
    return 0;
}

int sumOfDigits(int n)
{
    int counter = 0;
    
    while(n > 0)
    {
        int resto = n % 10;
        counter += resto;
        n /= 10;
    }
    
    return counter;
}

int isPrime(int digit)
{
    int numOfDivisors = 0;
    
    for(int i = 1; i <= digit; i++)
    {
        if(digit % i == 0)
        {
            numOfDivisors++;
        }
    }
    
    return numOfDivisors == 2;
}

