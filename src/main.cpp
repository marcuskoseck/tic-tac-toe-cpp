#include <iostream>

using namespace std;

#include "game/board.cpp"

void obtain_starting_piece(char& piece, char& opp_piece){
    cout<<"Enter the piece you'd like to start with: ";
    cin>>piece;
    cout<<"\nYou entered: "<<piece<<'\n';
    if (piece == 'x' || piece == 'X'){
        opp_piece = 'o';
    } 
    else{
        opp_piece = 'x';
    }
}


main(){
    Board board;
    
    char piece;
    char opp_piece;
    char use_piece;
    bool flag = true;
    

    obtain_starting_piece(piece,opp_piece);
    use_piece = piece;
    while (flag){
        board.view_board();
        board.place(use_piece);
        board.view_board();
        board.checkwin(use_piece,flag);
        if (use_piece==piece){
            use_piece = opp_piece;
        }
        else{
            use_piece = piece;
        }

    }
    cout<<"Thank you for playing!";

}