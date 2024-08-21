#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

char board[3][3];
bool pcmove = false;
bool win = false;
int size;


void printboard()
{
    printf("\n| %c | %c | %c |",board[0][0], board[0][1],board[0][2]);
    printf("\n-------------\n");
    printf("| %c | %c | %c |",board[1][0], board[1][1],board[1][2]);
    printf("\n-------------\n");
    printf("| %c | %c | %c |\n",board[2][0], board[2][1],board[2][2]);

    space();
    
}

void check_winner()
{
    int i;
    for( i = 0; i < 3 ; i++)
    {
        if (board[0][i] != ' ' && board[0][i] ==  board[1][i] && board[0][i] == board[2][i])
        {
            win = true;
            printf("\n%c Won", board[0][i]);
            return;
        }       
    }

    for(i=0; i<3; i++)
    {
        if (board[i][0] != ' ' && board[i][0] ==  board[i][1] && board[i][0] == board[i][2])
        {
            win = true;
            printf("\n%c Won", board[0][i]);
            return;
        }
        
    }

     if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        win = true;
        printf("\n%c Won\n", board[0][0]);
        return;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        win = true;
        printf("\n%c Won\n", board[0][2]);
        return;
    }
        
}

void playermove()
{
    int a;
    int b;
    check:
    printf("\nEnter Row Number(Horizontal)\n");
    scanf("%d", &a);
    printf("Enter Column Number(Vertical)\n");
    scanf("%d", &b);
    a--;
    b--;
    
    if (board[a][b] == ' ')
    {
        board[a][b] = 'X';
    }
    else
    {
        printf("\nAndha a Kya , Invalid move");
        goto check;
    }

    printboard();
    check_winner();
    pcmove = true;
    
    
}

void pcmover()
{
    int a;
    int b;
    
   while(board[a][b] != ' ')
   {
    a = rand()%3;
    b=rand()%3;
   }

    board[a][b] = 'O';
    printboard();
    check_winner();
    pcmove = false;
    
}


void space()
{
    size =0;
   for(int i = 0;i<3;i++)
    {
        for (int j = 0; j< 3 ; j++)
        {
            if(board[i][j] == ' ')
            {
                size++;
            }
        }
        
    } 
    printf("\nsize %d",size);
}


int main()
{
    srand(time(0));
    win = false;
    for(int i = 0;i<3;i++)
    {
        for (int j = 0; j< 3 ; j++)
        {
            board[i][j] = ' ';
        }
        
    }

    printboard();
    while (!win && size!= 0)
    { 
        
        if(!pcmove)
        {
            playermove();
        }
        else
        {
            pcmover();
        }
        
    }

    if(size == 0 && !win)printf("\nTIE");
    
}