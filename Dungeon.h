#include <iostream>
#include <cstdlib>
#include <vector>
#include "Room.h"

using namespace std;

class Dungeon
{

public:
    int numRows;
    int numCols;
    Dungeon(int lvl) : level(lvl) {
        numRows = numCols = level * 2 + 1;
        rooms.resize(numRows, vector<Room>(numCols, Room()));
        startRow = numRows / 2;
        startCol = numCols / 2;
    }
    void generateDungeon(){
        srand(time(NULL));
        bool nDoor, sDoor, eDoor, wDoor, startStair, exitStair;
        int stairRow = rand() % numRows;
        int stairCol = rand() % numCols;
        cout << stairRow << " " << stairCol << endl;
        for (int row = 0; row < numRows; row++){
            for (int col = 0; col < numCols; col++){
                nDoor = rand() < 0.6 * RAND_MAX;
                sDoor = rand() < 0.6 * RAND_MAX;
                eDoor = rand() < 0.6 * RAND_MAX;
                wDoor = rand() < 0.6 * RAND_MAX;

                //Check for staircases
                exitStair = row == stairRow && col == stairCol;
                startStair = row == startRow && col == startCol;
                
                // Check for edges
                if (row == 0)
                    nDoor = false;
                if (row == numRows - 1)
                    sDoor = false;
                if (col == 0)
                    wDoor = false;
                if (col == numCols - 1)
                    eDoor = false;

                // Check for adjacent rooms vertically
                if (row != 0 && rooms[row - 1][col].sDoor)
                    nDoor = true;
                else if (row != 0)
                    nDoor = false;
                // Check for adjacent rooms horizontally
                if (col != 0 && rooms[row][col - 1].eDoor)
                    wDoor = true;
                else if (col != 0)
                    wDoor = false;
                
                
                rooms[row][col] = Room(nDoor, sDoor, eDoor, wDoor, startStair, exitStair);
            } 
        }
    }
    void print()
    {
        for (int i = 0; i < this->level * 2 + 1; i++)
        {
            for (int j = 0; j < this->level * 2 + 1; j++)
            {
                cout << i << " " << j << endl;
                cout << (rooms[i][j].nDoor ? "# #\n" : "###\n");
                cout << (rooms[i][j].wDoor ? "  " : "# ");
                cout << (rooms[i][j].eDoor ? " \n" : "#\n");
                cout << (rooms[i][j].sDoor ? "# #" : "###\n");
                cout << "\n\n";
            }
        }
    }

    Room getRoom(int row, int col){
        return rooms[row][col];
    }
private:
    int level;
    int startRow;
    int startCol;
    vector<vector<Room>> rooms;
};

