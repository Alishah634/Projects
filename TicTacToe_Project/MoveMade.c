#include "MoveMade.h"
#include "TicRule.h"

//Update and placement and whether X or O:
void MoveMade(char* board, int* player, int* move_num, FILE* fptr)
{
    int pos;
    char marker;
    int temp = *player;//Stores it is the original players turn, in case an incorrect position is chosen
    fprintf(stdout,"\nWhere would you like to play?\n");
    fprintf(stdout,"Choose a number to marker your marker there('X' or 'O')\n");

    //Player one can play an "X"
    if(*player == 1){
        //Ask for where the player wants to marker his marker:
        //fprintf(stdout,"Where do you want to marker your marker?:"); //Ask the user for their where
        scanf("%d",&pos); //Statement to enter the where
        if(InvalidEntry(pos) == 1){
            fprintf(fptr,"\n%d. New Position:\n",*move_num);//Indicates the next position
            fprintf(stdout,"\n");//Move to next line after where is made
            marker = 'X';
            *player = 2;//Change to player 2
        }
        else{
            fprintf(stdout,"You entered INVALID DATA!\n");
            fprintf(stdout,"You did not enter a number!\n");
            fprintf(stdout,"Try again!\n\n");
            scanf("%d",&pos); //Statement to enter the where
        }
    }
    //Player two can play an "O"
    else if(*player == 2){
        //Ask for where the player wants to marker his marker:
        //fprintf(stdout,"Where do you want to marker your marker?:"); //Ask the user for their where
        scanf("%d",&pos); //Statement to enter the where
        if(InvalidEntry(pos) == 1){
            fprintf(fptr,"\n%d. New Position:\n",*move_num);//Move to next line after where is made
            fprintf(stdout,"\n");//Move to next line after where is made
            marker = 'O';
            *player = 1;//Change to player 1
        }
        else{
            fprintf(stdout,"You entered INVALID DATA!\n");
            fprintf(stdout,"You did not enter a number!\n");
            fprintf(stdout,"Try again!\n\n");
            scanf("%d",&pos); //Statement to enter the where
        }
    }

    //Check if the move has already occurred:
    if(!TicRule(board, pos, marker)){
        (*move_num)--;
        *player = temp;
        fprintf(fptr,"ERROR!!!\nCannot place here marker already present!!!\n");

        //fprintf(stderr,"This is run and the move is: %d\n",*move_num);
    }
    else{
        board[pos-1] = marker;
        system("clear"); //Clears the screen so the interface looks clean
    }
    //return board;
}