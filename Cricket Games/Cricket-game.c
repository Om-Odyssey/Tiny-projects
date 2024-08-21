#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

bool bf;
int target;
int ball;
int score;
int wickets;

void toss()
{
    srand(time(0));  
    int guess = (rand()%2) +1;
    int user;
    toss:
    printf("\t ***** \t \n" );
    printf("Press 1 for Heads Or Press 2 for Tails : ");
    scanf("%d", &user);
    if (user != 1 && user!=2 )
    {
        printf("Invalid input try again \n");
        goto toss;
    }
    
    if (user == guess)
    {
        printf("You Won The Toss\n PRESS 1 For Batting And 2 For Bowling : ");
        scanf("%d",&user);
        switch (user)
        {
        case 1:
            bf = true;
            batting();
            break;
        
        case 2:
            bf = false;
            bowling();
            break;
        }
    }
    else
    {
        printf("You lost The Toss \n");
        printf("\t ***** \t \n");
        switch (guess)
        {
            case 1:
             printf("Computer choose to Bat \n");
             printf("\t ***** \t \n");
             bf=false;
             bowling();
             break;

            case 2:
             printf("Computer choose to Bowl");
             printf("\t ***** \t \n");
             bf=true;
             batting();
             break;
        }
    }
    
}

void bowling()
{
    wickets = 0;
    printf("\t****** YOU'RE BOWLING NOW ******\t \n");
     printf("Chosse a number between 1 to 6 : \n 1: Inswing Yorker \n 2: Outswing Yorker \n 3: Inswing good lenght \n 4 : Outswing good length \n 5 : Slower \n 6 : Bouncer \n");
    ball=6;
    do
    {
        
    int user;
    int guess = (rand()%6)+1;
    printf("input your choice of ball : ");
    scanf("%d",&user);
    if (user > 6)
    {
        user= 20;
    }
    
    int shot= abs(user-guess);
    printf("\t ***** \t \n");
    switch(shot)
    {
        case 0:
        printf("Bad delivery Goes For A Maximum \n");
        score = score +6;
        ball--;
        break;

        case 1:
        printf("Goes For a Four \n");
        score = score+4;
        ball--;
        break;

        case 2:
        printf("normal delivery Pusher For a Double \n");
        score = score+2;
        ball--;
        break;

        case 3:
        printf("Brilliant Delivery , Clean Bowled \n");
        ball--;
        wickets++;
        break;

        case 4:
        printf("A Decent delivery pushed for a single \n");
        score++;
        ball--;
        break;

        case 5:
        printf("A GOOD delivery , Forced the Batsman to defend \n");
        ball--;
        break;

        default:
        printf("invalid Input Try Again \n");
        break;
    }


    printf("\t ***** \t \nCURRENT Score : %d , Balls Remaining : %d , Wickets : %d \n \t ***** \t \n", score,ball,wickets);
    }while (ball != 0 && wickets< 2);

    

    if(!bf)
    {
        printf("\t****** END OF THE INNINGS ******\t \n");
        batting();
    }
    
}

void batting()
{
    wickets = 0;
    printf("\t****** YOU'RE BATTING NOW ******\t \n");
    ball =6;
    printf("Tutorial \n Try to guess the number same as the computer \n IF THE DIFF BETWEEN YOUR NUMBER AND COMPUTER NUMBER IS 3YOU ARE OUT \n You have only 2 wickets \n");

    do{
         int user;
    int guess = (rand()%6)+1;
    printf("input your choice from 1 to 6: ");
    scanf("%d",&user);
    if (user > 6)
    {
        user= 20;
    }
    
    int shot= abs(user-guess);
    printf("\t ***** \t \n");

    switch(shot)
        {
            case 0 :
                printf("perfect shot 6 runs \n");
                target = target+6;
                ball--;
                break; 

            case 1:
                printf("Four \n");
                target = target +4;
                ball--;
                break;

            case 2:
                printf("Double \n");
                target = target +2;
                ball--;
                break;

            case 4:
                printf("Single \n");
                target = target +1;
                ball--;
                break;

            case 5:
                printf("Dot \n");
                target = target;
                ball--;
                break;

            case 3:
                printf("Wicket \n");
                target = target;
                ball--;
                wickets++;
                break;
            
            default:
            printf("invalid Input Try Again \n");
            break;
        }

        printf("\t ***** \t \nCURRENT Score : %d , Balls Remaining : %d , Wickets : %d\n \t ***** \t \n", target,ball,wickets);
    }while(ball != 0 && wickets !=2  );

    if(bf)
    {
        printf("\t****** END OF THE INNINGS ******\t \n");
        bowling();
    }

}

void result()
{
      if(target<score)
    {
        printf("\t****** END OF THE INNINGS ******\t \n");
        printf("\t****** YOU LOST BY %d RUNS ******\t \n", score-target);
    }

else{
    printf("\t****** END OF THE INNINGS ******\t \n");
    printf("\t****** YOU wON BY %d RUNS ******\t \n",target-score);
}

}

int main()
{
    system("cls");
    toss();
    result();

    return 0;
}

