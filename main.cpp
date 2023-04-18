#include <iostream>
#include <cstdlib>
#include "Dungeon.h"
#include "Player.h"
#include "Enemy.h"
#include "Entity.h"

using namespace std;

void combat(Entity &player, Entity &enemy){
	cout << "\n\n##############################" << endl;
	cout << "ENEMY ENCOUNTERD!" << endl;
	while(enemy.hp > 0 && player.hp > 0){
		cout << "\nYour HP: " << player.hp << endl;
		cout << "Enemy HP: " << enemy.hp << endl;

		cout << "\nWhat will you do?" << endl;
		cout << "1. Attack" << endl;
		cout << "2. Cast Spell" << endl;
		cout << "3. Defend" << endl;
		cout << "4. Item" << endl;

		int input;
		cin >> input;

		switch(input){
			case 1 :
				cout << "\nPlayer attacks!" << endl;
				enemy.hp -= rand() % 10 + 1;
				break;
			case 2 :
				break;
			case 3 :
				break;
			case 4 :
				break;
		}

		cout << "\nEnemy attacks!" << endl;
		player.hp -= rand() % 5 - 1;
	}
}

void mainMenu() {}

void playerInit() {}

int main(){
	srand(time(NULL));
	Dungeon dungeon(5);
	dungeon.generateDungeon();

	int curRow = dungeon.numRows / 2, curCol =  dungeon.numCols / 2;
	Room curRoom = dungeon.getRoom(curRow, curCol);
	
	Entity player(curRow, curCol, '@');

	int playerTile = -1;
	
	bool enemyInRoom = false;
	
	//20% chance of enemy in the room
	enemyInRoom = rand() < 0.2 * RAND_MAX;

	Entity enemy(rand() % curRoom.NUM_ROWS-1, rand() % curRoom.NUM_COLS-1, 1);

	
	while(playerTile != 4){
		char input;
		playerTile = curRoom.layout[player.row][player.col];
		curRoom = dungeon.getRoom(curRow, curCol);
		
		//Check if on door
		if(playerTile == 2){
			if(player.row == curRoom.NUM_ROWS-1){
				curRow++;
				player.row = 1;
			}
			else if(player.row == 0){
				curRow--;
				player.row = curRoom.NUM_ROWS - 1;
			}
			else if(player.col == 0){
				curCol--;
				player.col = curRoom.NUM_COLS - 1;
			}
			else if(player.col == curRoom.NUM_COLS - 1){
				curCol++;
				player.col = 1;
			}
			enemyInRoom = rand() < 0.2 * RAND_MAX;
			if(enemyInRoom){
				enemy.row = rand() % curRoom.NUM_ROWS-1;
				enemy.col = rand() % curRoom.NUM_COLS-1;
				enemy.hp = rand() % 10 + 1;
			}
		}

		//Check if enemy collision
		if(enemyInRoom && (player.row == enemy.row && player.col == enemy.col)){
			combat(player, enemy);
			if(player.hp <= 0){
				cout << "\nplayer dies!" << endl;
				break;
			}
			cout << "\nenemy dies!" << endl; 
			enemyInRoom = false;
		}

		cout << "Current Room: " << curRow << " " << curCol << endl;
		cout << "HP: " << player.hp << endl;
		if(enemyInRoom)
			curRoom.printRoom(player.row, player.col, enemy.row, enemy.col);
		else
			curRoom.printRoom(player.row, player.col);
		cout << "\nEnter W, A, S, D for movement: ";
		cin >> input;



		//Player movement + check for collision
		switch(input){
			case 'W' :
				if(dungeon.getRoom(curRow, curCol).layout[player.row-1][player.col] == 1)
					cout << "Wall Collision" << endl;
				else player.moveEntity(player.DIR_UP);
				break;
			case 'A' :
				if(dungeon.getRoom(curRow, curCol).layout[player.row][player.col-1] == 1)
					cout << "Wall Collision" << endl;
				else player.moveEntity(player.DIR_LEFT);
				break;
			case 'S' :
				if(dungeon.getRoom(curRow, curCol).layout[player.row+1][player.col] == 1)
					cout << "Wall Collision" << endl;
				else player.moveEntity(player.DIR_DOWN);
				break;
			case 'D' :
				if(dungeon.getRoom(curRow, curCol).layout[player.row][player.col+1] == 1)
					cout << "Wall Collision" << endl;
				else player.moveEntity(player.DIR_RIGHT);
				break;
		}
		
		//Enemy movement
		if(enemyInRoom && (abs(player.row - enemy.row) <= 2 && abs(player.col - enemy.col) <= 2)){
			if(enemy.row < player.row){
				enemy.moveEntity(enemy.DIR_DOWN);
			}
			else if(enemy.row > player.row){
				enemy.moveEntity(enemy.DIR_UP);
			}
			if(enemy.col < player.col){
				enemy.moveEntity(enemy.DIR_RIGHT);
			}
			else if(enemy.col > player.col){
				enemy.moveEntity(enemy.DIR_LEFT);
			}
		}

		//Check if on down staircase
		if(playerTile == 3){
			char in;
			cout << "\nRegenerate dungeon? (y/n)" << endl;
			cin >> in;
			if(in == 'y') dungeon.generateDungeon();
		}

		

	}

	cout << "\nYOU WIN!!";
	return 0;
}

