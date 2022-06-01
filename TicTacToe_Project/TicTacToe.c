#include "MoveMade.h"
#include "Display.h"
#include "TicRule.h"

/*Command for the executable:
gcc -std=c99 -Wall -Wshadow -Wvla -pedantic -g *.c -o all
gdb all.exe
 //When in gdb use this command to run the program like this:
 r game.txt

*/

/* DEVELOPMENT PLAN:
    1. First ask if playing?
    2. Display starting board.
    3. Then have first move made(denote move with "X", else with "O"),
        Display the move made ask for the other players move
    4. Then second and so on(max number of moves made is: 9)
    5. Display Winner
*/

int main(int argc, char* argv[])
{
    int is_playing = DisplayInterface(); //Display interface

    if(is_playing == 1){//If playing
        //Open file to write the game to it:
        FILE* fptr = fopen(argv[1],"w");
        //Error Statement for opening and writing ot the file:
        if(!fptr){//If NULL
            fprintf(stderr,"Error opening the file to write to!\n");
            //fclose(fptr); //Do I need this line???
            return EXIT_FAILURE;
        }

        //Game display:
        fprintf(fptr,"Starting Position:\n\n");
        char* board = malloc(9*sizeof(char*));
        for(int i = 0; i<9;i++){
            board[0] = '1';
            board[1] = '2';
            board[2] = '3';
            board[3] = '4';
            board[4] = '5';
            board[5] = '6';
            board[6] = '7';
            board[7] = '8';
            board[8] = '9';
        }
        DisplayGame(board,fptr);

        int player = 1;
        int move_num = 0;
        int winner = -1;

        while(!TicWinner(board,&winner) && (move_num < 9) ){
            move_num++; //Update the move number
            MoveMade(board,&player,&move_num,fptr);
            //fprintf(stderr,"The move number is currently: %d\n",move_num);
            DisplayGame(board,fptr);
        }

        //Display who the Winner is or if the game is a draw:
        if(!TicWinner(board,&winner)){fprintf(fptr,"\nGame is a Draw!"); fprintf(stdout,"\nGame is a Draw!");}
        else{fprintf(fptr,"\nThe Winner is: Player %d\n\n",winner); fprintf(stdout,"\nThe Winner is: Player %d\n\n",winner);}
        fclose(fptr); //Close the file

        fprintf(stderr,"\nYour game has concluded and been, recorded in a .txt file for you to review!\n\nENJOY! & Thank You for playing!\n");
        return EXIT_SUCCESS;
    }

    else if(is_playing == 0){return EXIT_SUCCESS;} //If not playing
    else if(is_playing == -1){fprintf(stderr,"Invalid Data Entered!!!\n");return EXIT_FAILURE;} //If invalid data entered
}