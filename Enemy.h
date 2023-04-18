#include <iostream>

using namespace std;

class Enemy{
    public:
        int row;
        int col;
        static const int ENEMY_RANGE = 2;

        int hp;
        string name;
        enum enemyDir{
            DIR_UP,
            DIR_DOWN,
            DIR_LEFT,
            DIR_RIGHT
        };

        Enemy(int r, int c, int h) : row(r), col(c), hp(h), name("Enemy"){}
        Enemy(int r, int c, int h, string n) : row(r), col(c), hp(h), name(n) {}
        
        void moveEnemy(enemyDir dir){
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