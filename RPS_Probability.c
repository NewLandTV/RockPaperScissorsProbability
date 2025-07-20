#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

// 가위바위보 전처리 
#define S 1
#define R 2
#define P 3

#define SHOW_STEP 0
#define SHOW_RESULT 1

// Variables
double win, draw, lose;
int testcase;

// Functions
void Init();
void StepRPCGame(int epoches);
void PlayGame();

int main(void)
{
	Init();
	
	int flag, t;
	
	printf("1 : 플레이, Other : 확률 검사\n> ");
	scanf("%d", &flag);
	
	if (flag == 1)
	{
		PlayGame();
		
		return 0;
	}
	
	printf("시도 횟수를 입력하세요.\n> ");
	scanf("%d", &t);
	StepRPCGame(t);	// 확률 계산을 위한 t번 가위바위보 진행  (Random vs Random)
	printf("플레이어가 이길 확률 : %.24Lf%\n", (win / testcase) * 100.0);
	printf("가위바위보 비길 확률 : %.24Lf%\n", (draw / testcase) * 100.0);
	printf("플레이어가 지는 확률 : %.24Lf%\n", (lose / testcase) * 100.0);
	
	return 0;
}

void Init()
{
	// Initialize for random
	srand((unsigned int)time(NULL));
	
	// Hide consol cursor
	CONSOLE_CURSOR_INFO consoleCursorInfo;
	
	consoleCursorInfo.dwSize = 1;
	consoleCursorInfo.bVisible = 0;
	
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);
}

void StepRPCGame(int epoches)
{
	int i;
	int x, y;
	
	testcase = epoches;
	
	for (i = 1; i <= epoches; i++)
	{
		x = rand() % 3 + 1;	// Random (1 to 3)
		y = rand() % 3 + 1;	// Random (1 to 3)
		
		printf("Step [%d]\n", i);
		
		if (SHOW_STEP == 1)
		{
			switch (x)
			{
			case S:
				printf("가위 vs ");
				
				break; 
			case R:
				printf("바위 vs ");
				
				break; 
			case P:
				printf("보 vs ");
				
				break; 
			}
			
			switch (x)
			{
			case S:
				printf("가위");
				
				break; 
			case R:
				printf("바위");
				
				break; 
			case P:
				printf("보");
				
				break; 
			}
			
			printf("\n");
		}
		
		if (x == y)
		{
			draw++;
			
			if (SHOW_RESULT == 1) printf("무승부\n\n");
		}
		else if ((x == S && y == P) || (x == R && y == S) || (x == P && y == R))
		{
			win++;
			
			if (SHOW_RESULT == 1) printf("플레이어 승!\n\n");
		}
		else
		{
			lose++;
			
			if (SHOW_RESULT == 1) printf("플레이어 패...\n\n");
		}
	}
}

void PlayGame()
{
	int input, x;
	
	while (1)
	{
		printf("가위 : %d, 바위 : %d, 보 : %d\n> ", S, R, P);
		scanf("%d", &input);
		
		switch (input)
		{
		case S:
			printf("가위 vs ");
			
			break; 
		case R:
			printf("바위 vs ");
			
			break; 
		case P:
			printf("보 vs ");
			
			break; 
		}
		
		x = rand() % 3 + 1;	// Random (1 to 3)
		
		switch (x)
		{
		case S:
			printf("가위");
			
			break; 
		case R:
			printf("바위");
			
			break; 
		case P:
			printf("보");
			
			break; 
		}
		
		printf("\n");
		
		if (x == input)
		{
			printf("무승부\n\n");
		}
		else
		{
			printf("%s\n\n", (input == S && x == P) || (input == R && x == S) || (input == P && x == R) ? "플레이어 승!" : "플레이어 패...");
		}
	}
}
