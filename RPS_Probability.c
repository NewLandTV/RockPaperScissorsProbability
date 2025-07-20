#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

// ���������� ��ó�� 
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
	
	printf("1 : �÷���, Other : Ȯ�� �˻�\n> ");
	scanf("%d", &flag);
	
	if (flag == 1)
	{
		PlayGame();
		
		return 0;
	}
	
	printf("�õ� Ƚ���� �Է��ϼ���.\n> ");
	scanf("%d", &t);
	StepRPCGame(t);	// Ȯ�� ����� ���� t�� ���������� ����  (Random vs Random)
	printf("�÷��̾ �̱� Ȯ�� : %.24Lf%\n", (win / testcase) * 100.0);
	printf("���������� ��� Ȯ�� : %.24Lf%\n", (draw / testcase) * 100.0);
	printf("�÷��̾ ���� Ȯ�� : %.24Lf%\n", (lose / testcase) * 100.0);
	
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
				printf("���� vs ");
				
				break; 
			case R:
				printf("���� vs ");
				
				break; 
			case P:
				printf("�� vs ");
				
				break; 
			}
			
			switch (x)
			{
			case S:
				printf("����");
				
				break; 
			case R:
				printf("����");
				
				break; 
			case P:
				printf("��");
				
				break; 
			}
			
			printf("\n");
		}
		
		if (x == y)
		{
			draw++;
			
			if (SHOW_RESULT == 1) printf("���º�\n\n");
		}
		else if ((x == S && y == P) || (x == R && y == S) || (x == P && y == R))
		{
			win++;
			
			if (SHOW_RESULT == 1) printf("�÷��̾� ��!\n\n");
		}
		else
		{
			lose++;
			
			if (SHOW_RESULT == 1) printf("�÷��̾� ��...\n\n");
		}
	}
}

void PlayGame()
{
	int input, x;
	
	while (1)
	{
		printf("���� : %d, ���� : %d, �� : %d\n> ", S, R, P);
		scanf("%d", &input);
		
		switch (input)
		{
		case S:
			printf("���� vs ");
			
			break; 
		case R:
			printf("���� vs ");
			
			break; 
		case P:
			printf("�� vs ");
			
			break; 
		}
		
		x = rand() % 3 + 1;	// Random (1 to 3)
		
		switch (x)
		{
		case S:
			printf("����");
			
			break; 
		case R:
			printf("����");
			
			break; 
		case P:
			printf("��");
			
			break; 
		}
		
		printf("\n");
		
		if (x == input)
		{
			printf("���º�\n\n");
		}
		else
		{
			printf("%s\n\n", (input == S && x == P) || (input == R && x == S) || (input == P && x == R) ? "�÷��̾� ��!" : "�÷��̾� ��...");
		}
	}
}
