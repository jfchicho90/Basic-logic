 #include <stdio.h>

int haveAWinner(int c1, int c2);
void showPartialResults(int c1, int c2);
int enterOneOrTwo();
void gameTenis();

int main()
{
    
    gameTenis();

    return 0;
}

void gameTenis()
{
    int counterPlayer1 = 0;
    int counterPlayer2 = 0;
    int difference = 0;
    int player = enterOneOrTwo();
    int amountOfPoints;
    
    while(!(difference == 2 && haveAWinner(counterPlayer1, counterPlayer2)))
    {
        if(player == 1)
        {
            printf("How many points has player %d won?:\n", 1);
            counterPlayer1 += enterOneOrTwo();
            player = 2;
        }
        
        if(player == 2){
            printf("How many points has player %d won?:\n", 2);
            counterPlayer2 += enterOneOrTwo();
            player = 1;
        }
        
        difference = counterPlayer1 - counterPlayer2;
        
        if(difference < 0)
        {
            difference = -difference;
        }
        
        showPartialResults(counterPlayer1, counterPlayer2);
    }
    
    if(counterPlayer1 > counterPlayer2)
    {
        printf("%d wins", 1);
    }else{
        printf("%d wins", 2);
    }
}

int enterOneOrTwo()
{
    int n;
    printf("Enter option 1 or 2:\n");
    scanf("%d", &n);
    while(n != 1 && n != 2)
    {
        printf("Error\n");
        fflush(stdin);
        scanf("%d", &n);
    }
    return n;
} 

int haveAWinner(int c1, int c2)
{
    return c1 >= 15 || c2 >= 15;
}

void showPartialResults(int c1, int c2)
{
    printf("C1: %d\nC2: %d\n", c1, c2);
}
