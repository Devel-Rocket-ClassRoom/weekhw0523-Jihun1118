#include <iostream>
#include "Day0523.h"
#include "stdio.h"
#include "time.h"
using namespace std;


void FisherYatesShuffle(char* Array, int Length)
{

	for (int i = Length - 1; i > 0; i--)
	{
		int RandIndex = rand() % (i + 1);
		char Temp = Array[i];
		Array[i] = Array[RandIndex];
		Array[RandIndex] = Temp;
	}
}

void Homework02_Run() {
	printf("수를 입력하세요\n");
	int Num;
	cin >> Num;

	int Digit[10];
	int Count = 0;

	while (Num > 0)
	{
		Digit[Count] = Num % 10;
		Num = Num / 10;
		Count++;
	}

	printf("자리수를 분리합니다 \n");
	for (int i = Count - 1; i >= 0; i--)
	{
		printf("%d ", Digit[i]);
	}
	printf("\n");

	int Result = 0;
	for (int i = Count - 1; i >= 0; i--)
	{
		Result = (Result * 10) + Digit[i];
	}
	printf("자리수를 다시 합칩니다. \n%d", Result);
}

void Homework03_Run()
{
	int SlotMachine[3] = { 0,0,0 };
	int StartMoney = 10000;
	int CurrentMoney = StartMoney;
	int BetMoney = 0;
	int Play;

	unsigned int Seed = (unsigned int)time(0);
	srand(Seed);


	printf("********슬롯 머신********\n");
	printf("슬롯 머신을 시작합니다. \n");

	while (CurrentMoney >= 100)
	{

		printf("\n\n베팅 금액을 설정하세요. (최소 베팅 금액은 100원이며 현재 금액을 초과할 수 없음)\n");
		printf("현재 금액 : %d\n", CurrentMoney);
		std::cin >> BetMoney;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			printf("숫자만 입력하세요.\n");
			continue;
		}

		if (BetMoney > CurrentMoney || BetMoney < 100)
		{
			printf("다시 입력하세요.\n");
			continue;

		}
		CurrentMoney -= BetMoney;

		printf("\n현재 금액: %d, 베팅 금액 %d\n", CurrentMoney, BetMoney);
		for (int i = 0; i < 3; i++)
		{
			SlotMachine[i] = rand() % 9 + 1;
			SlotMachine[i] = rand() % 9 + 1;
			SlotMachine[i] = rand() % 9 + 1;
			printf("%d ", SlotMachine[i]);

		}

		printf("\n");
		if (SlotMachine[0] == SlotMachine[1] && SlotMachine[1] == SlotMachine[2])
		{
			if (SlotMachine[0] == 7)
			{
				printf("축하합니다!, 베팅한 금액 %d원의 10000배를 돌려받습니다.\n", BetMoney);
				CurrentMoney = CurrentMoney + (BetMoney * 10000);
				printf("현재 금액 : %d", CurrentMoney);
			}
			else {
				printf("축하합니다!, 베팅한 금액 %d원의 50배를 돌려받습니다", BetMoney);
				CurrentMoney = CurrentMoney + (BetMoney * 50);
				printf("현재 금액 : %d", CurrentMoney);
			}
		}
		else
		{
			printf("베팅한 금액을 모두 잃습니다.\n");
		}

		if (CurrentMoney < 100)
		{
			printf("현재 금액이 100원 미만입니다.\n");
			printf("더 이상 베팅할 수 없어 게임을 종료합니다.\n");
			return;
		}

		while (true)
		{
			printf("계속하려면 1, 아니면 2를 누르세요 \n");
			std::cin >> Play;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				printf("숫자만 입력하세요.\n");
				continue;
			}

			if (Play == 1)
			{
				break;
			}
			else if (Play == 2)
			{
				printf("게임을 종료합니다");
				return;
			}
			else {
				printf("잘못된 입력입니다.\n");
			}
		}
	}
}



void Homework04_Run()
{
	int StartMoney = 10000;
	int CurrentMoney = StartMoney;
	int BetMoney = 0;
	int SecondChoice = 0;
	int PlayerChoice = 0;

	char TrumpCard[13] = { 'A', '2', '3','4','5','6','7','8','9','T','J','Q','K' };
	char RandomCard[3];
	char Joker = 'X';

	while (CurrentMoney >= 100)
	{
		printf("베팅 금액을 설정하세요. (최소 베팅 금액은 100원이며 현재 금액을 초과할 수 없음)\n");
		printf("현재 금액 : %d\n", CurrentMoney);
		std::cin >> BetMoney;

		if (BetMoney > CurrentMoney || BetMoney < 100)
		{
			printf("베팅 금액이 잘못되었습니다.\n");
			continue;
		}

		CurrentMoney -= BetMoney;
		printf("현재 금액 : %d 베팅 금액 : %d", CurrentMoney, BetMoney);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			printf("숫자만 입력하세요.\n");
			continue;
		}

		FisherYatesShuffle(TrumpCard, 13);
		RandomCard[0] = TrumpCard[0];
		RandomCard[1] = TrumpCard[1];
		RandomCard[2] = Joker;
		FisherYatesShuffle(RandomCard, 3);

		while (true)
		{
			printf("\n3장의 카드 중 한 장을 선택하세요. (1, 2, 3)\n");
			printf("[?] [?] [?]\n");

			std::cin >> PlayerChoice;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				printf("숫자만 입력하세요.\n");
				continue;
			}

			if (PlayerChoice < 1 || PlayerChoice > 3)
			{
				printf("1, 2, 3 중에서 선택하세요.\n");
				continue;
			}
			break;
		}

		int SelectIndex = PlayerChoice - 1;	// 뽑은 카드

		// 뽑은 카드 보여주기
		for (int i = 0; i < 3; i++)
		{
			if (i == SelectIndex)
			{
				printf("[%c] ", RandomCard[i]);
			}
			else
			{
				printf("[?] ");
			}
		}

		printf("\n");

		if (RandomCard[SelectIndex] == Joker)
		{
			printf("조커를 뽑았습니다. 플레이어의 승리입니다\n");
			CurrentMoney += BetMoney * 2;
			printf("현재 금액 : %d\n", CurrentMoney);
		}
		else
		{
			printf("조커를 뽑지못했습니다. 베팅한 금액을 잃습니다.\n");
			printf("현재 금액 : %d\n", CurrentMoney);
			printf("베팅한 금액의 2배를 지불하고 한 번 더 뽑으시려면 1번, 처음부터 다시 시작 하려면 2번\n");


			while (true)
			{
				std::cin >> PlayerChoice;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					printf("숫자만 입력하세요.\n");
					continue;
				}

				if (PlayerChoice < 1 || PlayerChoice > 2)
				{
					printf("1, 2 중에서 선택하세요.\n");
					continue;
				}
				break;
			}


			if (PlayerChoice == 1)
			{
				if (CurrentMoney >= BetMoney * 2)
				{
					printf("베팅 금액의 2배를 지불했습니다.\n");
					CurrentMoney -= BetMoney * 2;
					printf("현재 금액 : %d 베팅 금액 : %d \n", CurrentMoney, BetMoney * 2);

					printf("남은 카드 중 하나를 고르세요.\n");
					for (int i = 0; i < 3; i++)
					{
						if (i == SelectIndex)
						{
							printf("[%c] ", RandomCard[i]);
						}
						else
						{
							printf("[?] ");
						}
					}


					while (true)
					{

						cin >> SecondChoice;

						if (std::cin.fail())
						{
							std::cin.clear();
							std::cin.ignore(10000, '\n');
							printf("숫자만 입력하세요.\n");
							continue;
						}
						if (SelectIndex + 1 == SecondChoice)
						{
							printf("이미 선택하신 카드입니다.\n");
							continue;
						}
						if (SecondChoice < 1 || SecondChoice > 3)
						{
							printf("잘못된 입력입니다.\n");
							continue;
						}
						break;
					}
					printf("결과는 \n %c %c %c\n", RandomCard[0], RandomCard[1], RandomCard[2]);
					SelectIndex = SecondChoice - 1;
					if (RandomCard[SelectIndex] == Joker)
					{
						printf("조커를 뽑았습니다. 플레이어의 승리입니다\n");
						CurrentMoney += BetMoney * 4;
						printf("현재 금액 : %d\n", CurrentMoney);
					}
					else
					{
						printf("조커를 뽑지못했습니다. 베팅한 금액을 잃습니다.\n");
						printf("현재 금액 : %d\n\n", CurrentMoney);
					}
				}
				else
				{
					printf("소지금이 부족합니다.\n");
				}
			}
		}
		printf("게임을 다시 시작하시겠습니까?\n");

		printf("계속 하려면 1번, 종료하려면 2번\n");

		while (true)
		{
			std::cin >> PlayerChoice;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				printf("숫자만 입력하세요.\n");
				continue;
			}

			if (PlayerChoice < 1 || PlayerChoice > 2)
			{
				printf("1, 2 중에서 선택하세요.\n");
				continue;
			}
			break;
		}

		if (PlayerChoice == 1)
		{
			continue;
		}
		else
		{
			printf("게임을 종료합니다.");
			return;
		}
	}
}



void Homework05_Run()
{
	const int MazeRows = 10;
	const int MazeCols = 20;

	int	PlayerHp = 100;
	int EnemyHp = 100;
	int MinDamage = 5;
	int MaxDamage = 15;
	int Damage = 0; MinDamage + rand() % (MaxDamage - MinDamage + 1);
	int Encounter = 0;

	// 미로 배열
	int Maze[MazeRows][MazeCols] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
		{1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
		{1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
		{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
		{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
		{1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
		{1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
		{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	int PlayerX = 1;
	int PlayerY = 1;

	while (true) {
		PlayerHp = 100;
		EnemyHp = 100;
		for (int i = 0; i < MazeRows; i++)
		{
			for (int j = 0; j < MazeCols; j++)
			{
				if (i == PlayerY && j == PlayerX)
				{
					printf("P");
				}
				else if (Maze[i][j] == 0)
				{
					printf(".");
				}
				else if (Maze[i][j] == 1)
				{
					printf("#");
				}
				else if (Maze[i][j] == 2)
				{
					printf("S");
				}
				else if (Maze[i][j] == 3)
				{
					printf("E");
				}
			}
			printf("\n");
		}

		printf("W,A,S,D로 이동할 방향을 입력하세요.\n");

		int NextX = PlayerX;
		int NextY = PlayerY;

		char Move;
		std::cin >> Move;

		if (Move == 'w' || Move == 'W')
		{
			NextY--;
		}
		else if (Move == 'a' || Move == 'A')
		{
			NextX--;
		}
		else if (Move == 's' || Move == 'S')
		{
			NextY++;
		}
		else if (Move == 'd' || Move == 'D')
		{
			NextX++;
		}
		else
		{
			printf("잘못된 입력입니다. 다시 입력하세요. \n\n");
			continue;
		}

		if (Maze[NextY][NextX] == 1)
		{
			printf("벽이 있습니다. 다시 입력하세요\n\n");
			continue;
		}

		PlayerX = NextX;
		PlayerY = NextY;

		Encounter = rand() % 100 + 1;

		if (Encounter < 20)
		{
			printf("적과 조우하였습니다.\n전투를 시작합니다.\n");
			while (EnemyHp > 0 || PlayerHp > 0)
			{


				printf("플레이어의 공격\n");
				Damage = MinDamage + rand() % (MaxDamage - MinDamage + 1);
				EnemyHp -= Damage;
				EnemyHp = EnemyHp < 0 ? 0 : EnemyHp;

				printf("적의 남은 체력 : %d\n\n", EnemyHp);
				if (EnemyHp == 0)
				{
					printf("적이 사망했습니다.\n 전투를 종료합니다.\n");
					break;
				}
				printf("적의 공격\n");
				Damage = MinDamage + rand() % (MaxDamage - MinDamage + 1);
				PlayerHp -= Damage;
				PlayerHp = PlayerHp < 0 ? 0 : PlayerHp;

				printf("플레이어의 남은 체력 : %d\n\n", PlayerHp);
				
				if (PlayerHp == 0)
				{
					printf("플레이어가 사망했습니다.\n 게임을 종료합니다.");
					return;
				}

			}
		}

			if (Maze[PlayerY][PlayerX] == 3)
			{
				printf("게임이 클리어되었습니다.\n");
				return;
			}
		

	}
}


