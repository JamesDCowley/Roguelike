#include <iostream>

using namespace std;

class Room{
    public:
        static const int NUM_COLS = 12;
        static const int NUM_ROWS = 6;
        bool nDoor;
        bool sDoor;
        bool eDoor;
        bool wDoor;

        bool enterStair;
        bool exitStair;

        int layout[NUM_ROWS][NUM_COLS];

        Room() : nDoor(false), sDoor(false), eDoor(false), wDoor(false), enterStair(false), exitStair(false){
            initLayout();
        }
        Room(bool n, bool s, bool e, bool w, bool es, bool exs) : nDoor(n), sDoor(s), eDoor(e), wDoor(w), enterStair(es), exitStair(exs) {
            initLayout();
        }
        void initLayout(){
            for(int row = 0; row < NUM_ROWS; row++){
                for(int col = 0; col < NUM_COLS; col++){
                    //Top Row
                    if(row == 0){
                        if(nDoor && (col == NUM_COLS / 2 || col == NUM_COLS / 2 - 1)){
                            layout[row][col] = 2; //Door
                        }
                        else layout[row][col] = 1; //Wall
                    }
                    //Bottom Row
                    else if(row == NUM_ROWS-1){
                        if(sDoor && (col == NUM_COLS / 2 || col == NUM_COLS / 2 - 1))
                            layout[row][col] = 2; //Door
                        else layout[row][col] = 1; //Wall
                    }

                    //West Wall
                    else if(col == 0){
                        if(wDoor && (row == NUM_ROWS / 2 || row == NUM_ROWS / 2 - 1))
                            layout[row][col] = 2; //Door
                        else layout[row][col] = 1; //Wall
                    }

                    //East Wall
                    else if(col == NUM_COLS-1){
                        if(eDoor && (row == NUM_ROWS / 2 || row == NUM_ROWS / 2 - 1))
                            layout[row][col] = 2; //Door
                        else layout[row][col] = 1; //Wall
                    }

                    //Staircase
                    else if(exitStair && (row == NUM_ROWS / 2 && col == NUM_COLS / 2)){
                        layout[row][col] = 4;
                    }
                    else if(enterStair && (row == NUM_ROWS / 2 - 1 && col == NUM_COLS / 2 - 1))
                        layout[row][col] = 3;
                    else {
                        layout[row][col] = 0;
                    }
                }
            }
        }
        //Print room (no player, no ememies)
        void printRoom(){
            for(int i = 0; i < NUM_ROWS; i++){
                for(int j = 0; j < NUM_COLS; j++){
                    switch(layout[i][j]){
                        case 0 : 
                            cout << ".";
                            break;
                        case 1 :
                            cout << "#";
                            break;
                        case 2 :
                            cout << "D";
                            break;
                        case 3 :
                            cout << ">";
                            break;
                        case 4 :
                            cout << "^";
                            break;
                    }
                   //cout << layout[i][j] << " ";
                }
                cout << "\n";
            }
        }

        void printRoom(int playerRow, int playerCol){
            for(int i = 0; i < NUM_ROWS; i++){
                for(int j = 0; j < NUM_COLS; j++){
                    if(i == playerRow && j == playerCol){
                        cout << "@";
                    }
                    else{
                        switch(layout[i][j]){
                            case 0 : 
                                cout << ".";
                                break;
                            case 1 :
                                cout << "#";
                                break;
                            case 2 :
                                cout << "D";
                                break;
                            case 3 :
                                cout << ">";
                                break;
                            case 4 :
                                cout << "^";
                                break;
                        }
                    }
                }
                cout << "\n";
            }
        }

        void printRoom(int playerRow, int playerCol, int enemyRow, int enemyCol){
            for(int i = 0; i < NUM_ROWS; i++){
                for(int j = 0; j < NUM_COLS; j++){
                    if(i == playerRow && j == playerCol){
                        cout << "@";
                    }
                    else if(i == enemyRow && j == enemyCol){
                        cout << "E";
                    }
                    else{
                        switch(layout[i][j]){
                            case 0 : 
                                cout << ".";
                                break;
                            case 1 :
                                cout << "#";
                                break;
                            case 2 :
                                cout << "D";
                                break;
                            case 3 :
                                cout << ">";
                                break;
                            case 4 :
                                cout << "^";
                                break;
                        }
                    }
                }
                cout << "\n";
            }
        }
    
            
};