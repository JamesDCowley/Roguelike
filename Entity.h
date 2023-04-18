#include <iostream>

using namespace std;

class Entity{
    public :
        //position on grid
        int row;
        int col;

        char ch; //representation on grid
        
        string name;
        int hp; //hit points
        int ac; //armor class

        int str; //strength: determines dmg modifiers and to hit chances for melee atks
        int dex; //dexterity: determines armor class  
        int con; //constitution: determines hit points and poison resistance
        int arc; //arcana: determines spellcasting ability, spell damage mods

        enum entityDir{
            DIR_UP,
            DIR_DOWN,
            DIR_LEFT,
            DIR_RIGHT
        };


        Entity(int r, int c, char ch) : row(r), col(c), ch(ch) {
            hp = 10;
            ac = 10;
            str = 10;
            dex = 10;
            con = 10;
            arc = 10;
        }

        /*
            Moves an entity depending on the specified direction.

            @param dir direction to be moved in.
            @returns void.
        */
        void moveEntity(entityDir dir){
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