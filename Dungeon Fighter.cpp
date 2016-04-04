#include "stdafx.h"
#include "Dungeon.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>




//dungeon maximum X value
static const short int D_X = 40;

//dungeon maximum Y value
static const short int D_Y = 15;

//dungeon courrent maximum X value
short int C_X = D_X ;

//dungeon courrent maximum Y value
short int C_Y = D_Y ;

//If not in a battle
bool ExploreMode = true;

//if in a battle
bool BattleMode = false;

void SetColor(unsigned short int color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, color);
}


//Class of the Player
class PlayerClass
{ 
public:
	//name of the player
	std::string Name = "Player";
	
	//Position X of player
	short int X;

	//Position Y of player
	short int Y;

	//Last position X of player
	short int LastX;

	//Last position Y of player
	short int LastY;	

	//if player is Alive
	bool Alive = true;

	//level of player
	short int LVL = 1;	

	//Check if player already spawned
	bool Spawned = false;

	//Experience needed to level up when experience = 0
	short int ExpToLvlUP = 100;

	//Experience
	short int Experience = 0;

	//Damage
	double Damage;

	//Defense: Damage - Defense = Damage done 
	double Defense = 0.5;

	//maximum Health poshort ints amount
	double HPMax = 100;

	//Health poshort ints left
	double HP = HPMax;

	//maximum Food amount
	double FoodMax = 30;

	//Food left
	double Food = FoodMax;

	//maximum Mana amount
	double ManaMax = 20;

	//Mana left
	double Mana = ManaMax;

private:
	short int Attack(short int LVL, short int Damage, double HP)
	{

	}


}; PlayerClass Player;


class DungeonClass{ 

public:
	//Basically level of the dungeon
	short int Stage = 1;


	//Map of the entities: Player, Enemies, Neutral
	//1st in order to get prshort inted
	//0:	Nothing
	//1:	Player
	//2:	Enemy
	char EntityMap[ D_Y ][ D_X ];

	//Map of the dungeon structure: wall, path, spawnposhort int, Gate
	//2nd in order to get prshort inted
	//100:	Wall
	//0:	Nothing
	//1:	Path
	//2:	Spawn
	//3:	Gate
	char Map[ D_Y ][ D_X ];

	//Map of item on the ground: Key, Equipment, Food
	char ItemLayer1[ D_Y ][ D_X ];

	//Map of item on the ground: Equipment, Food	
	char ItemLayer2[D_Y][D_X];


	struct MapMemory {

		//the following arrays stores Dungeon map that will maybe be used as Map[][]
	
		struct Stage1
		{
			//Maximum ammount of enemy: Zombie
			short int MaxEnemyZombie = 1;

			//How many Zombie on this Stage
			short int EnemyZombieAmount;

			//Maximum ammount of enemy: Slime
			short int MaxEnemySlime = 3;

			//How many Slime on this Stage
			short int EnemySlimeAmount;

			struct Map1
			{
				//Map maximum X value
				static const short int M_X = 10;
				//Map maximum Y value
				static const short int M_Y = 10;

				//Stage 1 dungeon map 1
				char Map[10][10] = {
				{ 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 },//1st line
				{ 100,   2,   1, 100,   1,   1,   1,   1,   1, 100 },//2nd line
				{ 100,   1,   1, 100,   1, 100, 100, 100,   1, 100 },//3rd line
				{ 100, 100,   1,   1,   1, 100, 100, 100,   1, 100 },//4th line
				{ 100, 100, 100,   1, 100,   1, 100,   1,   1, 100 },//5th line
				{ 100,   3, 100,   1,   1,   1, 100,   1,   1, 100 },//6th line
				{ 100,   1,   1, 100, 100, 100, 100,   1, 100, 100 },//7th line
				{ 100, 100,   1, 100, 100,   1,   1,   1,   1, 100 },//8th line
				{ 100, 100,   1,   1,   1,   1, 100, 100, 100, 100 },//9th line
				{ 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 }//10th line
				};

			}; Map1 m1;

			struct Map2
			{
				//Map maximum X value
				static const short int M_X = 10;
				//Map maximum Y value
				static const short int M_Y = 10;

				//Stage 1 dungeon map 2
				char Map[10][10] = {
					{   1,   1,   1,   1, 100,   1,   1,   1,   1,   1 },//1st line
					{   3,   1,   1,   1, 100,   1,   1,   1,   1,   1 },//2nd line
					{   1,   1, 100,   1,   1,   1, 100, 100,   1,   1 },//3rd line
					{   1,   1, 100,   1,   1,   1, 100,   1,   1,   1 },//4th line
					{ 100, 100, 100, 100, 100, 100, 100,   1,   1,   1 },//5th line
					{ 100,   1,   1,   1,   1,   1,   1,   1,   1,   1 },//6th line
					{ 100, 100, 100, 100, 100, 100, 100,   1,   1,   1 },//7th line
					{   1,   1,   1, 100,   1,   1,   1,   1,   1,   1 },//8th line
					{   2,   1,   1,   1,   1,   1,   1,   1,   1, 100 },//9th line
					{   1,   1,   1, 100,   1,   1,   1,   1, 100, 100 }//10th line
				};



			}; Map2 m2;

		}; Stage1 s1;

		struct Stage2
		{
			//Maximum ammount of enemy: Zombie
			short int MaxEnemyZombie = 1;

			//How many Zombie on this Stage
			short int EnemyZombieAmount;

			//Maximum ammount of enemy: Slime
			short int MaxEnemySlime = 3;

			//How many Slime on this Stage
			short int EnemySlimeAmount;

			struct Map1
			{
				//Map maximum X value
				static const short int M_X = 15;
				//Map maximum Y value
				static const short int M_Y = 10;

				//Stage 2 dungeon map 1
				
				char Map[10][15] = {
				{ 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 },//1st line
				{ 100,   1,   1, 100, 100, 100, 100, 100, 100, 100, 100,   1,   1, 100, 100 },//2nd line
				{ 100,   1,   1,   1, 100, 100, 100, 100, 100, 100,   1,   1,   1, 100, 100 },//3rd line
				{ 100, 100, 100,   1,   1, 100, 100, 100, 100,   1,   1,   1,   1,   1, 100 },//4th line
				{ 100, 100, 100,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1, 100 },//5th line
				{ 100, 100, 100,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   3 },//6th line
				{ 100, 100, 100,   1,   1, 100, 100, 100, 100,   1,   1,   1,   1,   1, 100 },//7th line
				{ 100,   1,   1,   1, 100, 100, 100, 100, 100, 100,   1,   1,   1, 100, 100 },//8th line
				{ 100,   2,   1, 100, 100, 100, 100, 100, 100, 100, 100,   1,   1, 100, 100 },//9th line
				{ 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 }//10th line
				};


			}; Map1 m1;


		}; Stage2 s2;
			

	}; MapMemory MMem;


	void SetMap()
	{
		short int Set_Map;
		srand(time(NULL));
		
			
		if(Stage == 1)
		{
			Set_Map = 1 + rand() % 2;

			switch (Set_Map)
			{

			case 1:
			{
				C_X = MMem.s1.m1.M_X;
				C_Y = MMem.s1.m1.M_Y;
				for (short int i = 0; i < C_Y ; i++)
				{
					for (short int j = 0; j < C_X; j++)
					{
						Map[i][j] = MMem.s1.m1.Map[i][j];
					}
				}
				break;
			}
			case 2:
			{
				C_X = MMem.s1.m2.M_X;
				C_Y = MMem.s1.m2.M_Y;
				for (short int i = 0; i < C_Y; i++)
				{
					for (short int j = 0; j < C_X; j++)
					{
						Map[i][j] = MMem.s1.m2.Map[i][j];
					}
				}

				break;
			}
			default:
			{
				break;
			}
			}

		}
		else if( Stage == 2 )
		{
		}
		

    }

	void SetValues()
	{
		if (Stage == 1)
		{
			MMem.s1.EnemySlimeAmount =    rand() % MMem.s1.MaxEnemySlime ;
			MMem.s1.EnemyZombieAmount =   rand() % MMem.s1.MaxEnemyZombie ;
		}
		if (Stage == 2)
		{
			MMem.s2.EnemySlimeAmount =    rand() % MMem.s2.MaxEnemySlime  ;
			MMem.s2.EnemyZombieAmount =   rand() % MMem.s2.MaxEnemyZombie ;
		}
		
	}

	//prshort ints the Dungeon.Map to the screen
	void PrintMap()
	{
		static const char NothingCh = 46;
		static const char WallCh    = 176;
		static const char PathCh    = 32;	
		static const char GateCh    = 207;
		static const char SpawnCh   = 42;

		static const char PlayerCh  = 2;
		static const char SlimeCh	 = 111;
		static const char ZombieCh  = 1;

		static const char KeyCh     = 21;

		
		std::cout << (char)201;//for the frame

		for (short int x = 0; x < C_X; x++)//for the frame
		{
			std::cout << (char)205; }

		std::cout << (char)187 << '\n' ;//for the frame

		std::cout << (char)186 ;//for the frame

		std::cout << "Stage: " << Stage;

		if (Stage < 10) 
		{
			for (short int x = 0; x < C_X - 8; x++)//for the frame
			{
				std::cout << ' ';//for the frame
			}
			std::cout << (char)186 << '\n' ;
		}
		if (Stage >= 10)
		{
			for (short int x = 0; x < C_X - 9; x++)//for the frame
			{
				std::cout << ' ';
			}
			std::cout << (char)186 << '\n' ;//for the frame
		}

		
		
		std::cout << (char)204 ;//for the frame

		for (short int x = 0; x < C_X ; x++)//for the frame
		{
			std::cout << (char)205; }//for the frame
		std::cout << (char)185;//for the frame
		std::cout << "Lvl: " << Player.LVL << '\n';
		//for every Row
		for (short int y = C_Y; y > 0; y--)
		{
			std::cout << (char)186;//for the frame

			//For every Column
			for (short int x = 0; x < C_X; x++ )
			{ 

				//check for player 
				if ( EntityMap[y - 1][ x ] == 1 )
				{
					//Entity Player
					SetColor(3);
					std::cout << PlayerCh;
					SetColor(7);
				}
				//check for Slime
				else if (EntityMap[y - 1][x] == 2)
				{
					//Entity Slime
					SetColor(10);
					std::cout << SlimeCh;
					SetColor(7);
				}
				//check for Zombie
				else if (EntityMap[y - 1][x] == 3)
				{
					//Entity Zombie
					SetColor(2);
					std::cout << ZombieCh;
					SetColor(7);
				}
				else if ( Map[ y - 1 ][ x ] == 100 )
				{
					//Wall
					std::cout << WallCh;
				}
				else if ( Map[ y - 1 ][ x ] == 3 )
				{
					//DungeonGate
					std::cout << GateCh;
				}
				else if ( Map[ y - 1 ][ x ] == 2 )
				{
					//SpawnPoshort int
					std::cout << SpawnCh;
				}
				else if ( Map[ y - 1 ][ x ] == 1 )
				{
					//Path
					std::cout << PathCh;
				}
				else
				{
					//default
					std::cout << NothingCh;
				}

			}
			std::cout << (char)186 ;//for the frame
			if (y == C_Y) { SetColor(12); std::cout << "HP: " << Player.HP << '/' << Player.HPMax; SetColor(7); }
			else if(y == C_Y -1){ SetColor(6); std::cout << "Food: " << Player.Food << '/' << Player.FoodMax; SetColor(7); }
			else if (y == C_Y - 2) { SetColor(3); std::cout << "Mana: " << Player.Mana << '/' << Player.ManaMax; SetColor(7); }
			else if (y == C_Y - 3) { SetColor(10); std::cout << "exp: " << Player.Experience << '/' << Player.ExpToLvlUP; SetColor(7); }
			std::cout << '\n';
 
		}

		std::cout << (char)200;//for the frame
		for (short int x = 0; x < C_X; x++)//for the frame
		{
			std::cout << (char)205;

		}
		std::cout << (char)188 << '\n';//for the frame


	}

};DungeonClass Dungeon;


//check if there's Player in a "circle" arround an object
bool CheckCircle(short int &Y_, short int &X_, short int Range, short int Target)
{
	if (Range == 1)
	{
		if ( //range 1
			Dungeon.EntityMap[Y_ + 1][X_] == Target && Dungeon.EntityMap[Y_ + 1][X_ + 1] == Target &&
			Dungeon.EntityMap[Y_][X_ + 1] == Target && Dungeon.EntityMap[Y_ - 1][X_ + 1] == Target &&
			Dungeon.EntityMap[Y_ - 1][X_] == Target && Dungeon.EntityMap[Y_ - 1][X_ - 1] == Target &&
			Dungeon.EntityMap[Y_][X_ - 1] == Target &&  Dungeon.EntityMap[Y_ + 1][X_ - 1] == Target
			)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (Range == 2)
	{
		if (//range 1
			Dungeon.EntityMap[Y_ + 1][X_] == Target && Dungeon.EntityMap[Y_ + 1][X_ + 1] == Target && Dungeon.EntityMap[Y_][X_ + 1] == Target &&
			Dungeon.EntityMap[Y_ - 1][X_ + 1] == Target && Dungeon.EntityMap[Y_ - 1][X_] == Target && Dungeon.EntityMap[Y_ - 1][X_ - 1] == Target &&
			Dungeon.EntityMap[Y_][X_ - 1] == Target &&  Dungeon.EntityMap[Y_ + 1][X_ - 1] == Target &&

			//range 2		
			Dungeon.EntityMap[Y_ + 2][X_] == Target && Dungeon.EntityMap[Y_ + 2][X_ + 1] == Target && Dungeon.EntityMap[Y_ + 1][X_ + 2] == Target &&
			Dungeon.EntityMap[Y_][X_ + 2] == Target && Dungeon.EntityMap[Y_ - 1][X_ + 2] == Target && Dungeon.EntityMap[Y_ - 2][X_ + 1] == Target &&
			Dungeon.EntityMap[Y_ - 2][X_] == Target && Dungeon.EntityMap[Y_ - 2][X_ - 1] == Target && Dungeon.EntityMap[Y_ - 1][X_ - 2] == Target &&
			Dungeon.EntityMap[Y_][X_ - 2] == Target && Dungeon.EntityMap[Y_ + 1][X_ - 2] == Target && Dungeon.EntityMap[Y_ + 2][X_ - 1] == Target
			)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (Range == 4)
	{
		if (//range 1
			Dungeon.EntityMap[Y_ + 1][X_] == Target && Dungeon.EntityMap[Y_ + 1][X_ + 1] == Target && Dungeon.EntityMap[Y_][X_ + 1] == Target &&
			Dungeon.EntityMap[Y_ - 1][X_ + 1] == Target && Dungeon.EntityMap[Y_ - 1][X_] == Target && Dungeon.EntityMap[Y_ - 1][X_ - 1] == Target &&
			Dungeon.EntityMap[Y_][X_ - 1] == Target &&  Dungeon.EntityMap[Y_ + 1][X_ - 1] == Target &&

			//range 2		
			Dungeon.EntityMap[Y_ + 2][X_] == Target && Dungeon.EntityMap[Y_ + 2][X_ + 1] == Target && Dungeon.EntityMap[Y_ + 1][X_ + 2] == Target &&
			Dungeon.EntityMap[Y_][X_ + 2] == Target && Dungeon.EntityMap[Y_ - 1][X_ + 2] == Target && Dungeon.EntityMap[Y_ - 2][X_ + 1] == Target &&
			Dungeon.EntityMap[Y_ - 2][X_] == Target && Dungeon.EntityMap[Y_ - 2][X_ - 1] == Target && Dungeon.EntityMap[Y_ - 1][X_ - 2] == Target &&
			Dungeon.EntityMap[Y_][X_ - 2] == Target && Dungeon.EntityMap[Y_ + 1][X_ - 2] == Target && Dungeon.EntityMap[Y_ + 2][X_ - 1] == Target &&

			//range 3
			Dungeon.EntityMap[Y_ + 3][X_] == Target &&
			Dungeon.EntityMap[Y_ + 3][X_ + 1] == Target && Dungeon.EntityMap[Y_ + 2][X_ + 2] == Target && Dungeon.EntityMap[Y_ + 1][X_ + 3] == Target &&
			Dungeon.EntityMap[Y_][X_ + 3] == Target && Dungeon.EntityMap[Y_ - 1][X_ + 3] == Target && Dungeon.EntityMap[Y_ - 2][X_ + 2] == Target &&
			Dungeon.EntityMap[Y_ - 3][X_ + 1] == Target && Dungeon.EntityMap[Y_ - 3][X_] == Target && Dungeon.EntityMap[Y_ - 3][X_ - 1] == Target &&
			Dungeon.EntityMap[Y_ - 2][X_ - 2] == Target && Dungeon.EntityMap[Y_ - 1][X_ - 3] == Target && Dungeon.EntityMap[Y_][X_ - 3] == Target &&
			Dungeon.EntityMap[Y_ + 1][X_ - 3] == Target && Dungeon.EntityMap[Y_ + 2][X_ - 2] == Target && Dungeon.EntityMap[Y_ + 3][X_ - 1] == Target &&

			//range 4
			Dungeon.EntityMap[Y_ + 4][X_] == Target && Dungeon.EntityMap[Y_ + 4][X_ + 1] == Target &&
			Dungeon.EntityMap[Y_ + 4][X_ + 2] == Target && Dungeon.EntityMap[Y_ + 3][X_ + 3] == Target && Dungeon.EntityMap[Y_ + 2][X_ + 4] == Target &&
			Dungeon.EntityMap[Y_ + 1][X_ + 4] == Target && Dungeon.EntityMap[Y_][X_ + 4] == Target && Dungeon.EntityMap[Y_ - 1][X_ + 4] == Target &&
			Dungeon.EntityMap[Y_ - 2][X_ + 4] == Target && Dungeon.EntityMap[Y_ - 3][X_ + 3] == Target && Dungeon.EntityMap[Y_ - 4][X_ + 2] == Target &&
			Dungeon.EntityMap[Y_ - 4][X_ + 1] == Target && Dungeon.EntityMap[Y_ - 4][X_] == Target && Dungeon.EntityMap[Y_ - 4][X_ - 1] == Target &&
			Dungeon.EntityMap[Y_ - 4][X_ - 2] == Target && Dungeon.EntityMap[Y_ - 3][X_ - 3] == Target && Dungeon.EntityMap[Y_ - 2][X_ - 4] == Target &&
			Dungeon.EntityMap[Y_ - 1][X_ - 4] == Target && Dungeon.EntityMap[Y_][X_ - 4] == Target && Dungeon.EntityMap[Y_ + 1][X_ - 4] == Target &&
			Dungeon.EntityMap[Y_ + 2][X_ - 4] == Target &&Dungeon.EntityMap[Y_ + 3][X_ - 3] == Target && Dungeon.EntityMap[Y_ + 4][X_ - 2] == Target &&
			Dungeon.EntityMap[Y_ + 4][X_ - 1] == Target && Dungeon.EntityMap[Y_ + 3][X_ + 2] == Target && Dungeon.EntityMap[Y_ + 2][X_ + 3] == Target &&
			Dungeon.EntityMap[Y_ - 2][X_ + 3] == Target && Dungeon.EntityMap[Y_ - 3][X_ + 2] == Target && Dungeon.EntityMap[Y_ - 3][X_ - 2] == Target &&
			Dungeon.EntityMap[Y_ - 2][X_ - 3] == Target && Dungeon.EntityMap[Y_ + 2][X_ - 3] == Target && Dungeon.EntityMap[Y_ + 3][X_ - 2] == Target
			)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (Range == 40)
	{
		if ( //range 1
			Dungeon.EntityMap[Y_ + 1][X_] == Target || Dungeon.EntityMap[Y_ + 1][X_ + 1] == Target || Dungeon.EntityMap[Y_][X_ + 1] == Target ||
			Dungeon.EntityMap[Y_ - 1][X_ + 1] == Target || Dungeon.EntityMap[Y_ - 1][X_] == Target || Dungeon.EntityMap[Y_ - 1][X_ - 1] == Target ||
			Dungeon.EntityMap[Y_][X_ - 1] == Target || Dungeon.EntityMap[Y_ + 1][X_ - 1] == Target ||

			//range 2		
			Dungeon.EntityMap[Y_ + 2][X_] == Target || Dungeon.EntityMap[Y_ + 2][X_ + 1] == Target || Dungeon.EntityMap[Y_ + 1][X_ + 2] == Target ||
			Dungeon.EntityMap[Y_][X_ + 2] == Target || Dungeon.EntityMap[Y_ - 1][X_ + 2] == Target || Dungeon.EntityMap[Y_ - 2][X_ + 1] == Target ||
			Dungeon.EntityMap[Y_ - 2][X_] == Target || Dungeon.EntityMap[Y_ - 2][X_ - 1] == Target || Dungeon.EntityMap[Y_ - 1][X_ - 2] == Target ||
			Dungeon.EntityMap[Y_][X_ - 2] == Target || Dungeon.EntityMap[Y_ + 1][X_ - 2] == Target || Dungeon.EntityMap[Y_ + 2][X_ - 1] == Target ||

			//range 3
			Dungeon.EntityMap[Y_ + 3][X_] == Target ||
			Dungeon.EntityMap[Y_ + 3][X_ + 1] == Target || Dungeon.EntityMap[Y_ + 2][X_ + 2] == Target || Dungeon.EntityMap[Y_ + 1][X_ + 3] == Target ||
			Dungeon.EntityMap[Y_][X_ + 3] == Target || Dungeon.EntityMap[Y_ - 1][X_ + 3] == Target || Dungeon.EntityMap[Y_ - 2][X_ + 2] == Target ||
			Dungeon.EntityMap[Y_ - 3][X_ + 1] == Target || Dungeon.EntityMap[Y_ - 3][X_] == Target || Dungeon.EntityMap[Y_ - 3][X_ - 1] == Target ||
			Dungeon.EntityMap[Y_ - 2][X_ - 2] == Target || Dungeon.EntityMap[Y_ - 1][X_ - 3] == Target || Dungeon.EntityMap[Y_][X_ - 3] == Target ||
			Dungeon.EntityMap[Y_ + 1][X_ - 3] == Target || Dungeon.EntityMap[Y_ + 2][X_ - 2] == Target || Dungeon.EntityMap[Y_ + 3][X_ - 1] == Target ||

			//range 4
			Dungeon.EntityMap[Y_ + 4][X_] == Target || Dungeon.EntityMap[Y_ + 4][X_ + 1] == Target ||
			Dungeon.EntityMap[Y_ + 4][X_ + 2] == Target || Dungeon.EntityMap[Y_ + 3][X_ + 3] == Target || Dungeon.EntityMap[Y_ + 2][X_ + 4] == Target ||
			Dungeon.EntityMap[Y_ + 1][X_ + 4] == Target || Dungeon.EntityMap[Y_][X_ + 4] == Target || Dungeon.EntityMap[Y_ - 1][X_ + 4] == Target ||
			Dungeon.EntityMap[Y_ - 2][X_ + 4] == Target || Dungeon.EntityMap[Y_ - 3][X_ + 3] == Target || Dungeon.EntityMap[Y_ - 4][X_ + 2] == Target ||
			Dungeon.EntityMap[Y_ - 4][X_ + 1] == Target || Dungeon.EntityMap[Y_ - 4][X_] == Target || Dungeon.EntityMap[Y_ - 4][X_ - 1] == Target ||
			Dungeon.EntityMap[Y_ - 4][X_ - 2] == Target || Dungeon.EntityMap[Y_ - 3][X_ - 3] == Target || Dungeon.EntityMap[Y_ - 2][X_ - 4] == Target ||
			Dungeon.EntityMap[Y_ - 1][X_ - 4] == Target || Dungeon.EntityMap[Y_][X_ - 4] == Target || Dungeon.EntityMap[Y_ + 1][X_ - 4] == Target ||
			Dungeon.EntityMap[Y_ + 2][X_ - 4] == Target || Dungeon.EntityMap[Y_ + 3][X_ - 3] == Target || Dungeon.EntityMap[Y_ + 4][X_ - 2] == Target ||
			Dungeon.EntityMap[Y_ + 4][X_ - 1] == Target || Dungeon.EntityMap[Y_ + 3][X_ + 2] == Target || Dungeon.EntityMap[Y_ + 2][X_ + 3] == Target ||
			Dungeon.EntityMap[Y_ - 2][X_ + 3] == Target || Dungeon.EntityMap[Y_ - 3][X_ + 2] == Target || Dungeon.EntityMap[Y_ - 3][X_ - 2] == Target ||
			Dungeon.EntityMap[Y_ - 2][X_ - 3] == Target || Dungeon.EntityMap[Y_ + 2][X_ - 3] == Target || Dungeon.EntityMap[Y_ + 3][X_ - 2] == Target
			)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

}


struct EnemyStruct
{
	std::string Name = "ERROR";

	bool Alive = true;

	short int LVL;

	double Damage;

	double HPMax;

	double HP;

	double Defense;

	short int GiveExperience;

}; EnemyStruct Enemy;


class EnemySlimeClass
{
public:
	//Position X
	short int X;

	//Position Y
	short int Y;

	//Makes the Enemy exist
	bool Active = false;

	//if Slime is Alive
	bool Alive = true;
private:

	//level of Enemy: Slime
	short int LVL = 1;

	//damage
	double Damage;

	//Maximum Health poshort ints Ammount
	double HPMax = 25;

	//Health poshort ints left
	double HP = HPMax;

	//Defense: Damage - Defense = Damage done 
	double Defense;

	//Experience Enemy: Zombie give
	short int GiveExperience = 20;

	//value that will be multiplied for the LVL at the start of the Map generation
	double DamageMultiplier;
	//value that will be multiplied for the LVL at the start of the Map generation
	double HPMultiplier;
	//value that will be multiplied for the LVL at the start of the Map generation
	double GiveExperienceMultiplier;

public:

	//if fithing
	bool InBattle = false;

	struct Movement
	{
			short int UpX = 0;
			short int UpY = 1;

			short int LeftX = -1;
			short int LeftY = 0 ;

			short int DownX = 0 ;
			short int DownY = -1;

			short int RightX = 1;
			short int RightY = 0;

	}; Movement Mov;

	void SetEnemyValues()
	{
		if (InBattle) {
			Enemy.LVL = LVL;
			Enemy.HPMax = HPMax;
			Enemy.HP = HP;
			Enemy.Damage = Damage;
			Enemy.Defense = Defense;
			Enemy.GiveExperience = GiveExperience;
			Enemy.Name = "Slime";
		}
	}

	void SlimeMovAI()
	{
		//if Entity can't move left or right
		bool UnableToMovOrizontal = false;
		//if Entity can't move Up or Down
		bool UnableToMovVertical = false;
		//if can't move at all
		bool UnableToMov = false;

		//if enemy don't know where to go he goes randomly
		short int RMov;

		if (Active && Alive)
		{
			if (CheckCircle(Y, X, 40, 1))
			{
				if (abs(Player.X - X) > abs(Player.Y - Y))
				{
					if (Player.X - X > 0 && Dungeon.Map[Y + Mov.RightY][X + Mov.RightX] == 1 && Dungeon.EntityMap[Y + Mov.RightY][X + Mov.RightX] == 0)
					{
						Dungeon.EntityMap[Y][X] = 0;
						X += Mov.RightX;
						Y += Mov.RightY;
						Dungeon.EntityMap[Y][X] = 2;
						UnableToMovOrizontal = false;
						UnableToMov = false;
					}
					else if (Player.X - X < 0 && Dungeon.Map[Y + Mov.LeftY][X + Mov.LeftX] == 1 && Dungeon.EntityMap[Y + Mov.LeftY][X + Mov.LeftX] == 0)
					{
						Dungeon.EntityMap[Y][X] = 0;
						X += Mov.LeftX;
						Y += Mov.LeftY;
						Dungeon.EntityMap[Y][X] = 2;
						UnableToMovOrizontal = false;
						UnableToMov = false;
					}
					else
					{
						UnableToMovOrizontal = true;
					}

					if (UnableToMovOrizontal)
					{
						if (Player.Y - Y > 0 && Dungeon.Map[Y + Mov.UpY][X + Mov.UpX] == 1 && Dungeon.EntityMap[Y + Mov.UpY][X + Mov.UpX] == 0)
						{
							Dungeon.EntityMap[Y][X] = 0;
							X += Mov.UpX;
							Y += Mov.UpY;
							Dungeon.EntityMap[Y][X] = 2;
							UnableToMovVertical = false;
							UnableToMov = false;
						}
						else if (Player.Y - Y < 0 && Dungeon.Map[Y + Mov.DownY][X + Mov.DownX] == 1 && Dungeon.EntityMap[Y + Mov.DownY][X + Mov.DownX] == 0)
						{
							Dungeon.EntityMap[Y][X] = 0;
							X += Mov.DownX;
							Y += Mov.DownY;
							Dungeon.EntityMap[Y][X] = 2;
							UnableToMovVertical = false;
							UnableToMov = false;
						}
						else
						{
							UnableToMov = true;
						}
					}
				}
				else if (abs(Player.X - X) < abs(Player.Y - Y))
				{
					if (Player.Y - Y > 0 && Dungeon.Map[Y + Mov.UpY][X + Mov.UpX] == 1 && Dungeon.EntityMap[Y + Mov.UpY][X + Mov.UpX] == 0)
					{
						Dungeon.EntityMap[Y][X] = 0;
						X += Mov.UpX;
						Y += Mov.UpY;
						Dungeon.EntityMap[Y][X] = 2;
						UnableToMovVertical = false;
						UnableToMov = false;
					}
					else if (Player.Y - Y < 0 && Dungeon.Map[Y + Mov.DownY][X + Mov.DownX] == 1 && Dungeon.EntityMap[Y + Mov.DownY][X + Mov.DownX] == 0)
					{
						Dungeon.EntityMap[Y][X] = 0;
						X += Mov.DownX;
						Y += Mov.DownY;
						Dungeon.EntityMap[Y][X] = 2;
						UnableToMovVertical = false;
						UnableToMov = false;
					}
					else
					{
						UnableToMovVertical = true;
					}

					if (UnableToMovVertical)
					{
						if (Player.X - X > 0 && Dungeon.Map[Y + Mov.RightY][X + Mov.RightX] == 1 && Dungeon.EntityMap[Y + Mov.RightY][X + Mov.RightX] == 0)
						{
							Dungeon.EntityMap[Y][X] = 0;
							X += Mov.RightX;
							Y += Mov.RightY;
							Dungeon.EntityMap[Y][X] = 2;
							UnableToMovOrizontal = false;
							UnableToMov = false;
						}
						else if (Player.X - X < 0 && Dungeon.Map[Y + Mov.LeftY][X + Mov.LeftX] == 1 && Dungeon.EntityMap[Y + Mov.LeftY][X + Mov.LeftX] == 0)
						{
							Dungeon.EntityMap[Y][X] = 0;
							X += Mov.LeftX;
							Y += Mov.LeftY;
							Dungeon.EntityMap[Y][X] = 2;
							UnableToMovOrizontal = false;
							UnableToMov = false;
						}
						else
						{
							UnableToMov = true;
						}
					}
				}
				else if (abs(Player.X - X) == abs(Player.Y - Y))
				{
					RMov = (rand() % 2) + 1;
					if (RMov == 1)
					{
						if (Player.X - X > 0 && Dungeon.Map[Y + Mov.RightY][X + Mov.RightX] == 1 && Dungeon.EntityMap[Y + Mov.RightY][X + Mov.RightX] == 0)
						{
							Dungeon.EntityMap[Y][X] = 0;
							X += Mov.RightX;
							Y += Mov.RightY;
							Dungeon.EntityMap[Y][X] = 2;
							UnableToMovOrizontal = false;
							UnableToMov = false;
						}
						else if (Player.X - X < 0 && Dungeon.Map[Y + Mov.LeftY][X + Mov.LeftX] == 1 && Dungeon.EntityMap[Y + Mov.LeftY][X + Mov.LeftX] == 0)
						{
							Dungeon.EntityMap[Y][X] = 0;
							X += Mov.LeftX;
							Y += Mov.LeftY;
							Dungeon.EntityMap[Y][X] = 2;
							UnableToMovOrizontal = false;
							UnableToMov = false;
						}
						else
						{
							UnableToMovOrizontal = true;
						}

						if (UnableToMovOrizontal)
						{
							if (Player.Y - Y > 0 && Dungeon.Map[Y + Mov.UpY][X + Mov.UpX] == 1 && Dungeon.EntityMap[Y + Mov.UpY][X + Mov.UpX] == 0)
							{
								Dungeon.EntityMap[Y][X] = 0;
								X += Mov.UpX;
								Y += Mov.UpY;
								Dungeon.EntityMap[Y][X] = 2;
								UnableToMovVertical = false;
								UnableToMov = false;
							}
							else if (Player.Y - Y < 0 && Dungeon.Map[Y + Mov.DownY][X + Mov.DownX] == 1 && Dungeon.EntityMap[Y + Mov.DownY][X + Mov.DownX] == 0)
							{
								Dungeon.EntityMap[Y][X] = 0;
								X += Mov.DownX;
								Y += Mov.DownY;
								Dungeon.EntityMap[Y][X] = 2;
								UnableToMovVertical = false;
								UnableToMov = false;
							}
							else
							{
								UnableToMov = true;
							}
						}
					}
					else
					{
						if (Player.Y - Y > 0 && Dungeon.Map[Y + Mov.UpY][X + Mov.UpX] == 1 && Dungeon.EntityMap[Y + Mov.UpY][X + Mov.UpX] == 0)
						{
							Dungeon.EntityMap[Y][X] = 0;
							X += Mov.UpX;
							Y += Mov.UpY;
							Dungeon.EntityMap[Y][X] = 2;
							UnableToMovVertical = false;
							UnableToMov = false;
						}
						else if (Player.Y - Y < 0 && Dungeon.Map[Y + Mov.DownY][X + Mov.DownX] == 1 && Dungeon.EntityMap[Y + Mov.DownY][X + Mov.DownX] == 0)
						{
							Dungeon.EntityMap[Y][X] = 0;
							X += Mov.DownX;
							Y += Mov.DownY;
							Dungeon.EntityMap[Y][X] = 2;
							UnableToMovVertical = false;
							UnableToMov = false;
						}
						else
						{
							UnableToMovVertical = true;
						}

						if (UnableToMovVertical)
						{
							if (Player.X - X > 0 && Dungeon.Map[Y + Mov.RightY][X + Mov.RightX] == 1 && Dungeon.EntityMap[Y + Mov.RightY][X + Mov.RightX] == 0)
							{
								Dungeon.EntityMap[Y][X] = 0;
								X += Mov.RightX;
								Y += Mov.RightY;
								Dungeon.EntityMap[Y][X] = 2;
								UnableToMovOrizontal = false;
								UnableToMov = false;
							}
							else if (Player.X - X < 0 && Dungeon.Map[Y + Mov.LeftY][X + Mov.LeftX] == 1 && Dungeon.EntityMap[Y + Mov.LeftY][X + Mov.LeftX] == 0)
							{
								Dungeon.EntityMap[Y][X] = 0;
								X += Mov.LeftX;
								Y += Mov.LeftY;
								Dungeon.EntityMap[Y][X] = 2;
								UnableToMovOrizontal = false;
								UnableToMov = false;
							}
							else
							{
								UnableToMov = true;
							}
						}
					}
				}


			}
		}
	}

};EnemySlimeClass Slime01, Slime02, Slime03, Slime04, Slime05;


class EnemyZombieClass
{
public:
	//Position X
	short int X;

	//Position Y
	short int Y;

	//Makes the Enemy exist
	bool Active = false;

	//if Zombie is Alive
	bool Alive = true;

private:

	//level of Enemy: zombie
	short int LVL = 1;

	//damage
	double Damage = 12;

	//Maximum Health poshort ints Ammount
	double HPMax = 30;

	//Health poshort ints left
	double HP = HPMax;

	//Defense: Damage - Defense = Damage done 
	double Defense = 1.1;

	//Experience Enemy: Zombie give
	short int GiveExperience = 30;

	//value that will be multiplied for the LVL at the start of the Map generation
	double DamageMultiplier;
	//value that will be multiplied for the LVL at the start of the Map generation
	double HPMultiplier;
	//value that will be multiplied for the LVL at the start of the Map generation
	double GiveExperienceMultiplier;

public:

	//if figthing
	bool InBattle = false;

	struct Movement
	{
		short int UpX = 0;
		short int UpY = 1;

		short int LeftX = -1;
		short int LeftY = 0;

		short int DownX = 0;
		short int DownY = -1;

		short int RightX = 1;
		short int RightY = 0;

	}; Movement Mov;

	void SetEnemyValues()
	{
		if (InBattle) {
			Enemy.LVL = LVL;
			Enemy.HPMax = HPMax;
			Enemy.HP = HP;
			Enemy.Damage = Damage;
			Enemy.Defense = Defense;
			Enemy.GiveExperience = GiveExperience;
			Enemy.Name = "Zombie";
		}
	}

	void ZombieMovAI()
	{
		//if Entity can't move left or right
		bool UnableToMovOrizontal = false;
		//if Entity can't move Up or Down
		bool UnableToMovVertical = false;
		//if can't move at all
		bool UnableToMov = false;
		//if enemy don't know where to go he goes randomly
		short int RMov;

		if (Active && Alive)
		{
			if (CheckCircle(Y, X, 40, 1))
			{
				if (abs(Player.X - X) > abs(Player.Y - Y))
				{
					if (Player.X - X > 0 && Dungeon.Map[Y + Mov.RightY][X + Mov.RightX] == 1 && Dungeon.EntityMap[Y + Mov.RightY][X + Mov.RightX] == 0)
					{
						Dungeon.EntityMap[Y][X] = 0;
						X += Mov.RightX;
						Y += Mov.RightY;
						Dungeon.EntityMap[Y][X] = 3;
						UnableToMovOrizontal = false;
						UnableToMov = false;
					}
					else if (Player.X - X < 0 && Dungeon.Map[Y + Mov.LeftY][X + Mov.LeftX] == 1 && Dungeon.EntityMap[Y + Mov.LeftY][X + Mov.LeftX] == 0)
					{
						Dungeon.EntityMap[Y][X] = 0;
						X += Mov.LeftX;
						Y += Mov.LeftY;
						Dungeon.EntityMap[Y][X] = 3;
						UnableToMovOrizontal = false;
						UnableToMov = false;
					}
					else
					{
						UnableToMovOrizontal = true;
					}

					if (UnableToMovOrizontal)
					{
						if (Player.Y - Y > 0 && Dungeon.Map[Y + Mov.UpY][X + Mov.UpX] == 1 && Dungeon.EntityMap[Y + Mov.UpY][X + Mov.UpX] == 0)
						{
							Dungeon.EntityMap[Y][X] = 0;
							X += Mov.UpX;
							Y += Mov.UpY;
							Dungeon.EntityMap[Y][X] = 3;
							UnableToMovVertical = false;
							UnableToMov = false;
						}
						else if (Player.Y - Y < 0 && Dungeon.Map[Y + Mov.DownY][X + Mov.DownX] == 1 && Dungeon.EntityMap[Y + Mov.DownY][X + Mov.DownX] == 0)
						{
							Dungeon.EntityMap[Y][X] = 0;
							X += Mov.DownX;
							Y += Mov.DownY;
							Dungeon.EntityMap[Y][X] = 3;
							UnableToMovVertical = false;
							UnableToMov = false;
						}
						else
						{
							UnableToMov = true;
						}
					}
				}
				else if (abs(Player.X - X) < abs(Player.Y - Y))
				{
					if (Player.Y - Y > 0 && Dungeon.Map[Y + Mov.UpY][X + Mov.UpX] == 1 && Dungeon.EntityMap[Y + Mov.UpY][X + Mov.UpX] == 0)
					{
						Dungeon.EntityMap[Y][X] = 0;
						X += Mov.UpX;
						Y += Mov.UpY;
						Dungeon.EntityMap[Y][X] = 3;
						UnableToMovVertical = false;
						UnableToMov = false;
					}
					else if (Player.Y - Y < 0 && Dungeon.Map[Y + Mov.DownY][X + Mov.DownX] == 1 && Dungeon.EntityMap[Y + Mov.DownY][X + Mov.DownX] == 0)
					{
						Dungeon.EntityMap[Y][X] = 0;
						X += Mov.DownX;
						Y += Mov.DownY;
						Dungeon.EntityMap[Y][X] = 3;
						UnableToMovVertical = false;
						UnableToMov = false;
					}
					else
					{
						UnableToMovVertical = true;
					}

					if (UnableToMovVertical)
					{
						if (Player.X - X > 0 && Dungeon.Map[Y + Mov.RightY][X + Mov.RightX] == 1 && Dungeon.EntityMap[Y + Mov.RightY][X + Mov.RightX] == 0)
						{
							Dungeon.EntityMap[Y][X] = 0;
							X += Mov.RightX;
							Y += Mov.RightY;
							Dungeon.EntityMap[Y][X] = 3;
							UnableToMovOrizontal = false;
							UnableToMov = false;
						}
						else if (Player.X - X < 0 && Dungeon.Map[Y + Mov.LeftY][X + Mov.LeftX] == 1 && Dungeon.EntityMap[Y + Mov.LeftY][X + Mov.LeftX] == 0)
						{
							Dungeon.EntityMap[Y][X] = 0;
							X += Mov.LeftX;
							Y += Mov.LeftY;
							Dungeon.EntityMap[Y][X] = 3;
							UnableToMovOrizontal = false;
							UnableToMov = false;
						}
						else
						{
							UnableToMov = true;
						}
					}
				}
				else if (abs(Player.X - X) == abs(Player.Y - Y))
				{
					RMov = (rand() % 2) + 1;
					if (RMov == 1)
					{
						if (Player.X - X > 0 && Dungeon.Map[Y + Mov.RightY][X + Mov.RightX] == 1 && Dungeon.EntityMap[Y + Mov.RightY][X + Mov.RightX] == 0)
						{
							Dungeon.EntityMap[Y][X] = 0;
							X += Mov.RightX;
							Y += Mov.RightY;
							Dungeon.EntityMap[Y][X] = 3;
							UnableToMovOrizontal = false;
							UnableToMov = false;
						}
						else if (Player.X - X < 0 && Dungeon.Map[Y + Mov.LeftY][X + Mov.LeftX] == 1 && Dungeon.EntityMap[Y + Mov.LeftY][X + Mov.LeftX] == 0)
						{
							Dungeon.EntityMap[Y][X] = 0;
							X += Mov.LeftX;
							Y += Mov.LeftY;
							Dungeon.EntityMap[Y][X] = 3;
							UnableToMovOrizontal = false;
							UnableToMov = false;
						}
						else
						{
							UnableToMovOrizontal = true;
						}

						if (UnableToMovOrizontal)
						{
							if (Player.Y - Y > 0 && Dungeon.Map[Y + Mov.UpY][X + Mov.UpX] == 1 && Dungeon.EntityMap[Y + Mov.UpY][X + Mov.UpX] == 0)
							{
								Dungeon.EntityMap[Y][X] = 0;
								X += Mov.UpX;
								Y += Mov.UpY;
								Dungeon.EntityMap[Y][X] = 3;
								UnableToMovVertical = false;
								UnableToMov = false;
							}
							else if (Player.Y - Y < 0 && Dungeon.Map[Y + Mov.DownY][X + Mov.DownX] == 1 && Dungeon.EntityMap[Y + Mov.DownY][X + Mov.DownX] == 0)
							{
								Dungeon.EntityMap[Y][X] = 0;
								X += Mov.DownX;
								Y += Mov.DownY;
								Dungeon.EntityMap[Y][X] = 3;
								UnableToMovVertical = false;
								UnableToMov = false;
							}
							else
							{
								UnableToMov = true;
							}
						}
					}
					else
					{
						if (Player.Y - Y > 0 && Dungeon.Map[Y + Mov.UpY][X + Mov.UpX] == 1 && Dungeon.EntityMap[Y + Mov.UpY][X + Mov.UpX] == 0)
						{
							Dungeon.EntityMap[Y][X] = 0;
							X += Mov.UpX;
							Y += Mov.UpY;
							Dungeon.EntityMap[Y][X] = 3;
							UnableToMovVertical = false;
							UnableToMov = false;
						}
						else if (Player.Y - Y < 0 && Dungeon.Map[Y + Mov.DownY][X + Mov.DownX] == 1 && Dungeon.EntityMap[Y + Mov.DownY][X + Mov.DownX] == 0)
						{
							Dungeon.EntityMap[Y][X] = 0;
							X += Mov.DownX;
							Y += Mov.DownY;
							Dungeon.EntityMap[Y][X] = 3;
							UnableToMovVertical = false;
							UnableToMov = false;
						}
						else
						{
							UnableToMovVertical = true;
						}

						if (UnableToMovVertical)
						{
							if (Player.X - X > 0 && Dungeon.Map[Y + Mov.RightY][X + Mov.RightX] == 1 && Dungeon.EntityMap[Y + Mov.RightY][X + Mov.RightX] == 0)
							{
								Dungeon.EntityMap[Y][X] = 0;
								X += Mov.RightX;
								Y += Mov.RightY;
								Dungeon.EntityMap[Y][X] = 3;
								UnableToMovOrizontal = false;
								UnableToMov = false;
							}
							else if (Player.X - X < 0 && Dungeon.Map[Y + Mov.LeftY][X + Mov.LeftX] == 1 && Dungeon.EntityMap[Y + Mov.LeftY][X + Mov.LeftX] == 0)
							{
								Dungeon.EntityMap[Y][X] = 0;
								X += Mov.LeftX;
								Y += Mov.LeftY;
								Dungeon.EntityMap[Y][X] = 3;
								UnableToMovOrizontal = false;
								UnableToMov = false;
							}
							else
							{
								UnableToMov = true;
							}
						}
					}
				}
			}
		}
	}

};EnemyZombieClass Zombie01, Zombie02, Zombie03, Zombie04, Zombie05;


class SpawnClass
{
public:
	//Function called to make the Entity: Player 
	void Spawn()
	{
		if (Player.Spawned == false)
		{
			for (short int Yfor = 0; Yfor < C_Y; Yfor++)
			{
				for (short int Xfor = 0; Xfor < C_X; Xfor++)
				{
					if ( Dungeon.Map[Yfor][Xfor] == 2)
					{
						Dungeon.EntityMap[Yfor][Xfor] = 1;
						Player.X = Xfor;
						Player.Y = Yfor;
						Player.Spawned = true;

					}
				}
			}
		}
	}



	//Function made for spawning entity like Enemies in a random place
	void RandSpawn(char EnemyType)
	{
		short int X1, Y1;
		short int MaxEnemytype;
		char EntityIdentifier;

		//Bug Active and Alive
		//set every enemy death and not active
		//Slime01.Active = false;		Slime01.Alive = false;		Slime02.Active = false;		Slime02.Alive = false;
		//Slime03.Active = false;		Slime03.Alive = false;		Slime04.Active = false;		Slime04.Alive = false;
		//Slime05.Active = false;		Slime05.Alive = false;

		Zombie01.Active = false;	Zombie01.Alive = false;		Zombie02.Active = false;	Zombie02.Alive = false;
		Zombie03.Active = false;	Zombie03.Alive = false;		Zombie04.Active = false;	Zombie04.Alive = false;
		Zombie05.Active = false;	Zombie05.Alive = false;

		

		if (EnemyType == 'S')
		{
			EntityIdentifier = 2;
			if (Dungeon.Stage == 1) { MaxEnemytype = Dungeon.MMem.s1.EnemySlimeAmount; }
			else if (Dungeon.Stage == 2) { MaxEnemytype = Dungeon.MMem.s2.EnemySlimeAmount; }

		}
		else if (EnemyType == 'Z')
		{
			EntityIdentifier = 3;
			if (Dungeon.Stage == 1) { MaxEnemytype = Dungeon.MMem.s1.EnemyZombieAmount; }
			else if (Dungeon.Stage == 2) { MaxEnemytype = Dungeon.MMem.s2.EnemyZombieAmount; }
		}
		for (short int EnemytypeAmount = 1; EnemytypeAmount <= MaxEnemytype +1; EnemytypeAmount++)
		{
			srand(time(0));

			bool PossibleSpawn = true;
			do {
				X1 = rand() % C_X;
				Y1 = rand() % C_Y;
				//check if there is any obtruction in a "circle" arround his spawn

				if ((Dungeon.Map[Y1][X1] == 1 || Dungeon.Map[Y1][X1] == 3) && Dungeon.EntityMap[Y1][X1] == 0 && CheckCircle(Y1, X1, 2, 0))
				{
					
					if (EnemyType == 'S')
					{				
						PossibleSpawn = true;
						Dungeon.EntityMap[Y1][X1] = EntityIdentifier;

						if (EnemytypeAmount == 1)
						{
							Slime01.Active = true;
							Slime01.Alive = true;
							Slime01.X = X1;
							Slime01.Y = Y1;
						}
						else if (EnemytypeAmount == 2)
						{
							Slime02.Active = true;
							Slime02.Alive = true;
							Slime02.X = X1;
							Slime02.Y = Y1;
						}
						else if (EnemytypeAmount == 3)
						{
							Slime03.Active = true;
							Slime03.Alive = true;
							Slime03.X = X1;
							Slime03.Y = Y1;
						}
						else if (EnemytypeAmount == 4)
						{
							Slime04.Active = true;
							Slime04.Alive = true;
							Slime04.X = X1;
							Slime04.Y = Y1;
						}
						else if (EnemytypeAmount == 5)
						{
							Slime05.Active = true;
							Slime05.Alive = true;
							Slime05.X = X1;
							Slime05.Y = Y1;
						}
					}
					if (EnemyType == 'Z')
					{
						PossibleSpawn = true;
						Dungeon.EntityMap[Y1][X1] = EntityIdentifier;

						if (EnemytypeAmount == 1)
						{
							Zombie01.Active = true;
							Zombie01.Alive = true;
							Zombie01.X = X1;
							Zombie01.Y = Y1;
						}
						else if (EnemytypeAmount == 2)
						{
							Zombie02.Active = true;
							Zombie02.Alive = true;
							Zombie02.X = X1;
							Zombie02.Y = Y1;
						}
						else if (EnemytypeAmount == 3)
						{
							Zombie03.Active = true;
							Zombie03.Alive = true;
							Zombie03.X = X1;
							Zombie03.Y = Y1;
						}
						else if (EnemytypeAmount == 4)
						{
							Zombie04.Active = true;
							Zombie04.Alive = true;
							Zombie04.X = X1;
							Zombie04.Y = Y1;
						}
						else if (EnemytypeAmount == 5)
						{
							Zombie05.Active = true;
							Zombie05.Alive = true;
							Zombie05.X = X1;
							Zombie05.Y = Y1;
						}
					}
				}
				else { PossibleSpawn = false; }

			} while (!PossibleSpawn);
		}
	}

}; SpawnClass Spawn;


class Movements
{
	//Declare is a movement is possible with the help of CheckForMov();
	bool Possible[4] = { false, false, false,  false };//0: W,  1: A,  2: S,  3: D

	char SetMov;

	bool Err;

	//X:  0, Y: +1
	struct MovWStruct {
		static const short int X =  0;//0
		static const short int Y =  +1;//+1
	}; MovWStruct MovW;

	
	struct MovAStruct {
		static const short int X = -1; //-1
		static const short int Y = 0; //0
	}; MovAStruct MovA; //X:  -1, Y: 0

	
	struct MovSStruct {
		static const short int X = 0;//0
		static const short int Y = -1;//-1
	}; MovSStruct MovS;//X:  0, Y: -1

	//X:  +1, Y: 0
	struct MovDStruct {
		static const short int X = +1;//+1
		static const short int Y = 0;//0
	}; MovDStruct MovD;


	

	void CheckForMov()
	{
		if ((Dungeon.Map[Player.Y + MovW.Y][Player.X + MovW.X] == 1 || 
			Dungeon.Map[Player.Y + MovW.Y][Player.X + MovW.X] == 2 || 
			Dungeon.Map[Player.Y + MovW.Y][Player.X + MovW.X] == 3) &&
			Dungeon.EntityMap[Player.Y + MovW.Y][Player.X + MovW.X] == 0)
		{
			Possible[0] = true;
		}
		else
		{
			Possible[0] = false;
		}


		if ((Dungeon.Map[Player.Y + MovA.Y][Player.X + MovA.X] == 1 ||
			Dungeon.Map[Player.Y + MovA.Y][Player.X + MovA.X] == 2 ||
			Dungeon.Map[Player.Y + MovA.Y][Player.X + MovA.X] == 3) &&
			Dungeon.EntityMap[Player.Y + MovA.Y][Player.X + MovA.X] == 0)
		{
			Possible[1] = true;
		}
		else
		{
			Possible[1] = false;
		}


		if ((Dungeon.Map[Player.Y + MovS.Y][Player.X + MovS.X] == 1 ||
			Dungeon.Map[Player.Y + MovS.Y][Player.X + MovS.X] == 2 ||
			Dungeon.Map[Player.Y + MovS.Y][Player.X + MovS.X] == 3) &&
			Dungeon.EntityMap[Player.Y + MovS.Y][Player.X + MovS.X] == 0)
		{
			Possible[2] = true;
		}
		else
		{
			Possible[2] = false;
		}


		if ((Dungeon.Map[Player.Y + MovD.Y][Player.X + MovD.X] == 1 ||
			Dungeon.Map[Player.Y + MovD.Y][Player.X + MovD.X] == 2 ||
			Dungeon.Map[Player.Y + MovD.Y][Player.X + MovD.X] == 3) &&
			Dungeon.EntityMap[Player.Y + MovD.Y][Player.X + MovD.X] == 0)
		{
			Possible[3] = true;
		}
		else
		{
			Possible[3] = false;
		}
	}

	void ApplyMov()
	{
		std::cout << "Select between:";
		
		do {

		if (Possible[0])
		{
			std::cout << " w";
		}
		if (Possible[1])
		{
			std::cout << " a";
		}
		if (Possible[2])
		{
			std::cout << " s";
		}
		if (Possible[3])
		{
			std::cout << " d";
		}

		std::cout << ": ";


			std::cin >> SetMov;

			std::cout << '\n';

			if (SetMov == 'w' || SetMov == 'W' )
			{
				if (Possible[0]) 
				{
					Player.LastX = Player.X;
					Player.LastY = Player.Y;

					Player.X += MovW.X;
					Player.Y += MovW.Y;

					Dungeon.EntityMap[Player.Y][Player.X] = 1;
					Dungeon.EntityMap[Player.LastY][Player.LastX] = 0;

					Err = false;
				}
				else
				{
					std::cout << "Invalid char: " << SetMov << '\n';
					std::cout << "Try something like:";
					Err = true;
				}
			}
			else if (SetMov == 'a' || SetMov == 'A' )
			{
				if (Possible[1])
				{
					Player.LastX = Player.X;
					Player.LastY = Player.Y;

					Player.X += MovA.X;
					Player.Y += MovA.Y;

					Dungeon.EntityMap[Player.Y][Player.X] = 1;
					Dungeon.EntityMap[Player.LastY][Player.LastX] = 0;

					Err = false;
				}
				else
				{
					std::cout << "Invalid char: " << SetMov << '\n';
					std::cout << "Try something like:";
					Err = true;
				}

			}
			else if (SetMov == 's' || SetMov == 'S' )
			{
				if (Possible[2])
				{
					Player.LastX = Player.X;
					Player.LastY = Player.Y;

					Player.X += MovS.X;
					Player.Y += MovS.Y;

					Dungeon.EntityMap[Player.Y][Player.X] = 1;
					Dungeon.EntityMap[Player.LastY][Player.LastX] = 0;

					Err = false;
				}
				else
				{
					std::cout << "Invalid char: " << SetMov << '\n';
					std::cout << "Try something like:";
					Err = true;
				}
			}
			else if (SetMov == 'd' || SetMov == 'D' )
			{
				if (Possible[3])
				{
					Player.LastX = Player.X;
					Player.LastY = Player.Y;
					Player.X += MovD.X;
					Player.Y += MovD.Y;
					Dungeon.EntityMap[ Player.Y ][ Player.X ] = 1;
					Dungeon.EntityMap[ Player.LastY ] [Player.LastX ] = 0;

					Err = false;
				}
				else
				{
					std::cout << "Invalid char: " << SetMov << '\n';
					std::cout << "Try something like:";
					Err = true;
				}
			}
			else
			{
				std::cout << "Invalid char: " << SetMov << '\n';
				std::cout << "Try something like:";
				Err = true;
			}
			
		} while (Err);
		
	}

public:
	void Move()
	{
		CheckForMov();
		ApplyMov();
	}

}; Movements Mov;


class BattleClass
{
public:
	


	int CheckForCorrispondence(short int X_, short int Y_ )
	{
		if (Dungeon.EntityMap[X_][Y_] != 0)
		{
			
			BattleMode = true;
			ExploreMode = false;

			if (Dungeon.EntityMap[X_][Y_] == 2) 
			{
				std::cout << "\nits a slime\n";
				if (X_ == Slime01.X && Y_ == Slime01.Y ) {
					Slime01.InBattle = true;
					Slime01.SetEnemyValues();
					return 0;
				}
				else{ Slime01.InBattle = false; }

				if (X_ == Slime02.X && Y_ == Slime02.Y ) {
					Slime02.InBattle = true;
					Slime02.SetEnemyValues(); 
					return 0;
				}
				else { Slime02.InBattle = false; }

				if (X_ == Slime03.X && Y_ == Slime03.Y ) {
					Slime03.InBattle = true;
					Slime03.SetEnemyValues();
					return 0;
				}
				else { Slime03.InBattle = false; }

				if (X_ == Slime04.X && Y_ == Slime04.Y ) {
					Slime04.InBattle = true;
					Slime04.SetEnemyValues();
					return 0;
				}
				else { Slime04.InBattle = false; }

				if (X_ == Slime05.X && Y_ == Slime05.Y ) {
					Slime05.InBattle = true;
					Slime05.SetEnemyValues();
					return 0;
				}
				else { Slime05.InBattle = false; }
				std::cout << "\nERROR\nnone was chosed as enemy...\n";
			}
			if (Dungeon.EntityMap[X_][Y_] == 3)
			{
				std::cout << "\nits a Zombie\n";
				if (X_ == Zombie01.X && Y_ == Zombie01.Y ) {
					Zombie01.InBattle = true;
					Zombie01.SetEnemyValues();
					return 0;
				}
				else { Zombie01.InBattle = false; }

				if (X_ == Zombie02.X && Y_ == Zombie02.Y ) {
					Zombie02.InBattle = true;
					Zombie02.SetEnemyValues();
					return 0;
				}
				else { Zombie02.InBattle = false; }

				if (X_ == Zombie03.X && Y_ == Zombie03.Y ) {
					Zombie03.InBattle = true;
					Zombie03.SetEnemyValues();
					return 0;
				}
				else { Zombie03.InBattle = false; }

				if (X_ == Zombie04.X && Y_ == Zombie04.Y ) {
					Zombie04.InBattle = true;
					Zombie04.SetEnemyValues();
					return 0;
				}
				else { Zombie04.InBattle = false; }

				if (X_ == Zombie05.X && Y_ == Zombie05.Y ) {
					Zombie05.InBattle = true;
					Zombie05.SetEnemyValues();
					return 0;
				}
				else { Zombie05.InBattle = false; }
				std::cout << "\nERROR\nnone was chosed as enemy...\n";
			}


		}
	}

	

	void CheckForFight()
	{
		CheckForCorrispondence(  (( Player.Y )+1) , ( (Player.X)   ) );
		CheckForCorrispondence(  (( Player.Y )+1) , ( (Player.X) +1) );
		CheckForCorrispondence(  (( Player.Y )  ) , ( (Player.X) +1) );
		CheckForCorrispondence(  (( Player.Y )-1) , ( (Player.X) +1) );
		CheckForCorrispondence(  (( Player.Y )-1) , ( (Player.X)   ) );
		CheckForCorrispondence(  (( Player.Y )-1) , ( (Player.X) -1) );
		CheckForCorrispondence(  (( Player.Y )  ) , ( (Player.X) -1) );
		CheckForCorrispondence(  (( Player.Y )+1) , ( (Player.X) -1) );
	}

	void PrintBattle()
	{
		std::cout << (char)201;
		for (short int m = 0; m < 50; m++) { std::cout << (char)205; }
		std::cout << (char)187 << '\n'<< (char)186;; 
		if (Enemy.Name == "Slime") { SetColor(10); std::cout << 'o'; SetColor(7); }
		if (Enemy.Name == "Zombie") { SetColor(2); std::cout << (char)1 ; SetColor(7); }
		std::cout << " Enemy: " << Enemy.Name;;
		for (short int m = 0; m < (27 - Enemy.Name.size() ); m++) { std::cout << ' '; }
		std::cout << "Lvl: " << Enemy.LVL;
		if(Enemy.LVL < 10){ std::cout << ' '; }
		std::cout << "       " << (char)186 << '\n';
		std::cout << (char)186 << "  HP: " << Enemy.HP << '/' << Enemy.HPMax ;
		if (Enemy.HP < 10 ) { std::cout << ' '; }
		if (Enemy.HP < 100) { std::cout << ' '; }
		if (Enemy.HP < 1000) { std::cout << ' '; }
		if (Enemy.HPMax < 100) { std::cout << ' '; }
		if (Enemy.HPMax < 1000) { std::cout << ' '; }
		for (short int m = 0; m < 22; m++) { std::cout << ' '; }
		std::cout << "Def: " << Enemy.Defense<< "      ";
		if (Enemy.Defense < 10) { std::cout << ' '; }
		if (Enemy.Defense < 100) { std::cout << ' '; }  
		std::cout << (char)186 << '\n' << (char)204;
		for (short int m = 0; m < 50; m++) { std::cout << (char)205; }
		std::cout << (char)185 << '\n' << (char)186;
		SetColor(12);std::cout << (char)2 ;SetColor(7);
		std::cout << ' ' << Player.Name;
		for (short int m = 0; m < (34 - Player.Name.size() ); m++) { std::cout << ' '; }
		std::cout << "Lvl: " << Player.LVL;
		if (Player.LVL < 10) { std::cout << ' '; }
		std::cout << "       " << (char)186 << '\n' << (char)186 << "  HP: " << Player.HP << '/' << Player.HPMax;
		if (Player.HP < 10) { std::cout << ' '; }
		if (Player.HP < 100) { std::cout << ' '; }
		if (Player.HP < 1000) { std::cout << ' '; }
		if (Player.HPMax < 100) { std::cout << ' '; }
		if (Player.HPMax < 1000) { std::cout << ' '; }
		for (short int m = 0; m < 21; m++) { std::cout << ' '; }
		std::cout << "Def: " << std::setprecision(1) << Player.Defense << std::fixed <<"      ";
		if (Player.Defense < 10) { std::cout << ' '; }
		if (Player.Defense < 100) { std::cout << ' '; }
		std::cout << (char)186 << '\n' << (char)186 << "  " << "Mana: " << Player.Mana << '/' << Player.ManaMax;
		if (Player.Mana < 10) { std::cout << ' '; }
		if (Player.Mana < 100) { std::cout << ' '; }
		if (Player.Mana < 1000) { std::cout << ' '; }
		if (Player.ManaMax < 100) { std::cout << ' '; }
		if (Player.ManaMax < 1000) { std::cout << ' '; }
		for (short int m = 0; m < 19; m++) { std::cout << ' '; }
		std::cout << "Exp: " << Player.Experience << '/' << Player.ExpToLvlUP;
		if (Player.Experience < 10) { std::cout << ' '; }
		if (Player.Experience < 100) { std::cout << ' '; }
		if (Player.Experience < 1000) { std::cout << ' '; }
		if (Player.ExpToLvlUP < 100) { std::cout << ' '; }
		if (Player.ExpToLvlUP < 1000) { std::cout << ' '; }
		std::cout << (char)186 << '\n' << (char)204;
		for (short int m = 0; m < 25; m++) { std::cout << (char)196; }
		std::cout << (char)194;
		for (short int m = 0; m < 24; m++) { std::cout << (char)196; }
		std::cout << (char)185 << '\n' << (char)186 << "  [Melee Attack]:W";
		for (short int m = 0; m < 7; m++) { std::cout << ' '; }
		std::cout << (char)179 << "  [Ranged Attack]:A";
		for (short int m = 0; m < 5; m++) { std::cout << ' '; }
		std::cout << (char)186 << '\n' << (char)186;
		for (short int m = 0; m < 25; m++) { std::cout << ' '; }
		std::cout << (char)179;
		for (short int m = 0; m < 24; m++) { std::cout << ' '; }
		std::cout << (char)186 << '\n' << (char)204;
		for (short int m = 0; m < 25; m++) { std::cout << (char)196; }
		std::cout << (char)197;
		for (short int m = 0; m < 24; m++) { std::cout << (char)196; }
		std::cout << (char)185 << '\n' << (char)186 << "  [Speels]:Q";
		for (short int m = 0; m < 13; m++) { std::cout << ' ' ; }
		std::cout << (char)179 << "  [Inventory]:E";
		for (short int m = 0; m < 9; m++) { std::cout << ' '; }
		std::cout << (char)186 << '\n' << (char)186;
		for (short int m = 0; m < 25; m++) { std::cout << ' '; }
		std::cout << (char)179;
		for (short int m = 0; m < 24; m++) { std::cout << ' '; }
		std::cout << (char)186 << '\n'<< (char)200;
		for (short int m = 0; m < 25; m++) { std::cout << (char)205; }
		std::cout << (char)202;
		for (short int m = 0; m < 24; m++) { std::cout << (char)205; }
		std::cout << (char)188;
	}

public:
	void Start()
	{
		PrintBattle();

	}

}; BattleClass Battle;


class GameClass
{
	bool Run = true;

	void GameAI()
	{
		Slime01.SlimeMovAI();
		Slime02.SlimeMovAI();
		Slime03.SlimeMovAI();
		Slime04.SlimeMovAI();
		Slime05.SlimeMovAI();

		Zombie01.ZombieMovAI();
		Zombie02.ZombieMovAI();
		Zombie03.ZombieMovAI();
		Zombie04.ZombieMovAI();
		Zombie05.ZombieMovAI();
	}
public:


	//1st function called at every Player Spawn
	void Start()
	{
		SetColor(7);
		Dungeon.SetMap();
		Spawn.Spawn();
		Dungeon.SetValues();
		Spawn.RandSpawn('S');
		Spawn.RandSpawn('Z');
	}

	short int UpdateExploreMode()
	{
		if (ExploreMode)
		{
			Dungeon.PrintMap();
			Mov.Move();
			Player.Food -= 0.5;
			GameAI();
			Battle.CheckForFight();
			//system(" cls ");
			return 0;
		}
	}

	short int UpdateBattleMode()
	{
		if (BattleMode)
		{
			//system(" cls ");
			Battle.Start();
			std::cin.ignore(2);
			return 0;
		}
		else {
			return 1;
		}
	}

	short int Update()
	{
		do{
			UpdateExploreMode();
			UpdateBattleMode();
		}while (Run);
		return 0;

		
	}
}; GameClass Game;


short int main()
{
	Game.Start();
	Game.Update();
	return 0;
}