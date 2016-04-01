#include "stdafx.h"
	#include <iostream>
		#include <cstdlib>
			#include <ctime>

using namespace std;

//dungeon maximum X value
const int D_X = 20;

//dungeon maximum Y value
const int D_Y = 10;


class DungeonClass{ 

	//Basically level of the dungeon
	int Stage = 1;

	//Dungeon itself
	char DungeonMap[ D_Y ][ D_X ];
	
	//the following arrays stores Dungeon map that will maybe be used as DungeonMap[][]

		//Stage 1 dungeon map 1
		char DungeonS1M1[D_Y][D_X] = {
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },//1st line
			{ 1, 3, 2, 1, 2, 2, 2, 2, 2, 1 },//2nd line
			{ 1, 2, 2, 1, 2, 1, 1, 1, 2, 1 },//3rd line
			{ 1, 1, 2, 2, 2, 1, 1, 1, 2, 1 },//4th line
			{ 1, 1, 1, 2, 1, 5, 1, 2, 2, 1 },//5th line
			{ 1, 4, 1, 2, 2, 2, 1, 2, 2, 1 },//6th line
			{ 1, 2, 2, 1, 1, 1, 1, 2, 1, 1 },//7th line
			{ 1, 1, 2, 1, 1, 2, 2, 2, 2, 1 },//8th line
			{ 1, 1, 2, 2, 2, 2, 1, 1, 1, 1 },//9th line
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }//10th line
		};

public:
	void SetDungeonMap()
	{
		srand(time(NULL));
		
			
		if(Stage == 1)
		{
			//Maps for stage 1

			//REMINDER put here    \/ 3 or more
			int Set_Map = 1 + rand() % 1;

			switch (Set_Map)
			{

			case 1:
			{
				for (int i = 0; i < D_Y; i++)
				{
					for (int j = 0; j < D_X; j++)
					{
						DungeonMap[i][j] = DungeonS1M1[i][j];
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

	//Function made for spawning entity like Enemies
    void RandSpawn(int MaxEnemy, char EntityIdentifier)
    {
        srand(time(0));
        for (int x = 1; x <= MaxEnemy; x++)
        {
            bool Possible = true;
            int Y1;
            int X1;
            do{
                X1 =  (rand() % D_X ) ;
				Y1 =  (rand() % D_Y ) ;

                if( DungeonMap[Y1][X1] == '2')
                {
					Possible = true;
					DungeonMap[Y1][X1] = EntityIdentifier;
				}
                else
                {
					Possible = false;
				}
            }while( !Possible );     
        }
    }

	void PrintMap()
	{
		const char Nothing = '.';
		const char Wall = 176;
		const char Path = 32;
		const char Player = 2;
		const char Door = 207;
		const char Key = 21;

		cout << (char)201;
		for (int x = 0; x < D_X ; x++)
		{
			cout << (char)205;

		}

		cout << (char)187 <<'\n';

		for (int y = D_Y; y > 0; y--)
		{
			cout << (char)186;
			for (int x = 0; x < D_X; x++)
			{
				switch (DungeonMap[y-1][x])
				{
				case 0:
					cout << Nothing;
					break;

				case 1:
					cout << Wall;
					break;

				case 2:
					cout << Path;
					break;

				case 3:
					cout << Player;
					break;
				case 4:
					cout << Door;
					break;
				case 5:
					cout << Key;
					break;
				}
			}
			cout << (char)186 << '\n';
 
		}
		cout << (char)200;
		for (int x = 0; x < D_X; x++)
		{
			cout << (char)205;

		}
		cout << (char)188 << endl;


	}
};

class Player
{
	//Position X of player
	int PositionX;
	//Position Y of player
	int PositionY;
	//level of player
	int LVL = 1;
	//Experience
	int Experience = 0;
	//damage
	int Damage;
	//maximum Health points ammount
	float HPMax = 100;
	//Health points left
	float HP = HPMax;
	//maximum Mana ammount
	float ManaMax = 20;
	//Mana left
	float Mana = ManaMax;

	//Function called to make sure the values are correct at stage changing
	void SetValue(int Setlvl, int SetExperience, int SetDamage, float SetHPMax, float SetHP, float SetManaMax, float SetMana)
	{
		LVL = Setlvl;
		Experience = SetExperience;
		Damage = SetDamage;
		HPMax = SetHPMax;
		HP = SetHP;
		ManaMax = SetManaMax;
		Mana = SetMana;
	}

	int Attack(int LVL, int Damage, float HP)
	{

	}


};

class EnemySlime
{
	//Maximum ammount of enemy: Slime
	int MaxEnemySlime;
	//Makes the Enemy exist
	bool Active = false;
	//Position X
	int PositionX;
	//Position Y
	int PositionY;
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

	void SetValue(int Setlvl, int SetDamage, float SetHPMax, float SetHP, int SetGiveExperience)
	{
		LVL = Setlvl;
		Damage = SetDamage;
		HPMax = SetHPMax;
		HP = SetHP;
		GiveExperience = SetGiveExperience;
	}

};

class EnemyZombie
{
	//Maximum ammount of enemy: Zombie
	int MaxEnemyZombie;
	//Makes the Enemy exist
	bool Active = false;
	//Position X
	int PositionX;
	//Position Y
	int PositionY;
	//level of Enemy: zombie
	int LVL = 1;
	//damage
	int Damage;
	//Maximum Health points Ammount
	float HPMax = 100;
	//Health points left
	float HP = HPMax;
	//Experience Enemy: Zombie give
	int GiveExperience = 30;

	void SetValue(int Setlvl, int SetDamage, float SetHPMax, float SetHP, int SetGiveExperience)
	{
		LVL = Setlvl;
		Damage = SetDamage;
		HPMax = SetHPMax;
		HP = SetHP;
		GiveExperience = SetGiveExperience;
	}

};



int main()
{
	DungeonClass Dungeon;
	Dungeon.SetDungeonMap();
	Dungeon.PrintMap();
	char Ignore;
	cin >> Ignore;


	return 0;
}