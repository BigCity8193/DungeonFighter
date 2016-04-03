#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>



//dungeon maximum X value
const int D_X = 20;

//dungeon maximum Y value
const int D_Y = 10;

//dungeon courrent maximum X value
int C_X = D_X ;

//dungeon courrent maximum Y value
int C_Y = D_Y ;


class EnemySlimeClass
{
public:
	//Position X
	int X;

	//Position Y
	int Y;

	//Makes the Enemy exist
	bool Active = false;

	//if Slime is alive
	bool alive = true;
private:

	//level of Enemy: Slime
	int LVL = 1;

	//damage
	int Damage;

	//Maximum Health points Ammount
	float HPMax = 70;

	//Health points left
	float HP = HPMax;

	//Experience Enemy: Zombie give
	int GiveExperience = 20;

	//value that will be multiplied for the LVL at the start of the Map generation
	float DamageMultiplier;
	//value that will be multiplied for the LVL at the start of the Map generation
	float HPMultiplier;
	//value that will be multiplied for the LVL at the start of the Map generation
	float GiveExperienceMultiplier;

};
EnemySlimeClass Slime01, Slime02, Slime03, Slime04, Slime05;


class EnemyZombieClass
{
public:
	//Position X
	int X;

	//Position Y
	int Y;

	//Makes the Enemy exist
	bool Active = false;

	//if Zombie is alive
	bool alive = true;
private:


	//level of Enemy: zombie
	int LVL = 1;

	//damage
	int Damage = 12;

	//Maximum Health points Ammount
	float HPMax = 25;

	//Health points left
	float HP = HPMax;

	//Experience Enemy: Zombie give
	int GiveExperience = 30;

	//value that will be multiplied for the LVL at the start of the Map generation
	float DamageMultiplier;
	//value that will be multiplied for the LVL at the start of the Map generation
	float HPMultiplier;
	//value that will be multiplied for the LVL at the start of the Map generation
	float GiveExperienceMultiplier;

};
EnemyZombieClass Zombie01, Zombie02, Zombie03, Zombie04, Zombie05;

//Class of the Player
class PlayerClass
{ 
public:
	//Position X of player
	int X;
	//Position Y of player
	int Y;
	//Last position X of player
	int LastX;
	//Last position Y of player
	int LastY;	
	//if player is alive
	bool alive = true;
	//level of player
	int LVL = 1;	
	//Check if player already spawned
	bool Spawned = false;
	//Experience needed to level up when experience = 0
	int ExpToLvlUP = 100;
	//Experience
	int Experience = 0;
	//Damage
	float Damage;
	//Defense: Damage - Defense = Damage done 
	float Defence;
	//maximum Health points amount
	float HPMax = 100;
	//Health points left
	float HP = HPMax;
	//maximum Food amount
	int FoodMax = 30;
	//Food left
	int Food = FoodMax;
	//maximum Mana amount
	float ManaMax = 20;
	//Mana left
	float Mana = ManaMax;
	
	

	////Function called to make sure the values are correct at stage changing
	//void SetValue(int Setlvl, int SetExperience, int SetDamage, float SetHPMax, float SetHP, float SetManaMax, float SetMana)
	//{
	//	LVL = Setlvl;
	//	Experience = SetExperience;
	//	Damage = SetDamage;
	//	HPMax = SetHPMax;
	//	HP = SetHP;
	//	ManaMax = SetManaMax;
	//	Mana = SetMana;
	//}


private:
	int Attack(int LVL, int Damage, float HP)
	{

	}


}; PlayerClass Player;


class DungeonClass{ 

public:
	//Basically level of the dungeon
	int Stage = 1;


	//Map of the entities: Player, Enemies, Neutral
	//1st in order to get printed
	//0:	Nothing
	//1:	Player
	//2:	Enemy
	char EntityMap[ D_Y ][ D_X ];

	//Map of the dungeon structure: wall, path, spawnpoint, Gate
	//2nd in order to get printed
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
			int MaxEnemyZombie = 1;

			//How many Zombie on this Stage
			int EnemyZombieAmount;

			//Maximum ammount of enemy: Slime
			int MaxEnemySlime = 3;

			//How many Slime on this Stage
			int EnemySlimeAmount;

			struct Map1
			{
				//Map maximum X value
				const int M_X = 10;
				//Map maximum Y value
				const int M_Y = 10;

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
				const int M_X = 10;
				//Map maximum Y value
				const int M_Y = 10;

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
			int MaxEnemyZombie = 1;

			//How many Zombie on this Stage
			int EnemyZombieAmount;

			//Maximum ammount of enemy: Slime
			int MaxEnemySlime = 3;

			//How many Slime on this Stage
			int EnemySlimeAmount;

			struct Map1
			{
				//Map maximum X value
				const int M_X = 15;
				//Map maximum Y value
				const int M_Y = 10;

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
		int Set_Map;
		srand(time(NULL));
		
			
		if(Stage == 1)
		{

			//Memo put here    \/ 3 or more
			Set_Map = 1 + rand() % 2;

			switch (Set_Map)
			{

			case 1:
			{
				C_X = MMem.s1.m1.M_X;
				C_Y = MMem.s1.m1.M_Y;
				for (int i = 0; i < C_Y ; i++)
				{
					for (int j = 0; j < C_X; j++)
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
				for (int i = 0; i < C_Y; i++)
				{
					for (int j = 0; j < C_X; j++)
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
			MMem.s1.EnemySlimeAmount =  1- ( rand() % MMem.s1.MaxEnemySlime +1 );
			MMem.s1.EnemyZombieAmount = 1- ( rand() % MMem.s1.MaxEnemyZombie +1 );
		}
		if (Stage == 2)
		{
			MMem.s2.EnemySlimeAmount =  1- ( rand() % MMem.s2.MaxEnemySlime +1 );
			MMem.s2.EnemyZombieAmount = 1- ( rand() % MMem.s2.MaxEnemyZombie +1 );
		}
		
	}


	//check if there's Player in a "circle" arround an object
	bool CheckCircle(int Y_, int X_, int Range, int Target)
{	
	if (Range == 1) 
	{
		if( //range 1
			EntityMap[Y_ +1][X_] == Target && 
			EntityMap[Y_ + 1][X_ + 1] == Target && 
			EntityMap[Y_    ][X_ + 1] == Target &&
			EntityMap[Y_ - 1][X_ + 1] == Target && 
			EntityMap[Y_ - 1][X_] == Target &&
			EntityMap[Y_ - 1][X_ - 1] == Target && 
			EntityMap[Y_][X_ - 1] == Target && 
			EntityMap[Y_ + 1][X_ - 1] == Target 
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
			EntityMap[Y_ + 1][X_] == Target &&
			EntityMap[Y_ + 1][X_ + 1] == Target &&
			EntityMap[Y_][X_ + 1] == Target &&
			EntityMap[Y_ - 1][X_ + 1] == Target &&
			EntityMap[Y_ - 1][X_] == Target &&
			EntityMap[Y_ - 1][X_ - 1] == Target &&
			EntityMap[Y_][X_ - 1] == Target &&
			EntityMap[Y_ + 1][X_ - 1] == Target &&

			//range 2		
			EntityMap[Y_ + 2][X_] == Target &&
			EntityMap[Y_ + 2][X_ + 1] == Target &&
			EntityMap[Y_ + 1][X_ + 2] == Target &&
			EntityMap[Y_][X_ + 2] == Target &&
			EntityMap[Y_ - 1][X_ + 2] == Target &&
			EntityMap[Y_ - 2][X_ + 1] == Target &&
			EntityMap[Y_ - 2][X_] == Target &&
			EntityMap[Y_ - 2][X_ - 1] == Target &&
			EntityMap[Y_ - 1][X_ - 2] == Target &&
			EntityMap[Y_][X_ - 2] == Target &&
			EntityMap[Y_ + 1][X_ - 2] == Target &&
			EntityMap[Y_ + 2][X_ - 1] == Target 
			)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (Range == 3)
	{
		if (//range 1
			EntityMap[Y_ + 1][X_] == Target &&
			EntityMap[Y_ + 1][X_ + 1] == Target &&
			EntityMap[Y_][X_ + 1] == Target &&
			EntityMap[Y_ - 1][X_ + 1] == Target &&
			EntityMap[Y_ - 1][X_] == Target &&
			EntityMap[Y_ - 1][X_ - 1] == Target &&
			EntityMap[Y_][X_ - 1] == Target &&
			EntityMap[Y_ + 1][X_ - 1] == Target &&

			//range 2		
			EntityMap[Y_ + 2][X_] == Target &&
			EntityMap[Y_ + 2][X_ + 1] == Target &&
			EntityMap[Y_ + 1][X_ + 2] == Target &&
			EntityMap[Y_][X_ + 2] == Target &&
			EntityMap[Y_ - 1][X_ + 2] == Target &&
			EntityMap[Y_ - 2][X_ + 1] == Target &&
			EntityMap[Y_ - 2][X_] == Target &&
			EntityMap[Y_ - 2][X_ - 1] == Target &&
			EntityMap[Y_ - 1][X_ - 2] == Target &&
			EntityMap[Y_][X_ - 2] == Target &&
			EntityMap[Y_ + 1][X_ - 2] == Target &&
			EntityMap[Y_ + 2][X_ - 1] == Target &&
			
			//range 3
			EntityMap[Y_ +3][X_] == Target &&
			EntityMap[Y_ +3][X_ +1] == Target &&
			EntityMap[Y_ +2][X_ +2] == Target &&
			EntityMap[Y_ +1][X_ +3] == Target &&
			EntityMap[Y_ ][X_ +3] == Target &&
			EntityMap[Y_ -1][X_ +3] == Target &&
			EntityMap[Y_ -2][X_ +2] == Target &&
			EntityMap[Y_ -3][X_ +1] == Target &&
			EntityMap[Y_ -3][X_ ] == Target &&
			EntityMap[Y_ -3][X_ -1] == Target &&
			EntityMap[Y_ -2][X_ -2] == Target &&
			EntityMap[Y_ -1][X_ -3] == Target &&
			EntityMap[Y_ ][X_ -3] == Target &&
			EntityMap[Y_ +1][X_ -3] == Target &&
			EntityMap[Y_ +2][X_ -2] == Target &&
			EntityMap[Y_ +3][X_ -1] == 0
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
			EntityMap[Y_ + 1][X_] == Target &&
			EntityMap[Y_ + 1][X_ + 1] == Target &&
			EntityMap[Y_][X_ + 1] == Target &&
			EntityMap[Y_ - 1][X_ + 1] == Target &&
			EntityMap[Y_ - 1][X_] == Target &&
			EntityMap[Y_ - 1][X_ - 1] == Target &&
			EntityMap[Y_][X_ - 1] == Target &&
			EntityMap[Y_ + 1][X_ - 1] == Target &&

			//range 2		
			EntityMap[Y_ + 2][X_] == Target &&
			EntityMap[Y_ + 2][X_ + 1] == Target &&
			EntityMap[Y_ + 1][X_ + 2] == Target &&
			EntityMap[Y_][X_ + 2] == Target &&
			EntityMap[Y_ - 1][X_ + 2] == Target &&
			EntityMap[Y_ - 2][X_ + 1] == Target &&
			EntityMap[Y_ - 2][X_] == Target &&
			EntityMap[Y_ - 2][X_ - 1] == Target &&
			EntityMap[Y_ - 1][X_ - 2] == Target &&
			EntityMap[Y_][X_ - 2] == Target &&
			EntityMap[Y_ + 1][X_ - 2] == Target &&
			EntityMap[Y_ + 2][X_ - 1] == Target &&

			//range 3
			EntityMap[Y_ + 3][X_] == Target &&
			EntityMap[Y_ + 3][X_ + 1] == Target &&
			EntityMap[Y_ + 2][X_ + 2] == Target &&
			EntityMap[Y_ + 1][X_ + 3] == Target &&
			EntityMap[Y_][X_ + 3] == Target &&
			EntityMap[Y_ - 1][X_ + 3] == Target &&
			EntityMap[Y_ - 2][X_ + 2] == Target &&
			EntityMap[Y_ - 3][X_ + 1] == Target &&
			EntityMap[Y_ - 3][X_] == Target &&
			EntityMap[Y_ - 3][X_ - 1] == Target &&
			EntityMap[Y_ - 2][X_ - 2] == Target &&
			EntityMap[Y_ - 1][X_ - 3] == Target &&
			EntityMap[Y_][X_ - 3] == Target &&
			EntityMap[Y_ + 1][X_ - 3] == Target &&
			EntityMap[Y_ + 2][X_ - 2] == Target &&
			EntityMap[Y_ + 3][X_ - 1] == Target &&

			//range 4
			EntityMap[Y_ +4][X_] == Target &&
			EntityMap[Y_ +4][X_ +1] == Target &&
			EntityMap[Y_ +4][X_ +2] == Target &&
			EntityMap[Y_ +3][X_ +3] == Target &&
			EntityMap[Y_ +2][X_ +4] == Target &&
			EntityMap[Y_ +1][X_ +4] == Target &&
			EntityMap[Y_][X_ + 4] == Target &&
			EntityMap[Y_ -1][X_ + 4] == Target &&
			EntityMap[Y_ -2][X_ + 4] == Target &&
			EntityMap[Y_ -3][X_+3] == Target &&
			EntityMap[Y_ -4][X_+2] == Target && 
			EntityMap[Y_ -4][X_+1] == Target &&
			EntityMap[Y_ -4][X_] == Target &&
			EntityMap[Y_ -4][X_ -1] == Target &&
			EntityMap[Y_ -4][X_ -2] == Target &&
			EntityMap[Y_ -3][X_ -3] == Target &&
			EntityMap[Y_ -2][X_ -4] == Target &&
			EntityMap[Y_ -1][X_ -4] == Target &&
			EntityMap[Y_][X_ -4] == Target &&
			EntityMap[Y_ +1][X_ -4] == Target &&
			EntityMap[Y_ +2][X_ -4] == Target &&
			EntityMap[Y_ +3][X_ -3] == Target &&
			EntityMap[Y_ +4][X_ -2] == Target &&
			EntityMap[Y_ +4][X_ -1] == Target &&

			EntityMap[Y_ +3][X_ +2] == Target &&
			EntityMap[Y_ +2][X_ +3] == Target &&
			EntityMap[Y_ -2][X_ +3] == Target &&
			EntityMap[Y_ -3][X_ +2] == Target &&
			EntityMap[Y_ -3][X_ -2] == Target &&
			EntityMap[Y_ -2][X_ -3] == Target &&
			EntityMap[Y_ +2][X_ -3] == Target &&
			EntityMap[Y_ +3][X_ -2] == Target 
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

	//Function called to make the Entity: Player 
	void Spawn()
	{
		if (Player.Spawned == false)
		{
			for (int Yfor = 0; Yfor < C_Y; Yfor++)
			{
				for (int Xfor = 0; Xfor < C_X; Xfor++)
				{
					if (Map[Yfor][Xfor] == 2)
					{
						EntityMap[Yfor][Xfor] = 1;
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
		int X1, Y1;
		int MaxEnemytype;
		char EntityIdentifier;

		if (EnemyType == 'S')
		{
			EntityIdentifier = 2;
			if(Stage == 1){MaxEnemytype = MMem.s1.EnemySlimeAmount;}
			else if(Stage == 2) { MaxEnemytype = MMem.s2.EnemySlimeAmount; }
			
		}
		else if (EnemyType == 'Z')
		{
			EntityIdentifier = 3;
			if (Stage == 1) { MaxEnemytype = MMem.s1.EnemyZombieAmount; }
			else if (Stage == 2) { MaxEnemytype = MMem.s2.EnemyZombieAmount; }

		}



		for (int EnemytypeAmount = 0; EnemytypeAmount <= MaxEnemytype; EnemytypeAmount++)
		{

			srand(time(0));

			bool PossibleSpawn = true;


			do {
				X1 = (rand() % C_X);
				Y1 = (rand() % C_Y);
				//check if there is any obtruction in a "circle" arround his spawn

				if ((Map[Y1][X1] == 1 || Map[Y1][X1] == 3) && EntityMap[Y1][X1] == 0 && CheckCircle(Y1, X1, 2, 0))
				{
					if (EnemyType == 'S')
					{

						PossibleSpawn = true;
						EntityMap[Y1][X1] = EntityIdentifier;

						if (EnemytypeAmount == 0)
						{
							Slime01.X = X1;
							Slime01.Y = Y1;
						}
						else if (EnemytypeAmount == 1)
						{
							Slime02.X = X1;
							Slime02.Y = Y1;
						}
						else if (EnemytypeAmount == 2)
						{
							Slime03.X = X1;
							Slime03.Y = Y1;
						}
						else if (EnemytypeAmount == 3)
						{
							Slime04.X = X1;
							Slime04.Y = Y1;
						}
						else if (EnemytypeAmount == 4)
						{
							Slime05.X = X1;
							Slime05.Y = Y1;
						}
					}
					if (EnemyType == 'Z')
					{

						PossibleSpawn = true;
						EntityMap[Y1][X1] = EntityIdentifier;

						if (EnemytypeAmount == 0)
						{
							Zombie01.X = X1;
							Zombie01.Y = Y1;
						}
						else if (EnemytypeAmount == 1)
						{
							Zombie02.X = X1;
							Zombie02.Y = Y1;
						}
						else if (EnemytypeAmount == 2)
						{
							Zombie03.X = X1;
							Zombie03.Y = Y1;
						}
						else if (EnemytypeAmount == 3)
						{
							Zombie04.X = X1;
							Zombie04.Y = Y1;
						}
						else if (EnemytypeAmount == 4)
						{
							Zombie05.X = X1;
							Zombie05.Y = Y1;
						}
					}
				}
				else { PossibleSpawn = false; }

			} while (!PossibleSpawn);
		}
	}

	//prints the Dungeon.Map to the screen
	void PrintMap()
	{
		const char NothingCh = 46;
		const char WallCh    = 176;
		const char PathCh    = 32;	
		const char GateCh    = 207;
		const char SpawnCh   = 42;

		const char PlayerCh  = 2;
		const char SlimeCh	 = 111;
		const char ZombieCh  = 1;

		const char KeyCh     = 21;
		

		std::cout << (char)201;//for the frame

		for (int x = 0; x < C_X; x++)//for the frame
		{
			std::cout << (char)205; }

		std::cout << (char)187 << '\n' ;//for the frame

		std::cout << (char)186 ;//for the frame

		std::cout << "Stage: " << Stage;

		if (Stage < 10) 
		{
			for (int x = 0; x < C_X - 8; x++)//for the frame
			{
				std::cout << ' ';//for the frame
			}
			std::cout << (char)186 << '\n' ;
		}
		if (Stage >= 10)
		{
			for (int x = 0; x < C_X - 9; x++)//for the frame
			{
				std::cout << ' ';
			}
			std::cout << (char)186 << '\n' ;//for the frame
		}

		
		
		std::cout << (char)204 ;//for the frame

		for (int x = 0; x < C_X ; x++)//for the frame
		{
			std::cout << (char)205; }//for the frame
		std::cout << (char)185;//for the frame
		std::cout << "Lvl: " << Player.LVL << '\n';
		//for every Row
		for (int y = C_Y; y > 0; y--)
		{
			std::cout << (char)186;//for the frame

			//For every Column
			for (int x = 0; x < C_X; x++ )
			{ 

				//check for player 
				if ( EntityMap[y - 1][ x ] == 1 )
				{
					//Entity Player
					std::cout << PlayerCh;
				}
				//check for Slime
				else if (EntityMap[y - 1][x] == 2)
				{
					//Entity Slime
					std::cout << SlimeCh;
				}
				//check for Zombie
				else if (EntityMap[y - 1][x] == 3)
				{
					//Entity Zombie
					std::cout << ZombieCh;
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
					//SpawnPoint
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
			if (y == C_Y ) { std::cout << "HP: " << Player.HP << '/' << Player.HPMax; }
			else if(y == C_Y -1){ std::cout << "Food: " << Player.Food << '/' << Player.FoodMax; }
			else if (y == C_Y - 2) { std::cout << "Mana: " << Player.Mana << '/' << Player.ManaMax; }
			else if (y == C_Y - 3) { std::cout << "exp: " << Player.Experience << '/' << Player.ExpToLvlUP; }
			std::cout << '\n';
 
		}

		std::cout << (char)200;//for the frame
		for (int x = 0; x < C_X; x++)//for the frame
		{
			std::cout << (char)205;

		}
		std::cout << (char)188 << '\n';//for the frame


	}

};DungeonClass Dungeon;



class Movements
{
	//Declare is a movement is possible with the help of CheckForMov();
	bool Possible[4] = { false, false, false,  false };//0: W,  1: A,  2: S,  3: D

	char SetMov;

	bool Err;

	//X:  0, Y: +1
	struct MovWStruct {
		const int X =  0;//0
		const int Y =  +1;//+1
	}; MovWStruct MovW;

	
	struct MovAStruct {
		const int X = -1; //-1
		const int Y = 0; //0
	}; MovAStruct MovA; //X:  -1, Y: 0

	
	struct MovSStruct {
		const int X = 0;//0
		const int Y = -1;//-1
	}; MovSStruct MovS;//X:  0, Y: -1

	//X:  +1, Y: 0
	struct MovDStruct {
		const int X = +1;//+1
		const int Y = 0;//0
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





class GameClass
{
	bool Run = true;

public:


	//Very first function called in Main();
	void Start()
	{
	 
		Dungeon.SetMap();
		Dungeon.Spawn();
		Dungeon.SetValues();
		Dungeon.RandSpawn('S');
		Dungeon.RandSpawn('Z');
	}

	int Update()
	{
		while (Run)
		{
			Dungeon.PrintMap();
			Mov.Move();
			if (!Player.alive)
			{
				return 1;
			}
			Player.Food--;
		}


		
	}
}; GameClass Game;


int main()
{
	Game.Start();
	Game.Update();
	return 0;
}