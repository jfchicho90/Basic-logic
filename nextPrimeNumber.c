#include <stdio.h>

int returnNextPrime(int n);
int isPrime(int n);

int main()
{
    int n;
    
    printf("Enter prime: ");
    
    scanf("%d", &n);
    
    while(!isPrime(n))
    {
        printf("Error ");
        scanf("%d", &n);
        fflush(stdin);
    }
    
    int nextPrime = returnNextPrime(n);
    
    printf("The next prime is: %d", nextPrime);

    return 0;
}

int returnNextPrime(int n)
{
    int i = n + 1;
    while(!isPrime(i))
    {
        i++;
    }
    return i;
}

int isPrime(int n)
{
    int i = 1;
    int counter = 0;
    while(i <= n)
    {
        if(n % i == 0)
        {
            counter++;
        }
        
        i++;
    }
    return counter == 2;
}
