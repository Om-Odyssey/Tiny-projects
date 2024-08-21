#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int bullets;
int blanks;
bool playerturn = true;
int player_life;
int comlife;
int total;


 void loadgame(int level)
{   srand(time(0));
    switch(level)
    {
        case 1:
        bullets = 2;
        blanks = 2;
        break;

        case 2:
        bullets = (rand()%3)+1;
        blanks = 5- bullets;
        break;

        case 3:
        bullets = (rand()%5)+1;
        blanks = 8 - bullets;

    }
    printf("Bullets : %d \n", bullets);
    printf("Blanks : %d \n",blanks);
    total = blanks + bullets;
    printf("Total : %d \n",total);
    
}

void player_turn()
{   int choice;
    printf(" Choose A Option \n 1 : SHOOT YOURSELF \n 2 : SHOOT COMPUTER \n:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        Shootyourself();
        break;

        case 2:
        Shootcom();
        break;

        default:
        printf("Invalid Input , Try Again \n");
        player_turn();
    }
    total--;

}

void comturn()
{
    int com = (rand()%2)+1;
    switch(com)
    {
        case 1 :
        if(blanks != 0)
        {
        printf("\t****** ITS A BLANK ******\t\n");
        printf("\t****** THE GUNS GOES TO THE PLAYER ******\t\n");
        playerturn = true;
        blanks--;
        break;
        }
        printf("\t***** ITS A BULLET ******\n");
        printf("\t***** COMPUTER SHOT YOU*****\n");
        printf("\t****** THE GUNS REMAINS WITH THE COMPUTER ******\t\n");
        player_life --;
        bullets--;
        break;
        

        case 2:
        if(bullets != 0)
        {
            printf("\t***** ITS A BULLET ******\n");
            printf("\t***** COMPUTER SHOT YOU *****\n");
            player_life --;
            bullets--;
            break;
            
        }
        printf("\t****** ITS A BLANK ******\t\n");
        printf("\t****** THE GUNS GOES TO THE PLAYER ******\t\n");
        blanks--;
        playerturn = true;
        break;

        
    }
    printf("Life's Remaining : %d , Computers Life Remaining : %d \n", player_life,comlife);
    total --;
}

void Shootyourself()
{
    int com = (rand()%2)+1;
    switch(com)
    {
        case 1 :
        if(blanks != 0)
        {
        printf("\t****** ITS A BLANK ******\t\n");
        printf("\t****** THE GUNS REMAINS WITH YOU ******\t\n");
        break;
        blanks--;
        }
        printf("\t***** ITS A BULLET ******\n");
        printf("\t***** YOU JUST SHOOT YOURSELF *****\n");
        playerturn = false;
        player_life --;
        bullets--;
        break;
        

        case 2:
        if(bullets != 0)
        {
            printf("\t***** ITS A BULLET ******\n");
            printf("\t***** YOU JUST SHOOT YOURSELF *****\n");
        printf("\t****** THE GUNS GOES TO THE DEALER ******\t\n");
            bullets--;
            player_life --;
            playerturn = false;
            break;
        }
        printf("\t****** ITS A BLANK ******\t\n");
        printf("\t****** THE GUNS REMAINS WITH YOU ******\t\n");
        blanks--;
        break;
    }
    printf("Life's Remaining : %d , Computers Life Remaining : %d \n", player_life,comlife);

}

void Shootcom()
{
     int com = (rand()%2)+1;
    switch(com)
    {
        case 1 :
        if(blanks != 0)
        {
        printf("\t****** ITS A BLANK ******\t\n");
        printf("\t****** THE GUNS GOES TO THE DEALER ******\t\n");
        playerturn = false;
        blanks--;
        break;
        }
        printf("\t***** ITS A BULLET ******\n");
        printf("\t***** YOU JUST SHOOT THE COMPUTER *****\n");
        printf("\t****** THE GUNS REMAINS WITH YOU ******\t\n");
        bullets--;
        
        comlife --;
        break;
        

        case 2:
        if(bullets != 0)
        {
            printf("\t***** ITS A BULLET ******\n");
            printf("\t***** YOU JUST SHOOT THE COMPUTER *****\n");
            printf("\t***** THE GUN REMAINS WITH YOU ******\n");
            comlife --;
            bullets--;
            break;
            
        }
        printf("\t****** ITS A BLANK ******\t\n");
        printf("\t****** THE GUNS GOES TO THE DEALER ******\t\n");
        blanks--;
        playerturn = false;
        break;
    }
    printf("Life's Remaining : %d , Computers Life Remaining : %d \n", player_life,comlife);
}


int main()
{   player_life = 3;
    comlife = 3;
    system("cls");
    
    printf("enter level : ");
    int level;
    scanf("%d",&level);
    loadgame(level);
    
    while(player_life !=0 && comlife !=0)
    {
        if(total == 0)
        {
            printf("\t ********** RELOADING ********** \n");
            loadgame(level);
        }

        if(playerturn)
        {
            player_turn();
        }
        else
        {
            comturn();
        }
    }

    if (player_life == 0)
    {
        /* code */
        printf("\t****** YOU LOST ******\n");
    }
    else
    {
        printf("\t****** YOU WIN ******\n");
    }
    

    return 0;
    
}
