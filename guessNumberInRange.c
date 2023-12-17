#include <stdio.h>

#define winner 156
#define limInferior 0
#define limSuperior 200

int guessNumber(char* msj);
int numberInRange(int num);

int main()
{
    int takeAGuess;
    char* msj1 = "Enter number: ";
    int counter = 0;
    
    do
    {
        counter++;
        takeAGuess = guessNumber(msj1);
        
        if(takeAGuess > winner)
        {
            printf("Too  high.  Please  try  again ");
        }else{
            printf("Too  low. Please  try  again ");
        }
        printf("\n");
    }while(takeAGuess != winner);
    
    printf("Congratulations! You Won int %d attempts!", counter);
    
    return 0;
}

int guessNumber(char* msj)
{
    printf("%s\n", msj);
    int num;
    scanf("%d", &num);
    while(!(numberInRange(num)))
    {
        fflush(stdin);
        printf("Error. Enter number in range: ");
        scanf("%d", &num);
    }
    return num;
}

int numberInRange(int num)
{
   return num > limInferior && num < limSuperior;
}
