#include <stdio.h>

int isPalindrome(int number);

int main()
{
    if(isPalindrome(512215))
    {
        printf("Palindrome");
    }else{
        printf("Not palindrome");
    }
     
    return 0;
}

int isPalindrome(int number)
{
    int counter = 100000;
    int firstDigit;
    int auxFirstDigit = number;
    int auxLastDigit = number;
    int lastDigit;
    int isPalindrome = 1;
    
    while(auxFirstDigit > 0 && auxLastDigit > 0){
        
        lastDigit = auxLastDigit % 10;
        
        firstDigit = auxFirstDigit / counter;
        auxFirstDigit = auxFirstDigit % counter;
  
        auxLastDigit /= 10;
  
        if(firstDigit != lastDigit)
        {
           isPalindrome = 0;
        }
        counter /= 10;
        
    }
    
    return isPalindrome;
}
