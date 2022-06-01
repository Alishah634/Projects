#include "TicRule.h"

//Checks if someone won the game:
bool TicWinner(char* board, int* winner)
{
    int i = 0;
    //For The X's:
    //If horizontal:
    if((board[i] == 'X') && (board[i+1] == 'X') && (board[i+2] == 'X') ){*winner = 1; return true;}
    if((board[i+3] == 'X') && (board[i+4] == 'X') && (board[i+5] == 'X') ){*winner = 1; return true;}
    if((board[i+6] == 'X') && (board[i+7] == 'X') && (board[i+8] == 'X') ){*winner = 1; return true;}
    //If vertical:
    if((board[i] == 'X') && (board[i+3] == 'X') && (board[i+6] == 'X') ){*winner = 1; return true;}
    if((board[i+1] == 'X') && (board[i+4] == 'X') && (board[i+7] == 'X') ){*winner = 1; return true;}
    if((board[i+2] == 'X') && (board[i+5] == 'X') && (board[i+8] == 'X') ){*winner = 1; return true;}
    //If diagonal:
    if((board[i] == 'X') && (board[i+4] == 'X') && (board[i+8] == 'X') ){*winner = 1; return true;}
    if((board[i+2] == 'X') && (board[i+4] == 'X') && (board[i+6] == 'X') ){*winner = 1; return true;}

    //For The O's:
    //If horizontal:
    if(((board[i] == 'O') && (board[i+1] == 'O') && (board[i+2] == 'O')) ){*winner = 2; return true;}
    if((board[i+3] == 'O') && (board[i+4] == 'O') && (board[i+5] == 'O') ){*winner = 2; return true;}
    if((board[i+6] == 'O') && (board[i+7] == 'O') && (board[i+8] == 'O') ){*winner = 2; return true;}
    //If vertical:
    if((board[i] == 'O') && (board[i+3] == 'O') && (board[i+6] == 'O') ){*winner = 2; return true;}
    if((board[i+1] == 'O') && (board[i+4] == 'O') && (board[i+7] == 'O') ){*winner = 2; return true;}
    if((board[i+2] == 'O') && (board[i+5] == 'O') && (board[i+8] == 'O') ){*winner = 2; return true;}
    //If diagonal:
    if((board[i] == 'O') && (board[i+4] == 'O') && (board[i+8] == 'O') ){*winner = 2; return true;}
    if((board[i+2] == 'O') && (board[i+4] == 'O') && (board[i+6] == 'O') ){*winner = 2; return true;}
    return false;
}

bool TicRule(char* board, int choice,char place)
{
    for(int i = 0; i<9;i++){
        //If the player who already placed a marker, tries placing in the same place:
        if(board[choice-1] == place){
            system("clear"); //Clears the screen so the interface looks clean
            fprintf(stdout,"ERROR!!!\nCannot place here marker already present!!!\n");
            //If placing same where it is:
            if(place == 'X'){board[choice-1] = 'X';//Ensure the marker in that position is correct.
            }
            else{board[choice-1] = 'O';}
            return false;
        }
        //If the other player places a marker there, while there is already a marker there:
        else if(board[choice -1] != place && (board[choice-1] == 'X' || board[choice-1]== 'O') ){
            system("clear"); //Clears the screen so the interface looks clean
            fprintf(stdout,"ERROR!!!\nCannot place here marker already present!!!\n");
            if(board[choice-1] == 'X'){board[choice-1] = 'X';//Ensure the marker in that position is correct.
            }
            else{board[choice-1] = 'O';}
            return false;
        }
    }
    return true;
    /*
    for(int i = 0; i<9;i++){

        if(board[i] != 'X' || board[i] != 'O'){break;}

    }
    */
}
///*
int InvalidEntry(int entry)
{
    //If the data is valid:
    if((0 < entry) && (entry < 10)){
        return 1;
    }
    //The data is invalid:
    else{
        return 0;
    }



}
// */
