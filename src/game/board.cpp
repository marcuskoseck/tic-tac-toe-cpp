#include <iostream>
#include <unordered_map>

using namespace std;

class Board
{
private:
    int ROWS = 3;
    int COLS = 3;
    char board[3][3] = {
            {'-','-','-'},
            {'-','-','-'},
            {'-','-','-'}
        };
public:
    Board()
    {}

    int get_rows(){
        return ROWS;
    }

    int get_columns(){
        return COLS;
    }
    
    void reset_board()
    {
        for(int i=0;i<ROWS;++i){
            for(int j=0;j<ROWS;++j){
                board[i][j]='-';
            }
        }
    }

    void print_board_from_array(){
        for (int i=0;i<ROWS;++i){
            for (int j=0;j<COLS;++j){
                cout<<'|'<<board[i][j];
            }
            cout<<'|'<<'\n';
        }
    }

    void make_horizontal_line(const char& character,
                            const int& num_char){
        for (int i=0;i<num_char;++i){
            cout<<character;
        }
        cout<<'\n';
    }

    void view_board()
    {
        char dash = '-';
        int dashes = 7;
        
        //make left edge of board
        make_horizontal_line(dash,dashes);
        print_board_from_array();
        make_horizontal_line(dash,dashes);
    }

    void set_piece(int& selected_row,
                int& selected_col,
                char& piece){
        board[selected_row][selected_col]=piece;
    }

    void place(char& piece){
        int selected_row;
        int selected_col;
        cout<< "Select a row: ";
        cin>>selected_row;
        cout<< "Select a column: ";
        cin>>selected_col;
        set_piece(selected_row,
                selected_col,
                piece);
    }

    void play_again(bool& flag){
        string continue_playing="n";
        if (flag){
            cout<<"Would you like to play again? y/n: ";
            cin>>continue_playing;
            if (continue_playing=="y"){
                flag=true;
                reset_board();
            }
            else{
                flag=false;
            }
        }
    }
    void checkwin(const char& piece, bool& flag){
        vertical_win(piece,flag);
        horizontal_win(piece,flag);
        diagonal_win(piece,flag);
    }

    void diagonal_win(const char& piece, bool& flag){
        if (board[0][0] == piece &&
            board[1][1] == piece &&
            board[2][2] == piece){
                play_again(flag);
            }
        else if(board[0][2] == piece &&
            board[1][1] == piece &&
            board[2][0] == piece){
                play_again(flag);
            }   
    }
    void horizontal_win(const char& piece, bool& flag){
        if (board[0][0] == piece &&
            board[0][1] == piece &&
            board[0][2] == piece){
                play_again(flag);
            }
        else if(board[1][0] == piece &&
            board[1][1] == piece &&
            board[1][2] == piece){
                play_again(flag);
            }      
        else if(board[2][0] == piece &&
            board[2][1] == piece &&
            board[2][2] == piece){
                play_again(flag);
            }  
    }

    void vertical_win(const char& piece,bool& flag){
        if (board[0][0] == piece &&
            board[1][0] == piece &&
            board[2][0] == piece){
                play_again(flag);
            }
        else if(board[0][1] == piece &&
            board[1][1] == piece &&
            board[2][1] == piece){
                play_again(flag);
            }      
        else if(board[0][2] == piece &&
            board[1][2] == piece &&
            board[2][2] == piece){
                play_again(flag);
            }  
    }
};