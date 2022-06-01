#include "Display.h"

/*Command for the executable for this file(ONLY THIS FILE):
gcc -std=c99 -Wall -Wshadow -Wvla -pedantic -g display.c -o display
gdb display.exe

*/

int DisplayInterface()
{
    system("clear"); //Clears the screen so the interface looks clean
    fprintf(stdout,"======================================================================================================================================================\n");
    fprintf(stdout,"Hello There!\nMy Name is Envoy\nWould you like to play a game of Tic Tac Toe?\n");
    fprintf(stdout,"Enter Y for yes, and N for no?\n");

    char is_playing;
    fprintf(stdout,"Your Choice?:"); //Ask the user for their choice
    scanf("%c",&is_playing); //Statement to enter the choice
    fprintf(stdout,"\n");//Move to next line after choice is made

    //If playing:
    if(is_playing == 'Y' || is_playing == 'y'){
        fprintf(stdout,"How to play using this interface:\n");
        fprintf(stdout,"Player 1 can places an 'X' as their marker and Player 2 can place an 'O' as their marker:\n");
        return 1; //If true
    }
    //If not playing:
    else if(is_playing == 'N' || is_playing == 'n'){
        fprintf(stdout,"\nOkay! Maybe later then..\n");
        fprintf(stdout,"GoodBye\n");
        return 0; //if false
    }
    //If invalid choice added:
    fprintf(stdout,"Error!!!\nSorry you entered an invalid choice please re-run the program to try again!\n\n");
    fprintf(stdout,"The following is the correct compilation command\n");
    fprintf(stdout,"\ngcc -std=c99 -Wall -Wshadow -Wvla -pedantic -g *.c -o all\n\n");
    return -1; //If invalid
}

void DisplayGame(char* board,FILE* fptr)
{
    fprintf(fptr,"%c|%c|%c\n",board[0],board[1],board[2]);
    fprintf(fptr,"-|-|- \n");
    fprintf(fptr,"%c|%c|%c\n",board[3],board[4],board[5]);
    fprintf(fptr,"-|-|-\n");
    fprintf(fptr,"%c|%c|%c\n",board[6],board[7],board[8]);

    fprintf(stdout,"%c|%c|%c\n",board[0],board[1],board[2]);
    fprintf(stdout,"-|-|- \n");
    fprintf(stdout,"%c|%c|%c\n",board[3],board[4],board[5]);
    fprintf(stdout,"-|-|-\n");
    fprintf(stdout,"%c|%c|%c\n",board[6],board[7],board[8]);

    /*
    fprintf(stdout,"1|2|3\n");
    fprintf(stdout,"-|-|- \n");
    fprintf(stdout,"4|5|6\n");
    fprintf(stdout,"-|-|-\n");
    fprintf(stdout,"7|8|9\n");
    //fprintf(stdout,"_| |_\n");
    */
}

/* This main only test the individual functions in the file
int main()
{
    DisplayInterface();
    return EXIT_SUCCESS;
}
*/