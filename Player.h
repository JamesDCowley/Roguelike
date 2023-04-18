#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
class Player{
    public :
        int row;
        int col;
        int hp; //hit points
        int ac; //armor class

        int str; //strength: determines dmg modifiers and to hit chances for melee atks
        int dex; //dexterity: determines armor class  
        int con; //constitution: determines hit points and poison resistance
        int arc; //arcana: determines spellcasting ability, spell damage mods

        enum playerDir{
            DIR_UP,
            DIR_DOWN,
            DIR_LEFT,
            DIR_RIGHT
        };

        Player(int r, int c, int h) : row(r), col(c), hp(h){}

        void movePlayer(playerDir dir){
            switch(dir){
                case DIR_UP :
                    row--;
                    break;
                case DIR_DOWN :
                    row++;
                    break;
                case DIR_LEFT :
                    col--;
                    break;
                case DIR_RIGHT :
                    col++;
                    break;
            }
        }

    
};